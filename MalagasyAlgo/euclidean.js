function r (x) {
    return Math.round(x * (10**5)) / (10**5);
}
function processData(input) {
    //Enter your code here
    let lines = input.split("\n");
    let n = parseFloat(lines[0]);
    let points = [];
    for (let i = 1; i <= 2; i++) {
        points.push(lines[i].split(" ").map(x => parseFloat(x)));
    }
    let s = 0;
    for (let i = 0; i < points[0].length; i++) {
        s += Math.pow(points[0][i] - points[1][i], 2);
    }
    console.log(r(Math.sqrt(s)));
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
    
    
});

process.stdin.on("end", function () {
   processData(_input);
});
