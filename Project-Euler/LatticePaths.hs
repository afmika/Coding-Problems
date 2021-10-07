-- basic yet tricky combinatory problem
-- alphabet {R, L, U, D}
-- pairs (R,D) and (D,R) only works
-- arrangement(2*n sets with n elements)

solve n = foldl (*) 1 (map (\i -> (n + i) / i) [1 .. n])

main = print (round $ solve 20)