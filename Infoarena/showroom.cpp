/// even understanding girls
/// is easier than this
#include<bits/stdc++.h>
#define MOD 9001
#define nmax 550
using namespace std;
ifstream f("showroom.in");
ofstream g("showroom.out");
int n;
int A,R,K;
int nrd[nmax],nrm,vv[nmax],sz[nmax];
bool zz[nmax];
char c2[25];
char c3[3102];
struct chars
{
    vector<string>q;
};
chars v[nmax];
inline void first_cer()
{
    map<string,bool>m;
    int l;
    bool ok,ok2;
    for(int i=1;i<=n;++i)
        if(!zz[i])
         {
            l=0;
            zz[i]=1;
            ++nrm;
            for(int j=0;j<sz[i];++j)
                if(!m.count(v[i].q[j]))
                {
                    m[v[i].q[j]]=1;
                    ++l;
                }
            ok=1;
            while(ok)
            {
                ok=0;
                for(int j=i+1;j<=n;++j)
                    if(!zz[j])
                    {
                        ok2=0;
                        for(int qq=0;qq<sz[j];++qq)
                            if(m.count(v[j].q[qq])){
                                ok2=1;
                                break;
                            }
                        if(ok2)
                        {
                            zz[j]=1;
                            ok=1;
                            for(int qq=0;qq<sz[j];++qq)
                                if(!m.count(v[j].q[qq]))
                                    ++l,m[v[j].q[qq]]=1;
                        }
                    }
            }
            nrd[nrm]=l;
        }
    g<<nrm<<'\n';
}
inline long long pw(long long a, long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return ans;
}
inline void second_cer()
{
    long long prod=1;
    for(int i=1;i<=nrm;++i){
        if(i==1)
            vv[i]=A;
        else
            vv[i]=(vv[i-1]+R)%K;
        if(vv[i]>nrd[i])
            continue;
        long long ans1=1;
        long long ans2=1;
        long long ans3=1;
        long long j2;
        long long j;
        for(j=1;j<=nrd[i];++j){
            j2=j;
            while(j2%MOD==0)
                j2/=MOD;
            ans1=ans1*j2%MOD;
        }
        for(j=1;j<=nrd[i]-vv[i];++j){
            j2=j;
            while(j2%MOD==0)
                j2/=MOD;
            ans2=ans2*j2%MOD;
        }
        for(j=1;j<=vv[i];++j){
            j2=j;
            while(j2%MOD==0)
                j2/=MOD;
            ans3=ans3*j2%MOD;
        }
        prod=(((prod*ans1)%MOD*pw(ans2,MOD-2))%MOD*pw(ans3,MOD-2))%MOD;
    }
    g<<prod<<'\n';
}
int main()
{
    f>>n>>A>>R>>K;
    f.get();
    map<string,bool>m2;
    bool rep=0;
    for(int i=1;i<=n;++i){
        f.getline(c3,3100);
        int L=strlen(c3);
        int Lc=0;
        for(int j=0;j<L;++j)
            if(c3[j]!=' '){
                c2[Lc++]=c3[j];
                if(j+1==L || c3[j+1]==' '){
                    c2[Lc]=NULL;
                    if(!m2.count(c2))
                        m2[c2]=1;
                    else
                        rep=1;
                    v[i].q.push_back(c2);
                    ++sz[i];
                    Lc=0;
                }
            }
        Lc=0;
    }
    if(rep==0)
    {
        g<<n<<'\n';
        for(int i=1;i<=n;++i)
            nrd[i]=v[i].q.size();
        nrm=n;
    }
    else
        first_cer();
    second_cer();
    return 0;
}
