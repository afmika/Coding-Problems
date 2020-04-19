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

function putQueensOnBoard(game, col, row, n ) {
	if ( col * row == game.dim * game.dim ) {
		return n - 1;
	}
	// success
	if ( game.putQueen(col, row ) ) {
		return putQueensOnBoard(game, 0, 0, n - 1 );
	}
	
	// fail
	if( col == game.dim ) {
		return putQueensOnBoard(game, 0, row + 1, n );
	} else {
		return putQueensOnBoard(game, col + 1, row, n );
	}
}

function solve (game, n ) {
	if ( n == 1 ) {
		game.putQueen(0,0);
		return true;
	}
	for(let r = 0; r < game.dim; r++) {
		for(let c = 0; c < game.dim; c++) {
			let left = putQueensOnBoard(game, r, c, n);
			// console.log(c, r, left);
			if(left <= 0) {
				return true;
			} else if ( c + 1 < game.dim && r + 1 < game.dim ) {
				game.reset();
			}
		}
	}
	return false;
} 

let game = new Game(4);
game.print();

solve (game, 5 );
// console.log( putQueensOnBoard(game, 0, 0, 4) );
game.print();
