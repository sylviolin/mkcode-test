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

//using namespace codal;
//using namespace pxt;

namespace pixetto {
	//NRF52Serial *serial = nullptr;
	//MicroBitSerial *serial = nullptr;
	//bool bOnStarting = false;

    //% 
    bool begin() { 
		//bOnStarting = true;

		bool ret = false;
		//uBit.sleep(3000);
		
		//uBit.serial.setBaudrate(38400);
		//uBit.sleep(100);

		//if (ret)
			//bOnStarting = false;
			
		return ret;
    }
    
}
