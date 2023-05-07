#include<bits/stdc++.h>
using namespace std;

vector<int> split(string str)
{
    vector<int> vect;
    stringstream ss(str);
    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return vect;
}

int sum(vector<int> &v)
{
    int res=0;
    for(int i=0;i<v.size();i++)
        res+=v[i];
    return res;
}
int sum(vector<int> &v,int mask)
{
    int res=0;
    for(int i=0;i<v.size();i++)
        if(mask&(1<<i))
            res+=v[i];
    return res;
}

unordered_map<int,unordered_map<int,bool>> mp;
int ans=0;

bool should_compare(int maskS1,int maskS2)
{
    bitset<12> a1(maskS1);
    bitset<12> a2(maskS2);
    bool res1=0,res2=0;
    for(int i=0;i<12;i++)
    {
       // cout<<"a1.test("<<i<<")="<<a1.test(i)<<'\n';
        //cout<<"a2.test("<<i<<")="<<a2.test(i)<<'\n';
        if(a1.test(i)){
        for(int j=i+1;j<12;j++)
            if(a2.test(j)){
                res1=1;
                a2.reset(j);
                break;
            }
        }else if(a2.test(i)){
        for(int j=i+1;j<12;j++)
            if(a1.test(j)){
                res2=1;
                a1.reset(j);
                break;
            }
        }
       // cout<<"res1="<<res1<<'\n';
       // cout<<"res2="<<res2<<'\n';
    }
    return res1==res2;
}

bool checkSetHelper(vector<int> &v,int maskS1)
{
    int sumS1,sumS2,szS1,szS2;
    int n=v.size();
    bool ret=1;
    for(int maskS2=1;maskS2<(1<<n);maskS2++){

        if((maskS1&maskS2)==0)
        {
            sumS1=sum(v,maskS1);
            sumS2=sum(v,maskS2);
            szS1=__builtin_popcount(maskS1);
            szS2=__builtin_popcount(maskS2);
            //string binary1 = bitset<12>(maskS1).to_string();
            //string binary2 = bitset<12>(maskS2).to_string();
            //if(szS1==szS2 && !mp[maskS1][maskS2] && !mp[maskS2][maskS1])
            //    cout<<"mask1="<<binary1<<"\nmask2="<<binary2<<"\nsz1="<<szS1<<" sz2="<<szS2<<"\nsouldcompare="<<should_compare(maskS1,maskS2)<<"\n\n";
            if(szS1==szS2 && should_compare(maskS1,maskS2))
                ans++;
            if(sumS1==sumS2 ||(szS1>szS2 && sumS1<=sumS2) || (szS1<szS2 && sumS1>=sumS2))
                ret=0;
            mp[maskS1][maskS2]=1;
        }
    }
    return ret;
}
bool checkSet(vector<int> &v)
{
    bool res=1;
    int n=v.size();
    for(int maskS1=1;maskS1<(1<<n);maskS1++)
        if(!checkSetHelper(v,maskS1)){
            res=0;
            //break;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("p105_sets.txt","r",stdin);

    int sumOfSet;
    bool isSpecial;
    //string str="1,2,3,4,5,6,7,8,9,10,11,12";
    string str="1,2,3,4,5,6,7,8,9,10,11,12";

    vector<int> v=split(str);
    sumOfSet=sum(v);
    isSpecial=checkSet(v);
    cout<<"Set 1: isSpecial="<<isSpecial<<" Sum(A)="<<sumOfSet<<'\n';
    cout<<ans/2<<'\n';
    return 0;
}

