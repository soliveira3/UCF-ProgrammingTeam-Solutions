n = int(input())

res = []
for i in range(n):
    s = input()
    if "rest" in s:
        res.append("😎")
    elif "leg" in s:
        res.append("🦵")
    else:
        res.append("💪")

# print(res)
i = 0
for j in range(31):
    if j % 7 == 0:
        print(int(j // 7) + 1, end = " ")

    print(res[i % len(res)], end="")
    if (i % 7 == 6):
        print()
    
    i += 1


print()
    