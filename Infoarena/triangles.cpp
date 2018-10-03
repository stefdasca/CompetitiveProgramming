#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("triangles.in");
ofstream g("triangles.out");
int n,k;
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
struct lat
{
    int nr,pos;
};
lat v[2000002];
bool test(lat a, lat b)
{
    return a.nr<b.nr;
}
int cs,ce;
int main()
{
    InParser f("triangles.in");
    f>>n>>k;
    n=min(n,150000);
    for(int i=1;i<=n;++i)
        f>>v[i].nr,v[i].pos=i;
    sort(v+1,v+n+1,test);
    int cs=0;
    int ce=0;
    for(int i=k;i<=n;++i)
        if(v[i].nr<=v[i-k+1].nr+v[i-k+2].nr)
        {
            cs=i-k+1;
            ce=i;
            break;
        }
    for(int i=cs;i<=ce;++i)
        g<<v[i].pos<<" ";
    return 0;
}
