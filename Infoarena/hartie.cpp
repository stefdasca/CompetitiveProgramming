#include<bits/stdc++.h>
using namespace std;
ifstream f("hartie.in");
ofstream g("hartie.out");
int v[7],sol;
int q;
int main()
{
    while(f>>v[1]>>v[2]>>v[3]>>v[4]>>v[5]>>v[6])
    {
        ++q;
        sol+=v[6];
        v[6]=0;
        sol+=v[5];
        v[1]-=min(v[5]*11,v[1]);
        v[5]=0;
        sol+=v[4];
        int q=v[2];
        v[2]-=min(v[2],v[4]*5);
        if(v[2]==0 && q!=v[4]*5)
            v[1]-=min(v[4]*20-4*q,v[1]);
        v[4]=0;
        sol+=v[3]/4;
        v[3]%=4;
        if(v[3]!=0){
            ++sol;
            if(v[3]==1)
            {
                if(v[2]<=5)
                    v[1]-=min(v[1],27-4*v[2]),v[2]=0;
                else
                    v[1]-=min(v[1],7),v[2]-=5;
            }
            if(v[3]==2)
            {
                if(v[2]<=2)
                    v[1]-=min(v[1],18-4*v[2]),v[2]=0;
                else
                    v[1]-=min(v[1],6),v[2]-=3;
            }
            if(v[3]==3)
            {
                if(v[2]>=1)
                    v[1]-=min(v[1],5),--v[2];
                else
                    v[1]-=min(v[1],9);
            }
            v[3]=0;
        }
        sol+=v[2]/9;
        v[2]%=9;
        if(v[2]!=0)
        {
            ++sol;
            v[1]-=min(v[1],36-4*v[2]);
            v[2]=0;
        }
        sol+=v[1]/36;
        v[1]%=36;
        if(v[1])
            ++sol;
        v[1]=0;
        g<<sol<<'\n',sol=0;
        for(int i=1;i<=6;++i)
            v[i]=0;
    }
}
