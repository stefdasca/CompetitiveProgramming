#include<bits/stdc++.h>
using namespace std;
ifstream f("numere9.in");
ofstream g("numere9.out");
int t;
long long nr;
int v[15];
void cs(int a,int cz)
{
    if(a==1){
        if(cz==3)
            g<<"o ";
        if(cz==1)
            g<<"unu ";
        if(cz==22)
            g<<"un";
    }
    if(a==2){
        if(cz==22)
            g<<"doi";
        if(cz==21)
            g<<"doua";
        if(cz==3)
            g<<"doua ";
        if(cz==1)
            g<<"doi ";
    }
    if(a==3){
        g<<"trei";
        if(cz==3 || cz==1)
            g<<" ";
    }
    if(a==4){
        if(cz==22)
            g<<"pai";
        if(cz==3 || cz==1)
            g<<"patru ";
        if(cz==21)
            g<<"patru";
    }
    if(a==5){
        if(cz==22 || cz==21)
            g<<"cinci";
        if(cz==3 || cz==1)
            g<<"cinci ";
    }
    if(a==6){
        if(cz==21 || cz==22)
            g<<"sai";
        if(cz==3 || cz==1)
            g<<"sase ";
    }
    if(a==7){
        if(cz==21 || cz==22)
            g<<"sapte";
        if(cz==3 || cz==1)
            g<<"sapte ";
    }
    if(a==8){
        if(cz==21 || cz==22)
            g<<"opt";
        if(cz==3 || cz==1)
            g<<"opt ";
    }
    if(a==9){
        if(cz==21 || cz==22)
            g<<"noua";
        if(cz==3 || cz==1)
            g<<"noua ";
    }
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>nr;
        int l=0;
        while(nr)
        {
            v[++l]=nr%10;
            nr/=10;
        }
        reverse(v+1,v+l+1);
        int l1=l;
        nr=1;
        while(l1>3)
            l1-=3,nr*=1000;
        for(;l1<=l;l1+=3,nr/=1000)
        {
            int p=0;
            for(int i=max(l1-2,1);i<=l1;++i)
                p=p*10+v[i];
            if(p>99)
            {
                cs(p/100,3);
                if(p/100==1)
                    g<<"suta ";
                else
                    g<<"sute ";
            }
            if(p%100>9)
            {
                if(p%100==10)
                    g<<"zece ";
                else
                    if(p%100<20){
                        if(l-l1)
                            if((p%100)%10==2)
                                g<<"doua";
                            else
                                cs((p%100)%10,22);
                        else
                            cs((p%100)%10,22);
                        g<<"sprezece ";
                    }
                    else{
                        cs((p%100)/10,21);
                        g<<"zeci ";
                    }
            }
            if(p%100>=20 && p%10>0){
                g<<"si ";
                if(p%10==2 && l-l1)
                    g<<"doua ";
                else
                    cs(p%10,1);
            }
            if(p%100<10){
                if(l-l1==3)
                    {
                        if(p==1)
                            g<<"o ";
                        else
                            if(p%10==1)
                                g<<"unu ";
                        if(p%10==2)
                            g<<"doua ";
                        if(p%10>=3)
                            cs(p%10,1);
                    }
                else
                    if(l-l1>=6)
                    {
                        if(p==1)
                            g<<"un ";
                        else
                            if(p%10==1)
                                g<<"unu ";
                        if(p%10==2)
                            g<<"doua ";
                        if(p%10>=3)
                            cs(p%10,1);
                    }
                else
                    cs(p%10,1);
            }
            if(p%100>=20 || p>=100)
                if(l1!=l)
                g<<"de ";
            if(nr==1000000000  && p>0)
                if(p==1)
                    g<<"miliard ";
                else
                    g<<"miliarde ";
            if(nr==1000 && p>0)
                if(p==1)
                    g<<"mie ";
                else
                    g<<"mii ";
            if(nr==1000000  && p>0)
                if(p==1)
                    g<<"milion ";
                else
                    g<<"milioane ";
        }
        g<<'\n';
    }
    return 0;
}
