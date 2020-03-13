#include "mbed.h"

//% color=#D400D4 weight=111 icon="\uf192"
namespace pixetto {
    //% 
    void begin(PinName rx, PinName tx){
        serial=new MicroBitSerial(rx, tx);
        serial.baud(38400);
        
        serial.send("{\"header\":\"STREAMON\"};");
    }
    
    ManagedString isDetected(){
		a = serial.readUntil(";")
		return a;
	}
	
}
