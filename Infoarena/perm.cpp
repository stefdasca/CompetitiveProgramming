#include<iostream>
using namespace std;
int n,v[12];
int verif(int va,int k)
{
    for(int i=1;i<k;++i)
        if(v[i]==va)
            return 0;
    return 1;
}
void bkt(int k)
{
    if(k==n+1)
    {
        for(int i=1;i<=n;++i)
            cout<<v[i]<<" ";
        cout<<'\n';
    }
    else
        for(int i=1;i<=n;++i)
        {
            v[k]=i;
            if(verif(i,k))
                bkt(k+1);
        }
}
int main()
{
    cin>>n;
    bkt(1);
    return 0;
}
