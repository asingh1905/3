import matplotlib.pyplot as plt
import numpy as np

# ---------- FLOOD FILL ----------

grid1 = np.array([
    [1, 1, 1, 1, 1],
    [1, 0, 0, 0, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 0, 0, 1],
    [1, 1, 1, 1, 1]
], dtype=int)

rows1, cols1 = grid1.shape

def flood_fill(x, y, old_color, new_color):
    if x < 0 or x >= cols1 or y < 0 or y >= rows1:
        return
    if grid1[y, x] != old_color or grid1[y, x] == new_color:
        return
    grid1[y, x] = new_color
    flood_fill(x + 1, y, old_color, new_color)
    flood_fill(x - 1, y, old_color, new_color)
    flood_fill(x, y + 1, old_color, new_color)
    flood_fill(x, y - 1, old_color, new_color)

# apply flood fill from seed (2, 2)
flood_fill(2, 2, old_color=0, new_color=2)

plt.figure(figsize=(8, 4))
plt.subplot(1, 2, 1)
plt.title("Flood Fill")
plt.imshow(grid1, cmap='viridis', origin='lower')
plt.colorbar(fraction=0.046, pad=0.04)
plt.xticks(range(cols1))
plt.yticks(range(rows1))

# ---------- BOUNDARY FILL ----------

grid2 = np.array([
    [1, 1, 1, 1, 1],
    [1, 0, 0, 0, 1],
    [1, 0, 0, 0, 1],
    [1, 0, 0, 0, 1],
    [1, 1, 1, 1, 1]
], dtype=int)

rows2, cols2 = grid2.shape

def boundary_fill(x, y, fill_color, boundary_color):
    if x < 0 or x >= cols2 or y < 0 or y >= rows2:
        return
    if grid2[y, x] == boundary_color or grid2[y, x] == fill_color:
        return
    grid2[y, x] = fill_color
    boundary_fill(x + 1, y, fill_color, boundary_color)
    boundary_fill(x - 1, y, fill_color, boundary_color)
    boundary_fill(x, y + 1, fill_color, boundary_color)
    boundary_fill(x, y - 1, fill_color, boundary_color)

# apply boundary fill from seed (2, 2)
boundary_fill(2, 2, fill_color=2, boundary_color=1)

plt.subplot(1, 2, 2)
plt.title("Boundary Fill")
plt.imshow(grid2, cmap='viridis', origin='lower')
plt.colorbar(fraction=0.046, pad=0.04)
plt.xticks(range(cols2))
plt.yticks(range(rows2))

plt.tight_layout()
plt.show()
