def fib_gen(num):
    a = 1
    b = 1
    fib_num = [a]
    for i in range(1,num):
        c = b
        b = a+b
        a = c
        fib_num.append(a)
    return fib_num



with open('fib_numbers.txt', 'w') as fib_file:
    for num in fib_gen(10):
        fib_file.write(str(num)+'\n')


with open('fib_numbers.txt', 'r') as fib_file:
    for line in fib_file:
        print(line[:-1])

