import string

plain_text = "zx no is no"
book = "In a village of La Mancha, the name of which I have no desire to call to mind, there lived not long since one of those gentlemen that keep a lance in the lance-rack, an old buckler, a lean hack, and a greyhound for coursing."
cypher = "22*13*33*137*59*11*23*11*1*57*6*13*1*2*6*57*2*6*1*22*13*33*137*59*11*23*11*1*57*6*173*7*11"


gen_code_keys = (lambda book, plain_text: {c: str(book + c if c not in book else book).find(c) for c in plain_text})

encoder = (lambda code_keys, plain_text:''.join(['*' + code_keys[c] for c in plain_text])[1:])

encrypt = (lambda book, plain_text:encoder(gen_code_keys(book, plain_text), plain_text))

gen_code_unknown = (lambda book: {book.find(c): c for c in string.printable})
#gen_code_unknown = (lambda book: {book.index(c): c for c in book})

decode = (lambda cypher, code_keys: ''.join([code_keys[int(c)] for c in cypher.split("*")]))


print(decode(cypher, gen_code_unknown(book)))
#print (encrypt(book,plain_text))