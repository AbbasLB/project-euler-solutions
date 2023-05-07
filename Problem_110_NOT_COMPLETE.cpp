#include<bits/stdc++.h>
using namespace std;


//problem 110
//xy=n^2
//number of divisors of (n^2)/2 exceeds 4,000,000

long long power(long long x,long long n)
{
    long long res=1;
    for(int i=0;i<n;i++)
        res*=x;
    return res;
}
long long primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,47};
set<long long> s;
void CombinationRepetitionUtil(int chosen[], int arr[],int index, int r, int start, int end)
{
    if (index == r)
    {
        long long divs=1;
        for (int i = r-1; i >= 0; i--){
            divs*=2*arr[chosen[i]]+1;

        }
        if(divs>0 && (divs/2)<=4000000)
            return ;
        long long res=1;
        int pos=1;
        for (int i = r-1; i >= 0; i--){
                res*=power(primes[pos++],arr[chosen[i]]);
                if(res<0)
                    return;
            //printf("%d ", arr[chosen[i]]);
        }
        if(res<0)
            return ;
        s.insert(res);
        // printf("\n");
        return;
    }
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        CombinationRepetitionUtil(chosen, arr, index + 1,
                                               r, i, end);
    }
    return;
}
void CombinationRepetition(int arr[], int n, int r)
{
    int chosen[r+1];
    CombinationRepetitionUtil(chosen, arr, 0, r, 0, n-1);
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
    //CombinationRepetition(arr,13,14);
    long long r=1;
    for(int i=0;i<15;i++)
        r*=primes[i];
    cout<<r<<'\n';
    int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    CombinationRepetition(arr,15,13);

    int i=0;
    for(long long x:s){
        cout<<x<<'\n';
        i++;
        if(i==5)
            break;
    }


    return 0;
}



