import Data.Char(digitToInt)

pDigits p n = sum $ map ((^p) . digitToInt) $ show n

isOk p n = (pDigits p n) == n

 -- any reasonable bound is fine (this is basically brute force)
 -- this will do for now
solve p curr total
    | curr > 10^(p + 1) = total
    | otherwise =
        solve p (curr + 1) ntotal
        where
            ntotal = if (isOk p curr) then (total + curr) else total

-- exclude 1 (trivial ans)
solution n = -1 + solve n 0 0

main = print (solution 5)