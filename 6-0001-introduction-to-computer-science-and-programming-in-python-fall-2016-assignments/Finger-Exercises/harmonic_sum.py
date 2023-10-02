def h_sum(n):
    if n == 1:
        return n
    else:
        return (1/n)+h_sum(n-1)
    

for x in range(1, 100):
    print(h_sum(x))