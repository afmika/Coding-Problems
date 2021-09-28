-- Note : Any integer greater than 1 is either a prime number, or can be written as a unique product of prime numbers

largestPrimeH :: Int -> Int -> Int -> Int
largestPrimeH n curr largest
    | curr*curr > n        = max n largest
    | n `mod` curr == 0    = largestPrimeH (n `div` curr) curr curr 
    | otherwise            = largestPrimeH n (curr + 1) largest

largestPrime n = largestPrimeH n 2 0

main = 
    print (largestPrime 600851475143)