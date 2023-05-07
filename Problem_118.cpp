#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000005
bool prime[MAX_N+5];

bool isLargePrime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long  i = 5; i*i<=n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

bool checkDistPrime(string n)
{
    return isLargePrime(stoi(n));
}

set<string> m;
void checkCanForm(string num,string append)
{
    if(num.size()==0){
        m.insert(append);
        return ;
    }
    for(int i=1;i<=num.size();i++)
        if(checkDistPrime(num.substr(0,i))){
            string tmp=append;
            tmp+='0'+i;
            checkCanForm(num.substr(i),tmp);
        }
}

string mySort(string x)
{
    vector<int> v;
    string num=x.substr(0,9);
    string rem=x.substr(9);
    for(int i=0;i<rem.size();i++)
    {
        int sz=rem[i]-'0';
        v.push_back(stoi(num.substr(0,sz)));
        num=num.substr(sz);
    }
    sort(v.begin(),v.end());
    string newStr="";
    for(int s:v)
        newStr+=to_string(s);
    for(int s:v)
        newStr+=(to_string(s).size()-'0');
   // cout<<x<<'\n';
    //for(auto abc:v)
    //    cout<<abc<<' ';
    //cout<<'\n';
    return newStr;
}


int solve()
{
    string s="123456789";
    do{
            checkCanForm(s,s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<m.size()<<'\n';
    unordered_set<string> newM;
    for(string x:m){
        newM.insert(mySort(x));
    }
    cout<<newM.size()<<'\n';
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    SieveOfEratosthenes(MAX_N);
    solve();
    return 0;
}



