// Only one person can stop me from coding(at least for a day)
// and that person is ... => i won't stop coding
#include<bits/stdc++.h>
using namespace std;
ifstream f("patrate6.in");
ofstream g("patrate6.out");
int n;
int v[100002];
deque<int>ar;
deque<int>fr;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    ar.push_back(v[n]);
    fr.push_back(1);
    --n;
    int sz=0;
    while(n)
    {
        if(v[n]==ar.back()){
            ++fr.back();
            while(fr.back()==4 && sz>=1)
            {
                ++ar.back();
                fr.back()=1;
                if(ar[sz]==ar[sz-1]){
                    fr[sz-1]++;
                    ar.pop_back();
                    fr.pop_back();
                    --sz;
                }
                else
                    break;
            }
            if(sz==0 && fr.back()==4)
                fr.back()=1,ar[0]++;
        }
        else
        {
            ar.push_back(v[n]);
            fr.push_back(1);
            ++sz;
        }
        --n;
    }
    if(sz>0 || sz==0 && fr[0]>1)
        g<<ar[0]+1;
    else
        g<<ar[0];
    return 0;
}
