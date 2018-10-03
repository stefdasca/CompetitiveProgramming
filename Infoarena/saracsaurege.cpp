#include<bits/stdc++.h>
#define N 50010
using namespace std;
int arb[4*N+66],i,j,m,max1,st,dr,mij,pos,x,start,finish,cd,a,b,n;
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
int Maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
void update(int nod,int st,int dr)
{
    if(st==dr)
    {
        arb[nod]=x;
        return;
    }
    int mij=(st+dr)/2;
    if(pos<=mij)
        update(2*nod,st,mij);
    else
        update(2*nod+1,mij+1,dr);
    arb[nod]=Maxim(arb[2*nod],arb[2*nod+1]);
}
void query(int nod,int st,int dr)
{
    if(start<=st && dr<=finish)
    {
        if(max1<arb[nod])
            max1=arb[nod];
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
    InParser f("saracsaurege.in");
    ofstream g("saracsaurege.out");
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>x;
        pos=i;
        update(1,1,n);
    }
    for(i=1;i<=m;i++)
    {
        f>>a>>b;
        max1=-1;
        start=a;
        finish=b;
        query(1,1,n);
        g<<max1<<"\n";
    }
    return 0;
}
