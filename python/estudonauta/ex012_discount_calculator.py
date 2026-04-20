"""
1. Percentage Calculation: Multiplying a value by a decimal (0.05) to find the discount amount. [cite: 9]
2. Arithmetic Subtraction: Deducting the calculated discount from the original price (p - discount). [cite: 9]
3. Financial Data Input: Using float() to handle currency values, which often include cents. [cite: 13, 39]
4. String Formatting: Using :.2f to ensure the final price is displayed with two decimal places. [cite: 11, 19, 38]
"""

p = float(input('Digite o preço do produto para ganhar o desconto: R$'))

# Calculation: Original price minus (original price * 0.05)
# This represents a 5% reduction.
final_price = p - (p * 0.05)

print('O produto com 5% de desconto fica por: R${:.2f}'.format(final_price))
