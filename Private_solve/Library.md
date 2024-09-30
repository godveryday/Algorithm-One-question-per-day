# 꼭 알아야 하는 라이브러리 정리

## 1. 내장함수

### sorted()

```
result = sorted([4,7,3,1])  # 오름 차순으로 정렬
print(result) --> [1,3,4,7]

result = sorted([4,7,3,1], reverse = True) # 내림 차순
print(result) --> [7,4,3,1]


key 속성으로 기준 정할 수 있음 --> key = lambda로 기준 정하기
result = sorted([('a' 40), ('b',70), ('c', 20)], key = lambda x : x[1], reverse = True)
print(result) --> [('b',70), ('a', 40), ('c', 20)]  # x[1]로 정렬했으므로 숫자 기준에서 내림차순
```


## 2. itertools : 반복되는 데이터 처리

순서를 생각하면 순열, 순서를 생각하지 않으면 조합

### permutations

: 리스트 같은 iterable 객체에서 r개의 데이터를 뽑아 일렬로 나열하는 모든 경우제시 (순열)

```
from itertools import permutations
data = ['a', 'b', 'c']
result = list(permutations(data, 3))   # list로 감싸주기 !
print(result) --> [('a', 'b', 'c'), ('a', 'c', 'b'), ('b', 'a', 'c'), ('b', 'c', 'a'), ('c', 'a', 'b'), ('c', 'b', 'a')]
```


### combinations

: 리스트 같은 iterable 객체에서 r개의 데이터를 뽑아 순서없이 일렬로 나열하는 모든 경우제시 (조합)

```
data = ['a', 'b', 'c', 'd']

result = list(combinations(data, 3))
print(result) --> [('a', 'b', 'c'), ('a', 'b', 'd'), ('a', 'c', 'd'), ('b', 'c', 'd')]
```


## 3. 수학

### factorial(x) 
### sqrt(x)  --> x의 제곱근 출력  
ex) math.sqrt(7) --> 2.6457513111...

### gcd(a,b) --> a와 b의 최대공약수 출력








