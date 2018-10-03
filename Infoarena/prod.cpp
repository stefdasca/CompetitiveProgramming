#include<bits/stdc++.h>
using namespace std;
ifstream f("prod.in");
ofstream g("prod.out");
int v[12];
deque<int>q1;
deque<int>q2;
int l1,l2;
int prd[1204];
int pr2[602],pr3[602];
int main()
{
    for(int i=1;i<=9;++i)
        f>>v[i];
    for(int i=9;i>=1;--i)
        for(;v[i];--v[i])
        {
            if(l1==l2){
                for(int a=0;a<l1;++a)
                    pr2[a]=i*q1[a];
                for(int a=0;a<l2;++a)
                    pr3[a]=i*q2[a];
                int cmp=0;
                for(int a=l1;a>=0 && !cmp;--a)
                    if(pr3[a]>pr2[a])
                        cmp=1;
                    else
                        if(pr3[a]<pr2[a])
                            cmp=-1;
                if(cmp>=0)
                    q1.push_front(i),++l1;
                else
                    q2.push_front(i),++l2;
            }
            else
                if(l1>l2)
                    q2.push_front(i),++l2;
                else
                    q1.push_front(i),++l1;
        }
    for(int i=0;i<l1;++i)
        for(int j=0;j<l2;++j)
            prd[i+j]+=q1[i]*q2[j];
    int s=l1+l2;
    for(int i=0;i<=s;++i)
    {
        if(prd[i]>9)
        {
            prd[i+1]+=prd[i]/10;
            prd[i]%=10;
            if(prd[s+1])
                ++s;
        }
    }
    while(prd[s]==0)
        --s;
    for(int i=s;i>=0;--i)
        g<<prd[i];
}
