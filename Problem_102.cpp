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

long double heron(long double a, long double b, long double c)
{
    long double s = (a + b + c) / 2;
    return sqrt(s * (s - a) *(s - b) * (s - c));
}
long double dist(long double x1,long double y1,long double x2,long double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool check(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
{
    long double s1=dist(x1,y1,x2,y2),s2=dist(x2,y2,x3,y3),s3=dist(x3,y3,x1,y1);
    long double inter1=dist(0,0,x1,y1),inter2=dist(0,0,x2,y2),inter3=dist(0,0,x3,y3);
    //cout<<fixed<<setprecision(30)<<"Area of Tri: "<<heron(s1,s2,s3)<<'\n';
    //cout<<fixed<<setprecision(30)<<"Area of In1: "<<heron(inter1,inter2,s1)<<'\n';
    //cout<<fixed<<setprecision(30)<<"Area of In2: "<<heron(inter2,inter3,s2)<<'\n';
    //cout<<fixed<<setprecision(30)<<"Area of In3: "<<heron(inter3,inter1,s3)<<'\n';
    //cout<<fixed<<setprecision(30)<<"Sum of 3Ins: "<<(heron(inter1,inter2,s1)+heron(inter2,inter3,s2)+heron(inter3,inter1,s3))<<'\n';
    return fabs(heron(s1,s2,s3)-(heron(inter1,inter2,s1)+heron(inter2,inter3,s2)+heron(inter3,inter1,s3)))<1e-9;

}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    freopen("p102_triangles.txt","r",stdin);
    string str;
    long long res=0;
    long long tot=0;
    while(cin>>str)
    {
        vector<int> v=split(str);
        res+=check(v[0],v[1],v[2],v[3],v[4],v[5]);
        tot++;
    }
    cout<<tot<<'\n';
    cout<<res<<'\n';
    return 0;
}
