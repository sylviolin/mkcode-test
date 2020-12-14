//#include "pxt.h"
//#include "mbed.h"
//#include "MicroBitPin.h"
//#include "MicroBitSerial.h"
#include "MicroBit.h"


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

using namespace codal;

namespace pixetto {
	NRF52Serial *serial = nullptr;
	//MicroBitSerial *serial = nullptr;
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

    //% 
    bool begin() { 
		bOnStarting = true;
		
		//uBit.init();
		
		bool ret = false;
		PinName txn, rxn;
		uBit.sleep(3000);
		
		//if (getPinName(tx, txn) && getPinName(rx, rxn))
		{
			//if (serial == nullptr)
				//serial = &(uBit.serial);
				//serial = new NRF52Serial(*new NRF52Pin(txn, txn, PIN_CAPABILITY_ALL), *new NRF52Pin(rxn, rxn, PIN_CAPABILITY_ALL));
				//serial = new NRF52Serial(txn, rxn);//, 64, 20);
				//serial = new MicroBitSerial(txn, rxn, 64, 20);
				

			//serial->baud(38400);
			uBit.serial.setBaudrate(38400);
			//serial->setRxBufferSize(64);
			//serial->setTxBufferSize(32);
			uBit.sleep(100);
			
			//ret = opencam(false);
		}
		if (ret)
			bOnStarting = false;
			
		return ret;
    }
    
}
