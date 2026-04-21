"""
1. Lists (Arrays): Storing multiple string values in a single ordered collection [n1, n2, n3, n4].
2. Pseudorandomness: Importing the 'choice' function from the 'random' module to pick an element.
3. Collection Handling: Passing a list as an argument to a function that expects a sequence.
4. Input Management: Collecting individual strings to build a dynamic data set.
"""

from random import choice

n1 = input('Digite o nome do aluno 1: ')
n2 = input('Digite o nome do aluno 2: ')
n3 = input('Digite o nome do aluno 3: ')
n4 = input('Digite o nome do aluno 4: ')

# Creating a list to group the names
alunos = [n1, n2, n3, n4]

# Choice picks a random element from the list
escolhido = choice(alunos)

print('O Aluno sorteado foi {}'.format(escolhido))
