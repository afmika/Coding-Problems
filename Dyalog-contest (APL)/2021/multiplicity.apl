⍝ Example : 2 3 l_multiple_r 1 2 3 4 5 6 → [2 4 6] [3]
⍝ The outer product construct a boolean mass then we simply multiply it with the inital array 
⍝ then filters the zeroes
l_multiple_r ← {0~⍨¨((⊂⍵)×⍺∘.|⊂(1+⍵))}