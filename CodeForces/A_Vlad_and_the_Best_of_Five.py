
t = int(input())
for _ in range(t):
    s = input()
    A=B=0
    for c in s:
        if c == 'A':
            A+=1
        else :
            B+=1
    
    if A>B:
        print('A')
    else :
        print('B')