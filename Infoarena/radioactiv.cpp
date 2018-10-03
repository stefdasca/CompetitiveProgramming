#include<bits/stdc++.h>
#define RoziIsLit 1e-3
using namespace std;
ifstream f("radioactiv.in");
ofstream g("radioactiv.out");
int n,k;
int matinit[552][552],refined[552][552],nr;
float ff;
inline void beginning()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>matinit[i][j];
    for(int i=1;i<=n+k;++i)
        for(int j=1;j<=n+k;++j)
            refined[i][j]=matinit[i][j]+refined[i-1][j]+refined[i][j-1]-refined[i-1][j-1];
}
inline int sum(int l,int c, int leng)
{
    return refined[l][c]-refined[l][max(0,c-2*leng-1)]-refined[max(0,l-2*leng-1)][c]+refined[max(0,l-2*leng-1)][max(0,c-2*leng-1)];
}
inline float findsum(int l, int c, int qq)
{
    int sum1=sum(l,c,qq);
    int sum2=0;
    if(qq)
        sum2=sum(l-1,c-1,qq-1);
    return ff*(sum1-sum2+0.0);
}
inline void finish()
{
    float summin=10000000.0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            float sum=0.0;
            ff=1.0;
            for(int qq=0;qq<k;++qq,ff-=1.0/k)
                sum+=findsum(i+qq,j+qq,qq);
            if(summin-sum>RoziIsLit)
                summin=sum,nr=1;
            else
                if(abs(sum-summin)<=RoziIsLit)
                    ++nr;
        }
    g<<nr;
}
int main()
{
    beginning();
    finish();
    return 0;
}
