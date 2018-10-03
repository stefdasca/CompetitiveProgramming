#include<fstream>
using namespace std;
ifstream f("ordine.in");
ofstream g("ordine.out");
char j,c,ant=0,s[1000003];
int n,i,ok,ap[123];
int main()
{
    f>>s;
    for(n=0;s[n];++n)
        ++ap[s[n]];
    for(i=0;i<n;++i)
    {
        for(ok=1,j='a';j<='z'&&ok;++j)
            if(ap[j]==(n-i)/2+1){
                c=j;
                ok=0;
            }
        for(j='a';j<='z'&&ok;++j)
            if(ap[j]&&j!=ant){
                c=j;
                ok=0;
            }
        g<<c;
        --ap[c];
        ant=c;
    }
    g<<'\n';
    return 0;
}
