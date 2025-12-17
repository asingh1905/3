import matplotlib.pyplot as plt

def midpoint_circle(r):
    x = 0
    y = r
    p = 1 - r

    xs, ys = [], []

    while x <= y:
        xs += [ x,  y, -x, -y,  x,  y, -x, -y]
        ys += [ y,  x,  y,  x, -y, -x, -y, -x]

        x += 1
        if p < 0:
            p = p + 2 * x + 1
        else:
            y -= 1
            p = p + 2 * (x - y) + 1

    plt.scatter(xs, ys, s=10)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.title("Mid-point Circle")
    plt.grid(True)
    plt.show()

r = int(input("Enter radius: "))
midpoint_circle(r)
