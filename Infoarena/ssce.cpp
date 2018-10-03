#include<bits/stdc++.h>
#define DIMB 4
#define DIMN 10010
using namespace std;
int n, b, k, i, u, j, t, mx, c, sol, p, ok, minim, r, jj;
int v[DIMB], w[DIMB];
int P[] = {1,10,100,1000,10000,100000};
int x[DIMN];
int y[DIMN];
int d[5555], e[5555];
void nrcif(int n, int v[DIMB]) {
    memset(v, 0, 16);
    if (n==0){
        v[0]=1;
        return;
    }
    while (n) {
        v[ n%10 ]++;
        n/=10;
    }
}
int verif(int v[DIMB]) {
    ok = 0;
    for (int i=0;i<b;i++) {
        if (v[i] == 0)
            ok = 1;
        for (jj=0;jj<i;jj++)
            if (abs(v[i]-v[jj])>k)
                return 0;
    }
    return ok;

}
int normalizare(int v[DIMB]) {
    int i;
    ok = 0;
    minim = v[0];
    for (i=1;i<b;i++)
        if (v[i] < minim)
            minim = v[i];

    for (i=0;i<b;i++) {
        v[i]-=minim;
        if (v[i] > k)
            return 0;
    }
    return 1;
}

int cod(int v[DIMB]) {
    int i;
    minim = v[0];
    for (i=1;i<b;i++)
        if (v[i] < minim)
            minim = v[i];
    r = 0;
    for (i=0;i<b;i++)
        r += (v[i]-minim)*P[i];
    return r;
}
int main() {
    ifstream f("ssce.in");
    ofstream g("ssce.out");
    f>>n>>b>>k;
    for (i=1;i<=n;i++)
       f>>x[i];
    mx = 0;
    for (i=1;i<=b;i++)
        mx = mx * 10 + k;
    for (i=0;i<=mx;i++) {
        t = i;
        for (j=0;j<b;j++) {
            v[j] = t%10;
            t = t/10;
        }
        if (verif(v))
            y[++u] = i;
    }
    d[0] = e[0] = 1;
    for (i=1;i<=n;i++) {
        memcpy(d, e, sizeof(d));
        nrcif(x[i], w);
        for (j=1;j<=u;j++) {
            if (d[y[j]] == 0)
                continue;
            memcpy(v, w, 16);
            t = y[j];
            p = 0;
            while (t){
                v[p++] += t%10;
                t/=10;
            }
            if (normalizare(v)) {
                c = cod(v);
                if (e[c] < 1 + d[ y[j] ])
                    e[c] = 1 + d[ y[j] ];
            }
        }
    }
    g<<e[0]-1;
    return 0;
}
