
```
'''
a1=1
a2=2
a3=3

print(a1, a2, a3)
a1, a2, a3 = 3, 2, 1

print(a1, a2, a3)
print(a1, a2, a3, sep=', ')
print(a1, a2, a3, sep='')
print(a1, a2, a3, sep=' ')
print(a1, a2, a3, sep='\n')
print(a1,a2, a3, sep=' ,,,', end=' ')
print(a1, a2, a3, end=' ')
print(a1, a2, a3, end='')

sep는 괄호 안 요소들을 출력할때마다 (안에서) 어떻게 할건지
end는 괄호 안 요소들은 출력하고, 그 후에 (끝나고) 어떻게 할건지
'''



'''
# 변수입력
a=input("숫자를 입력하세요 : ")
print(a)


a, b = input("숫자를 입력하세요 : ").split()
print(a,b)
print(a+b)  # result = ab   # a,b가 string형으로 입력받아짐


a, b = map(int, input("숫자를 입력하세요 : ").split())
print(a,b)
print(a+b)
print(a-b)
print(a*b)
print(a/b)
print(a//b)  # 몫        #  //로 "목을 치겠다"
print(a%b)   # 나머지
'''



'''
x=6
if x==7:
    print("x는 7입니다")
else:
    print("x는 7이 아닙니다")
    

x=7
if x>0 and x<10:       # if 0<x<10 으로 해도 똑같음
    print("x는 10보다 작은 자연수")
else:
    print("모르겠다")

x=93
if x>90:
    print("A")
if x>80:
    print("B")
if x>70:
    print("C")
    
# result A B C 모두 출력됌
'''



'''
a=range(10)
print(a)   # result = range(10) 
print(list(a)) # result = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

b=range(1,11)
print(list(b))

for i in range(10):
    print(i, end=' ')
print("\n")

for i in range(10, 0, -1):
    print(i, end=' ')
print('\n')
#result 10 9 8 7 6 5 4 3 2 1

i=1
while i<=10:
    print(i, end = ' ')
    i+=1
print(i, end='\n')

# python에서는 ++, -- 같은 증감연산자 없음


i=1
while True:
    if i<=5:
        i+=1
        print(i, end=' ')
        continue;
    else:
        break;
print(i)
'''



# 반복문을 이용한 문제풀이
# 1) 1부터 N까지의 홀수출력
# 2) 1부터 N까지의 합 출력
# 3) N의 약수출력

'''
N = int(input("숫자를 입력하시오 : " ))
# N = int(N)       # 여기 그냥 int(N) 해주면 N에 대입이 안된다. 주의!! 

# 1)
for i in range(N+1):
    if i % 2 == 1:
        print(i, sep =' ')
    
# 2)
total = 0    
for i in range(N+1):
    total += i
print(total)


# 3)
for i in range(1, N+1):
    if N%i==0:
        print(i, end = ' ')
'''



# 별 출력하기
# *****
# ****
# ***
# **
# *
  
'''
for j in range(5, 0, -1):
    while j>0:
        print("*", end='')
        j-=1
    print()     # 주의!! print("\n")하면 줄바꿈이 2줄된다. print() 하면 기본적으로 줄바꿈 1회하기 때문
print()


# 위 코드를 for문 2개로 구현해보기
for i in range(5, 0 , -1):
    for j in range(i):
        print("*", end='')
    print()
'''


#====================== 내장함수 checkcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheck 
# # 문자열과 내장함수(1)
# .upper, .lower, .find, .count, len, .isalpha, ord (아스키넘버) , chr (아스키에 해당하는 문자)

''' 
msg = "It's time to go"
print(msg)
print(msg.upper())
print(msg.lower())
print(msg)  # msg자체는 그대로 있음.

print(msg.find('t'))  # result = 1
print(msg.find('t'))  # result = 1
print(msg[2])  # result = '
print(msg.count('t')) # result = 3
print(msg[:])
print(msg[:2])
print(msg[3:])  # result = s time to go
print(len(msg)) # result = 15 공백까지 셈


for x in msg:
    if x.isalpha():   # 알파벳만 True 공백은 False
        print(x, end='')
print()


tmp = 'AZ'
for x in tmp:
    print(ord(x))   # 아스키코드 , A=65, Z=90
    
tmp = 'az'
for x in tmp:
    print(ord(x))   # 아스키코드, a=97, z=122
    
tmp = 65
print(chr(tmp))
'''



# 리스트, 내장함수 (2)
# .append, .insert, .pop, .remove, .index, sum, max/min, rd.shuffle, .sort(reverse=True), .clear
'''
import random as rd

a = []
b = list()
print(a)
print(b)

a=[1,2,3,4,5]
print(a)

b = list(range(10))
print(b)

print(type(a), type(b), sep=', ')
c = a+b   # 두 리스트 합침
print(c)


a.append(6)
print(a)

a.insert(3, 7)
print(a)

a.pop()
print(a)

a.pop(3)           # 3번 인덱스에 있는 값 pop
print(a)

a.remove(4)   # '4'를 삭제
print(a)

print(a.index(5))   # 5의 index번호를 출력
print(a)
a.pop(a.index(5))   # 5의 index번호를 출력하고 그 index번호를 삭제 == a.remove(5)


print(sum(a))
print(max(a))
print(min(a))
print(max(0,5))


print(a)
rd.shuffle(a)
print(a)

a.sort()
print(a)

a.sort(reverse=True)
print(a)

a.clear()
print(a)
'''


# 리스트, 내장함수 (3)
# enumerate, all, any

'''
a = [22, 12, 36, 53, 19]
print(a[:3])
print(a[1:4])
print(len(a))


for x in enumerate(a):   # 튜플로 출력, Index, Value 둘다 출력함
    print(x)
    print(x[0], x[1], sep=', ')
print()


b = (1,2,3,4,5)
print(b[0])
print()


for index, value in enumerate(a):
    print(index, value, sep=',')
print()


print(a)
a.append(61)
if all(60>x for x in a):
    print("모든 x가 60보다 작습니다.")
else:
    print("하나 이상의 x값이 60이상입니다.")


a.remove(12)
if any(15>x for x in a):
    print("하나 이상의 x값이 15보다 작습니다")
else:
    print("모든 x값이 15이상입니다.")
'''


# 2차원 리스트 생성과 접근

'''
# 1차원
a=[0]*3
print(a)

# 2차원
a=[[0]*3 for i in range(3)]
print(a)   # 3 by 3

a[0][1] = 1
print(a)

for x in a:     # x가 2차원 리스트 안의 행을 차례대로 출력, 리스트안에 있는 값을 출력한다고 생각하기!
    print(x)
'''



# 함수 만들기
'''def add(a, b):
    return a+b

print(add(3, 5))
 
 
# 소수(솟수) 구현한건데 checkcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheckcheck
def isPrime(x):
    for i in range(2, x):
        if x%i ==0:
            return False
        else:
            return True
a = [12, 13, 7, 9, 19]

for y in a:
    print(isPrime(y))
'''



# 람다함수
'''
def plus_one(x):
    return x+1
print(plus_one(1))


plus_two = lambda x: x+2
print(plus_two(1))

# 람다함수는 내장함수의 인자로 사용할때 편리
a = [1,2,3]
print(list(map(plus_one, a)))  # map라는 함수는 (함수명, 자료) 형태로 사용    
print(list(map(lambda x: x+1, a)))

# 예를들어서 sort라는 함수의 인자로  (어떤기준으로 sort할건지) lambda를 사용하는 경우 많음
'''

# day1 복습

'''
# 몫과 나머지 연산자 
num1 = 17
num2 = 10
num3 = 5
print(num1 % num2) # result 예상 : 7
print(num2 % num3) # result 예상 : 0
print(num3 % num1) # result 예상 : 5
print(num2 // num3) # result 예상 : 2
print(num1 // num2 % num3) # result 예상 : 1 --> 앞에서부터 처리하지 않을까? (O)
print(num1 + num2 % num3) # result 예상 : 17 --> 나머지 연산부터 처리하지 않을까? (O)



# 위 내용을 바탕으로 한 자연수 n의 약수 찾기
N = int(input())
for i in range(1, N+1):
    if N % i == 0:
        print("{}는 {}의 약수입니다.".format(i, N))




# 위 내용을 바탕으로 한 솟수 찾기 --> 내 잘못된 습관 check --> c언어 특성으로 항상 이중for문으로 구현하려고함 // if문안에 조건문 생각하기 !
 
# 내가 여기서 잘 못하는게 for문과 break 등 사용 시 어디서 분기되고 어디로 가는지?
# --> break는 그 for문을 반복하지 않고 나감 , continue는 그 for문 continue만난 지점에서 다시 실행

numbers = list(map(int, input("숫자를 입력하세요 : ").split()))  
for i in numbers:
    if any (i % x ==0 for x in range(2, i)):
        print("{}는 솟수가 아닙니다".format(i))
        continue
    print("{}는 솟수입니다".format(i))

# 이 코드는 근데 2보다 작은수를 판단하는 조건은 없음 --> 추가해야됌.



# ========================================================================================================
# 내장함수 복습
# 1) .upper, .lower, .find, .count, len, .isalpha, ord (아스키넘버) , chr (아스키에 해당하는 문자)
# 2) list 내장함수(Tuple에도 가능).append, .insert, .pop, .remove, .index, sum, max/min, rd.shuffle, .sort(inverse=True), .clear
# 3) enumerate, all, any

A = "hello world"
print(A.upper())

A = A.upper()      # --> 대입가능
print(A)

print(A.find('W')) # --> return값으로 공백포함했을때 0부터 시작하는 인덱스값 리턴함  
print(A.find('w')) # --> return값으로 해당 문자 없을 때 -1 리턴함

print(A.count('W'))
print(A.count('w')) # --> return값으로 해당 문자 없으니까 count 0 리턴함

print(len(A))
print(A.isalpha()) # --> return : False // 공백 존재 시 False로 return함.

B = "abcd"
print(B.isalpha()) # return : True

# print(ord(B))  --> TypeError : ord() expected a character // 위에 B가 대입되서 안됌
# print(ord(c))  --> TypeError : c는 변수로 인식함. 'c'로 사용해야됌
print(ord('b'))
print(chr(97))  



# 아스키코드 값 암기 : A ~ Z , 65 ~ 90
#                     a ~ z , 97 ~ 122 
#                     공백 , 32
# 내가 잊어먹은 거 : input으로 받으면 무조건 문자열로 취급함.
'''
```
