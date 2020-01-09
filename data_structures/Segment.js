/*
 * @author afmika
 * github.com/afmika
 * email afmichael73@gmail.com
 **/

let Point = require("./Point");

module.exports = class Segment {
    constructor(pA, pB) {
        if(pA.equals(pB)) {
            throw "POINTS MUST BE DIFFERENTS!";
        }
        this.vertexes = [pA, pB];
    }
    equals (segment) {
        let c = 0;
        this.vertexes.forEach(v => {
            segment.vertexes.forEach(s => {
                if( v.equals(s) ) {
                    c++;
                }
            });
        });
        return c == 2;
    }
    sharedPointWith (segment) {
        let n = 0;
        this.vertexes.forEach(v => {
            segment.vertexes.forEach(u => {
                if(u.equals(v)) {
                    n++;
                }
            })
        });
        return n;
    }
    scalarProd (segment) {
        let [a, b] = this.vertexes;
        let [c, d] = segment.vertexes;
        let v1 = new Point(b.x - a.x, b.y - a.y);
        let v2 = new Point(d.x - c.x, d.y - c.y);

        return v1.x * v2.x + v1.y * v2.y;
    }
    crossProd (segment) {
        let [a, b] = this.vertexes;
        let [c, d] = segment.vertexes;
        let v1 = new Point(b.x - a.x, b.y - a.y);
        let v2 = new Point(d.x - c.x, d.y - c.y);

        return v1.x * v2.y - v1.y * v2.x;
    }
    perpendicularTo (segment) {
        return this.scalarProd(segment) == 0;
    }
	
	toString() {
		return "Segment[ "+this.vertexes[0].toString()+", "+this.vertexes[1].toString()+" ]";
	}
}