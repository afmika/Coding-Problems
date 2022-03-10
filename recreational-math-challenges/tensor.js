function Vec(x, y) {
	this.x = x;
	this.y = y;
	this.dot = v => v.x * this.x + v.y * this.y;
}

let axis = [
	new Vec (1/2, 0),
	new Vec (0, 1/2)
];

// if the axis increases, it decreases (contrary to the axis)
// v^1
// usual way of defining a vector
// ie. the coordinates highly depends on the axis
function contra_var (v) {
	return new Vec(
		v.x / axis[0].x, // how many x do we use for v.x ie. v^1.x * e1 => v.x
		v.y / axis[1].y  // how many y do we use for v.y
	);
}

// covariant => def v_1
// (which is in fact the dual of v ie. v* just like the <bra| in quantum mec)
// dual maybe because they scale the same amount in both coordinates
// ie. E* is isomorphic to E (note E* = L(E, R) := all linear map from E to R, x in E -> x.v in R)
function co_var (v) {
	return new Vec(
		axis[0].dot(v), // we 'project' on x
		axis[1].dot(v), // we 'project' on y
	);
}

function tensorContra (u, v) {
	let a = contra_var(u);	
	let b = contra_var(v);	
	return [
		[a.x * b.x, a.x * b.y],
		[a.y * b.x, a.y * b.y]
	];
}

function tensorMixed (u, v) {
	let a = contra_var(u);	
	let b = co_var(v);	
	return [
		[a.x * b.x, a.x * b.y],
		[a.y * b.x, a.y * b.y]
	];
}

function prodVec (T, v) {
	return new Vec (
		T[0][0] * v.x + T[0][1] * v.y,
		T[1][0] * v.x + T[1][1] * v.y
	);
}

let u = new Vec (1, 1);
let v = new Vec (2, 2);

console.log(prodVec(tensorMixed(u, v), u));
console.log(prodVec(tensorContra(u, v), u));
