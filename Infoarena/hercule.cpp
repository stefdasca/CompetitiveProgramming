#include<bits/stdc++.h>
using namespace std;
ifstream f("hercule.in");
ofstream g("hercule.out");
int t;
int n;
int v2[100002],i;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        if (n==3 || n==5 || n==6 || n==9 || n==10)
            g<<-1<<'\n';
        else
        {
            int nrc=1,p2=1;
            i=0;
            while(nrc<n)
            {
                if(nrc+p2<=n)
                    v2[++i]=p2;
                else
                    v2[++i]=n-nrc;
                nrc+=p2;
                p2*=2;
            }
            bool ok=0;
            for(int j=1;j<i;++j)
                if(v2[j]==v2[i]){
                    ok=1;
                    break;
                }
            if(ok)
            {
                int i3=i-1;
                do{
                    ++v2[i];
                    if(v2[i3]==v2[i3-1])
                        --i3;
                    --v2[i3];
                    ok=0;
                    for(int j=1;j<i;++j)
                        if(v2[j]==v2[i]){
                            ok=1;
                            break;
                        }
                }while(ok);
            }
            g<<i<<'\n';
            for(int j=1;j<=i;++j)
                g<<v2[j]<<" ";
            g<<'\n';
        }
    }
    return 0;
}
