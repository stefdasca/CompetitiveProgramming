#include<bits/stdc++.h>
using namespace std;
ifstream f("okcpp.in");
ofstream g("okcpp.out");
int fr[10], k, p;
long long ans;
inline bool bun(long long n, int s) {
    if (s && !n)
        return 1;
    memset(fr, 0, sizeof fr);
    do {
        fr[n % 10]++;
        n /= 10;
    } while(n);
    sort(fr, fr + 10, greater < int > ());
    for (int i = 0; i < s; i++) {
        int poz = 0;
        for (int j = 1; j < 10; j++)
            if (fr[j] < fr[poz])
                poz = j;
        fr[poz]++;
    }
    int q = 0, sum = 0;
    while (sum < k && q < 10) {
        sum += fr[q];
        q++;
    }
    return (sum >= k && q >= p);
}
void bkt(long long n, int s, int last){
    if (ans || !bun(n, s))
        return;
    if (s == 0)
        ans = n;
    else
        for(int i = last; i < 10; i++)
            bkt(n*10+i,s-1,i);
}
inline void calc(int s){
    bkt(1,s-1,0);
}
int main() {
    int t;
    f >> t >> k >> p;
    if (t == 1){
        long long a, b;
        f >> a >> b;
        while (a <= b){
            ans += bun(a, 0);
            a++;
        }
    }
    else
    {
        long long n;
        int s = 0;
        f >> n;
        if (bun(n, 0))
            ans = n;
        while (ans == 0 && n > 0) {
            int c = n % 10 + 1;
            n /= 10;
            while (c < 10) {
                bkt(n * 10 + c, s, 0);
                c++;
            }
            s++;
        }
        if (ans == 0)
            calc(s + 1);
    }
    g << ans;
    return 0;
}
