"""
1. Data Type Differentiation: Using int() for discrete units (days) and float() for continuous measures (distance).
2. Linear Function Application: Calculating cost using the formula (fixed_rate * days) + (variable_rate * distance).
3. Operator Precedence: Using parentheses to clearly separate the daily cost from the mileage cost.
4. Monetary Formatting: Applying :.2f to ensure the final total reflects standard currency representation.
"""

dias = int(input('Quantos dias alugados? '))
km = float(input('Quantos Km rodados? '))

# Calculating total price: R$ 60.00 per day and R$ 0.15 per km
# The formula follows the structure: (days * 60) + (km * 0.15)
total = (dias * 60) + (km * 0.15)

print('O total a pagar é de R${:.2f}'.format(total))
