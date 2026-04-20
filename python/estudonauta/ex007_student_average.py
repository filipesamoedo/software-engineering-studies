"""
1. Data Input and Type Casting: Reading user input and converting it to float for numerical calculations.
2. Arithmetic Mean: Calculating the average by summing values and dividing by the total count.
3. Operator Precedence: Using parentheses (n1 + n2) to ensure addition happens before division.
4. Output Formatting: Using the :.1f format specifier to round the result to one decimal place.
"""

n1 = float(input('Digite a nota 1: '))
n2 = float(input('Digite a nota 2: '))

# The parentheses are crucial here due to the Order of Operations (PEMDAS)
average = (n1 + n2) / 2

print('A média do aluno é: {:.1f}'.format(average))
