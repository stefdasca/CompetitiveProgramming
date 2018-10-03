#include<bits/stdc++.h>
using namespace std;
ifstream in("grup.in");
ofstream out("grup.out");
int n, s, k1, k2;
string va, vb;
int cost[100002];
vector<int>v[5];
int nr[5];
void Read()
{
    ios_base::sync_with_stdio(false);
    in >> n >> s >> k1 >> k2;
    for(int i = 1; i <= n; ++i)
        in >> cost[i];
    in >> va;
    in >> vb;
    for(int i = 0; i < n; ++i)
    {
        short to = 0;
        if(va[i] == '1' && vb[i] == '1')
            to = 1;
        if(va[i] == '1' && vb[i] == '0')
            to = 2;
        if(va[i] == '0' && vb[i] == '1')
            to = 3;
        if(va[i] == '0' && vb[i] == '0')
            to = 4;
        v[to].push_back(cost[i+1]);
    }
    for(int i = 1; i <= 4; ++i)
        sort(v[i].begin(), v[i].end());
    nr[1] = nr[2] = nr[3] = nr[4] = -1;
}
long long sol = (1LL<<60);
long long sumc = 0;
long long sz = 0;
long long buni = 0;
long long rai = 0;
int nxt(int seg)
{
    if(seg == 3 && rai == k2)
        return 2000000001;
    if(nr[seg] == v[seg].size()-1)
        return 2000000000;
    return v[seg][nr[seg]+1];
}
void Solve()
{
    bool rau = 1;
    int xxx = v[1].size();
    for(int i = 0; i <= min(min(s, xxx), k2); ++i)
    {
        if(rau)
        {
            if(i + v[2].size() >= k1 && (v[2].size() + v[4].size()  >= s - k2))
            {
                for(int j = 0; j < i; ++j)
                    sumc += v[1][j], ++nr[1], ++buni, ++rai, ++sz;
                for(int j = 0; buni < k1; ++j)
                    sumc += v[2][j], ++nr[2], ++buni, ++sz;
                while(sz < s)
                {
                    int val2 = nxt(2);
                    int val3 = nxt(3);
                    int val4 = nxt(4);
                    if(val2 <= val3 && val2 <= val4)
                        ++nr[2], sumc += v[2][nr[2]], ++buni, ++sz;
                    else
                        if(val3 <= val2 && val3 <= val4)
                            ++nr[3], sumc += v[3][nr[3]], ++rai, ++sz;
                        else
                            ++nr[4], sumc += v[4][nr[4]], ++sz;
                }
                rau = 0;
                sol = min(sol, sumc);
            }
        }
        else
        {
            ++nr[1];
            sumc += v[1][nr[1]];
            ++buni;
            ++rai;
            ++sz;
            if(rai > k2)
            {
                sumc -= v[3][nr[3]];
                --nr[3];
                --rai;
                --sz;
            }
            else
            {
                int aa, bb, cc;
                if(nr[2] == -1)
                    aa = -1;
                else
                    aa = v[2][nr[2]];
                if(nr[3] == -1)
                    bb = -1;
                else
                    bb = v[3][nr[3]];
                if(nr[4] == -1)
                    cc = -1;
                else
                    cc = v[4][nr[4]];
                if(aa >= bb && aa >= cc)
                {
                    sumc -= aa;
                    --buni;
                    --nr[2];
                    --sz;
                }
                else
                    if(bb >= aa && bb >= cc)
                    {
                        sumc -= bb;
                        --nr[3];
                        --rai;
                        --sz;
                    }
                    else
                    {
                        sumc -= cc;
                        --nr[4];
                        --sz;
                    }
            }
            while(buni > k1)
            {
                int val3 = nxt(3);
                int val4 = nxt(4);
                if(min(val3, val4) == 2000000000)
                    break;
                if(min(val3, val4) < v[2][nr[2]])
                {
                    sumc -= v[2][nr[2]];
                    --nr[2];
                    --buni;
                    --sz;
                    if(val3 < val4)
                    {
                        ++nr[3];
                        sumc += v[3][nr[3]];
                        ++rai;
                        ++sz;
                    }
                    else
                    {
                        ++nr[4];
                        sumc += v[4][nr[4]];
                        ++sz;
                    }
                }
                else
                    break;
            }
            sol = min(sol, sumc);
        }
    }
}
int main()
{
    Read();
    Solve();
    out << sol;
    return 0;
}
