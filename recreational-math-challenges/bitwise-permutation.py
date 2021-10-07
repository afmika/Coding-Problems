"""
@author afmika
Permutation using bitwise operations
"**/

def permutHelper (word, curr, m, solutions):
    if len(curr) is len(word):
        solutions.append(curr)
        return
    
    for i in range(0, len(word)):
        mask = 1 << i
        if not (m & mask):
            m ^= mask # set it
            permutHelper(word, curr + word[i], m, solutions)
            m ^= mask # go back

def permut (word) :
    m = 0x00000000
    solutions = []
    permutHelper(word, "", m, solutions)
    for n in range(0, len(solutions)):
        print ( str(n + 1) + " : " + solutions[n])

permut("123")
