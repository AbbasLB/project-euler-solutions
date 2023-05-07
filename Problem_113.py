def fact(n):
    res = 1
    for i in range(2,n+1):
        res*=i
    return res


def nCr(n,r):
    return int(fact(n) / (fact(r) * fact(n - r)))


def solveHelper(r):
    if r==0:
        return 0
    n=9
    return nCr(r+n-1,r)

def solveZeros(r):
    res=0
    for i in range(1,r):
        res+=solveHelper(i)
    return res

def solveExactlyR(n):
    return 2*solveHelper(n)+solveZeros(n)-10

def solve(n):
    res=0
    for i in range(1,n+1):
        res += solveExactlyR(i)
    return res+n


if __name__ == "__main__":
    print(solve(100))
