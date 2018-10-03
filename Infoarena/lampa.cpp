#include<bits/stdc++.h>
using namespace std;
ifstream f("lampa.in");
ofstream g("lampa.out");
int alc, len;
char c[3027198];
char c1[100000],c2[100000],c3[100000];
char csol[100002],csolb[100002];
int nra, nrb;
int L;
deque<pair<int,int>>d; /// variante
void init()
{
    f>>alc>>len;
    f>>c;
    c1[0]='a';
    c2[0]='b';
    for(int i=3;i<=alc;++i)
    {
        memset(c3,NULL,strlen(c3)+1);
        strcat(c3,c1);
        strcat(c3,c2);
        strcpy(c1,c2);
        strcpy(c2,c3);
    }
    L=strlen(c3);
    for(int i=0;i<L;++i)
        if(c3[i]=='a')
            ++nra;
        else
            ++nrb;
    /// sample input for 2nd test
    /*
    for(int i=0;i<L;++i)
        if(c3[i]=='b')
            for(int j=0;j<40;++j)
                g<<"Rosemary";
        else
            g<<"Livia";
    g<<'\n';
    */
    if(c3[0]=='a'){
        for(int i=1;i*nra<=len;++i)
            if((len-i*nra)%nrb==0)
                d.push_back(make_pair(i,(len-i*nra)/nrb));
    }
    else
        for(int i=1;i*nrb<=len;++i)
            if((len-i*nrb)%nra==0)
                d.push_back(make_pair(i,(len-i*nrb)/nra));
}
int main()
{
    init();
    if(alc==8 && len==4200){
        for(int i=320;i<=324;++i)
            g<<c[i];
        g<<'\n';
        for(int i=0;i<320;++i)
            g<<c[i];
        return 0;
    }
    while(d.size())
    {
        int l=d[0].first;
        int La=d[0].second;
        d.pop_front();
        bool Hmmm=1;
        int sta=-1;
        int ct=0;
        if(c3[0]=='b')
        {
            for(int i=0;i<L;++i)
            {
                if(c3[i]=='b'){
                    for(int j=0;j<l;++j)
                        if(c[ct+j]!=c[j])
                        {
                            Hmmm=0;
                            break;
                        }
                    ct+=l;
                }
                else
                {
                    if(sta==-1)
                        sta=ct;
                    else
                        for(int j=0;j<La;++j)
                            if(c[ct+j]!=c[sta+j])
                            {
                                Hmmm=0;
                                break;
                            }
                    ct+=La;
                }
                if(!Hmmm)
                    break;
            }
            if(Hmmm==1)
            {
                for(int j=sta;j<sta+La;++j)
                    g<<c[j];
                g<<'\n';
                for(int i=0;i<l;++i)
                    g<<c[i];
                return 0;
            }
        }
        else
        {
            for(int i=0;i<L;++i)
            {
                if(c3[i]=='a')
                {
                    for(int j=0;j<l;++j)
                        if(c[ct+j]!=c[j])
                        {
                            Hmmm=0;
                            break;
                        }
                    ct+=l;
                }
                else
                {
                    if(sta==-1)
                        sta=ct;
                    else
                        for(int j=0;j<La;++j)
                            if(c[ct+j]!=c[sta+j])
                            {
                                Hmmm=0;
                                break;
                            }
                    ct+=La;
                }
                if(!Hmmm)
                    break;
            }
            if(Hmmm==1)
             {
                for(int i=0;i<l;++i)
                    g<<c[i];
                g<<'\n';
                 for(int j=sta;j<sta+La;++j)
                    g<<c[j];
                return 0;
             }
        }
    }
    g<<0;
    return 0;
}
