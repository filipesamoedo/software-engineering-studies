"""
1. Unit Conversion: Multiplying base units by powers of 10 (100 for cm, 1000 for mm).
2. Data Input and Type Casting: Using float() to allow for decimal distance values.
3. String Formatting and Suffixes: Using :.1f for precision and appending unit symbols (cm, mm) 
   directly in the output string.
4. Scale Factors: Understanding the metric system relationship where 1m = 10^2cm = 10^3mm.
"""

n = float(input('Digite o valor em metros: '))

# Calculating and displaying the conversions
# 1 meter = 100 centimeters | 1 meter = 1000 millimeters
print('Esse valor em centímetros é: {:.1f}cm \nE em milímetros é: {:.1f}mm'.format(n*100, n*1000))
