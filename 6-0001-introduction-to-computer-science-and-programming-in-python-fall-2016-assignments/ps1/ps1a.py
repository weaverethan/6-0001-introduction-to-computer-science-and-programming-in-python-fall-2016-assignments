total_cost = 300000
portion_down_payment = total_cost*.66
current_savings = 0
annual_salary = 62400
monthly_salary = annual_salary/12
portion_saved=.8 * monthly_salary
annual_return = .04
monthly_return = annual_return/12
monthcounter = 0




while current_savings < portion_down_payment:
    current_savings = round((portion_saved + current_savings)+(monthly_return*(portion_saved + current_savings)))
    monthcounter = monthcounter+1
    print("month "+ str(monthcounter) +" savings: $"+str(current_savings) )

print("it took "+ str(monthcounter) +" months to save $"+str(current_savings))
