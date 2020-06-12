/**
 * @author afmika
 * https://gist.github.com/afmika/be9c96d1664389ce6e796e0a420ed12a
 **/
 
#include <bits/stdc++.h>

using namespace std;

// 
//-2 -1  0  1  2  
// --------------+
// .  X  .  X  . | -2 
// X  .  .  .  X | -1
// .  .  K  .  . |  0
// X  .  .  .  X |  1
// .  X  .  X  . |  2
//

const vector<vector<int>> directions {
	// y, x
	{-2, -1},
	{-2, 1},
	{-1, -2},
	{-1, 2},
	{1, -2},
	{1, 2},
	{2, -1},
	{2, 1}
};

bool isOut(pair<int, int> knight) {
	int y = knight.first,
		x = knight.second;
	return y < 0 || x < 0 || y >= 8 || x >= 8;
}

void DFS (double& is_out_count, double& total_count, int k_moves, pair<int, int> knight) {
	if ( k_moves == 0 ) {
		return;
	}
	
	for (auto dir : directions ) {
		pair<int, int> new_knight_pos = {
			dir[0] + knight.first, 
			dir[1] + knight.second
		};
		
		total_count++;
		
		if ( isOut(new_knight_pos) ) {
			// isLeaf
			is_out_count++;
		} else {
			DFS(is_out_count, total_count, k_moves - 1, new_knight_pos);
		}
	}
}

double getProba(pair<int, int> knight, int k_moves) {
	
	if ( k_moves <= 0 ) return 0;
	
	double is_out_count = 0;
	double total_count = 0; 
	
	DFS(is_out_count, total_count, k_moves, knight);
	
	double proba = is_out_count / total_count;
	
	return proba;
}

int main() {
	
	vector<pair<int, int>> test_init_pos {
		{0, 0},
		{3, 3},
		{7, 6},
		{2, 2}
	};
	int num_exp = 1;
	int n_proba = 0;
	double total_proba = 0;
	for (auto knight_pos : test_init_pos ) {
		cout << "* Experiment :: " << num_exp << "\n";
		cout << "Initial pos [0-indexed] : y=" << knight_pos.first << ", x=" << knight_pos.second << "\n"; 
		// display
		for (int moves = 1; moves <= 7; ++moves ) {
			double current_proba = getProba(knight_pos, moves);
			total_proba += current_proba;
			n_proba++;
			
			cout << "Moves k = " << moves;
			cout << ": P = "<< current_proba;
			cout << "\n";
		}
		
		cout << "\n";
		num_exp++;
	}
	cout << "* AVG[ P ] = " <<  (total_proba / n_proba ) << "\n";
	
	
	return 0;
}
