"""
1. Loops (Iterative Structures): Using a 'for' loop with range(1, 11) to repeat an action 10 times.
2. String Multiplication: Using '-' * 11 to create a visual separator line efficiently.
3. Advanced Formatting: Using the :2 specifier (e.g., {:2}) to align single and double-digit numbers.
4. Input Handling: Converting input to int() since multiplication tables typically use integers.
"""

n = int(input('Digite um número inteiro para saber sua tabuada: '))

print('-' * 11)
# range(1, 11) starts at 1 and stops before 11
for c in range(1, 11):
    # {:2} ensures the numbers occupy two spaces, keeping the '=' signs aligned
    print('{} x {:2} = {}'.format(n, c, c * n))
print('-' * 11)
