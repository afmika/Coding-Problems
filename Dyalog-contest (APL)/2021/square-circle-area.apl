⍝ inscribed square = 4* ((d/2)^2 / 2) = 2*(d^2/4)
⍝ cirlce = (d^2/4) × pi
⍝ → diff =  |2-pi|*(d^2 / 4)


sq_circ_area ← {Y←⍵ ⋄ {|(2-○1)×(⍵*2)÷4} ¨ Y}