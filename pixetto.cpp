#include "pxt.h"
#include "MicroBit.h"

#define PXT_PACKET_START 	0xFD
#define PXT_PACKET_END   	0xFE
#define PXT_CMD_STREAMON	0x79

//% color=#D400D4 weight=111 icon="\uf192"
namespace pixetto {
	MicroBitSerial *serial=nullptr;
	
    //% 
    void begin(PinName rx, PinName tx){
		uint8_t data_buf[5] = {PXT_PACKET_START, 0x05, PXT_CMD_STREAMON, 0, PXT_PACKET_END};
        serial=new MicroBitSerial(rx, tx);
        serial->baud(38400);
        uBit.sleep(100);
        
        serial->send(data_buf, 5);
        //uBit.sleep(1000);
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
		
		//return 5;
		if (data_buf[2] < 20)
			return data_buf[2];
		else
			return 0;
	}
}
