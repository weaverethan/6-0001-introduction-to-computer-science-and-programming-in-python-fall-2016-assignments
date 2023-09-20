def Mean(x):
    """assumes a tuple of type ints to be passed in and gives mean of the tuple"""
    mean = sum(x)/len(x)
    return mean

tuple=(423,32,452,54,234,)

print(Mean(tuple))