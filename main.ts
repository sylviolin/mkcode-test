enum ser_pins {
    P0 = 1,
    P1 = 2,
    P2 = 3
}

//% weight=0 color=#A88002 icon="\uf0ad" block="pixetto"
namespace pixetto {

	//% block="初始化視覺感測器 RX %rx TX %tx"
	export function ss_init(rx: ser_pins, tx: ser_pins): boolean {
		return true;
    }
    
    //% block="識別到物體"
    export function isDetected(): boolean {
        return false;
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
