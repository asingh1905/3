# Q.5 DDA line drawing from (0,0) to (8,9)

x1, y1 = 0, 0
x2, y2 = 8, 9

dx = x2 - x1
dy = y2 - y1

# number of steps
steps = max(abs(dx), abs(dy))

# calculate increments
x_inc = dx / steps
y_inc = dy / steps

x = x1
y = y1

print("Intermediate points using DDA:")
for i in range(steps + 1):      # includes start and end
    print(round(x), round(y))
    x += x_inc
    y += y_inc
