#include<bits/stdc++.h>
using namespace std;


long long dp[101][101];
long long solve(long long sz, long long rects)
{
    if (rects == 0)
        return 1;
    if (sz < 3)
        return 0;
    if (dp[sz][rects] != -1)
        return dp[sz][rects];
    long long res = 0;
    rects--;
    for (long long len = 3; len <= sz; len++)
        for (long long i = 0; i < sz - len + 1; i++)
            if (rects == 0)
                res += solve(i - 1, 0) * solve(sz - i - len - 1, 0);
            else
                for (long long j = 0; j < rects; j++) {
                    res += solve(i - 1, rects - j) * solve(sz - i - len - 1, j);
                    res += solve(i - 1, j) * solve(sz - i - len - 1, rects - j);
                }
    rects++;
    // cout << "dp[" << sz << "][" << rects << "]=" << res / rects << "\n";
    return dp[sz][rects] = res/rects;
}

long long solve(long long sz)
{
    long long res = 0;
    for (long long i = 0; i <= sz/2; i++)
    {
        res += solve(sz, i) ;
        //cout << "solve(" << i << ")=" << solve(size, i) << '\n';
    }
    return res;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("p105_sets.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<51;i++)
        cout<<"solve("<<i<<")="<<solve(i)<<'\n';

   // cout << solve(19, 5) << '\n';
    //cout << solve(50) << '\n';
    return 0;
}
