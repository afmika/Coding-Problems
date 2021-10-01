iSqrt     = floor . sqrt . fromIntegral

-- slow
-- isPrime 1 = False
-- isPrime n = length [x | x <- [2 .. iSqrt n], n `mod` x == 0] == 0

-- faster
isPrimeH n c
    | c > iSqrt n    = True
    | n `mod` c == 0 = False
    | otherwise      = isPrimeH n (c + 1)
isPrime 1 = False
isPrime n = isPrimeH n 2

sumInterval a b = (sum . filter isPrime) [a..b]
solution = (sumInterval 1 1000000) + (sumInterval 1000001 2000000)
main = print (solution)