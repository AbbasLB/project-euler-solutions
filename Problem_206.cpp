#include<bits/stdc++.h>
using namespace std;

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
     __int128 cnt=1e9;
     __int128 tmp;
     int a[10];
    for(;1;cnt++)
    {
        tmp=cnt*cnt;
        for(int j=0;j<10;j++){
            a[j]=tmp%10;
            tmp/=100;
        }
        if(cnt%10000000==0)
            cout<<"searching "<<cnt<<'\n';
        if(a[0]!=0)
            continue;
        bool cont=false;
        for(int j=1;j<10;j++)
            if(a[j]!=10-j)
                cont=true;
        if(cont)
            continue;
        else break;
    }
    cout<<cnt<<'\n';

    return 0;


}

