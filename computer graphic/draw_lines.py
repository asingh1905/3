import matplotlib.pyplot as plt

# Triangle vertices
tri_x = [0, 2, 4, 0]      # repeat first point to close the triangle
tri_y = [0, 3, 0, 0]

# Rectangle vertices
rect_x = [5, 9, 9, 5, 5]  # repeat first point to close the rectangle
rect_y = [0, 0, 3, 3, 0]

plt.figure()

# draw triangle
plt.plot(tri_x, tri_y, color='blue', linewidth=2, label='Triangle')

# draw rectangle
plt.plot(rect_x, rect_y, color='red', linewidth=2, label='Rectangle')

plt.axis('equal')          # same scale on both axes
plt.grid(True)
plt.legend()
plt.title("Triangle and Rectangle using Lines")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

plt.show()
