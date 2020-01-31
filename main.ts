enum pins {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    A0,
    A1,
    A2,
    A3,
    A4,
    A5
}

//% weight=0 color=#A88002 icon="\uf0ad" block="pixetto"
namespace pixetto {

	//% block="初始化視覺感測器 RX# %rx TX# %tx"
	export function ss_init(rx: DigitalPin, tx: DigitalPin) {

    }
    /**
    * 計算長方形面積，並回傳
    */
    //% blockId="areaOfRectangle" block="area of rectangle length %length|width %width"
    //% blockGap=2 weight=0 blockExternalInputs=true
    export function areaOfRectangle(length: number, width:number): number {
        return length*width
    }
    /**
    * 計算長方形面積，不回傳，只顯示在LED
    */
    //% blockId="ledOfRectangle" block="show area of rectangle length %length|width %width"
    //% blockGap=2 weight=1
    export function ledOfRectangle(length: number, width:number): void {
        basic.showNumber(length*width)
    }
}
