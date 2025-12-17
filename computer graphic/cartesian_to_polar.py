import math

# read Cartesian coordinates
x = float(input("Enter x: "))
y = float(input("Enter y: "))

# convert to polar
r = math.hypot(x, y)          # same as sqrt(x*x + y*y)
theta = math.atan2(y, x)      # angle in radians

print("Polar coordinates:")
print("r =", r)
print("theta (radians) =", theta)
