import math
import matplotlib.pyplot as plt

def dda_circle(r, steps=360):
    xs, ys = [], []

    for i in range(steps + 1):
        theta = 2 * math.pi * i / steps
        x = r * math.cos(theta)
        y = r * math.sin(theta)
        xs.append(x)
        ys.append(y)

    plt.scatter(xs, ys, s=10)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.title("DDA (Polar) Circle")
    plt.grid(True)
    plt.show()

r = int(input("Enter radius: "))
dda_circle(r)
