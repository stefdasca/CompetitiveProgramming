#include<fstream>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
ifstream f("dir.in");
ofstream g("dir.out");
char c[1700];
int len;
struct sir
{
    char c[302];
    int ln;
};
sir v[102];
int sz;
deque<pair<int,int> >d;
void recind(int poz)
{
    while(poz!=len)
    {
        if(c[poz]>='A' && c[poz]<='Z')
        {
            int st=poz;
            int sf=poz;
            while(c[poz]!='(')
                ++sf,++poz;
            d.push_back(make_pair(st,sf-1));
        }
        else
            if(c[poz]>='a' && c[poz]<='z')
            {
                int st=poz;
                int sf=poz;
                while(c[poz]!=')' && c[poz]!=',')
                    ++sf,++poz;
                d.push_back(make_pair(st,sf-1));
                ++sz;
                for(int i=0;i<d.size();++i){
                    for(int j=d[i].first;j<=d[i].second;++j)
                        v[sz].c[v[sz].ln++]=c[j];
                    if(i!=d.size()-1)
                        v[sz].c[v[sz].ln++]=92;
                }
                d.pop_back();
            }
            else
            {
                if(c[poz]=='(')
                    ++poz;
                else
                    if(c[poz]==')')
                        ++poz,d.pop_back();
                    else
                        if(c[poz]==',')
                            ++poz;
            }
    }
}
bool test(sir a, sir b)
{
    return strcmp(a.c,b.c)<0;
}
int main()
{
    f>>c;
    len=strlen(c);
    recind(0);
    sort(v+1,v+sz+1,test);
    g<<sz<<'\n';
    for(int i=1;i<=sz;++i)
        g<<v[i].c<<'\n';
    return 0;
}
