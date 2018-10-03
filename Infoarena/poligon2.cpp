/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define eps 1e-3
using namespace std;
ifstream f("poligon2.in");
ofstream g("poligon2.out");
int n;
double xm[10002],ym[10002];
double xa[10002],ya[10002],Sx,Sy;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>xm[i]>>ym[i],Sx+=xm[i],Sy+=ym[i];
    if(n%2==1)
    {
        double Sp=0.0;
        for(int i=1;i<=n;i+=2)
            Sp+=xm[i];
        xa[1]=2.0000*Sp-Sx;
        bool ok=1;
        for(int i=1;i<=n;++i)
        {
            if(i<n)
                xa[i+1]=(2.0000*xm[i]-xa[i]);
            else
                if(abs(xa[n]+xa[1]-2.0000*xm[n])>eps)
                    ok=0;
        }
        Sp=0.0;
        for(int i=1;i<=n;i+=2)
            Sp+=ym[i];
        ya[1]=2.0000*Sp-Sy;
        for(int i=1;i<=n;++i)
        {
            if(i<n)
                ya[i+1]=(2.0000*ym[i]-ya[i]);
            else
                if(abs(ya[n]+ya[1]-2.0000*ym[n])>eps)
                    ok=0;
        }
        if(ok==0)
            g<<"fara solutie"<<'\n';
        else
            for(int i=1;i<=n;++i)
            {
                g<<fixed<<setprecision(6)<<xa[i]<<" ";
                g<<fixed<<setprecision(6)<<ya[i]<<'\n';
            }
    }
    else
    {
        bool ok=1;
        for(int i=1;i<n;++i)
            xa[i+1]=(2.0000*xm[i]-xa[i]);
        for(int i=1;i<n;++i)
            ya[i+1]=(2.0000*ym[i]-ya[i]);
        if(xa[1]+xa[n]!=2.0000*xm[n])
            xa[1]-=(2.0000*xm[n]-xa[1]-xa[n])/2;
        if(ya[1]+ya[n]!=2.0000*ym[n])
            ya[1]-=(2.0000*ym[n]-ya[1]-ya[n])/2;
        for(int i=1;i<n;++i)
            xa[i+1]=(2.0000*xm[i]-xa[i]);
        for(int i=1;i<n;++i)
            ya[i+1]=(2.0000*ym[i]-ya[i]);
        if(xa[1]+xa[n]!=2.0000*xm[n] || ya[1]+ya[n]!=2.0000*ym[n])
            g<<"fara solutie"<<'\n';
        else
        {
            for(int i=1;i<=n;++i)
            {
                g<<fixed<<setprecision(6)<<xa[i]<<" ";
                g<<fixed<<setprecision(6)<<ya[i]<<'\n';
            }
        }
    }
    return 0;
}
