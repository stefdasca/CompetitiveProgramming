#include<bits/stdc++.h>
#define Nmax 26
#define LgMax 252
using namespace std;
ifstream fin("apel.in");
ofstream g("apel.out");
int v[Nmax],ar[Nmax];
char f[Nmax][LgMax],s[LgMax];
void Citire()
{   char lin[LgMax],*p;
    fin.getline(s,LgMax);
    while(fin.getline(lin,LgMax))
    {   if('a'<=lin[0] and lin[0]<='z') v[lin[0]-'a']=atoi(lin+2);
        else{   p=strchr(lin,'='); strcpy(f[lin[0]-'A'],p+1);
                ar[lin[0]-'A']=1; p=strchr(lin,',');
                while (p) {ar[lin[0]-'A']++; p=strchr(p+1,',');}
            }
    }
}
int expresie(int &, int, int []);
int factor(int& poz, int nr, int x[])
{   int fc;
    if(f[nr][poz]=='(') {poz++; fc=expresie(poz,nr,x); poz++;}
    else  if(f[nr][poz]>='0' and f[nr][poz]<='9') fc=f[nr][poz++]-'0'; else fc=x[f[nr][poz++]-'a'];
    return fc;
}
int termen(int& poz, int nr, int x[])
{   int fc=factor(poz,nr,x);
    while(f[nr][poz] and f[nr][poz]=='*') {poz++; fc*=factor(poz,nr,x);}
    return fc;
}
int  expresie(int& poz, int nr, int x[])
{   char op;
    int t=termen(poz,nr,x);
    while(f[nr][poz] and (f[nr][poz]=='+'||f[nr][poz]=='-'))
    {   op=f[nr][poz]; poz++;
        if(op=='+') t+=termen(poz,nr,x); else t-=termen(poz,nr,x);
    }
    return t;
}
int eval(char *s)
{   int poz=0,i=0,nr=s[0]-'A',nrp,x[10];
    char *p,*q;
    s[strlen(s)-1]=','; q=s+2; p=strchr(q,',');
    while(p)
    {   if(q[0]>='0' and q[0]<='9') x[i++]=q[0]-'0';
        else if(q[0]>='a' and q[0]<='z') x[i++]=v[q[0]-'a'];
                else
                {   nrp=1; p=q+2;
                    while(nrp)
                    {   if(*p=='(') nrp++; else if(*p==')') nrp--;
                        p++;
                    }
                    *p=0; x[i++]=eval(q);
                }
        q=p+1; p=strchr(q,',');
    }
    return expresie(poz,nr,x);
}
int main ()
{   Citire();
    g<<eval(s)<<'\n';
    return 0;
}
