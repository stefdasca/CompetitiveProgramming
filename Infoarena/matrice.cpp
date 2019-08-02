/*
        Infoarena matrice(google translate does a good job at translating the statement)
        
    Let's fix the length of one side of the rectangle. Then, we will iterate among the possible sides in a sliding window fashion and
we will keep information of the sequence with the most zeroes and of the sequence with the most ones. Basically, in order to maximize the answer, 
we have to use a rectangle either with many zeroes in both R and C arrays, or with many ones, so that the xors will be 0.

    Therefore, the running time will be O((n+m) sqrt n)

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("matrice.in");
ofstream g("matrice.out");
int n, m, a;
int v[30002], v2[30002];
int main()
{
    f >> n >> m >> a;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    for(int i = 1; i <= m; ++i)
        f >> v2[i];
    long long mx = 0, ct = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a % i == 0 && a / i <= m)
        {
            int mxwh = 0, mxbl = 0;
            int wh = 0, bl = 0;
            int ctw = 0, ctb = 0;
            int val = a / i;
            for(int j = 1; j <= m; ++j)
            {
                if(j > val)
                {
                    wh -= (v2[j - val] == 0);
                    bl -= (v2[j - val] == 1);
                }
                wh += (v2[j] == 0);
                bl += (v2[j] == 1);
                if(j >= val)
                {
                    if(wh > mxwh)
                        mxwh = wh, ctw = 1;
                    else
                        if(wh == mxwh)
                            ctw++;
                    if(bl > mxbl)
                        mxbl = bl, ctb = 1;
                    else
                        if(bl == mxbl)
                            ctb++;
                }
            }
            wh = 0, bl = 0;
            for(int j = 1; j <= n; ++j)
            {
                if(j > i)
                {
                    wh -= (v[j - i] == 0);
                    bl -= (v[j - i] == 1);
                }
                wh += (v[j] == 0);
                bl += (v[j] == 1);
                if(j >= i)
                {
                    if(wh > bl)
                    {
                        int ans = wh * mxwh + bl * (val - mxwh);
                        if(ans > mx)
                            mx = ans, ct = ctw;
                        else
                            if(ans == mx)
                                ct = ct + ctw;
                    }
                    if(wh < bl)
                    {
                        int ans = wh * (val - mxbl) + bl * mxbl;
                        if(ans > mx)
                            mx = ans, ct = ctb;
                        else
                            if(ans == mx)
                                ct = ct + ctb;
                    }
                    if(wh == bl)
                    {
                        int ans = wh * val;
                        if(ans > mx)
                            mx = ans, ct = m - val + 1;
                        else
                            if(ans == mx)
                                ct = ct + m - val + 1;
                    }
                }
            }
        }
    }
    g << mx << " " << ct << '\n';
    return 0;
}
