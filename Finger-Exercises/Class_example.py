class Int_set(object):
        def __init__(self):
                self._vals = []

        def insert(self, e):
                if e not in self._vals:
                        self._vals.append(e)

        def member(self, e):
                return e in self._vals
        
        def remove(self, e):
                try:
                    self._vals.remove(e)
                except:
                    raise ValueError(str(e)+' not found')
        
        def get_member(self):
               return self._vals[:]
        
        def __str__(self):
                if self._vals == []:
                    return '{}'
                self._vals.sort()
                result = ''
                for e in self._vals:
                    result = result + str(e) + ','
                return f'{{{result[:-1]}}}'
        def union(self, other):
            """other is an Int_set mutates self so that 
            it contains exactly the elemnts in 
            self plus the elements in other."""
            for i in other.get_member():
                  if i not in self._vals:
                        self._vals.append(i)
            



x = Int_set()
y = Int_set()

x.insert(1)
x.insert(3)
x.insert(2)
y.insert(1)
y.insert(9)
y.insert(3)
y.insert(4)

x.union(y)



print(x)