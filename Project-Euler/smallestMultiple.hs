-- gcd can be used
-- lcm a b * gcd a b = ab

-- damn... this is so elegant
solve = foldl lcm 1
main = print (solve [1 .. 20])