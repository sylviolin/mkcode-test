#include "pxt.h"
#include "MicroBit.h"

#define PXT_PACKET_START 	0xFD
#define PXT_PACKET_END   	0xFE
#define PXT_CMD_STREAMON	0x79

#define PXT_RET_CAM_SUCCESS	0xE0
#define PXT_RET_CAM_ERROR	0xE1

//% color=#D400D4 weight=111 icon="\uf192"
namespace pixetto {
	MicroBitSerial *serial = &uBit.serial; //nullptr;
	uint8_t data_buf[10] = {0xFF};

    //% 
    int begin(PinName rx, PinName tx){
		PinName txn;
		PinName rxn;
		
		//if (tryResolvePin(tx, txn) && tryResolvePin(rx, rxn))
		{
			//serial=new MicroBitSerial(MICROBIT_PIN_P2, MICROBIT_PIN_P1);//(txn, rxn);
			serial->baud(38400);
			serial->redirect(MICROBIT_PIN_P0, MICROBIT_PIN_P1);
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
			/*
			int i = 1;
			do {
				read_len = serial->read(&code_buf[i], 1);
				//if (read_len == 0) continue; //return 0;
				i++;
			} while (code_buf[i-1] != PXT_PACKET_END && i < 5);
			*/
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
		
		do {
			read_len = serial->read(data_buf, 1, ASYNC);
			//if (read_len == 0) continue; //return 0;
			//if (read_len == MICROBIT_SERIAL_IN_USE) return 0;
			//if (read_len == 0) return 0;
		} while (data_buf[0] != PXT_PACKET_START);

		/*
		int i = 1;
		do {
			read_len = serial->read(&data_buf[i], 1);
			if (read_len == MICROBIT_SERIAL_IN_USE) continue;
			if (read_len == 0) continue;
			if (data_buf[i] == 0xFF) continue;
			i++;
		} while (data_buf[i-1] != PXT_PACKET_END && i < 10);
		*/
		
		read_len = serial->read(&data_buf[1], 9);
		
		int aa = 10000;
		if (data_buf[0] == PXT_PACKET_START) aa += 5000;
		if (data_buf[9] == PXT_PACKET_END) aa += 600;
		if (data_buf[2] == 1) aa += 70;
		if (data_buf[3] == 4) aa += 8;
		return aa;
		
	}
	
	
	int getFuncID(){
		if (data_buf[0] == PXT_PACKET_START) return 6;
		else return 9;
		//return data_buf[1];
	}

	int getTypeID() {
		return data_buf[2];
	}

	int getPosX() {
		return data_buf[3];
	}
	
	int getPosY() {
		if (data_buf[9] == PXT_PACKET_END) return 6;
		else return 9;
		
	}
}
