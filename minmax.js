const player = -1;
const comp = 1;
const game = [
	[1, 0, 0],
	[0, 1, 0],
	[-1, 0, 0]
];

function game_over( game ) {
	let hor = 0, 
		diag_left = 0, 
		diag_right = 0, 
		vert = 0;
	for(let y = 0; y < 3; y++) {
		diag_left += game[y][y];
		diag_right += game[2 - y][y];
		for(let x = 0; x < 3; x++) {
			hor += game[y][x];
			vert += game[x][y];
		}
		if(vert == 3 * player || hor == 3 * player) {
			return player;
		} else if(hor == 3 * comp || hor == 3 * comp) {
			return comp;
		} else {
			hor = 0;
			vert = 0;
		}
	}
	let diag = [diag_left, diag_right];
	for (let i in diag) {
		let d = diag[i];
		if(d == 3 * player) {
			return player;
		} else if(d == 3 * comp) {
			return comp;
		}	
	}
	return 0;
}

function evaluate( game ) {
	let winner = game_over( game );
	if( winner != 0 ) {
		return winner == player ? -Infinity : Infinity;
	}
	
	return 0;
}

console.log("val", evaluate( game ) );