// Complete the fibonacciModified function below.
function fibonacciModified(t1, t2, n) {
    let tN_2 = BigInt(t1);
    let tN_1 = BigInt(t2);
    if (n == 1) return tN_2;
    if (n == 2) return tN_1;
    for (let i = 3; i <= n; i++) {
        const prev = tN_1;
        tN_1 = tN_1*tN_1 + tN_2;
        tN_2 = prev;
    }
    return tN_1;
}