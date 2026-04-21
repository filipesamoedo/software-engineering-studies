"""
1. Pythagorean Theorem: Calculating the hypotenuse where a² + b² = c².
2. Mathematical Modules: Importing 'hypot' from the 'math' library for direct calculation.
3. Euclidean Distance: Using specialized functions to avoid manual power and root operations.
4. Output Formatting: Using :.2f to display the result with two decimal places.
"""

from math import hypot

print('====== Desafio 017 ======')
print('Descobrindo a HIPOTENUSA a partir dos valores de CATETO OPOSTO e CATETO ADJACENTE')

co = float(input('Cateto Oposto: '))
ca = float(input('Cateto Adjacente: '))

# The hypot() function computes sqrt(co*co + ca*ca) automatically
hi = hypot(co, ca)

print('A hipotenusa deste triângulo retângulo é {:.2f}'.format(hi))
