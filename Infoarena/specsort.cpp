#include<bits/stdc++.h>
using namespace std;
ifstream f("specsort.in");
ofstream g("specsort.out");
int n;
int arr[50002],arr2[50002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>arr[i];
    for(int i=1;i<=n;i<<=1)
    {
        int sz=0;
        for(int j=1;j<=n;++j)
            if(!(arr[j]&i))
                arr2[++sz]=arr[j];
        for(int j=1;j<=n;++j)
            if((arr[j]&i))
                arr2[++sz]=arr[j];
        for(int j=1;j<=n;++j)
            g<<arr2[j]<<" ",arr[j]=arr2[j];
        g<<'\n';
    }
    return 0;
}
