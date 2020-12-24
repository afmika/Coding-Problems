#include <bits/stdc++.h>

using namespace std;

vector<char> out_op;
string ops = "+-/*";


unordered_map<char, bool> pass;
unordered_map<char, int> op_force {
	{'*', 2},
	{'/', 2},
	{'-', 1},
	{'+', 1}
};

vector<pair<char, int>> cloneSet(vector<pair<char, int>> v) {
    vector<pair<char, int>> res;
    for (auto i : v ) {
        res.push_back(i);
    }
    return res;
}

void dfs(
        vector<vector<pair<char, int>>>& solutions, 
        string& candidates, 
        vector<pair<char, int>> current, 
        int current_sum, 
        int target
    ) {

    if ( current_sum >= target ) {
        if ( current_sum == target ) {
            solutions.push_back(current);
        }
        return;
    }

    for (char n : candidates) {
        if ( !pass[n] ) { 
            pass[n] = true;
            int div = target;
            for (int k = div; k >= 1; --k) { 
                vector<pair<char, int>> clone = cloneSet(current);
                clone.push_back({k, n});
                dfs(solutions, candidates, clone, current_sum + k, target);
            }
            pass[n] = false;
        }
    }
}


vector<string> constructSolution(vector<vector<pair<char, int>>> solutions){
    vector<string> final_sol;
    for (auto s : solutions) {
        string temp = "";
        for (auto n : s) {
            int times = n.first;
            int value = n.second;
            for (int t = 0; t < times; t++) {
                temp.push_back(value);
            }
        }
        final_sol.push_back(temp);
    } 
    return final_sol;
}

vector<string> composeAllOperators(string& candidates, int target) {
    for (char n : candidates ) {
        pass[n] = false;
    }    
    vector<vector<pair<char, int>>> solutions;
    vector<pair<char, int>> temp;
    dfs(solutions, candidates, temp, 0, target);
    return constructSolution(solutions);
}

double operate(double a, double b, char op) {
	switch( op ) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
	return 0.;
}

bool isOperator(char val) {
	return op_force.find(val) != op_force.end();
}

bool comparePrec(string a, string b) {
	return op_force[a[0]] >= op_force[b[0]];
}

vector<string> convertInfix(vector<string> expr) {
	stack<string> symbols;
	vector<string> output;
	for (string part : expr) {
		if ( isOperator(part[0]) ) {
			while (!symbols.empty() && comparePrec(symbols.top(), part)) {
				output.push_back(symbols.top());
				symbols.pop();
			}
			symbols.push(part);
		} else {
			output.push_back(part);
		}
	}
	while (!symbols.empty()) {
		output.push_back(symbols.top());
		symbols.pop();
	}
	return output;
}

double convertDouble(string a) {
	stringstream t(a);
	double x;
	t >> x;
	return x;
}

void populatePermut(vector<string> &solution, string cur) {
	sort(cur.begin(), cur.end());
	do {
		solution.push_back(cur);
	} while (next_permutation(cur.begin(), cur.end()));
}

double evaluate(vector<string> to_eval) {
	vector<string> expr = convertInfix(to_eval);
	stack<string> exec;
	for (string token : expr) {
		if ( isOperator(token[0]) ) {
			string b = exec.top(); exec.pop();
			string a = exec.top(); exec.pop();
			double res = operate(convertDouble(a), convertDouble(b), token[0]);
			exec.push(to_string(res));
		} else {
			exec.push(token);
		}
	}
	return convertDouble(exec.top());
}

void displayExpr(vector<string> expr, double res) {
	for (string it : expr)
		cout << it << " ";
	cout << "= " << res << "\n";
}
void runAndFilter(vector<double> input, double target) {
	pair<vector<string>, double> best_so_far;
	unordered_map<string, bool> done;
	double cur_diff = INT_MAX;
	int op_count = input.size() - 1;
	vector<string> op_combi = composeAllOperators(ops, op_count);
	for (string cur_combi : op_combi) {
		vector<string> all_combi; // ++-
		populatePermut(all_combi, cur_combi); //+-+, -++ 
		
		// fuse
		for (string combi : all_combi) {
			vector<string> expr;
			for (int i = 1; i < (int) input.size(); i++) {
				int a = input[i-1];
				expr.push_back(to_string(a));
				char cur_op = combi[i - 1];
				string b = "";
				string op(b + cur_op);
				expr.push_back(op);
			}
			int last = input[input.size() - 1];
			expr.push_back(to_string(last));

			double res = evaluate(expr);
			double delta = fabs(res - target);
			
			if (delta < cur_diff) {
				best_so_far.first = expr;
				best_so_far.second = res;
				cur_diff = delta;
			}
			
			if (delta > 10e-6)
				continue;
			if (done.find(combi) != done.end()) {
				done[combi] = true;
				displayExpr(expr, res);
			}
		}
		// end fuse
	}
	cout << "\nBest so far : \n"; 
	displayExpr(best_so_far.first, best_so_far.second);
}

int main() {
	// 88 * 3 + 1 - 1 * 6
	
	vector<pair<vector<double>, double>> tests {
		{{5, 8, 6}, 18},
		{{1, 2, 1}, 0},
		{{65, 6, 8, 78}, 1014},
		{{2, 4, 8, 9}, 10},
		{{2, 4, 7, 9, 15}, 30},
		{{10, 20, 1, 8, 3, 15}, 50},
		{{23, 6, 21, 23, 34, 1}, 3761},
	
		{{88, 3, 1, 1, 6}, 259},
		{{1, 1, 1, 1, 1}, 0}
	};
	int i = 0;
	for (auto test : tests) {
		cout << "\nTest #" << (i++);
		auto input = test.first;
		double target = test.second;
		cout << " : target " << target;
		runAndFilter(input, target);
	}
	return 0;
}
