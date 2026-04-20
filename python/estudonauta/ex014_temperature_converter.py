"""
1. Temperature Conversion Formula: Applying the algebraic relation (C * 9/5) + 32.
2. Operator Precedence: Understanding that multiplication and division are performed before addition.
3. Floating Point Precision: Using :.1f to display temperatures with a single decimal place for readability.
4. Input Casting: Using float() to allow for precise temperature readings (e.g., 36.5°C).
"""

c = float(input('Digite a temperatura em graus Celsius: '))

# Conversion logic: 
# (Celsius multiplied by 9/5) plus 32 equals Fahrenheit
fahrenheit = (c * 9/5) + 32

print('A temperatura de {:.1f}ºC corresponde a {:.1f}ºF'.format(c, fahrenheit))
