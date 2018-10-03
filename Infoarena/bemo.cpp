#include<bits/stdc++.h>
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
}f("bemo.in");
ofstream g("bemo.out");
int n,m,mat[1502][1502];
bool taken[1502][1502];
struct numere
{
    int L,C;
};
numere v[1502*1502];
int mini[1502];
int maxi[1502];
int Aintmax[8002],Aintmin[8002];
void build(int nod, int st, int dr)
{
    if(st==dr)
    {
        Aintmin[nod]=mini[st];
        Aintmax[nod]=maxi[st];
        return;
    }
    int mid=(st+dr)>>1;
    build(nod<<1,st,mid);
    build(nod<<1|1,mid+1,dr);
    Aintmin[nod]=min(Aintmin[nod<<1],Aintmin[nod<<1|1]);
    Aintmax[nod]=max(Aintmax[nod<<1],Aintmax[nod<<1|1]);
}
void update(int nod, int st, int dr, int poz)
{
    if(st==dr)
    {
        Aintmin[nod]=mini[st];
        Aintmax[nod]=maxi[st];
        return;
    }
    int mid=(st+dr)>>1;
    if(poz<=mid)
        update(nod<<1,st,mid,poz);
    else
        update(nod<<1|1,mid+1,dr,poz);
    Aintmin[nod]=min(Aintmin[nod<<1],Aintmin[nod<<1|1]);
    Aintmax[nod]=max(Aintmax[nod<<1],Aintmax[nod<<1|1]);
}
int sti,sfi,max1,min1;
void queryM(int nod, int st, int dr)
{
    if(dr<sti || st>sfi)
        return;
    if(sti<=st && dr<=sfi)
    {
        max1=max(max1,Aintmax[nod]);
        return;
    }
    int mid=(st+dr)>>1;
    if(sti<=mid)
        queryM(nod<<1,st,mid);
    if(mid<sfi)
        queryM(nod<<1|1,mid+1,dr);
}
void querym(int nod, int st, int dr)
{
    if(dr<sti || st>sfi)
        return;
    if(sti<=st && dr<=sfi)
    {
        min1=min(min1,Aintmin[nod]);
        return;
    }
    int mid=(st+dr)>>1;
    if(sti<=mid)
        querym(nod<<1,st,mid);
    if(mid<sfi)
        querym(nod<<1|1,mid+1,dr);
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            f>>mat[i][j];
            int nr=mat[i][j];
            v[nr]={i,j};
        }
    for(int i=1;i<=n;++i)
        mini[i]=8002;
    taken[v[1].L][v[1].C]=1;
    mini[v[1].L]=maxi[v[1].L]=v[1].C;
    build(1,1,n);
    int j=1;
    for(int i=2;i<=n*m;++i)
    {
        int pozL=v[i].L;
        int pozC=v[i].C;
        max1=0;
        if(pozL!=1){
            sti=1;
            sfi=pozL-1;
            queryM(1,1,n);
        }
        min1=8002;
        if(pozL!=n)
        {
            sti=pozL+1;
            sfi=n;
            querym(1,1,n);
        }
        if(max1<=pozC && pozC<=min1)
        {
            taken[pozL][pozC]=1;
            mini[pozL]=min(mini[pozL],pozC);
            maxi[pozL]=max(maxi[pozL],pozC);
            update(1,1,n,pozL);
            ++j;
            if(j==(n+m-1))
                break;
        }
    }
    int L=1;
    int C=1;
    while(L<=n || C<=m)
    {
        g<<mat[L][C]<<" ";
        if(taken[L+1][C])
            ++L;
        else
            if(taken[L][C+1])
                ++C;
            else
                break;
    }
    return 0;
}
