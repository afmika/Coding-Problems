/*
You have a rectangular white board with some black cells. The black cells create a connected black figure, i.e. it is possible to get from any black cell to any other one through connected adjacent (sharing a common side) black cells.

Find the perimeter of the black figure assuming that a single cell has unit length.

It's guaranteed that there is at least one black cell on the table.

Example

    For

    matrix = [[false, true,  true ],
              [true,  true,  false],
              [true,  false, false]]

    the output should be
    polygonPerimeter(matrix) = 12
	
*/

function Cell (x, y, dim) {
	this.x = x;
	this.y = y;
	this.number = x + y * dim; 	
	this.initBounds = function () {
		this.bounds = {
			left : `LEFT_${ this.number }`,
			right :`RIGHT_${ this.number }`,
			down : `DOWN_${ this.number }`,
			up :   `UP_${ this.number }`
		};
		if ( x + 1 < dim ) {
			this.bounds.right_mir = `LEFT_${ this.number + 1 }`;
		}
		if ( x > 0 ) {
			this.bounds.left_mir = `RIGHT_${ this.number - 1 }`;
		}
		if ( y + 1 < dim ) {
			this.bounds.down_mir = `UP_${ this.number + dim }`;
		}
		if ( y > 0 ) {
			this.bounds.up_mir = `DOWN_${ this.number - dim }`;
		}
	}
	
	this.getBoundsAsKeysArray = function() {
		let arr = [];
		for (let bound in this.bounds ) {
			arr.push(this.bounds[bound]);
		}
		return arr;
	}
	
	this.initBounds();
} 
// if two squares share the same bound{} 
// => this common bound{} should not be counted and need to be removed!
function polygonPerimeter(matrix) {
    
	let cell_arr = [];
	let num_map = {};
	for (let y = 0; y < matrix.length; y++) {
		for (let x = 0; x < matrix[y].length; x++) {
			if ( matrix[y][x] ) {				
				let dim = matrix[y].length;
				let cell = new Cell(x, y, dim);
				num_map[  x + y * dim ] = true;
				cell_arr.push( cell );
			}
		}
	}

	let map = {};
	let similar = {};
	for (let c = 0; c < cell_arr.length; c++) {
		let arr = cell_arr[c].getBoundsAsKeysArray();
		arr.forEach( key => {
			let cur_digit = key.split('_')[1];
			if ( num_map[ cur_digit ] ) {				
				if (map[key] == undefined ) {
					map[key] = true;
				} else {
					similar[key] = true;
				}
			}
		});
	}
	let p = 0;
	for (let key in map ) {
		if ( similar[key] == undefined ) {
			// console.log(key);
			p++;
		}
	}
	return p;
}

let arr= [
	[true, true, true],
	[true, false, true],
	[false, true, true]
];
console.log( polygonPerimeter(arr)  );