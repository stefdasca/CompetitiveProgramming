/*
        JOI 17-joioi

    One can observe that a valid configuration is a configuration where the length of the component of letter J is increasing(or decreasing),
therefore the other letter will be decreasing(or increasing). Checking whether for a certain difference(vdif) we can assign letters to the squares
in the matrix can be done using greedy and some casework.

    Basically, okA[i][j] = 1 if a[i][j] - smallest value <= vdif and okB[i][j] = 1 if biggest value - a[i][j] <= vdif

    Then, mxA[i] = biggest line where we have a position where we can add only A
          mxB[i] = biggest line where we have a position where we can add only B
          mnA[i] = smallest line where we have a position where we can add only A
          mnB[i] = smallest line where we have a position where we can add only B

    For each of the two cases described previously, we can check using a rather easy greedy algorithm if we can actually build the matrix based on the values
precomputed previously.

    Therefore, we can binary search the answer.

*/
#include<bits/stdc++.h>
using namespace std;
int n, m, a[2002][2002], mxA[2002], mnA[2002], mxB[2002], mnB[2002], mx, mn;
bool okA[2002][2002], okB[2002][2002];
bool chk(int vdif)
{
    for(int i = 1; i <= m; ++i)
    {
        mnA[i] = mnB[i] = n+1;
        mxA[i] = mxB[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i][j] - mn <= vdif)
                okA[i][j] = 1;
            else
                okA[i][j] = 0;
            if(mx - a[i][j] <= vdif)
                okB[i][j] = 1;
            else
                okB[i][j] = 0;
            if(!okA[i][j] && !okB[i][j])
                return 0;
            if(okA[i][j] && !okB[i][j])
            {
                mxA[j] = max(mxA[j], i);
                mnA[j] = min(mnA[j], i);
            }
            if(okB[i][j] && !okA[i][j])
            {
                mxB[j] = max(mxB[j], i);
                mnB[j] = min(mnB[j], i);
            }
        }
    bool ok = 1;
    bool ok2 = 1;
    int mxxA = 0, mxxB = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(mxA[i] > mnB[i])
            ok = 0;
        if(mxB[i] > mnA[i])
            ok2 = 0;
        if(mnB[i] - 1 < mxxA)
            ok = 0;
        if(mnA[i] - 1 < mxxB)
            ok2 = 0;
        mxxA = max(mxxA, mxA[i]);
        mxxB = max(mxxB, mxB[i]);
    }
    if(ok)
        return 1;
    if(ok2)
        return 1;
    ok = 1;
    ok2 = 1;
    mxxA = n+1, mxxB = n+1;
    for(int i = 1; i <= m; ++i)
    {
        if(mxA[i] > mnB[i])
            ok = 0;
        if(mxB[i] > mnA[i])
            ok2 = 0;
        if(mxA[i] > mxxA)
            ok = 0;
        if(mxB[i] > mxxB)
            ok2 = 0;
        mxxA = min(mxxA, mnB[i] - 1);
        mxxB = min(mxxB, mnA[i] - 1);
    }
    if(ok)
        return 1;
    if(ok2)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    mn = 1000000001;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
            mn = min(mn, a[i][j]);
        }
    int st = 0;
    int dr = mx - mn;
    int ans = dr;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(chk(mid))
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}
