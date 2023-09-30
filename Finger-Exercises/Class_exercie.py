import datetime

class Person(object):
        def __init__(self, name):
                self._name = name
                try:
                        last_blank = name.rindex(' ')
                        self._last_name = name[last_blank]
                except:
                      self._last_name = name
                self._birthday = None


        def get_name(self):
              return self._name
        
        def get_last_name(self):
              return self._last_name
        
        def set_birthday(self, birthdate):
              self._birthday = birthdate

        def get_age(self):
              if self._birthday == None:
                    raise ValueError
              return (datetime.date.today() - self._birthday).days
        
        def __It__(self, other):
              if self._last_name == other._last_name:
                    return self._name < other._name
              return self._last_name < other._last_name
        
        def __str__(self):
              return self._name
        


class Politician(Person):
       def __init__(self, name, party=None):
              Person.__init__(self, name)
              self._party = party

              
       def get_party(self):
              return self._party
       

       def might_agree(self, other):
              if self._party == other._party or self._party == None or other._party == None:
                     return True
              else:
                     return False
              



ethan = Politician('Ethan Weaver', "Republican")
india = Politician('India Weaver', 'Democratic')
ezra = Politician("Ezra Weaver")
ethan.set_birthday(datetime.date(1969, 6, 26))
print(ethan.get_age())
print(ethan.get_party())

print(ethan.might_agree(india))
print(ezra.might_agree(india))
