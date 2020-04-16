//% weight=0 color=#A88002 icon="\uf0ad" block="Pixetto"
namespace pixetto {

	 export enum PixFunction {
        //% block="Color Detection"
        COLOR_DETECTION=1,
        //% block="Color Label Detection"
        COLOR_LABEL,
        //% block="Shape Detection"
        SHAPE_DETECTION,
        //% block="Circle Detection"
        CIRCLE_DETECTION,
        //% block="Template Matching"
        TEMPLATE,
        //% block="Keypoint"
        KEYPOINT,
        //% block="Neural Network"
        NEURAL_NETWORK,
        //% block="Face Detection"
        FACE_DETECTION,
        //% block="Traffic Sign Detection"
        TRAFFIC_SIGN_DETECTION,
        //% block="Handwriting Digits Detection"
        HANDWRITING_DIGITS_DETECTION,
        //% block="Handwriting Letters Detection"
        HANDWRITING_LETTERS_DETECTION,
        //% block="AprilTag(16h5)"
        APRILTAG
    }
    
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
    
	//% block="initialize vision sensor RX %rx TX %tx"
	//% shim=pixetto::begin
	export function begin(rx: PixSerialPin, tx: PixSerialPin): boolean {
		return false
    }
    
    //% block="object is detected"
    //% shim=pixetto::isDetected
    export function isDetected(): boolean {
		return false;
    }
    
    //% block="current function is %func_id"
    //% shim=pixetto::getFuncID
    export function getFuncID(func_id: PixFunction): boolean {
        return false;
    }
    
    //% block="object type"
    //% shim=pixetto::getTypeID
    export function getTypeID(): number {
        return 0;
    }
    
    //% block="object position x"
    //% shim=pixetto::getPosX
    export function getPosX(): number {
        return 0;
    }
    
    //% block="object position y"
    //% shim=pixetto::getPosY
    export function getPosY(): number {
        return 0;
    }

    //% block="object width"
    //% shim=pixetto::getWidth
    export function getWidth(): number {
        return 0;
    }

    //% block="object height"
    //% shim=pixetto::getHeight
    export function getHeight(): number {
        return 0;
    }
}
