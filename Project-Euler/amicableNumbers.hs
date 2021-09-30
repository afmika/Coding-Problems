import Data.List
import qualified Data.Set as S


divide n d = n `mod` d == 0

divisors n = filter (divide n) (take (n - 1) [1 .. ])
sDivisors  = sum . divisors

{-- 
    isAmicable if d(a) = b and d(b) = a
    <=> d(d(a)) = a
--}

-- sum d(a) != a
amicable n = n == (sDivisors . sDivisors) n && (sDivisors n /= n)

amicablePair n = sort [sDivisors n, n]

-- Set with no duplicate
amicableSet limit = S.fromList $ map amicablePair basicAmicable
    where
        basicAmicable = filter amicable (take  (limit - 1) [1..])

solution n = (sum . (S.map sum)) (amicableSet n)

-- 31626
main = print (solution 10000)