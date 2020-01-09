/*
 * @author afmika
 * github.com/afmika
 * email afmichael73@gmail.com
 **/

module.exports = class Point {
    constructor(x, y, name) {
        this.x = x;
        this.y = y;
		this.name = name || '';
    }
	
	toString() {
		return this.name + `(${this.x}, ${this.y})`;
	}
	
    equals (point) {
        return point.x == this.x && point.y == this.y;
    }
}