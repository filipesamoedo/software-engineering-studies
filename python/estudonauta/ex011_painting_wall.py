"""
1. Geometry Foundations: Calculating the area of a rectangular surface (Width * Height). 
2. Applied Proportions: Dividing the total area by the paint's coverage rate (2m² per liter). 
3. Float Data Handling: Using float() to allow precise measurements for dimensions and volume. [cite: 26, 39]
4. Mathematical Modeling: Translating a real-world problem into a simple algebraic expression.
"""

l = float(input('Digite a largura da parede: '))
a = float(input('Digite a altura da parede: '))

# Calculating the area: width times height
area = l * a
# Calculating paint: area divided by coverage (2m²/L)
tinta = area / 2

print('Serão necessários {} litros de tinta para pintar essa parede.'.format(tinta))
