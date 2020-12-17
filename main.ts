//% weight=111 color=#A88002 icon="\uf030" block="VIA Pixetto" 
namespace pixetto {

    export enum PixColorType {
        //% block="red"
        RED=1,
        //% block="yellow"
        YELLOW,
        //% block="green"
        GREEN,
        //% block="blue"
        BLUE,
        //% block="purple"
        PURPLE,
        //% block="black"
        BLACK
    }
    
    export enum PixShapeType {
        //% block="circle"
        CIRCLE=1,
        //% block="rectangle"
        RECTANGLE,
        //% block="triangle"
        TRIANGLE,
        //% block="pentagon"
        PENTAGON,
    }

    export enum PixTrafficSign {
        //% block="No entre"
        SIGN_NO_ENTRE = 0,
        //% block="No left turn"
		SIGN_NO_LEFT_TURN,
		//% block="No right turn"
		SIGN_NO_RIGHT_TURN,
		//% block="Wrong way"
		SIGN_WRONG_WAY,
		//% block="No U turn"
		SIGN_NO_U_TURN,
		//% block="Maximum speed limit"
		SIGN_MAX_SPEED,
		//% block="One-way traffic"
		SIGN_ONEWAY_TRAFFIC,
		//% block="Left turn"
		SIGN_LEFT_TURN,
		//% block="Right turn"
		SIGN_RIGHT_TURN,
		//% block="Minimum speed limit"
		SIGN_MIN_SPEED,
		//% block="U turn"
		SIGN_U_TURN,
		//% block="Tunnel ahead"
		SIGN_TUNNEL_AHEAD,
		//% block="Beware of children"
		SIGN_BEWARE_OF_CHILDREN,
		//% block="Roundabout"
		SIGN_ROUNDABOUT,
		//% block="Yield to pedestrian"
		SIGN_YIELD_TO_PEDESTRIAN,
		//% block="Red light"
		SIGN_RED_LIGHT,
		//% block="Green light"
		SIGN_GREEN_LIGHT
    }
  
    export enum PixHandDigit {
        //% block="0"
        Digit_0,
        //% block="1"
        Digit_1,
        //% block="2"
        Digit_2,
        //% block="3"
        Digit_3,
        //% block="4"
        Digit_4,
        //% block="5"
        Digit_5,
        //% block="6"
        Digit_6,
        //% block="7"
        Digit_7,
        //% block="8"
        Digit_8,
        //% block="9"
        Digit_9
    }
    
    export enum PixHandLetter {
		//% block="Aa"
		A=0,
		//% block="Bb"
		B,
		//% block="Cc"
		C,
		//% block="Dd"
		D,
		//% block="Ee"
		E,
		//% block="Ff"
		F,
		//% block="Gg"
		G,
		//% block="Hh"
		H,
		//% block="Ii"
		I,
		//% block="Jj"
		J,
		//% block="Kk"
		K,
		//% block="Ll"
		L,
		//% block="Mm"
		M,
		//% block="Nn"
		N,
		//% block="Oo"
		O,
		//% block="Pp"
		P,
		//% block="Qq"
		Q,
		//% block="Rr"
		R,
		//% block="Ss"
		S,
		//% block="Tt"
		T,
		//% block="Uu"
		U,
		//% block="Vv"
		V,
		//% block="Ww"
		W,
		//% block="Xx"
		X,
		//% block="Yy"
		Y,
		//% block="Zz"
		Z
    }
      
    export enum PixVoiceCommand {
		//% block="你好"
		VOICE_Hello = 1,
		//% block="謝謝"
		VOICE_Thanks,
		//% block="再見"
		VOICE_Bye,
		//% block="這是甚麼"
		VOICE_WhatsThis,
		//% block="現在幾點"
		VOICE_WhatTime,
		//% block="我幾歲"
		VOICE_HowOld,
		//% block="今天星期幾"
		VOICE_WhatDay,
		//% block="講故事"
		VOICE_TellStory,
		//% block="說笑話"
		VOICE_TellJoke,
		//% block="念唐詩"
		VOICE_ReadPoem,
		//% block="開燈"
		VOICE_TurnOnLight,
		//% block="關燈"
		VOICE_TurnOffLight,
		//% block="左轉"
		VOICE_TurnLeft,
		//% block="右轉"
		VOICE_TurnRight,
		//% block="前進"
		VOICE_GoAhead,
		//% block="後退"
		VOICE_MoveBack,
		//% block="停止"
		VOICE_Stop,
		//% block="開啟"
		VOICE_Open,
		//% block="關閉"
		VOICE_Close,
		//% block="睜開眼睛"
		VOICE_OpenEyes1,
		//% block="睜眼"
		VOICE_OpenEyes2,
		//% block="閉上眼睛"
		VOICE_CloseEyes1,
		//% block="閉眼"
		VOICE_CloseEyes2,
		//% block="跳一下"
		VOICE_Jump,
		//% block="起立"
		VOICE_StandUp,
		//% block="蹲下"
		VOICE_SquatDown
    }
    
	//% block="initialize vision sensor RX %rx TX %tx"
	//% shim=pixetto::begin
	//% weight=100
	export function begin(rx: PixSerialPin, tx: PixSerialPin): boolean {
		return false
    }
    
}
