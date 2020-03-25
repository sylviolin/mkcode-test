#include "pxt.h"
#include "mbed.h"
#include "MicroBitConfig.h"
#include "MicroBitPin.h"
#include "MicroBitSerial.h"

#define PXT_PACKET_START 	0xFD
#define PXT_PACKET_END   	0xFE
#define PXT_CMD_STREAMON	0x79
#define PXT_CMD_QUERY		0x7B

#define PXT_RET_CAM_SUCCESS	0xE0
#define PXT_RET_CAM_ERROR	0xE1

enum SerialPin2 {
	//% block="P0"
    PP0 = 0,
    //% block="P1"
    PP1 = 1,
    //% block="P2"
    PP2 = 2,
    //% block="P8"
    PP8 = 8,
    //% block="P12"
    PP12 = 12,
    //% block="P13"
    PP13 = 13,
    //% block="P14"
    PP14 = 14,
    //% block="P15"
    PP15 = 15,
    //% block="P16"
    PP16 = 16
};

using namespace pxt;

//% color=#A88002 weight=111 icon="\uf192"
namespace pixetto {

	MicroBitSerial *serial = nullptr;
	uint8_t data_buf[10] = {0xFF};

    bool tryResolvePin(SerialPin2 p, PinName& name) {
      switch(p) {
        case PP0: name = MICROBIT_PIN_P0;  return true;
        case PP1: name = MICROBIT_PIN_P0;  return true;
        case PP2: name = MICROBIT_PIN_P0;  return true;
        case PP8: name = MICROBIT_PIN_P0;  return true;
        case PP12: name = MICROBIT_PIN_P0; return true;
        case PP13: name = MICROBIT_PIN_P0; return true;
        case PP14: name = MICROBIT_PIN_P0; return true;
        case PP15: name = MICROBIT_PIN_P0; return true;
        case PP16: name = MICROBIT_PIN_P0; return true;
      }
      return false;
    }

    //% 
    int begin(SerialPin2 rx, SerialPin2 tx){
		PinName txn, rxn;
		if (tryResolvePin(tx, txn) && tryResolvePin(rx, rxn))
		{
			serial = new MicroBitSerial(txn, rxn); //(MICROBIT_PIN_P1, MICROBIT_PIN_P2);
			serial->baud(38400);
			//serial->setRxBufferSize(500);
			//serial->setTxBufferSize(32);
			uBit.sleep(100);

			uint8_t cmd_buf[5] = {PXT_PACKET_START, 0x05, PXT_CMD_STREAMON, 0, PXT_PACKET_END};
			serial->send(cmd_buf, 5);
			//uBit.sleep(100);
			
			int read_len = 0;
			
			uint8_t code_buf[5] = {0};
			do {
				read_len = serial->read(code_buf, 1, ASYNC);
			} while (code_buf[0] != PXT_PACKET_START);

			read_len = serial->read(&code_buf[1], 4);
			int aa = 10000;
			if (code_buf[0] == PXT_PACKET_START) aa += 1;
			if (code_buf[1] == 5) aa += 20;
			if (code_buf[2] == PXT_RET_CAM_SUCCESS) aa +=300;
			if (code_buf[4] == PXT_PACKET_END) aa += 4000;
			return aa;
		}
    }
    
    //%
    int isDetected(){
		int read_len = 0;
		for (int a=0; a<10; a++)
			data_buf[a] = 0xFF;
	
		uint8_t cmd_buf[5] = {PXT_PACKET_START, 0x05, PXT_CMD_QUERY, 0, PXT_PACKET_END};
		serial->send(cmd_buf, 5);

		do {
			read_len = serial->read(data_buf, 1, ASYNC);
		} while (data_buf[0] != PXT_PACKET_START);

		read_len = serial->read(&data_buf[1], 9);
		if (read_len != 9) return 0;
		if (data_buf[9] != PXT_PACKET_END) return 0;
		if (data_buf[3] == 0) return 0;
		return 1;
	}
	//%
	int getFuncID(){
		return data_buf[2];
	}
	//%
	int getTypeID() {
		return data_buf[3];
	}
	//%
	int getPosX() {
		return data_buf[4];
	}
	//%
	int getPosY() {
		return data_buf[5];
	}
	//%
	int getWidth() {
		return data_buf[6];
	}
	//%
	int getHeight() {
		return data_buf[7];
	}
}
