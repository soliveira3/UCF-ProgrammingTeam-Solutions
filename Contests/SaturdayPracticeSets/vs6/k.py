n = int(input())
maxi = 0
for _ in range(n):
    a = input()
    if (a == '/'):
        print(10 * (maxi // 10 + 1))
    else:
        maxi = max(maxi, int(a))
        print(a)