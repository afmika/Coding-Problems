function Game(dim) {
	this.dim = dim || 4;
	this.board = null;
	this.reset = function ( dont_touch ) {
		this.board = new Array( dim )
				.fill(0)
				.map(
					k => new Array(dim).fill('.')
				);
		this.pieces = {};
		
		if(this.protected_case != null) {
			this.putValue(this.protected_case.c, this.protected_case.r, 1);
		}
	}
	
	this.pieces = {};
	this.latest = null;
	
	this.makeKey = function (c, r) {
		return r + ',' + c;
	}
	
	this.putValue = function(c, r, value) {
		this.latest = { c : c, r : r};
		this.board[r][c] = value;
		this.pieces[ this.makeKey(c, r) ] = this.latest;
		this.reasons = null;
	}
	
	this.removeLatest = function() {
		let lat = this.latest;
		this.pieces[ this.makeKey(lat.c, lat.r) ] = false;
		this.board[lat.r][lat.c] = 0;
	}
	
	this.reasons = null;
	this.protected_case = null;
	
	this.setProtectedCase = function(c, r) {
		this.putValue(c, r, 1);
		this.protected_case = {c : c, r : r};
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
				this.reasons = piece.c == c ? 'COL' : 'ROW';
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
	
	this.print = function ( onScreen ) {
		let str = '';
		for(let i = 0; i < this.dim; i++) {
			for(let j = 0; j < this.dim; j++) {
				str += (this.board[i][j] == 1 ? 'Q' : this.board[i][j]);
			}
			str += '\n';
		}
		if (onScreen == undefined || onScreen == true)
			console.log( str );
		return str;
	}
	
	this.reset();
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

function solve (game, index, n_left, init_case, init_n ) {
	let r = Math.floor( index / game.dim ),
		c = index % game.dim;
	
	// all cases checked 
	if (r == game.dim || init_case + 1 == Math.pow(game.dim, 2)) {
		if ( n_left > 0 ) {
			game.reset();
			return solve (game, init_case + 1, init_n, init_case + 1, init_n);
		}
		return false;
	}
	
	// success
	if ( n_left == 0 ) {
		return true;
	}
	
	if ( game.putQueen(c, r) ) {
		return solve(game, 0, n_left - 1, init_case, init_n);
	} else {
		if (game.reasons == 'ROW') {
			index = ( r + 1 ) * game.dim - 1;
		}
		return solve(game, index + 1, n_left, init_case, init_n);
	}
	
	return false;
} 

function getAllPossibilities( n_qeens ) {
	let game = new Game(n_qeens);
	let clean = {};
	let res = [];
	for(let i = 0; i < Math.pow(n_qeens, 2); i++) {
		let r = Math.floor( i / game.dim ),
			c = i % game.dim;
		game.putQueen(c, r);
		game.setProtectedCase( c, r );
		try {			
			let start = i == 0 ? 1 : 0;
			if (  solve (game, start, n_qeens - 1, start, n_qeens - 1) ) {
				clean[  game.print( false ) ] = true;
				game.reset();
			}
		} catch(e) {
			console.log(`Error at c = ${c}, r = ${r}`)
			continue;
		}
	}
	for(let sol in clean) {
		res.push(sol);
	}
	return res;
}
let p = getAllPossibilities(5);

p.forEach(state => {
	console.log(state);
});
console.log(p.length, "Possibilities found");
/*
let n = 6;
let game = new Game(n);
game.print();
console.log( solve (game, 0, n, 0, n) );
game.print();
*/