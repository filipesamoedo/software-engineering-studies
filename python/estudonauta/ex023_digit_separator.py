"""
1. String Indexing and Slicing: Accessing individual characters of a number by their position.
2. Dynamic Loops: Using range(len(n)) to iterate based on the input size.
3. Collection Mapping: Pairing numeric positions with a list of labels (Unit, Ten, etc.).
4. Reverse Indexing Logic: Using n[qtdd-i-1] to extract digits from right to left.
"""

n = input('Digite um número entre 0 e 9999: ')
qtdd = len(n)

# Label mapping for each decimal position
nome = ['Unidade', 'Dezena', 'Centena', 'Milhar']

# Iterating through the length of the string to map each digit
for i in range(qtdd):
    # n[qtdd-i-1] ensures we always start from the last digit (the units)
    print('{} : {}'.format(nome[i], n[qtdd-i-1]))
