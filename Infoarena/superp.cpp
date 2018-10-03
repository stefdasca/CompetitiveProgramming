#include<bits/stdc++.h>
using namespace std;
ifstream f("superp.in");
ofstream g("superp.out");
int n;
long long nr;
deque<long long>pos;
int fr[12],fr2[12];
bool isPrime(long long pr)
{
    for(long long i=2;i*i<=pr;++i)
        if(pr%i==0)
            return 0;
    return 1;
}
void geninit()
{
    pos.push_back(2);
    pos.push_back(3);
    pos.push_back(5);
    pos.push_back(7);
    int poz=0;
    while(1)
    {
        if(pos[poz]*10+3>1e12 || pos[poz]==0)
            break;
        if(isPrime(pos[poz]*10+1))
            pos.push_back(pos[poz]*10+1);
        if(isPrime(pos[poz]*10+3))
            pos.push_back(pos[poz]*10+3);
        if(isPrime(pos[poz]*10+7))
            pos.push_back(pos[poz]*10+7);
        if(isPrime(pos[poz]*10+9))
            pos.push_back(pos[poz]*10+9);
        ++poz;
    }
}
int main()
{
    geninit();
    f>>n;
    for(;n;--n)
    {
        f>>nr;
        for(int i=0;i<=9;++i)
            fr[i]=0;
        while(nr)
        {
            fr[nr%10]++;
            nr/=10;
        }
        for(int j=pos.size()-1;j>=0;--j)
        {
            long long z=pos[j];
            for(int i=0;i<=9;++i)
                fr2[i]=0;
            while(z)
            {
                fr2[z%10]++;
                z/=10;
            }
            bool ok=1;
            for(int i=0;i<=9;++i)
                if(fr2[i]>fr[i])
                    ok=0;
            if(ok==1){
                g<<pos[j]<<'\n';
                break;
            }
        }
    }
}
