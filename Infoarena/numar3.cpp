#include<bits/stdc++.h>
using namespace std;
int n;
char c,a;
int la[12],pmare,nrpmic,nrpmare;
void rd()
{
    ifstream f("numar3.in");
    f>>n;
    f>>a;
    pmare=1;
    ++la[a-'0'];
    for(int i=2;i<=n;++i)
    {
        f>>c;
        if(c>a){
            pmare=i-1,nrpmare=c-'0',nrpmic=a-'0';
            for(int j=0;j<=9;++j)
                la[j]=0;
            la[c-'0']=1;
        }
        else
            la[c-'0']++;
        a=c;
    }
    f.close();
}
int main()
{
    rd();
    ifstream f("numar3.in");
    ofstream g("numar3.out");
    f>>n;
    for(int i=1;i<pmare;++i)
    {
        f>>c;
        g<<c;
    }
     for(int i = nrpmic+ 1; i <= 9 ; ++i)
        if(la[i] > 0){
            --la[i];
            g << i;
            break;
        }
    ++la[nrpmic];
    for(int i = 0; i <= 9 ; ++i)
        while(la[i] > 0)
            g<<i, --la[i];
    return 0;
}
