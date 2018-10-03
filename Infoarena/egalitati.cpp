#include<bits/stdc++.h>
using namespace std;
ifstream f("egalitati.in");
ofstream g("egalitati.out");
char c[100002];
bool ok=1;
int p;
int main()
{
    f.get(c,100001);
    int N=strlen(c);
    for(int i=0;i<N;++i)
        if(c[i]==';' || c[i]=='.'){
            if(ok==1 && p!=0)
                ok=0;
            g<<ok<<'\n',p=0,ok=1;
        }
        else
            if(c[i]=='(')
               ++p;
            else
                if(c[i]==')')
                {
                    --p;
                    if(p<0)
                        ok=0;
                }
                else
                    if(c[i]=='='){
                        if(p!=0)
                            ok=0;
                        p=0;
                    }
    return 0;
}
