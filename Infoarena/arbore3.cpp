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
}f("arbore3.in");
const int MAX=1e6+3;
ofstream g("arbore3.out");
int n,v[MAX],ss;
vector<int>Orez[MAX];
unordered_map<int,int>m;
long long sol;
inline void Read()
{
    f>>n>>ss;
    for(int i=1;i<=n;++i)
    {
        int a;
        f>>a>>v[i];
        Orez[a].push_back(i);
    }
}
inline void dfs(int nod, int s)
{
    m[s]++;
    if(m[s-ss])
        sol+=m[s-ss];
    for(int i=0;i<Orez[nod].size();++i){
        dfs(Orez[nod][i],s+v[Orez[nod][i]]);
        m[s+v[Orez[nod][i]]]--;
    }
}
int main()
{
    Read();
    m[0]=1;
    dfs(1,v[1]);
    g<<sol;
    return 0;
}
