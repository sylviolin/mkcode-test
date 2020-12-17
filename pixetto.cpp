//#include "pxt.h"
//#include "mbed.h"
//#include "MicroBitPin.h"
//#include "MicroBitSerial.h"
#include "MicroBit.h"

#ifdef CODAL_CONFIG_H
#define MICROBIT_CODAL 1
#else
#define MICROBIT_CODAL 0
#endif

#define PXT_PACKET_START 	0xFD
#define PXT_PACKET_END   	0xFE
#define PXT_CMD_STREAMOFF	0x7A
#define PXT_CMD_STREAMON_CB 0x7B
#define PXT_CMD_QUERY		0x7C
#define PXT_CMD_RESET		0x53 //(83)

#define PXT_RET_CAM_SUCCESS	0xE0
#define PXT_RET_CAM_ERROR	0xE1   

#define SERIAL_BUF_SIZE		64
#define DATA_SIZE			33

enum PixSerialPin {
    P0 = 0,
    P1 = 1,
    P2 = 2,
    P8 = 8,
    P12 = 12,
    P13 = 13,
    P14 = 14,
    P15 = 15,
    P16 = 16
};

//using namespace pxt;
//using namespace codal;

namespace pixetto {
	MicroBit uBit;
	MicroBitSerial *serial = nullptr;
	uint8_t data_buf[DATA_SIZE] = {0xFF};
	int data_len = 0;
	int m_type = 0;
	int m_x = 0;
	int m_y = 0;
	int m_w = 0;
	int m_h = 0;
	int m_eqLen = 0;
	float m_eqAnswer = 0;
	char m_eqExpr[17] = {0};
	float m_posx=0, m_posy=0, m_posz=0, m_rotx=0, m_roty=0, m_rotz=0, m_centerx=0, m_centery=0;
	bool bOnStarting = false;

    bool getPinName(PixSerialPin p, PinName& name) {
      switch(p) {
        case P0: name = MICROBIT_PIN_P0;  return true;
        case P1: name = MICROBIT_PIN_P1;  return true;
        case P2: name = MICROBIT_PIN_P2;  return true;
        case P8: name = MICROBIT_PIN_P8;  return true;
        case P12: name = MICROBIT_PIN_P12; return true;
        case P13: name = MICROBIT_PIN_P13; return true;
        case P14: name = MICROBIT_PIN_P14; return true;
        case P15: name = MICROBIT_PIN_P15; return true;
        case P16: name = MICROBIT_PIN_P16; return true;
      }
      return false;
    }
    
    bool ssflush()
	{
		uint8_t a;
		
		int read_len = 0;
		do {
			read_len = serial->read(&a, 1, ASYNC);
		} while (read_len > 0 && read_len != MICROBIT_NO_DATA);
		
		return true;
	}
	
	int ssread(uint8_t *buf, int len, int wait_loop)
	{
		int read_len = 0;
		int read_idx = 0;
		int loop = 0;
		do {
			read_len = serial->read(&buf[read_idx], 1, ASYNC);
			
			if (read_len == 0 || read_len == MICROBIT_NO_DATA)
				loop++;
			else
				read_idx++;
		} while (read_idx < len && loop < wait_loop);
		
		if (read_len == 0 || read_len == MICROBIT_NO_DATA)
			read_idx = read_len;

		return read_idx;
	}

	bool opencam(bool reset) 
	{
		if (reset)
			uBit.sleep(8000);
			
		int try_streamon = 0;
		do {
			ssflush();
			
			uint8_t cmd_buf[5] = {PXT_PACKET_START, 0x05, PXT_CMD_STREAMON_CB, 0, PXT_PACKET_END};
			serial->send(cmd_buf, 5, ASYNC);
			
			int read_len = 0;
			uint8_t code_buf[5] = {0xFF};
			
			read_len = ssread(code_buf, 1, 50000);			
			if (read_len == 0 || read_len == MICROBIT_NO_DATA) return false;
			
			read_len = ssread(&code_buf[1], 4, 50000);

			if (read_len == 4 &&
			    code_buf[0] == PXT_PACKET_START &&
				code_buf[4] == PXT_PACKET_END &&
				code_buf[2] == PXT_RET_CAM_SUCCESS)
				return true;
				
			try_streamon++;
			uBit.sleep(500);
		} while (try_streamon < 4);
		
		return false;
	}
	
    //% 
    bool begin(PixSerialPin rx, PixSerialPin tx){
		bOnStarting = true;
		bool ret = false;

		PinName txn, rxn;
		//uBit.init();
		
		uBit.sleep(3000);
		
		if (getPinName(tx, txn) && getPinName(rx, rxn))
		{
			serial = new MicroBitSerial(txn, rxn, 64, 20);
				
			#if MICROBIT_CODAL
			serial->setBaudrate(38400);
			#else
			serial->baud(38400);
			#endif
			//serial->setRxBufferSize(64);
			//serial->setTxBufferSize(32);
			uBit.sleep(100);
			
			ret = opencam(false);
		}
		if (ret)
			bOnStarting = false;
			
		return ret;
    }
}
