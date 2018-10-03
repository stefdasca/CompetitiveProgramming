#include<bits/stdc++.h>
using namespace std;
ifstream f("editor.in");
ofstream g("editor.out");
int n;
char c1[60002],c2[60002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>c1;
        f.get();
        int l=strlen(c1)-1;
        int prd=0,pri=0,ppd=0,ppi=0;
        int q=0;
        for(int j=0;j<l;++j)
            if(c1[j]!='*')
                c2[q]=c1[j],++q;
            else
                if(q)
                    --q,c2[q]=NULL;
        int ok=1;
        for(int j=0;j<q;++j)
        {
            if(c2[j]=='(')
                ++prd;
            if(c2[j]=='[')
                ++ppd;
            if(c2[j]==']')
            {
                ++ppi;
                if(ppi>ppd)
                    ok=0;
            }
            if(c2[j]==')')
            {
                ++pri;
                if(pri>prd)
                    ok=0;
            }
        }
        if(ppi!=ppd || prd!=pri)
            ok=0;
        if(ok==1)
            g<<":)"<<'\n';
        else
            g<<":("<<'\n';
        c2[0]=NULL;
    }
    return 0;
}
