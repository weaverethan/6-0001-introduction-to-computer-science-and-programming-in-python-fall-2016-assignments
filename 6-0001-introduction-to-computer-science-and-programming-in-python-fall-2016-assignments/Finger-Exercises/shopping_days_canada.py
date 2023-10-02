import calendar as cal
from datetime import date





def find_thanksgiving(year):
    month = cal.monthcalendar(year, 10)
    if month[0][cal.SUNDAY] != 0:
        thanksgiving = month[2][cal.MONDAY]
    else:
        thanksgiving = month[3][cal.MONDAY]
    return thanksgiving
    


def shopping_days(year):
    """year a number >= 1941 returns the number of days between U.S. Thanksgiving and Christmas in year"""
    # Define two dates
    date1 = date(year, 12, 25)  # Christmas
    date2 = date(year, 10, find_thanksgiving(year))   # Current date (for example)

    # Calculate the difference in days
    days_difference = (date1 - date2).days
    return days_difference

    
year = 2023
print(find_thanksgiving(1977))
print(f"The number of shopping days is {shopping_days(year)} in {year}")