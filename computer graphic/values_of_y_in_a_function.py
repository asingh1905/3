import random

# number of random x values
n = int(input("How many random x values? "))

for i in range(n):
    x = random.randint(-10, 10)      # random integer x in [-10, 10]
    y = x**2 + 2*x + 1               # example function y = x^2 + 2x + 1
    print(f"x = {x}, y = {y}")
