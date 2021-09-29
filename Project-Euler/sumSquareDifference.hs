-- X = sum Squares := n*(n + 1)*(2*n + 1) / 6
-- Y = sum Squared := (n*(n + 1)/2)^2 = (n*(n + 1))^2 / 4
-- Y - X = (1/12) * n *(3*n^3 + 2*n^2 - 3*n - 2)

solve n = div (n*(3*n^3 + 2*n^2 - 3*n - 2)) 12
-- 25164150
main = print (solve 100)