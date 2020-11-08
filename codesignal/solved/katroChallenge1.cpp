int katroChallenge1(vector<vector<int>> board, int row, int col) {
	bool inner = row == 1 || row == 2;
    int d  = row < 2 ? 1 : -1;
    int ar = row + d;
	if ( !inner )
        return 0;
    if ( board[ar][col] > 0 )
        return board[ar][col];
	
	int can = true;
	for (int i = 0; i < 4; i++) {
		if ( board[ar][i] > 0 ) {
			can = false;
			break;
		}
	}
	if ( can )
        return board[ar + d][col];
    return 0;
}