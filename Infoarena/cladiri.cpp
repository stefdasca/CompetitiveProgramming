#include<bits/stdc++.h>
using namespace std;
ifstream f("cladiri.in");
ofstream g("cladiri.out");
int n, m, x, y, mxs[1002][1002], mxd[1002][1002], sp[1002][1002];
short mat[1002][1002], len[1002][1002];
int main()
{
    f >> n >> m;
    f >> x >> y;
    swap(x, y);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            f >> mat[i][j];
            sp[i][j] = sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1] + mat[i][j];
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(mat[i][j] == 0)
                len[i][j] = len[i-1][j] + 1;
    for(int i = 1; i <= n; ++i)
    {
        deque<int>dq;
        int sst = -1;
        for(int j = 1; j <= m; ++j)
        {
            if(mat[i][j] == 1)
                sst = -1, dq.clear();
            else
            {
                if(sst == -1)
                    sst = j;
                while(!dq.empty() && len[i][j] <= len[i][dq.back()])
                    dq.pop_back();
                dq.push_back(j);
                int st = 0;
                int dr = dq.size()-1;
                while(dr - st >= 5)
                {
                    int mid = st + (dr - st)/3;
                    int mid2 = dr - (dr - st)/3;
                    int sola = len[i][dq[mid]];
                    int solb = len[i][dq[mid2]];
                    if(mid == 0)
                        sola *= (j-sst+1);
                    else
                        sola *= (j-dq[mid-1]);
                    if(mid2 == 0)
                        solb *= (j-sst+1);
                    else
                        solb *= (j-dq[mid2-1]);
                    mxs[i][j] = max(mxs[i][j], max(sola, solb));
                    if(sola == solb)
                        st = mid, dr = mid2;
                    else
                        if(sola > solb)
                            st = mid;
                        else
                            dr = mid2;
                }
                for(int a = st; a <= dr;++a)
                    if(a == 0)
                        mxs[i][j] = max(mxs[i][j], len[i][dq[a]] * (j - sst + 1));
                    else
                        mxs[i][j] = max(mxs[i][j], len[i][dq[a]] * (j - dq[a-1]));

            }
        }
    }
    for(int i = n; i >= 1; --i)
        for(int j = m; j >= 1; --j)
            if(mat[i][j] == 0)
                len[i][j] = len[i+1][j] + 1;
            else
                len[i][j] = 0;
    for(int i = n; i >= 1; --i)
    {
        deque<int>dq;
        int sst = -1;
        for(int j = m; j >= 1; --j)
        {
            if(mat[i][j] == 1)
                sst = -1, dq.clear();
            else
            {
                if(sst == -1)
                    sst = j;
                while(!dq.empty() && len[i][j] <= len[i][dq.back()])
                    dq.pop_back();
                dq.push_back(j);
                int st = 0;
                int dr = dq.size()-1;
                while(dr - st >= 5)
                {
                    int mid = st + (dr - st)/3;
                    int mid2 = dr - (dr - st)/3;
                    int sola = len[i][dq[mid]];
                    int solb = len[i][dq[mid2]];
                    if(mid == 0)
                        sola *= (sst - j + 1);
                    else
                        sola *= (dq[mid-1] - j);
                    if(mid2 == 0)
                        solb *= (sst - j + 1);
                    else
                        solb *= (dq[mid2-1] - j);
                    mxd[i][j] = max(mxd[i][j], max(sola, solb));
                    if(sola == solb)
                        st = mid, dr = mid2;
                    else
                        if(sola > solb)
                            st = mid;
                        else
                            dr = mid2;
                }
                for(int a = st; a <= dr; ++a)
                    if(a == 0)
                        mxd[i][j] = max(mxd[i][j], len[i][dq[a]] * (sst - j + 1));
                    else
                        mxd[i][j] = max(mxd[i][j], len[i][dq[a]] * (dq[a-1] - j));
            }
        }
    }
    for(int i = 1; i <= n;++i)
        for(int j = 1; j <= m;++j)
            mxs[i][j] = max(mxs[i][j], max(mxs[i-1][j], mxs[i][j-1]));
    for(int i = n; i >= 1; --i)
        for(int j = m; j >= 1; --j)
            mxd[i][j] = max(mxd[i][j], max(mxd[i+1][j], mxd[i][j+1]));
    int sol = 0;
    for(int i = 1; i + x - 1 <= n; ++i)
        for(int j = 1; j + y - 1 <= m; ++j)
        {
            if(sp[i + x - 1][j + y - 1] - sp[i + x - 1][j - 1] - sp[i - 1][j + y - 1] + sp[i - 1][j - 1] == 0)
            {
                sol = max(sol, mxs[n][j-1]);
                sol = max(sol, mxs[i-1][m]);
                sol = max(sol, mxd[i+x][1]);
                sol = max(sol, mxd[1][j+y]);
            }
        }
    g << sol;
    return 0;
}
