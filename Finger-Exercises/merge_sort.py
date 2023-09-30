def merge(left, right, compare):
    result = []
    i,j =0,0
    while i < len(left) and j < len(right):
        if compare(sum(left[i]),sum(right[j])):
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    while (i < len(left)):
        result.append(left[i])
        i += 1
    while (j < len(right)):
        result.append(right[j])
        j += 1
    return result

def merge_sort(L, compare = lambda x, y:x<y):
    if len(L) < 2:
        return L[:]
    else:
        middle = len(L)//2
        left = merge_sort(L[:middle], compare)
        right = merge_sort(L[middle:], compare)
        return merge(left, right, compare)
    
tuple_list = [(2,5),(6,1),(54,3),(94,2),(2,9)]

print(merge_sort(tuple_list))