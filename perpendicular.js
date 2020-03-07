/**
 * @author afmika
 * github.com/afmika
 * afmichael73@gmail.com
 */
 
 
 /*
 * COMPUTES THE SIZE OF THE SET OF PERPENDICULAR SEGMENTS WITH A GIVEN SET OF RANDOM POINTS
 * */

let Point = require("./data_structures/Point");
let Hashmap = require("./data_structures/Hashmap");
let Segment = require("./data_structures/Segment");

function countPerpendicularLines( points ) {

    let segment_map = new Hashmap();
    points.forEach(A => {
        points.forEach(B => {
            if( ! A.equals(B)  ) {
                let segment = new Segment(A, B);
                segment_map.set(segment, 1);
            }
        });
    });

    let perp_map = new Hashmap();
    
    segment_map.forEach((segA, vA) => {
        segment_map.forEach((segB, vB) => {
            // they must have one shared point !
            // the scalar product considers each segment as a vector from the origin
            // that's why we need to check if seg A & seg B shares one point
            if( ! segA.equals( segB ) && segA.perpendicularTo( segB ) && segA.sharedPointWith( segB ) == 1) {
                let temp_map = new Hashmap();
                // temp_map.set( segA, segB); // not good because order doesnt matter
                temp_map.set( segA, -1 );
                temp_map.set( segB, -1 );
                perp_map.set( temp_map, -1 );
           }
        });
    });
    
    perp_map.forEach((k, v) => {
        // displays
        let aff_arr = [];
        k.forEach(seg => {
            aff_arr.push( seg.toString() );
        });
        console.log(aff_arr.join(" is perpendicular to "));
    });
    return perp_map.key.length;
}



let points = [
    new Point(1, 0, 'A'),
    new Point(0, 1, 'B'),
    new Point(1, 1, 'C'),
    new Point(5, 3, 'D'),
    new Point(5, 5, 'E'),
    new Point(-1, 1, 'F'),
    new Point(1, 5, 'G'),
];

console.log( "Size ", countPerpendicularLines( points ) );

/*
let a = new Point(1, 1);
let b = new Point(2, 1);
let s1 = new Segment(a, b);
let s2 = new Segment(b, a);
let s3 = new Segment(a, new Point(1, 2));
console.log(s3.scalarProd(s1), "cross");


let h = new Hashmap(), u = new Hashmap();
h.set(s1, 1);
u.set(s1, 1);
console.log(h.equals(u), "HASHMAP COMPARE");
console.log(s1.equals(s2))
console.log(h.key, h.value)
*/