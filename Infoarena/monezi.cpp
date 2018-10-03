#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream f("monezi.in");
ofstream g("monezi.out");
int n,s,v1[20],v2[20];
bool pos[525];
int main()
{
    int sol=0;
    f>>n>>s;
    for(int i=1;i<=n;++i)
        f>>v1[i];
    sort(v1+1,v1+n+1);
    v1[n+1]=2949559;
    int comb=(1<<n)-1;
    while(comb)
    {
        ++v2[n];
        int z=n;
        while(v2[z]==2)
        {
            ++v2[z-1];
            v2[z]=0;
            --z;
        }
        pos[0]=1;
        for(int i=1;i<=s;++i)
            if(!pos[i])
                for(int j=1;i>=v1[j];++j)
                    if(v2[j])
                        if(pos[i-v1[j]]){
                            pos[i]=1;
                            ++sol;
                            break;
                        }
        memset(pos,0,s+2);
        --comb;
    }
    g<<sol;
    return 0;
}
