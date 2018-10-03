#include<fstream>
using namespace std;
ifstream f ("piata.in");
ofstream g ("piata.out");
long long n,i,xm,ym,xt,yt;
int a[40010];
long long s,nr;
int sumac(int x){
    int suma=0;
    while(x>0){
        suma=suma+x%10;
        x/=10;
    }
    return suma;
}
int main()
{
    f>>n;
    f>>xm>>ym>>xt>>yt;
    for(i=1;i<=n;i++){
        nr=i;
        a[i]=sumac(nr);
    }
    a[0]=a[n];
    for(i=ym;i<=yt;i++){
        int nr=(n+i-xm+1)%n;
        s=s+a[nr];
    }
    long long su=s;
    for(i=xm+1;i<=xt;i++){
        s=s-a[(n+yt-i+2)%n]+a[(n+ym-i+1)%n];
        su=su+s;
    }
    g<<su;
}
