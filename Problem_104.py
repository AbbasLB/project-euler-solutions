import math
import decimal

def check(num):
    arr=[False]*10
    while num!=0:
        arr[int(num%10)]=True;
        num/=10
    for i in range(1,10):
        if arr[i]==False:
            return False
    return True

def leftmost(n):
    n=int(n)
    return int(n/pow(10,int(math.log10(n))-8))

def calcFibb(n):
    sqrt5=decimal.Decimal(math.sqrt(5))
    a1=decimal.Decimal((1+sqrt5)/2);
    a2=decimal.Decimal((1-sqrt5)/2);
    return leftmost((pow(a1,n)-pow(a2,n))/sqrt5)

if __name__ == "__main__":
    fib = [0] * 1000000;
    fib[1] = 1
    fib[2] = 1
    for i in range(3, 1000000):
        fib[i] = ((fib[i - 1] % 1000000000) + (fib[i - 2] % 1000000000)) % 1000000000
        if check(fib[i]) == True and check(calcFibb(i))==True:
            print("fibb(" + str(i) + ")= Correct")
