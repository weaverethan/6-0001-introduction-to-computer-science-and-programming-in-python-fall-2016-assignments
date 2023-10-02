

class Int_dict(object):
    def __init__(self, num_buckets):
        self.buckets = []
        self.num_buckets = num_buckets
        for i in range(num_buckets):
            self.buckets.append([])

    def add_entry(self, key, dict_val):
        hash_bucket = self.buckets[key % self.num_buckets]
        for i, kv in enumerate(hash_bucket):
            if kv[0] == key:
                hash_bucket[i] = (key, dict_val)
                return
        hash_bucket.append((key, dict_val))

    def get_value(self, key):
        hash_bucket = self.buckets[key % self.num_buckets]
        for e in hash_bucket:
            if e[0] == key:
                return e[1]
        return None

    def __str__(self):
        result = '{'
        for b in self.buckets:
            for e in b:
                result += f'{e[0]}:{e[1]}, '
        return result[:-2]+'}'        

import random
D = Int_dict(17)
for i in range(20):
    #choose a random int in the range 0 to 10**5 - 1
    key = random.choice(range(10**5))
    D.add_entry(key, i)
print('The value of the Int_dict is:')
print(D)