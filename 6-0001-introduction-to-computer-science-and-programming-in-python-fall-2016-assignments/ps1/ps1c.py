total_cost = 300000
months_to_save = 36
portion_down_payment = total_cost*.66
annual_return = .04
monthly_return = annual_return/12
annual_raise = .03


def compare_within_100(a,b):
    if abs(a-b) < 100:
        return True
    else:
        return False

def three_year_total(portion_saved):
    current_savings = 0
    for i in range(1,(months_to_save+1)):
        current_savings=((portion_saved)*(1+monthly_return))+current_savings
        if (i % 12) == 0:
            portion_saved=(1*annual_raise)+portion_saved
    return current_savings


guess = portion_down_payment/months_to_save

while compare_within_100(three_year_total(guess), portion_down_payment) == False: 
    guess=guess-1

print("optimal monthly savings rate is $"+str(round(guess))+" to save $"+str(round(portion_down_payment))+" in "+str(months_to_save)+" months")
