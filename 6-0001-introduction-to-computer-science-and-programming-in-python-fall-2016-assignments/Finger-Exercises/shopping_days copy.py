import calendar as cal
from datetime import date





def find_thanksgiving(year):
    month = cal.monthcalendar(year, 11)
    if month[0][cal.THURSDAY] != 0:
        thanksgiving = month[3][cal.THURSDAY]
    else:
        thanksgiving = month[4][cal.THURSDAY]
    return thanksgiving
    


def shopping_days(year):
    """year a number >= 1941 returns the number of days between U.S. Thanksgiving and Christmas in year"""
    # Define two dates
    date1 = date(year, 12, 25)  # Christmas
    date2 = date(year, 11, find_thanksgiving(year))   # Current date (for example)

    # Calculate the difference in days
    days_difference = (date1 - date2).days
    return days_difference

    
year = 1947
print(f"The number of shopping days is {shopping_days(year)} in {year}")