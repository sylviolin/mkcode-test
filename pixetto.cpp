//#include "pxt.h"
//#include "mbed.h"
//#include "MicroBitPin.h"
//#include "MicroBitSerial.h"
#include "MicroBit.h"

#ifdef CODAL_CONFIG_H
#define MICROBIT_CODAL 1
#else
#define MICROBIT_CODAL 0
#define target_panic(n) microbit_panic(n)
#define target_wait(n) wait_ms(n)
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

enum PixFunction {
        //% block="Color Detection"
        COLOR_DETECTION=1,
        //% block="Color Codes Detection"
        COLOR_LABEL=2,
        //% block="Shape Detection"
        SHAPE_DETECTION=3,
        //% block="Sphere Detection"
        SPHERE_DETECTION=4,
        //% block="Template Matching"
        TEMPLATE=6,
        //% block="Keypoint"
        KEYPOINT=8,
        //% block="Neural Network"
        NEURAL_NETWORK=9,
        //% block="AprilTag(16h5)"
        APRILTAG=10,
        //% block="Face Detection"
        FACE_DETECTION=11,
        //% block="Traffic Sign Detection"
        TRAFFIC_SIGN_DETECTION=12,
        //% block="Handwritten Digits Detection"
        HANDWRITTEN_DIGITS_DETECTION=13,
        //% block="Handwritten Letters Detection"
        HANDWRITTEN_LETTERS_DETECTION=14,
        //% block="Remote Computing"
        REMOTE_COMPUTING=15,
        //% block="Lanes Detection"
        LANES_DETECTION=16,
        //% block="Digits Operation"
        DIGITS_OPERATION=17,
        //% block="Simple Classifier"
        SIMPLE_CLASSIFIER=18,
        //% block="Voice Commands"
        VOICE_COMMANDS=19
};
    
enum PixApriltagField {
        //% block="position x"
        APRILTAG_POS_X=1,
        //% block="position y"
        APRILTAG_POS_Y,
        //% block="position z"
        APRILTAG_POS_Z,
        //% block="rotation x"
        APRILTAG_ROT_X,
        //% block="rotation y"
        APRILTAG_ROT_Y,
        //% block="rotation z"
        APRILTAG_ROT_Z,
        //% block="center x"
        APRILTAG_CENTER_X,
        //% block="center y"
        APRILTAG_CENTER_Y
};

enum PixLanesField {
        //% block="Left X1"
        LANES_LX1=1,
        //% block="Left Y1"
        LANES_LY1,
        //% block="Left X2"
        LANES_LX2,
        //% block="Left Y2"
        LANES_LY2,
        //% block="Right X1"
        LANES_RX1,
        //% block="Right Y1"
        LANES_RY1,
        //% block="Right X2"
        LANES_RX2,
        //% block="Right Y2"
        LANES_RY2
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
	/*
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
    }*/
	
    //% 
    bool begin(PixSerialPin rx, PixSerialPin tx){
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
