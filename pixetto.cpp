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
	//MicroBit uBit;
	bool bOnStarting = false;
	
    //% 
    bool begin(PixSerialPin rx, PixSerialPin tx){
		bOnStarting = true;
		bool ret = false;

		/*
		PinName txn, rxn;
		uBit.init();
		
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
		}*/
		if (ret)
			bOnStarting = false;
			
		return ret;
    }
}
