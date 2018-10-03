#include<bits/stdc++.h>
using namespace std;
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
int t,l;
unsigned long long n;
int sol[5001][3];
int sol1=0;
int main()
{
    ifstream f("nodiv.in");
    OutParser g("nodiv.out");
    f>>t;
    for(;t;--t)
    {
        f>>n;
        sol1=0;
        int put=0;
        while(n)
        {
            ++sol1;
            while(!(n&1))
                ++put,n>>=1;
            int put1=0;
            if(n){
                unsigned long long prd=1;
                while(prd*3<=n)
                    prd*=3,++put1;
                n-=prd;
            }
            sol[sol1][1]=put;
            sol[sol1][2]=put1;
        }
        g<<sol1<<" ";
        for(int i=1;i<=sol1;++i)
            g<<sol[i][1]<<" "<<sol[i][2]<<" ";
        g<<'\n';
    }
    return 0;
}
