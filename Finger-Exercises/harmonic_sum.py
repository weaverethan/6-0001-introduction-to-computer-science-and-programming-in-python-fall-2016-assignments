def H_sum(n):
    if n == 1:
        return n
    else:
        return (1/n)+H_sum(n-1)
    

print(H_sum(33))