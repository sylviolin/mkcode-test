//% weight=0 color=#A88002 icon="\uf0ad" block="Pixetto"
namespace PIXETTO {
	//% block="初始化視覺感測器 RX %rx TX %tx"
	//% shim=pixetto::begin
	function begin(rx: SerialPin2, tx: SerialPin2): number {
		return 0
    }
    
    //% block="識別到物體"
    //% shim=pixetto::isDetected
    function isDetected(): number {
		return 0
    }
    
    //% block="目前功能"
    //% shim=pixetto::getFuncID
    function getFuncID(): number {
        return 0;
    }
    
    //% block="物體類別"
    //% shim=pixetto::getTypeID
    function getTypeID(): number {
        return 0;
    }
    
    //% block="物體座標X"
    //% shim=pixetto::getPosX
    function getPosX(): number {
        return 0;
    }
    
    //% block="物體座標Y"
    //% shim=pixetto::getPosY
    function getPosY(): number {
        return 0;
    }

    //% block="物體寬度"
    //% shim=pixetto::getWidth
    function getWidth(): number {
        return 0;
    }

    //% block="物體高度"
    //% shim=pixetto::getHeight
    function getHeight(): number {
        return 0;
    }
}
