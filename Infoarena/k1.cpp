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
}f("k1.in");
ofstream g("k1.out");
int n;
long long nr,sol,a,b;
map<long long,int>m;
map<long long,int> ::iterator it;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        m[nr]++;
    }
    long long trs=0;
    for(it=m.begin();it!=m.end();++it)
    {
       // g<<trs<<" "<<it->first<<" "<<it->second<<'\n';
        if(trs)
        {
            sol+=trs+(it->first);
            m[trs+(it->first)]++;
            trs=0;
            --(it->second);
        }
        sol+=(it->second)/2*((it->first)*2);
        if(it->second>=2)
            m[2*(it->first)]+=(it->second)/2;
        (it->second)%=2;
        if(it->second)
            trs=it->first;
    }
    g<<sol;
    return 0;
}
