'''
Yet another sorting algorithm (YAS algorithm ;))

- if L and S are lists, it takes O(n^2)
- if you replace L and S with a min-heaps, you get O(n log n)

The data structure plays an important role in this algorithm
'''
def yasSort (L, S = []):
    if len(L) == 0:
        return S
    a = min(L)
    del L[L.index(a)]
    S.append(a)
    return yasSort (L, S)

print (yasSort([2, 7, 3, 2]))
