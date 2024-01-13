def fill_grid(n):
    grid = [[0] * n for _ in range(n)]

    row, col = 0, 0
    direction = 'right'
    num = 1

    for _ in range(n * n):
        grid[row][col] = num
        num += 1

        if direction == 'right':
            if col + 1 < n and grid[row][col + 1] == 0:
                col += 1
            else:
                direction = 'down'
                row += 1
        elif direction == 'down':
            if row + 1 < n and grid[row + 1][col] == 0:
                row += 1
            else:
                direction = 'left'
                col -= 1
        elif direction == 'left':
            if col - 1 >= 0 and grid[row][col - 1] == 0:
                col -= 1
            else:
                direction = 'up'
                row -= 1
        elif direction == 'up':
            if row - 1 >= 0 and grid[row - 1][col] == 0:
                row -= 1
            else:
                direction = 'right'
                col += 1

    return grid

def print_grid(grid):
    for row in grid:
        print(" ".join(map(lambda x: str(x).rjust(2), row)))

n = int(input())
res = fill_grid(n)
for row in res:
    for col in row:
        if col == n * n:
            print('T',end = " ")
        else:
            print(col, end = " ")
    print()
