# 1. K번째 약수 5min


```
n, k = map(int, input().split())
list = []

for i in range(1, n+1):
    if n%i == 0:
        list.append(i)

list.sort()
if len(list)>k:
    print(list[k-1])
else:
    print(-1)
```

약수 계산 시 나머지가 0임을 활용

리스트의 인덱스가 0부터 시작하는 것을 잘 생각하기 --> print(list[k-1])
