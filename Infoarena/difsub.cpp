#include<fstream>
#include<cmath>
using namespace std;
ifstream f("difsub.in");
ofstream g("difsub.out");
int val[1002];
int st[1002],dr[1002];
int dad[1002];
int a,b,n;
int s[3];
void desc(int tata,int p)
{
    if(dad[tata]==0){
        if(st[tata])
            desc(st[tata],0);
        if(dr[tata])
            desc(dr[tata],1);
    }
    else{
        s[p]+=val[tata];
        if(st[tata])
            desc(st[tata],p);
        if(dr[tata])
            desc(dr[tata],p);
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i){
        f>>val[i]>>st[i]>>dr[i];
        if(st[i])
            dad[st[i]]=i;
        if(dr[i])
            dad[dr[i]]=i;
    }
    int nr=0;
    for(int i=1;i<=n;++i)
        if(dad[i]==0)
        {
            nr=i;
            break;
        }
    desc(nr,0);
    g<<abs(s[0]-s[1]);
    return 0;
}
