#include<fstream>
#include<cstring>
using namespace std;
ifstream f("pufu.in");
ofstream g("pufu.out");
int t,n;
char ch[12];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        int a=0;
        int b=0;
        int c=0;
        for(;n;--n)
        {
            f>>ch;
            if(ch[strlen(ch)-1]=='a')
                ++a;
            else
                if(ch[strlen(ch)-1]=='l')
                    ++b;
                else
                    ++c;
        }
        g<<a<<" "<<b<<" "<<c<<'\n';
    }
    return 0;
}
