"""
1. List Mutation: Using functions that modify the original list in-place (inplace modification).
2. Sequence Shuffling: Applying random.shuffle() to reorder elements while maintaining the set.
3. List Indexing: Accessing specific elements using their position (e.g., lista[0]) starting from zero.
4. Pseudorandom Permutation: Using algorithms to generate a random arrangement of a finite set.
"""

from random import shuffle

n1 = input('Digite o nome do aluno 1: ')
n2 = input('Digite o nome do aluno 2: ')
n3 = input('Digite o nome do aluno 3: ')
n4 = input('Digite o nome do aluno 4: ')

lista = [n1, n2, n3, n4]

# shuffle() changes the order of the list elements directly in the 'lista' variable
shuffle(lista)

print('A ordem de apresentação dos alunos será:')
# Accessing elements by their index after shuffling
print('1º Lugar {}\n2º Lugar {}\n3º Lugar {}\n4º Lugar {}'.format(lista[0], lista[1], lista[2], lista[3]))
