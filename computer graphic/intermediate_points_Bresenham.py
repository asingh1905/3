# Bresenham's line drawing algorithm in Python
# Example line: from (2, 2) to (10, 6)

x0, y0 = 2, 2
x1, y1 = 10, 6

dx = x1 - x0
dy = y1 - y0

p = 2 * dy - dx        # initial decision parameter

x = x0
y = y0

print("Points using Bresenham's algorithm:")
print(x, y)            # starting point

while x < x1:
    x += 1
    if p < 0:
        # next point is (x, y)
        p = p + 2 * dy
    else:
        # next point is (x, y+1)
        y += 1
        p = p + 2 * dy - 2 * dx
    print(x, y)
