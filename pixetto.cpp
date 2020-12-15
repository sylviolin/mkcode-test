//#include "pxt.h"
//#include "mbed.h"
//#include "MicroBitPin.h"
//#include "MicroBitSerial.h"
//#include "Serial.h"
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

Pin *edgeConnector[] = {
    &uBit.io.P0, 
    &uBit.io.P1, 
    &uBit.io.P2, 
    &uBit.io.P3, 
    &uBit.io.P4, 
    &uBit.io.P5, 
    &uBit.io.P6, 
    &uBit.io.P7, 
    &uBit.io.P8, 
    &uBit.io.P9, 
    &uBit.io.P10, 
    &uBit.io.P11, 
    &uBit.io.P12, 
    &uBit.io.P13, 
    &uBit.io.P14, 
    &uBit.io.P15, 
    &uBit.io.P16, 
    &uBit.io.P19, 
    &uBit.io.P20
};

namespace pixetto {
	Serial *serial = nullptr;
	
//#if MICROBIT_CODAL
	//codal::NRF52Serial *serial = nullptr;
//#else
	//MicroBitSerial *serial = nullptr;
//#endif

	//bool bOnStarting = false;
	MicroBit uBit;
	
    //% 
    bool begin() { 
		//uBit.init();
		bool ret = false;
		
		//uBit.sleep(3000);
		//Pin aa = uBit.io.P0;
		//Pin bb = uBit.io.P1;
		//serial = new Serial(&uBit.io.P0, &uBit.io.P1);

		//serial->setBaudrate(38400);
		
		//uBit.serial.printf("data");
		//uBit.serial.setBaudrate(38400);
		//uBit.sleep(100);

    uBit.display.disable();
    uBit.buttonA.disable();
    uBit.buttonB.disable();

    for (Pin *p : edgeConnector)
        p->setDigitalValue(0);

    while(1)
    {
        for (Pin *p : edgeConnector)
        {
            p->setDigitalValue(1);
            uBit.sleep(500);
            p->setDigitalValue(0);
            uBit.sleep(500);
        }
    }

		return ret;
    }
    
}
