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

bool checkSetHelper(vector<int> &v,int maskS1)
{
    int sumS1,sumS2,szS1,szS2;
    int n=v.size();
    for(int maskS2=1;maskS2<(1<<n);maskS2++){

        if((maskS1&maskS2)==0)
        {
            sumS1=sum(v,maskS1);
            sumS2=sum(v,maskS2);
            szS1=__builtin_popcount(maskS1);
            szS2=__builtin_popcount(maskS2);
            if(sumS1==sumS2 ||(szS1>szS2 && sumS1<=sumS2) || (szS1<szS2 && sumS1>=sumS2))
                return 0;
        }
    }
    return 1;
}
bool checkSet(vector<int> &v)
{
    bool res=1;
    int n=v.size();
    for(int maskS1=1;maskS1<(1<<n);maskS1++)
        if(!checkSetHelper(v,maskS1)){
            res=0;
            break;
    }
    return res;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("p105_sets.txt","r",stdin);

    int total=19000000;
    int pass=0;
    vector<int> v(7);
    for(int a=15;a<=22;a++)
    for(int b=27;b<=36;b++)
    for(int c=27;c<=38;c++)
    for(int d=30;d<=40;d++)
    for(int e=33;e<=44;e++)
    for(int f=36;f<=50;f++)
    for(int g=36;g<=50;g++)
    {
        v[0]=a;
        v[1]=b;
        v[2]=c;
        v[3]=d;
        v[4]=e;
        v[5]=f;
        v[6]=g;
        if(checkSet(v))
        {
            cout<<"Set:";
            cout<<"sum="<<sum(v)<<'\n';
            for(int x:v)
                cout<<x<<' ';
            cout<<'\n';
        }
        pass++;
        if(pass%100000==0)
            cout<<"Calculating  ... "<<(double)pass*100/total<<"%\n";
    }

    return 0;
}

