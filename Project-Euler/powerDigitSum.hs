import Data.Char(digitToInt)

-- one can simply reproduce the multiplication algorithm while allocating
-- an array of a length = E(log10(2^1000)) + 1 but the simplicity does not really make it challenging
-- so I will stick with this elegant function composition form

solve a b = (quick_sum . map digitToInt . show) result
    where
        result = a^b
        quick_sum = foldl (+) 0

main = print (solve 2 1000)