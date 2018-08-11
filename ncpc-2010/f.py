n = int(input())
for i in range(n):
    s = input().strip()
    if s == "P=NP":
        print("skipped")
    else:
        print(eval(s))
