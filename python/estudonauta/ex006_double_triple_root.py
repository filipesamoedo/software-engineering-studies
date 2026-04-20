"""
1. Basic Arithmetic Operators: Multiplication (*) and Exponentiation (**).
2. Input Handling: Converting string input to float for mathematical operations.
3. String Formatting: Using the .format() method with precision specifiers 
   (e.g., :.3f) to control decimal places.
4. Square Root Logic: Using the power of 0.5 (n**(1/2)) as an alternative to the math.sqrt() function.
"""

n = float(input('Digite um número: '))

# Calculating and displaying the results
# Using \n for line breaks and {:.3f} for 3 decimal places
print('O dobro é: {} \nO triplo é: {} \nA raiz quadrada é: {:.3f}'.format(n*2, n*3, n**(1/2)))
