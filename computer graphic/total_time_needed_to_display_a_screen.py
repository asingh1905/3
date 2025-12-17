# Q.4 Program to find total time to display one frame

# input resolution
width = int(input("Enter screen width (in pixels): "))
height = int(input("Enter screen height (in pixels): "))

# time calculations (all in nanoseconds)
pixel_time = width * height          # 1 ns per pixel
horizontal_retrace_time = height     # 1 ns per line
vertical_retrace_time = 1           # 1 ns for full-screen vertical retrace

total_time = pixel_time + horizontal_retrace_time + vertical_retrace_time

print("Resolution =", width, "x", height, "pixels")
print("Total time for one frame =", total_time, "ns")
