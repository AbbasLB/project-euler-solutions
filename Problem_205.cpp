#include<bits/stdc++.h>
using namespace std;


int arrFourSided[37];

void solveFourSided(int i,int sum)
{
    if(i==9)
    {
        arrFourSided[sum]++;
        return;
    }
    solveFourSided(i+1,sum+1);
    solveFourSided(i+1,sum+2);
    solveFourSided(i+1,sum+3);
    solveFourSided(i+1,sum+4);
}

int arrSixSided[37];
void solveSixSided(int i,int sum)
{
    if(i==6)
    {
        arrSixSided[sum]++;
        return;
    }
    solveSixSided(i+1,sum+1);
    solveSixSided(i+1,sum+2);
    solveSixSided(i+1,sum+3);
    solveSixSided(i+1,sum+4);
    solveSixSided(i+1,sum+5);
    solveSixSided(i+1,sum+6);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    memset(arrFourSided,0,sizeof(arrFourSided));
    memset(arrSixSided,0,sizeof(arrSixSided));
    solveFourSided(0,0);
    solveSixSided(0,0);

    cout<<pow(4,9)<<'\n';
    for(int i=1;i<37;i++)
        cout<<arrFourSided[i]<<' ';
    cout<<'\n';

    cout<<pow(6,6)<<'\n';
    for(int i=1;i<37;i++)
        cout<<arrSixSided[i]<<' ';
    cout<<'\n';

    long double denoFourSided=pow(4,9);
    long double denoSixSided=pow(6,6);
    long double res=0;
    for(int i=0;i<37;i++)
        for(int j=0;j<i;j++)
            res+=((long double)arrFourSided[i]/denoFourSided)*((long double)arrSixSided[j]/denoSixSided);
    cout<<setprecision(7)<<res<<'\n';

    return 0;
}



