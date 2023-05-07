
def power(a,b,m):
    a %= m
    res = 1
    while (b > 0) :
        if (b & 1):
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res


def SieveOfEratosthenes(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    pos=0
    for p in range(2, n + 1):
        if prime[p]:
            pos=pos+1
            rem=(power(p-1,pos,p*p)+power(p+1,pos,p*p))%(p*p)
            if (rem > 10000000000):
                print(pos)
                print(p)
                print(rem)
                break



if __name__ == '__main__':
    SieveOfEratosthenes(1000000);



