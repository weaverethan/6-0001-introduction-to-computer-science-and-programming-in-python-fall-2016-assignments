def get_min(d):
    """d a dict mapping letters to ints returns the value in d with the key that occurs first in the alphabet. E.g., if d = {x = 11, b = 12}, get_min returns 12."""
    
    num = []
    for i in d:
        num.append(ord(i))
    return chr(min(num))




dic = {"i","k","j"}

print(get_min(dic))
