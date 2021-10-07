const assert = require ('assert');

function makeBoard () {
	return [
		[2, 2, 2, 2],
		[2, 2, 2, 2]
	];
}

function show (board, position) {
	let str = '';
	for (let i = 0; i < board.length; i++) {
		for (let j = 0; j < board[i].length; j++) {
			if (position && position[0] == i && position[1] == j)
				str += '*' + board[i][j] + ' ';
			else
				str += board[i][j] + ' ';
		}
		str += '\n';
	}
	console.log(str);
}

function play (position, board, direction) {
	let [y, x] = position;
	
	let dx = direction == 'RIGHT' ? 1 : -1;
	let dy = y == 0 ? 1 : -1;
	
	let count = board[y][x];
	console.log(count)
	board[y][x] = 0;
	
	while (count--) {
		assert (y >= 0 && y < 2, 'Invalid position y : ' + y);
		x += dx;
		if (x < 0 || x > board[y].length - 1) {
			y += dy;
			
			// undefined index auto offset
			x = Math.min(Math.max(0, x), board[y].length - 1);
			
			dx *= -1;
			dy *= -1;
			direction = dx > 0 ? 'RIGHT' : 'LEFT';
		}
		
		assert (x >= 0 && x < board[y].length, 'Invalid position x : ' + x);
		
		board[y][x]++;
	}
	
	return {board : board, position : [y, x], direction : direction};
}

function runPlay (position, board, direction) {
	let [curr_board, curr_pos, curr_dir] = [board, position, direction];
	console.log('START ' + direction);
	show (curr_board, curr_pos);
	
	// let other = makeBoard ();

	let interval = setInterval (() => {
		// stop
		let [cy, cx] = curr_pos;
		// if (other[1][cx] > 0 && (cy == 0)) { curr_board[cy][cx] += other[1][cx]; other[1][cx] = 0; console.log('GOT'); };
		
		if (curr_board[cy][cx] == 1) {
			clearInterval (interval);
			return;
		}
		
		// continue
		let res = play (curr_pos, curr_board, curr_dir);
		show (res.board, res.position);
		[curr_board, curr_pos, curr_dir] = [res.board, res.position, res.direction];		
	}, 2000);
}

// note : does not consider the opponent
runPlay ([0, 1], makeBoard(), 'RIGHT');
