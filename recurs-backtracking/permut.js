function permut(res, current, str_left ) {
	if ( str_left.length == 0 ) {
		res.push( current );
	} else {
		for(let i = 0; i < str_left.length; i++) {
			// the (i+1)-th character should be excluded
			let cur_left = str_left.substring(0, i) + str_left.substring(i + 1, str_left.length);
			permut(res, current + str_left[i], cur_left);
		}
	}
}

let res = [];
permut( res, '', '12345');
console.log(res, res.length);