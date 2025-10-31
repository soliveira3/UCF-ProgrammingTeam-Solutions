grid = [input() for _ in range(7)]


cur = 0
res = 0
for i in range((len(grid[0])+1) // 6):
    r1 = grid[0][i * 6: (i+1) * 6 - 1]
    r2 = grid[1][i * 6: (i+1) * 6 - 1]
    r3 = grid[2][i * 6: (i+1) * 6 - 1]
    r4 = grid[3][i * 6: (i+1) * 6 - 1]
    r5 = grid[4][i * 6: (i+1) * 6 - 1]
    r6 = grid[5][i * 6: (i+1) * 6 - 1]
    r7 = grid[6][i * 6: (i+1) * 6 - 1]
    # print(res, cur)

    if (r1 == "....x"):
        cur = cur * 10 + 1
    elif r1 == '.....':
        res += cur
        cur = 0
    elif r1 == 'x...x':
        cur = cur * 10 + 4
    elif r4 == 'x...x':
        cur = cur * 10
    elif r1 == 'xxxxx':
        if r2 == 'x...x' and r5 == 'x...x':
            cur = cur * 10 + 8
        elif r2 == 'x...x' and r5 == '....x':
            cur = cur * 10 + 9
        elif r2 == '....x' and r5 == 'x....':
            cur = cur * 10 + 2
        elif r2 == '....x' and r5 == '....x' and r4 == 'xxxxx':
            cur = cur * 10 + 3
        elif r2 == 'x....' and r5 == '....x':
            cur = cur * 10 + 5
        elif r2 == 'x....' and r5 == 'x...x':
            cur = cur * 10 + 6
        elif r2 == '....x' == r3 == r4 == r5:
            cur = cur * 10 + 7 
        else:
            raise Exception
    else:
        raise Exception

idk = [
"""xxxxxx...xx...xx...xx...xx...xxxxxx""",
"""....x....x....x....x....x....x....x""",
"""xxxxx....x....xxxxxxx....x....xxxxx""",
"""xxxxx....x....xxxxxx....x....xxxxxx""",
"""x...xx...xx...xxxxxx....x....x....x""",
"""xxxxxx....x....xxxxx....x....xxxxxx""",
"""xxxxxx....x....xxxxxx...xx...xxxxxx""",
"""xxxxx....x....x....x....x....x....x""",
"""xxxxxx...xx...xxxxxxx...xx...xxxxxx""",
"""xxxxxx...xx...xxxxxx....x....xxxxxx""",
""".......x....x..xxxxx..x....x.......""",
]

res += cur
# res = "1234567890+1234567890"
# print(res)

for row in range(0, 7):
    for i, digit in enumerate(str(res)):
        # if i == 10:
        #     digit = "10"
        print(idk[int(digit)][row * 5: (row + 1) * 5], end = '')
        if (i < len(str(res)) - 1):
            print('.', end = '')
    print()
