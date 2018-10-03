/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("string.in");
ofstream g("string.out");
int n;
char c[500002];
bool ish[1000002];
int main()
{
    f>>n;
    f>>c+1;
    bool Hmmm=0; /// she is not happy yet;
    int L,nr;
    for(int i=1;;++i)
    {
        int Nr=0;
        memset(ish,0,(1<<i)+1);
        for(int j=1;j<=i;++j)
        {
            Nr<<=1;
            Nr+=(c[j]-'a');
        }
        ish[Nr]=1;
        for(int j=i+1;j<=n;++j)
        {
            if(Nr&(1<<(i-1)))
                Nr-=(1<<(i-1));
            Nr<<=1;
            Nr+=(c[j]-'a');
            ish[Nr]=1;
        }
        for(int j=0;j<=(1<<i)-1;++j)
            if(!ish[j])
            {
                L=i;
                nr=j;
                Hmmm=1;
                break;
            }
        if(Hmmm==1)
            break;
    }
    g<<L<<'\n';
    for(int i=L-1;i>=0;--i)
        if(nr&(1<<i))
            g<<"b";
        else
            g<<"a";
    return 0;
}
