function Game(dim) {
	this.dim = dim || 4;
	this.board = new Array( dim )
				.fill(0)
				.map(
					k => new Array(dim).fill('_')
				);;
	
	this.reset = function () {
		this.board = new Array( dim )
				.fill(0)
				.map(
					k => new Array(dim).fill('_')
				);
		this.pieces = {};
	}
	this.pieces = {};
	
	this.makeKey = function (c, r) {
		return r + ',' + c;
	}
	
	this.putValue = function(c, r, value) {
		this.board[r][c] = value;
		this.pieces[ this.makeKey(c, r) ] = { c : c, r : r};
	}
	
	this.putQueen = function(c, r) {
		if ( c >= this.dim || r >= this.dim ) 
			return false;
		let key = this.makeKey(c, r);
		if( this.pieces[ key ] ) {
			return false;
		}
		
		for( let item in this.pieces ) {
			const piece = this.pieces[ item ];
			if ( piece.c == c || piece.r == r ) {
				return false;
			}
			let dx = Math.abs(piece.c - c);
			let dy = Math.abs(piece.r - r);
			if( dx <= 1 && dy <= 1 ) {
				return false;
			}
			if ( dy / dx == 1 ) {
				return false;
			}
		}
		this.putValue(c, r, 1);
		return true;
	}
	
	this.print = function () {
		let str = '';
		for(let i = 0; i < this.dim; i++) {
			for(let j = 0; j < this.dim; j++) {
				str += this.board[i][j] + ' '
			}
			str += '\n';
		}
		console.log( str );
	}
}

/**
dim 4*4

0 1 2 3
4 5 6 7
8 9 10 11
12 13 14 14

case 9 = (y = 2, x = 1)
y = E(9 / 4) = 2
x = 9 % 4

*/

function solve (game, index, n ) {
	let r = Math.floor( index / game.dim ),
		c = index % game.dim;
	let done = false;
	if ( game.putQueen(r, c) ) {
		if ( solve(game, index, n - 1) ) {
			done = true;
		}
	} else {
		return solve(game, index + 1, n - 1);
	}
	if ( done && n > 0 ) {
		console.log( 'dsad' );
		return solve(game, 0, n - 1);
	}
	return false;
} 

let n = 5;
let game = new Game(n);
game.print();
solve (game, 0, n);
// console.log( putQueensOnBoard(game, 0, 0, 4) );
game.print();
