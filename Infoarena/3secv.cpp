#include<bits/stdc++.h>
using namespace std;
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
long long s[1000002],s1;
long long cmin,c1,c2,c;
int main()
{
    InParser f("3secv.in");
    ofstream g("3secv.out");
    f>>n;
    for(int i=1;i<=n;++i)
        f>>s[i],s[i]+=s[i-1];
    cmin=s[n];
    int b=2;
    int e=n-1;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(s[m]-s[1]<=s[n]-s[m] && s[m+1]-s[1]>s[n]-s[m+1])
        {
            long long max1=max(s[1],max(s[m]-s[1],s[n]-s[m]));
            long long min1=min(s[1],min(s[m]-s[1],s[n]-s[m]));
            if(max1-min1<cmin)
                cmin=max1-min1,c1=1,c2=m;
            max1=max(s[1],max(s[m+1]-s[1],s[n]-s[m+1]));
            min1=min(s[1],min(s[m+1]-s[1],s[n]-s[m+1]));
            if(max1-min1<cmin)
                cmin=max1-min1,c1=1,c2=m+1;
            break;
        }
        else
            if(s[m+1]-s[1]<=s[n]-s[m+1])
                b=m+1;
            else
                e=m-1;
    }
    int ca=c1;
    int cb=c2;
    while(cb<n)
    {
        ++ca;
        while(s[cb]-s[ca]<=s[n]-s[cb] && s[cb+1]-s[ca]<=s[n]-s[cb+1])
            ++cb;
        long long max1=max(s[ca],max(s[cb]-s[ca],s[n]-s[cb]));
        long long min1=min(s[ca],min(s[cb]-s[ca],s[n]-s[cb]));
        if(max1-min1<cmin)
            cmin=max1-min1,c1=ca,c2=cb;
        max1=max(s[ca],max(s[cb+1]-s[ca],s[n]-s[cb+1]));
        min1=min(s[ca],min(s[cb+1]-s[ca],s[n]-s[cb+1]));
        if(max1-min1<cmin)
            cmin=max1-min1,c1=ca,c2=cb+1;
    }
    g<<c1<<" "<<c2;
    return 0;
}
