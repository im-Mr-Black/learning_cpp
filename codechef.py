number_of_testcase = int(input())

for _ in range(number_of_testcase):
    a , b = map(int , input().split())
    x = list(map(int , input().split()))
    x.reverse()
    print(x)
    m = 0
    for n in x:
        if b > n:
            break
        m += 1
    print(a - m)

