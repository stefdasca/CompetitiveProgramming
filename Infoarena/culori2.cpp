/// #bettercoderthanshebeautiful
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
}f("culori2.in");
ofstream g("culori2.out");
int n,q,tq,a,b,qq,i,plm;
int c,d;
struct zz
{
    int len;
    unsigned char col,org;
};
zz v[524289];
int main()
{
    f>>n>>c>>q;
    v[0].len=n;
    v[0].col=c;
    for(i=1;i<=q;++i)
    {
        f>>tq;
        if(tq==0)
        {
            f>>a;
            g<<(int)v[a].col<<'\n';
        }
        if(tq==1)
        {
            f>>a;
            v[a].col=v[a].org;
            v[a].org=v[a+v[a].len].org;
            v[a].len+=v[a+v[a].len].len;
        }
        if(tq==2)
        {
            f>>a>>b>>c>>d;
            v[a+b].org=v[a].org;
            v[a].org=v[a].col;
            v[a].col=c,v[a+b].col=d;
            v[a+b].len=v[a].len-b;
            v[a].len=b;
        }
    }
    return 0;
}
