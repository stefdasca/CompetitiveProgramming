#include<bits/stdc++.h>
using namespace std;
ifstream f("zone2.in");
ofstream g("zone2.out");
int n,m,k;
vector<int>v[90002];
vector<int>mrkd[90002];
int sz[100002];
int vec[100002];
int Smax=0;
unordered_map<int,int>s;
unordered_map<int,int> ::iterator it;
char c[302][302];
bool viz[302][302];
int nrz;
int belong[302][302];
struct coada
{
    int l,c;
};
coada v2[90002];
bool taken[90002];
deque<int>d;
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
unordered_map<int,int>el;
bool isinq[90002];
bool gut(int i, int j)
{
    if(i>n || i<1)
        return 0;
    if(j>m || j<1)
        return 0;
    return 1;
}
void lee1()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!viz[i][j])
            {
                nrz++;
                int st=1;
                int dr=1;
                v2[dr]={i,j};
                viz[i][j]=1;
                while(st<=dr)
                {
                    int X=v2[st].l;
                    int Y=v2[st].c;
                    for(int p=0;p<=3;++p)
                        if(!viz[X+ox[p]][Y+oy[p]] && gut(X+ox[p],Y+oy[p]) && c[X+ox[p]][Y+oy[p]]==c[i][j])
                        {
                            viz[X+ox[p]][Y+oy[p]]=1;
                            v2[++dr]={X+ox[p],Y+oy[p]};
                        }
                    ++st;
                }
                Smax=max(Smax,dr);
                sz[nrz]=dr;
                for(int p=1;p<=dr;++p)
                    belong[v2[p].l][v2[p].c]=nrz;
            }
    memset(viz,0,sizeof(viz));
}
void lee2()
{
    nrz=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!viz[i][j])
            {
                nrz++;
                s.clear();
                int st=1;
                int dr=1;
                v2[dr]={i,j};
                viz[i][j]=1;
                while(st<=dr)
                {
                    int X=v2[st].l;
                    int Y=v2[st].c;
                    for(int p=0;p<=3;++p)
                        if(!viz[X+ox[p]][Y+oy[p]] && gut(X+ox[p],Y+oy[p]) && c[X+ox[p]][Y+oy[p]]==c[i][j])
                        {
                            viz[X+ox[p]][Y+oy[p]]=1;
                            v2[++dr]={X+ox[p],Y+oy[p]};
                        }
                    ++st;
                }
                for(int p=1;p<=dr;++p)
                    for(int z=0;z<=3;++z)
                    {
                        int X=v2[p].l+ox[z];
                        int Y=v2[p].c+oy[z];
                        if(belong[X][Y]==nrz)
                            continue;
                        if(gut(X,Y) && !s[belong[X][Y]])
                            s[belong[X][Y]]=1;
                    }
                for(it=s.begin();it!=s.end();++it)
                    v[nrz].push_back(it->first),mrkd[nrz].push_back(0);
            }
    for(int i=1;i<=nrz;++i)
        vec[i]=v[i].size();
}
void solve()
{
    for(int i=1;i<=nrz;++i)
        d.push_back(i),isinq[i]=1;
    while(d.size())
    {
        bool ok=0;
        do{
            int z=d.size();
            ok=0;
            for(int j=0;j<z;++j)
            {
                int pr=d.front();
                for(int q=0;q<v[pr].size();++q)
                    if(!mrkd[pr][q])
                    {
                        if(!el[v[pr][q]])
                            continue;
                        --vec[pr];
                        mrkd[pr][q]=1;
                    }
                if(vec[pr]>=k)
                    d.push_back(pr);
                else
                    if(!el[pr])
                        el[pr]=1,ok=1;
                d.pop_front();
            }
        }while(ok);
        if(!d.size())
            break;
        int zz=d.size();
        for(it=el.begin();it!=el.end();++it)
            if(!isinq[it->first]){
                d.push_back(it->first);
                isinq[it->first]=1;
            }
        el.clear();
        int ss=0;
        for(int i=0;i<zz;++i)
            ss+=sz[d[i]];
        Smax=max(Smax,ss);
        while(zz){
            el[d.front()]=1;
            isinq[d.front()]=0;
            d.pop_front();
            --zz;
        }
        for(int i=0;i<d.size();++i){
            int pr=d[i];
            for(int q=0;q<v[pr].size();++q)
                if(!mrkd[pr][q])
                {
                    if(el[v[pr][q]])
                        --vec[pr];
                    mrkd[pr][q]=1;
                }
        }
        el.clear();
    }
    g<<Smax<<'\n';
}
int main()
{
    f>>n>>m>>k;
    for(int i=1;i<=n;++i)
        f>>c[i]+1;
    lee1();
    lee2();
    solve();
    return 0;
}
