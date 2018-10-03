#include<bits/stdc++.h>
using namespace std;
ifstream f("secventa.in");
ofstream g("secventa.out");
int n,k,x,sol,ok;
deque<int>w;
int maxm=-40000,st,sf;
int v[500001];
char s[3500001];
int main()
{
    f>>n>>k;
    f.get();
    f.get(s,3500001,'\n');
    int p=1,semn,st,fi,l=strlen(s);
    for(int i=0;i<l;i++)
    {
        semn=1;
        if(s[i]=='-')
            {semn=0;
             i++;}
            while(s[i]>='0'&&s[i]<='9')
            {
                v[p]=v[p]*10+s[i]-'0';
                i++;
            }
            if(semn==0)
                v[p]=-v[p];
            p++;
    }
    for(int i=1;i<=n;++i)
    {

        while(  w.empty() == 0 && v[w.back()] > v[i] ){
            w.pop_back();
         }
         w.push_back(i);
         if( w.front()<= i - k ){
            w.pop_front();
         }
        if( ok == 0 && w.back() >= k){
            maxm = v[w.front()];
            st= i - k + 1;
            sf = i;
            ok =1;
        }
         if( v[w.front()] > maxm && w.back() >= k){
            maxm = v[w.front()];
            st = i - k + 1;
            sf = i;
         }
    }
    g<<st<<" "<<sf<<" "<<maxm;
    return 0;
}
