#include<bits/stdc++.h>
using namespace std;
int n,v[1002];
int a[1002][1002],q=1,p;
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
};
int main()
{
    ifstream f("sah.in");
    OutParser g("sah.out");
    f>>n;
    for(int i=1;i<=n;i+=2)
    {
        for(int j=1;j<=n-p;++j)
            a[j][i]=a[j][i+1]=q;
        ++q;
        if(p!=0)
        {
            for(int j=n-p+1;j<=n;++j)
                a[j][i]=a[j][i+1]=q;
            ++q;
        }
        ++p;
    }
    for(int i=1;i<=n;g<<'\n',++i)
        for(int j=1;j<=n;++j)
            g<<a[i][j]<<" ";
    return 0;
}
