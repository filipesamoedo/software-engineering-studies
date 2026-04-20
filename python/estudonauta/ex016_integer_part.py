"""
1. External Modules: Importing specific functions (trunc) from the 'math' library to extend functionality.
2. Number Truncation: Using math.trunc() to remove decimal digits without rounding the value.
3. Type Casting: Understanding the difference between a full float and its integer component.
4. Input Handling: Utilizing float() to capture numbers with decimal parts for processing.
"""

from math import trunc

n = float(input('Digite um número real: '))

# trunc(n) eliminates everything after the decimal point
print('A porção inteira do número {} é {}'.format(n, trunc(n)))
