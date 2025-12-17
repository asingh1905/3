# Mid-point line drawing algorithm in Python
# Example: from (2, 2) to (10, 5)

x0, y0 = 2, 2
x1, y1 = 10, 5

dx = x1 - x0
dy = y1 - y0

d = dy - (dx / 2)          # initial decision parameter
x = x0
y = y0

print("Points using Mid-point line algorithm:")
print(x, y)                # starting point

while x < x1:
    x += 1                 # always move in x
    if d < 0:
        # choose East pixel
        d = d + dy
    else:
        # choose North-East pixel
        y += 1
        d = d + dy - dx
    print(x, y)
