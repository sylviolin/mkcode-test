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


//using namespace pxt;
//using namespace codal;

namespace pixetto {
	//MicroBit uBit;
	bool bOnStarting = false;
	
    //% 
    bool begin(){
		bool ret = false;

		bOnStarting = true;
		
		/*
		PinName txn, rxn;
		* 
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
			
			//ret = opencam(false);
		}*/
		if (ret)
			bOnStarting = false;
			
		return ret;
    }
}
