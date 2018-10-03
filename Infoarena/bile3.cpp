/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("bile3.in");
class OutParser {
private:
    FILE *fout;
    char *buff;
    int sp;

    void write_ch(char ch) {
        if (sp == 50000) {
            fwrite(buff, 1, 50000, fout);
            sp = 0;
            buff[sp++] = ch;
        } else {
            buff[sp++] = ch;
        }
    }


public:
    OutParser(const char* name) {
        fout = fopen(name, "w");
        buff = new char[50000]();
        sp = 0;
    }
    ~OutParser() {
        fwrite(buff, 1, sp, fout);
        fclose(fout);
    }

    OutParser& operator << (int vu32) {
        if (vu32 <= 9) {
            write_ch(vu32 + '0');
        } else {
            (*this) << (vu32 / 10);
            write_ch(vu32 % 10 + '0');
        }
        return *this;
    }

    OutParser& operator << (long long vu64) {
        if (vu64 <= 9) {
            write_ch(vu64 + '0');
        } else {
            (*this) << (vu64 / 10);
            write_ch(vu64 % 10 + '0');
        }
        return *this;
    }

    OutParser& operator << (char ch) {
        write_ch(ch);
        return *this;
    }
    OutParser& operator << (const char *ch) {
        while (*ch) {
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
}g("bile3.out");
int n,k;
bool prs[22];
int vv[22];
bitset<3000002>v;
long long hm=1;
int nr=0;
void init()
{
    f>>n>>k;
    for(int i=1;i<=k;++i){
        prs[i]=1;
        vv[i]=i;
        nr+=(1<<i);
    }
    v[nr]=1;
    for(int i=1;i<=k;++i)
        g<<i<<" ";
    g<<'\n';
    for(int j=k+1;j<=n;++j)
        hm=(hm*j);
    for(int j=2;j<=n-k;++j)
        hm/=j;
    --hm;
}
int main()
{
    init();
    while(hm)
    {
        bool ok=1;
        for(int j=k;j>=1;--j)
        {
            for(int q=1;q<=n;++q)
            {
                if(prs[q])
                    continue;
                if(!v[nr-(1<<vv[j])+(1<<q)])
                {
                    v[nr-(1<<vv[j])+(1<<q)]=1;
                    nr=nr-(1<<vv[j])+(1<<q);
                    prs[vv[j]]=0;
                    prs[q]=1;
                    vv[j]=q;
                    ok=0;
                    break;
                }
            }
            if(!ok)
                break;
        }
        sort(vv+1,vv+k+1);
        for(int i=1;i<=k;++i)
            g<<vv[i]<<" ";
        g<<'\n';
        --hm;
    }
    return 0;
}
