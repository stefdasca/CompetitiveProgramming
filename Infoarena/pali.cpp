#include<fstream>
#include<cstring>
using namespace std;
ifstream f("pali.in");
ofstream g("pali.out");
int sol;
char c1[5002];
int pmin[5002];
int main()
{
    f>>c1+1;
    int n=strlen(c1+1);
    for(int i=1;i<=n;++i)
        pmin[i]=1e9;
    for(int i=1;i<=n;++i)
    {
        int p=0;
        while(c1[i-p]==c1[i+p])
        {
            pmin[i+p]=min(pmin[i+p],pmin[i-p-1]+1);
            ++p;
            if(i==p || i+p>n)
                break;
        }
        p=0;
        while(c1[i-p]==c1[i+p+1])
        {
            pmin[i+p+1]=min(pmin[i+p+1],pmin[i-p-1]+1);
            ++p;
            if(i==p || i+p+1>n)
                break;
        }
    }
    g<<pmin[strlen(c1+1)];
    return 0;
}
