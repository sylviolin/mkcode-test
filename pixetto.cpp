#include "pxt.h"
#include "MicroBit.h"

#define PXT_PACKET_START 	0xFD
#define PXT_PACKET_END   	0xFE
#define PXT_CMD_STREAMON	0x79
#define PXT_CMD_QUERY		0x7B

#define PXT_RET_CAM_SUCCESS	0xE0
#define PXT_RET_CAM_ERROR	0xE1

//% color=#D400D4 weight=111 icon="\uf192"
namespace pixetto {
	MicroBitSerial *serial = nullptr;
	uint8_t data_buf[10] = {0xFF};
	int funcid = 0;
	int tid = 0;
	int posx = 0;
	int posy = 0;
	int width = 0;
	int height = 0;
    //% 
    int begin(PinName rx, PinName tx){
		PinName txn;
		PinName rxn;
		
		//if (tryResolvePin(tx, txn) && tryResolvePin(rx, rxn))
		{
			serial=new MicroBitSerial(MICROBIT_PIN_P1, MICROBIT_PIN_P2);//(txn, rxn);
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
		
		funcid	= data_buf[2];
		tid		= data_buf[3];
		posx	= data_buf[4];
		posy	= data_buf[5];
		width	= data_buf[6];
		height	= data_buf[7];
		return 1;
		
		/*
		int aa = 10000;
		if (data_buf[0] == PXT_PACKET_START) aa += 5000;
		if (data_buf[9] == PXT_PACKET_END) aa += 600;
		if (data_buf[2] == 1) aa += 70;
		if (data_buf[3] == 4) aa += 8;
		
		if (data_buf[8] == PXT_PACKET_END) aa += 200;
		if (data_buf[1] == 1) aa += 30;
		if (data_buf[2] == 4) aa += 4;
		
		return aa;
		*/
	}
	
	
	int getFuncID(){
		return funcid;
	}

	int getTypeID() {
		return tid;
	}

	int getPosX() {
		return posx;
	}
	
	int getPosY() {
		return posy;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}
}
