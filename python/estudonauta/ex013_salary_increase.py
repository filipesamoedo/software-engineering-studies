"""
1. Percentage Increase: Multiplying a value by a factor greater than 1 (1.15) to calculate a 15% raise.
2. Compound Arithmetic: Using the shorthand (s * 1.15) which is equivalent to (s + (s * 0.15)).
3. Financial Data Input: Using float() to handle currency values and salary cents.
4. Output Formatting: Using :.2f to ensure the new salary is displayed with two decimal places.
"""

s = float(input(' Digite o seu salário: '))

# Calculation: Original salary multiplied by 1.15 (115%) to include the 15% increase
new_salary = s * 1.15

print('Seu novo salário com 15% de aumento ficou: R${:.2f} Reais'.format(new_salary))
