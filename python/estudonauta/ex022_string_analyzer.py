"""
1. String Methods: Using .upper(), .lower(), and .strip() for text transformation and cleaning.
2. Character Counting: Utilizing len() combined with .count(' ') to calculate the effective length.
3. Substring Indexing: Using .find(' ') to locate the first space, which effectively gives the 
   length of the first name in a zero-indexed system.
4. Input Sanitization: Applying .strip() to remove accidental leading/trailing whitespaces.
"""

# .strip() removes whitespace from the beginning and end of the string
nome = str(input('Digite seu nome completo: ')).strip()

print(nome.upper())
print(nome.lower())

# Total letters logic: (Total length of string) minus (Number of spaces)
print('Seu nome tem um total de {} letras'.format(len(nome) - nome.count(' ')))

# First name logic: find(' ') returns the index of the first space found
print('Seu primeiro nome tem {} letras'.format(nome.find(' ')))
