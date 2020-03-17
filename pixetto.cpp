#include "pxt.h"
#include "MicroBit.h"

#define PXT_PACKET_START 	0xFD
#define PXT_PACKET_END   	0xFE
#define PXT_CMD_STREAMON	0x79

using namespace pxt;

//% color=#D400D4 weight=111 icon="\uf192"
namespace pixetto {
	MicroBitSerial *serial=nullptr;
	
    //% 
    void begin(PinName rx, PinName tx){
		PinName txn;
		PinName rxn;

		//if (tryResolvePin(tx, txn) && tryResolvePin(rx, rxn))
		{
			serial=new MicroBitSerial(MICROBIT_PIN_P2, MICROBIT_PIN_P1);//(txn, rxn);
			serial->baud(38400);
			uBit.sleep(100);

			uint8_t data_buf[5] = {PXT_PACKET_START, 0x05, PXT_CMD_STREAMON, 0, PXT_PACKET_END};
			serial->send(data_buf, 5);
			//uBit.sleep(1000);
		}
    }
    
    //%
    int isDetected(){
		uint8_t data_buf[10] = {0};
		int read_len = 0;
		do {
			read_len = serial->read(data_buf, 1);
			if (read_len == 0) return 0;
		} while (data_buf[0] != PXT_PACKET_START);

		int i = 0;
		do {
			i++;
			read_len = serial->read(&data_buf[i], 1);
			if (read_len == 0) return 0;
		} while (data_buf[i] != PXT_PACKET_END && i < 9);
		
		if (data_buf[i] == PXT_PACKET_END)
			return i;
		if (i == 9)
			return 0;
		
		if (data_buf[2] < 20)
			return data_buf[2];
		else
			return 0;
	}
}
