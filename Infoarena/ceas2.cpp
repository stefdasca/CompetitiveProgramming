#include<bits/stdc++.h>
using namespace std;
ifstream f("ceas2.in");
ofstream g("ceas2.out");
char c1[100002],c2[100002];
struct op
{
    char c1,c2;
};
op v[200002];
int q;
int z[30];
bool test(op a, op b)
{
    return a.c1<b.c1;
}
int main()
{
    f>>c1>>c2;
    int l=strlen(c1);
    for(int i=0;i<=29;++i)
        z[i]=-2;
    for(int i=0;i<l;++i)
        if(z[c1[i]-'a']==-2)
            if(c1[i]==c2[i]);
            else{
                z[c1[i]-'a']=c2[i]-'a';
                ++q;
                v[q].c1=c1[i];
                v[q].c2=c2[i];
            }
        else
        {
            char c='a'+z[c1[i]-'a'];
            if(c==c2[i]);
            else
            {
                g<<"NU";
                return 0;
            }
        }
    sort(v+1,v+q+1,test);
    g<<"DA"<<'\n';
    for(int i=1;i<=q;++i)
        g<<v[i].c1<<" "<<v[i].c2<<'\n';
    return 0;
}
