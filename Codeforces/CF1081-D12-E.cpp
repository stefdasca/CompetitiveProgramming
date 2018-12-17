/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
long long nr[200002];
long long pp[200002];
long long gp[200002];
long long sum[200002];
int valid(long long dif, long long sf, long long st)
{
    if(st > sf || dif <= 0)
        return 0;
    if(st * st + dif == sf * sf)
        return 1;
    long long mini = (st - sf) * (st - sf - 1);
    dif -= mini;
    if(dif % (st - sf) == 0)
    {
        long long st2 = dif / (st - sf);
        long long sf2 = dif / (st - sf) + (st - sf - 1) * 2;
        st2 = st2 / 2 + 1;
        sf2 = sf2 / 2 + 1;
        if(st2 == st && sf2 == sf)
            return 1;
        return 0;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 2; i <= n; i += 2)
        cin >> nr[i];
    for(int i = 2; i <= n; i += 2)
    {
        if(nr[i] % 2 == 1)
        {
            pp[i] = nr[i] / 2 + 1;
            gp[i] = 1;
            if(pp[i] <= pp[i-2])
            {
                cout << "No";
                return 0;
            }
            long long nrr = 1;
            long long pg = 0;
            long long dif = 2;
            while(1)
            {
                if(nrr + pg > nr[i])
                    break;
                if((nr[i] - pg) % nrr == 0)
                {
                    long long aa = (nr[i] - pg) / nrr + (nrr - 1) * 2;
                    aa = aa / 2 + 1;
                    long long diff = 1LL * aa * aa - nr[i] - 1LL * pp[i-2] * pp[i-2];
                    if(valid(diff, aa - nrr, pp[i-2]))
                    {
                        pp[i] = aa;
                        gp[i] = nrr;
                    }
                }
                nrr += 2;
                pg += dif;
                dif += 2;
                pg += dif;
                dif += 2;
            }
            pp[i-1] = pp[i] - gp[i];
        }
        else
        {
            pp[i] = (nr[i] - 2) / 2 + 1;
            gp[i] = 2;
            if(pp[i] <= pp[i-2])
            {
                cout << "No";
                return 0;
            }
            long long nrr = 2;
            long long pg = 2;
            long long dif = 4;
            while(1)
            {
                if(nrr + pg > nr[i])
                    break;
                if((nr[i] - pg) % nrr == 0)
                {
                    long long aa = (nr[i] - pg) / nrr + (nrr - 1) * 2;
                    aa = aa / 2 + 1;
                    long long diff = 1LL * aa * aa - nr[i] - 1LL * pp[i-2] * pp[i-2];
                    if(valid(diff, aa - nrr, pp[i-2]))
                    {
                        pp[i] = aa;
                        gp[i] = nrr;
                    }
                }
                nrr += 2;
                pg += dif;
                dif += 2;
                pg += dif;
                dif += 2;
            }
            pp[i-1] = pp[i] - gp[i];
        }
    }
    long long summ = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i % 2 == 0)
            summ += nr[i];
        else
            nr[i] = 1LL * pp[i] * pp[i] - 1LL * pp[i-1] * pp[i-1], summ += 1LL * pp[i] * pp[i] - 1LL * pp[i-1] * pp[i-1];
        long long p = (int)sqrt(summ);
        if(p * p != summ)
        {
            cout << "No";
            return 0;
        }
        if(nr[i] <= 0)
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes" << '\n';
    for(int i = 1; i <= n; ++i)
    {
        if(i % 2 == 0)
            cout << nr[i] << " ";
        else
            cout << 1LL * pp[i] * pp[i] - 1LL * pp[i-1] * pp[i-1] << " ";
    }
    return 0;
}
