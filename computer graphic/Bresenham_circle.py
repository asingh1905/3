import matplotlib.pyplot as plt

def bresenham_circle(r):
    x = 0
    y = r
    d = 3 - 2 * r

    xs, ys = [], []

    while x <= y:
        # 8-way symmetry
        xs += [ x,  y, -x, -y,  x,  y, -x, -y]
        ys += [ y,  x,  y,  x, -y, -x, -y, -x]

        if d < 0:
            d = d + 4 * x + 6
        else:
            d = d + 4 * (x - y) + 10
            y -= 1
        x += 1

    plt.scatter(xs, ys, s=10)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.title("Bresenham Circle")
    plt.grid(True)
    plt.show()

r = int(input("Enter radius: "))
bresenham_circle(r)
