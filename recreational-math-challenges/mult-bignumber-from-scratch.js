// ex: '124705484102105442084411002445' + '1405474512005454545100254411'
function add (a, b) {
	let up   = a.length > b.length ? a : b;
	let down = a.length > b.length ? b : a;
	let r = '';
	let carry = 0, i = 0, ans = '';
	
	while (i < down.length) {
        const l = parseInt (up[up.length - i - 1]),
              r = parseInt (down[down.length - i - 1]);
		
        let dsum = l + r;
        if (carry > 0)
			dsum += carry;
		
        carry = dsum >= 10 ? 1 : 0;
        ans = (dsum % 10) + ans; // concat
		
		i++;
	}
	
	while (i < up.length) {
		let temp = parseInt(up[up.length - i - 1]);
		
		if (carry > 0) 
			temp += carry;
		carry = temp >= 10 ? 1 : 0;
		
		ans = (temp % 10) + ans; // concat
		i++;
	}
	
	return (carry == 0 ? '' : carry) + ans;
}

// ex '485784005' * '5'
function multSingleNumber (bignum, single_num) {
	let ans = '', carry = 0, i = 0;
	while (i < bignum.length) {
		let dmult = parseInt(bignum[bignum.length - i - 1]) * parseInt(single_num);
		
		if (carry > 0) 
			dmult += carry;
		carry = Math.floor(dmult / 10);
		
		ans = (dmult % 10) + ans;
			
		i++;
	}

	return (carry == 0 ? '' : carry) + ans;
}

// ex : '1485405' * '10^2' = '148540500'
let done = {};
function multBy10 (bignum, power) {
	let pow = power;
	if (done[power] == undefined) {		
		let zeros = '';
		while (power--)
			zeros += '0';
		done[pow] = zeros;
	}
	return bignum + done[pow];
}

// ex : '45461102648941001057919' * '90191578410054547100'
function mult (a, b) {
	let res = '';
	let up   = a.length > b.length ? a : b;
	let down = a.length > b.length ? b : a;
	let dsum = '0';
	for (let i = 0; i < down.length; i++) {
		let curr = multBy10 (
			multSingleNumber (up, down[down.length - i - 1]),
			i
		);
		dsum = add (dsum, curr);
	}
	return dsum;
}

function powBig (a, power) {
	let p = '1';
	while (power--) p = mult (p, a);
	return p;
} 

// Test 1
console.log('-------------- TEST MULT OPTIMIZED --------------');
let a = '454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919454611026489410100579115402781057919', 
	b = '90191411187548408481057844546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579194546110264894101005791154027810579191005454710017';
console.log('Our ans', mult(a, b));
console.log('JS ans', BigInt (a) * BigInt (b));

console.log('-------------- TEST POW UNOPTIMIZED --------------');
// Test 2
let q = '45461102648941010057914101005791161102540278105010001007919', 
	N = 35;
console.log('Our ans', powBig(q, N));
console.log('\nJS ans', BigInt (q) ** BigInt (N));