function _char(x) {
	// curryfication goes brrr...
    const _for = i => (_, s) => [
        [3, -947, 4463, -19729, 2827, -58418, 22822],
        [7,    6,    5,      4,    3,      2,     1],
        [80, 720,  240,    144,    5,     45,    15]
    ][s][i];
	
    let v = 0;
    for (let i = 0; i < 7; i++) {
        const [a, pw, dv] = new Array(3)
			.fill(0)
			.map(_for(i));
        v += a * Math.pow(x, pw) / dv;
    }
    return Math.round(v) - 592;
}

// will output 'Michael'
for (let x = 1; x <= 7; x++)
    console.log(String.fromCharCode (_char(x)))