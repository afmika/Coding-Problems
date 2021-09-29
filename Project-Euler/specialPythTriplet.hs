{-- 
a + b + c = 1000
a < b < c < 1000

a2 + b2 = c2
a2 < b2 < c2 < 1000000
=> c2 should be a perfect square less than 100000
--}

-- helpers
lessThan limit v     = v <= limit
listGreaterThan n xs = filter (lessThan n)
iSqrt                = floor . sqrt . fromIntegral
isPerfectSquare      = \n -> (iSqrt n)^2 == n
sqRoot (a2, b2, c2)  = (iSqrt a2, iSqrt b2, iSqrt c2)
doProduct (a, b, c)  = a * b * c


prefectSquare limit = 
    [ n^2 | n <- series ]
        where
            series = [1 .. limit]

generateTriplets limit = 
    let 
        squares      = prefectSquare limit
        listLessThan = \b -> filter (lessThan b) squares
        validTriplet = \(a2, b2, c2) -> (iSqrt c2) <= limit && (isPerfectSquare c2)
        joinAll      = foldl (++) []
    in
        map sqRoot $
        filter validTriplet 
        (joinAll [ [(a2, b2, b2 + a2) | a2 <- listLessThan b2] | b2 <- squares ])

findTriplet limit =
    filter solution (generateTriplets limit)
        where
            solution = \(a, b, c) -> a + b + c == limit
        
solve xs = doProduct (xs !! 0)

main = print $ (solve . findTriplet) 1000