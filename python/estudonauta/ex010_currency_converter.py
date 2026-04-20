"""
1. Currency Conversion: Dividing the local balance by the exchange rate to get the foreign value.
2. Floating Point Precision: Using :.2f to represent monetary values, as currency typically uses two decimal places.
3. Financial Data Input: Using float() to allow the entry of cents and fractional values.
4. Constant Exchange Rate: Applying a fixed numeric literal (5.33) as a multiplier/divisor in the calculation.
"""

reais = float(input('Digite o valor em reais: R$'))

# Calculation: Balance divided by the current dollar rate
# Result formatted to 2 decimal places for financial accuracy
print('Com esse valor você pode comprar ${:.2f} dólares'.format(reais/5.33))
