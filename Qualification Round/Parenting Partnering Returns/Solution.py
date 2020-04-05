def parenting(n):
    arr1=[]
    arr2=[]
    tmp=[0 for _ in range(len(n))]
    for j,k in enumerate(n):
        p=k[0]
        q=k[1]
        if j==0:
            arr1=q
            tmp[p]='J'
            continue
        x1=min(q)
        y1=max(q)
        x2=min(arr1)
        y2=max(arr1)
        if y1<=x2:
            arr1+=q
            tmp[p] = 'J'
            continue
        elif y2<=x1:
            arr1+=q
            tmp[p]='J'
            continue
        elif not arr2:
            arr2=q
            tmp[p]='C'
            x3=min(arr2)
            y3=max(arr2)
            continue
        elif y1<=x3:
            arr2+=q
            tmp[p]='C'
            x3=min(arr2)
            y3=max(arr2)
            continue
        elif y3<=x1:
            arr2+=q
            tmp[p]='C'
            x3=min(arr2)
            y3=max(arr2)
            continue
        else:
            tmp=['IMPOSSIBLE']
            break    
    res=''.join(tmp)
    return res

m=int(input())
for i in range(1,m+1):
    p1=int(input())
    q1={}
    for a in range(p1):
        q=list(map(int, input().split(" ")))
        q1[a]=q
    q1=sorted(q1.items(), key=(lambda x: x[1][0]))
    print('Case #{}: {}'.format(i, parenting(q1)))
