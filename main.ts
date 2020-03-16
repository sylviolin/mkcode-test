//% weight=0 color=#A88002 icon="\uf0ad" block="Pixetto"
namespace PIXETTO {

	//% block="初始化視覺感測器 RX %rx TX %tx"
	//% shim=pixetto::begin
	export function begin(rx: SerialPin, tx: SerialPin): void {
		return;
    }
    
    //% block="識別到物體"
    //% shim=pixetto::isDetected
    export function isDetected(): number {
		return 0;
    }
    
    //% block="目前功能"
    export function getFuncID(): number {
        return 0;
    }
    
    //% block="物體類別"
    export function getTypeID(): number {
        return 0;
    }
    
    //% block="物體座標X"
    export function getPosX(): number {
        return 0;
    }
    
    //% block="物體座標Y"
    export function getPosY(): number {
        return 0;
    }

    //% block="物體寬度"
    export function getWidth(): number {
        return 0;
    }

    /**
    * 計算長方形面積，並回傳
    */
    //% block="物體高度"
    export function getHeight(): number {
        return 0;
    }
}
