"""
1. Trigonometric Functions: Computing Sine (sin), Cosine (cos), and Tangent (tan).
2. Angular Unit Conversion: Using math.radians() to convert degrees to radians 
   (required by the math library's functions).
3. Precision Formatting: Displaying results with two decimal places using :.2f.
4. Modular Programming: Importing multiple specific functions from the math module.
"""

from math import sin, cos, tan, radians

print('======= DESAFIO 018 =======')
# The user provides the angle in degrees
a = int(input('Digite o angulo para descobrir o seno, cosseno e tangente: '))

# Conversion is essential because math.sin, math.cos, and math.tan expect radians
rad = radians(a)

print('Seno: {:.2f}\nCosseno: {:.2f}\nTangente: {:.2f}'.format(sin(rad), cos(rad), tan(rad)))
