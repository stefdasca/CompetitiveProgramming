#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int n, q;
char c[100002];

int frq[402][30], whr[100002], bksz;
int crt[402], sta[402], sf[402];

int vf[32];

void prc(int bkt)
{
    if(crt[bkt] == 1)
    {
        int pz = 0;
        for(int i = sta[bkt]; i <= sf[bkt]; ++i)
        {
            while(frq[bkt][pz] == 0)
                ++pz;
            c[i] = 'a' + pz;
            --frq[bkt][pz];
        }
    }
    if(crt[bkt] == 2)
    {
        int pz = 25;
        for(int i = sta[bkt]; i <= sf[bkt]; ++i)
        {
            while(frq[bkt][pz] == 0)
                --pz;
            c[i] = 'a' + pz;
            --frq[bkt][pz];
        }
    }
    if(crt[bkt])
    {
        for(int i = sta[bkt]; i <= sf[bkt]; ++i)
            frq[bkt][c[i] - 'a']++;
        crt[bkt] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    cin >> (c + 1);
    bksz = sqrt(n);
    int x = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(!sta[x])
            sta[x] = i;
        sf[x] = i;
        whr[i] = x;
        frq[whr[i]][c[i] - 'a']++;
        if(i % bksz == 0)
            ++x;
    }
    for(int i = 1; i <= q; ++i)
    {
        int st, dr, x;
        cin >> st >> dr >> x;
        x ^= 1;
        prc(whr[st]);
        prc(whr[dr]);
        memset(vf, 0, sizeof(vf));
        int pf = sf[whr[st]];
        int s2 = st;
        while(st <= dr && st <= pf)
        {
            vf[c[st] - 'a']++;
            frq[whr[st]][c[st] - 'a']--;
            c[st] = 0;
            ++st;
        }
        while(sf[whr[st]] <= dr && st <= dr)
        {
            for(int j = 0; j <= 25; ++j)
                vf[j] += frq[whr[st]][j];
            memset(frq[whr[st]], 0, sizeof(frq[whr[st]]));
            crt[whr[st]] = x + 1;
            st = sf[whr[st]] + 1;
        }
        while(st <= dr)
        {
            vf[c[st] - 'a']++;
            frq[whr[st]][c[st] - 'a']--;
            c[st] = 0;
            ++st;
        }
        st = s2;
        int pz;
        if(x == 0)
            pz = 0;
        else
            pz = 25;
        while(st <= dr && st <= pf)
        {
            while(vf[pz] == 0)
            {
                if(x == 0)
                    ++pz;
                else
                    --pz;
            }
            vf[pz]--;
            frq[whr[st]][pz]++;
            c[st] = 'a' + pz;
            ++st;
        }
        while(sf[whr[st]] <= dr && st <= dr)
        {
            int bksz = sf[whr[st]] - sta[whr[st]] + 1;
            memset(frq[whr[st]], 0, sizeof(frq[whr[st]]));
            while(bksz)
            {
                if(vf[pz] >= bksz)
                    frq[whr[st]][pz] += bksz, vf[pz] -= bksz, bksz = 0;
                else
                    frq[whr[st]][pz] += vf[pz], bksz -= vf[pz], vf[pz] = 0;
                while(vf[pz] == 0)
                {
                    if(x == 0)
                        ++pz;
                    else
                        --pz;
                }
            }
            st = sf[whr[st]] + 1;
        }
        while(st <= dr)
        {
            while(vf[pz] == 0)
            {
                if(x == 0)
                    ++pz;
                else
                    --pz;
            }
            vf[pz]--;
            frq[whr[st]][pz]++;
            c[st] = 'a' + pz;
            ++st;
        }
    }
    for(int i = 1; i <= whr[n]; ++i)
        prc(i);
    for(int i = 1; i <= n; ++i)
        cout << c[i];
    return 0;
}
