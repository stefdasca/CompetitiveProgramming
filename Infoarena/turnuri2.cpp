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
};
InParser f("turnuri2.in");
ofstream g("turnuri2.out");
int n,nr,poz,start,finish,max1;
int vh[1000002],vf[1000002],arbint[5000002],mxs[1000002],mxd[1000002];
void build(int nod, int st, int dr)
{
    if(st==dr)
    {
        arbint[nod]=nr;
        return;
    }
    int m=(st+dr)/2;
    if(poz<=m)
        build(2*nod,st,m);
    else
        build(2*nod+1,m+1,dr);
    arbint[nod]=max(arbint[2*nod],arbint[2*nod+1]);
}
void query(int nod,int st,int dr)
{
    if(start<=st && dr<=finish)
    {
        if(max1<arbint[nod])
            max1=arbint[nod];
        return;
    }
    int mij=(st+dr)/2;
    if(start<=mij)
        query(2*nod,st,mij);
    if(mij<finish)
        query(2*nod+1,mij+1,dr);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i){
        f>>vh[i]>>vf[i];
        nr=vf[i];
        poz=i;
        build(1,1,n);
    }
    mxs[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(vh[i-1]>vh[i])
            mxs[i]=i-1;
        else
        {
            mxs[i]=mxs[i-1];
            while(vh[mxs[i]]<=vh[i] && mxs[i]>1)
                mxs[i]=mxs[mxs[i]];
        }
    }
    mxd[n]=n;
    for(int i=n-1;i>=1;--i)
    {
        if(vh[i+1]>vh[i])
            mxd[i]=i+1;
        else
        {
            mxd[i]=mxd[i+1];
            while(vh[mxd[i]]<=vh[i] && mxd[i]<n)
                mxd[i]=mxd[mxd[i]];
        }
    }
    for(int i=1;i<=n;++i)
    {
        start=mxs[i];
        finish=mxd[i];
        max1=-1;
        query(1,1,n);
        g<<max1<<'\n';
    }
    return 0;
}
