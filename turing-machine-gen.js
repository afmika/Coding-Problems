class Machine {
	constructor (name, init, accept) {
		this.name = name;
		this.initialState = init;
		this.acceptedState = accept;
		
		this.transitions = [];
	}
	
	asCode () {
		let code = [];
		code.push('name: ' + this.name);
		code.push('init: ' + this.initialState);
		code.push('accept: ' + this.acceptedState);
		code.push('');
		
		for (let tran of this.transitions) {
			const {current, transitTo} = tran;
			code.push(current.state + ', ' + current.reads);
			code.push(transitTo.state + ', ' + transitTo.writes + ', ' + transitTo.go);
			code.push('');
		}
		
		return code.join('\n');
	}
	
	static BLANK () {
		return '_';
	}
	
	static RIGHT () {
		return '>';
	}
	
	static LEFT () {
		return '<';
	}
	
	static HALT () {
		return '-';
	}
}


function generateMachineFrom (str) {
	const transitions = [];
	
	str = str.replace(' ', '_');
	
	for (let i = 0; i < str.length; i++) {
		const ch = str[i];
		transitions.push({
			current : {state : 'q' + i, reads : Machine.BLANK ()},
			transitTo : {state : 'q' + (i + 1), writes : ch, go : Machine.RIGHT () }
		});
	}
	
	let L = str.length - 1;
	transitions.push({
		current : {state : 'q' + (L + 1), reads : Machine.BLANK ()},
		transitTo : {state : 'q' + (L + 2), writes : Machine.BLANK (), go : Machine.HALT () }
	});
	
	const machine = new Machine ('Test');
	machine.transitions = transitions;
	machine.initialState = 'q0';
	machine.acceptedState = 'q' + (L + 2);
	
	return machine;
}

// plz use std-out
const code = generateMachineFrom ('Hello World').asCode();
console.log(code);