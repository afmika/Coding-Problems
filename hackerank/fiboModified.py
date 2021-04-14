def fibonacciModified(t1, t2, n):
    tN_2 = t1
    tN_1 = t2
    if n == 1 :
        return tN_2
    if n == 2 :
        return tN_1
    for i in range(3, n + 1):
        prev = tN_1
        tN_1 = tN_1**2 + tN_2
        tN_2 = prev
    return tN_1