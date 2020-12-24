/**
 * @author afmika
 */
const operators = "+-*/";

function compute(a, b, op) {
    switch (op) {
        case "+" : return a + b;
        case "-" : return a - b;
        case "/" : return a / b;
        case "*" : return a * b;
    }
    return 0;
}

function fromTo(input, put_first) {
    let res = [put_first];
    for (let i = 2; i < input.length; i++) {
        res.push(input[i]);
    }
    return res;
}

function display(arr) {
	arr.forEach(it => console.log(it));
}

let found = false;
let cur_delta = Infinity;
function find(input, current_sum) {
    if (found) return;
    if (current_sum >= input.target) {
		let delta = Math.abs(current_sum - input.target);
		found = delta <= 10e-6;
		if ( cur_delta > delta ) {
			input.best_so_far = input.solution;
			cur_delta = delta;
		}
		if (!found)
			input.solution = [];
        return;
    }

    for (let i = 1; i < input.numbers.length; i++) {
        let a = input.numbers[i - 1], b = input.numbers[i];
		
        for (let k = 0; k < operators.length; k++) {
            let cur = compute(a, b, operators[k]);

			if (!input.enable_float_division) {
				cur = Math.floor(cur)
			}

            let sol_before = input.solution.map(x => x);
            let num_before = input.numbers;
            let n_input = fromTo(input.numbers, cur);
            
			input.numbers = n_input;
            input.solution.push(`${a} ${operators[k]} ${b} -> ${cur}`);
            
			find(input, cur);
			
            input.numbers  = num_before; // CTRL-Z
            input.solution = sol_before;
        }
		
    }
} 

let input = {
    numbers : [15, 8, 9, 2, 1, 10, 20],
    target : 735,
	enable_float_division : false,
	best_so_far : [],
    solution : []
};

find(input, null);
console.log('Target ', input.target, ' numbers = ', input.numbers);
console.log('=>', !found ? 'Not found :(' : 'Found it!');
display(input.best_so_far);