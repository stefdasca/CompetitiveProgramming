#include<bits/stdc++.h>
using namespace std;
ifstream f("colectie.in");
ofstream g("colectie.out");
int n, k, nec[12], nnb[100002], p10, sum[12], sol = 1000;
map<vector<int>,int>mp;
struct cati
{
    int arr[12];
};
cati v[50];
void pepe()
{
    for(int Rose = 0; Rose <= 9; ++Rose)
    {
        p10 = 10;
        for(int i = 1; i <= 100000000; i*=10, p10*=10)
        {
            int nrcg = k / p10 - (Rose == 0);
            if(nrcg < 0)
                break;
            nec[Rose] += nrcg * (p10/10) + max(0, min(k % p10 - (p10/10)*Rose + 1, p10/10));
        }
    }
}
int nrb(int nr)
{
    if(nnb[nr])
        return nnb[nr];
    nnb[nr] = __builtin_popcount(nr);
    return nnb[nr];
}
int main()
{
    f >> n >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= 9; ++j)
            f >> v[i].arr[j];
    pepe();
    int hf = n/2 + n%2;
    vector<int>z(10);
    vector<int>aa(33);
    for(int i = 0; i < (1<<hf); ++i)
    {
        memset(sum, 0, sizeof(sum));
        for(int j = 1; j <= hf; ++j)
            if(i & (1<<(j-1)))
                for(int a = 0; a <= 9; ++a)
                    sum[a] += v[j].arr[a];
        for(int a = 0; a <= 9; ++a)
            z[a]=sum[a];
        if(!mp[z] || nrb(mp[z]) > nrb(i))
            mp[z] = i;
    }
    hf -= n%2;
    for(int i = 0; i < (1<<hf); ++i)
    {
        memset(sum, 0, sizeof(sum));
        for(int j = 1; j <= hf; ++j)
            if(i & (1<<(j-1)))
                for(int a = 0; a <= 9; ++a)
                    sum[a] += v[hf + (n&1) + j].arr[a];
        for(int a = 0; a <= 9; ++a)
            z[a] = nec[a] - sum[a];
        if(!mp[z])
            continue;
        int ma = nrb(i) + nrb(mp[z]);
        if(ma >= sol)
            continue;
        sol = 0;
        for(int j = 1; j <= 20; ++j)
            if(mp[z] & (1<<(j-1)))
                aa[sol++]=j;
        for(int j = 1; j <= 20; ++j)
            if(i & (1<<(j-1)))
                aa[sol++]=hf + (n&1) + j;
    }
    g << 1 << '\n' << sol << '\n';
    for(int j = 0; j < sol; ++j)
        g << aa[j] << " ";
    return 0;
}
