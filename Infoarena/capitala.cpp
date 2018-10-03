#include<bits/stdc++.h>
#define max_dim 200010
using namespace std;
class InParser {
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch() {
        ++sp;
        if (sp == 4096) {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume) {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser& operator >> (int &n) {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }

    InParser& operator >> (long long &n) {
        char c;
        n = 0;
        while (!isdigit(c = read_ch()) && c != '-');
        long long sgn = 1;
        if (c == '-') {
            n = 0;
            sgn = -1;
        } else {
            n = c - '0';
        }
        while (isdigit(c = read_ch())) {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
}f("capitala.in");
ofstream g("capitala.out");
vector<int> Lista[max_dim];
bool Marcat[max_dim];
int low[max_dim],nr[max_dim],up[max_dim],n,minim=1e9,poz;
void dfs(int nc){
    nr[nc]=1;
    for(int i=0;i<Lista[nc].size();i++)
    {
        int nv=Lista[nc][i];
        if(!nr[nv]){
            dfs(nv);
            nr[nc]+=nr[nv];
            low[nc]+=low[nv]+nr[nv];
        }
    }
}
void sol(int nc){
    Marcat[nc]=1;
    for(int i=0;i<Lista[nc].size();i++)
    {
        int nv=Lista[nc][i];
        if(!Marcat[nv]){
            up[nv]=low[nc]+up[nc]+n-low[nv]-nr[nv]-nr[nv];
            sol(nv);
        }
    }
}
int main () {
    f>>n;
    for(int i=1;i<n;i++){
        int x,y;
        f>>x>>y;
        Lista[x].push_back(y);
        Lista[y].push_back(x);
    }
    dfs(1);
    sol(1);
    for(int i=1;i<=n;i++)
        if(minim>low[i]+up[i]){
            minim=low[i]+up[i];
            poz=i;
        }
    g<<poz<<" "<<minim<<"\n";
    return 0;
}
