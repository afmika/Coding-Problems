{-


A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.



-}
main =
	let
		ida = [1 .. 300]
		idb = [1 .. 300]
		idc = [1 .. 400]
	in 
		do
			print $ [(a, b, c, a + b + c) | a <- ida, b <- idb, c <- idc, a^2 + b^2 == c^2 && a + b + c == 1000]