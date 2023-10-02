plain_text = "no is no"
book = "Once upon a time, in a house in a land far away,"

gen_code_keys = (lambda book, plain_text:({c: str(book.find(c)) for c in plain_text}))

encoder = (lambda code_keys, plain_text:''.join(['*' + code_keys[c] for c in plain_text])[1:])

encrypt = (lambda book, plain_text:encoder(gen_code_keys(book, plain_text), plain_text))

print (gen_code_keys(book, plain_text))