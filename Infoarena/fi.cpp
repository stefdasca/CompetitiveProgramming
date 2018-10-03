#include<fstream>
using namespace std;
ifstream f("fi.in"); ofstream g("fi.out");
int m,n,a,b,c,d,tf,p,k,nrmaxLC,nrpLC,ok=1;
int Stanga()
{   c=a;
    if(p<=b) {d=b-p+1; tf=p;}
        else if(p<2*b) {d=p-b+1; tf=b;} else d=tf=p-b+1;
    return 0;
}
int Completa()
{   int nrlin=p/(3*k+1);
    c=a+nrlin; b+=nrlin*k; p-=nrlin*(3*k+1); tf+=nrlin*(2*k+1);
    if(p==0) {c--; d=b;}
        else if(p<=k+1)  {d=b-p+1; tf+=p;}
                else if(p<=2*k+1) {d=b-2*k+p-1; tf+=k+1;}
                        else {d=b+p-2*k-1; tf+=p-k;};
    return 0;
}
int Dreapta()
{   c=a; d=b;
    if(p<=k+1) {d=b-p+1; tf+=p;}
        else if(p<=2*k+1) {d=b-2*k+p-1; tf+=k+1;}
                else {d=b+p-2*k-1; tf+=p-k;};
    return 0;
}
void NumaiStanga()
{   int nrlin=p/(2*k+1);
    c=a+nrlin; tf+=nrlin*(k+1); p-=nrlin*(2*k+1);
    if(p==0) {c=c-1; d=n;}
        else if (p<=k+1) {d=b-p+1; tf+=p;}
                else {d=b+p-2*k-1;tf+=k+1;};
}
int main()
{   f>>m>>n>>k>>p>>a>>b;
    if(b<k+1)
        if(p<=2*b+k-1) ok=Stanga();
                else {tf=b+k; p-=2*b+k-1; a++; b+=k;};
    if(ok)
    {   nrmaxLC=(n-b)/k; nrpLC=nrmaxLC*(3*k+1);
        if(p<=nrpLC) ok=Completa();
            else {p-=nrpLC; tf+=nrmaxLC*(2*k+1); a+=nrmaxLC; b+=nrmaxLC*k;};
    }
    if(ok)
    {   if(b<n)
            if(p<=2*k+n-b+1) ok=Dreapta();
            else {p-=1+2*k+n-b; tf+=k+n-b+1; a++; b=n;};
    }
    if(ok) NumaiStanga();
    g<<c<<' '<<d<<'\n'<<tf<<'\n';
    return 0;
}
