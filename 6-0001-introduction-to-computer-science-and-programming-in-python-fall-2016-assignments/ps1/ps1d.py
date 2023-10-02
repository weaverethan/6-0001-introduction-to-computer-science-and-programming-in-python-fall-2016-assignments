salary=int(input("enter your yearly salary:"))
TOTAL_PAYMENT = 1000000
down_payment = TOTAL_PAYMENT*.25

Min=0
Max=salary/12
guess = (Max+Min)/2

def compare_within_100(a,b):
    if abs(a-b) < 100:
        return True
    else:
        return False

def three_year_total(monthly_savings):
    current_savings = 0
    for i in range(1,37):
        current_savings=(current_savings+monthly_savings)*(1+(.04/12))
        if (i % 12) == 0:
            monthly_savings=(1.07)*monthly_savings
    return current_savings

if three_year_total(Max) < down_payment:
    print("salary not large enough")
else:
    while compare_within_100(three_year_total(guess), down_payment) == False: 
        if three_year_total(guess) < down_payment:
            Min = guess
        else:
            Max = guess
        guess = (Max+Min)/2
    
    ans = round(guess/(salary/12),2)
    print(ans)
