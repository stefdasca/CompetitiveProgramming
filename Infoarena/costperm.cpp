#include<bits/stdc++.h>
using namespace std;
ifstream f("costperm.in");
ofstream g("costperm.out");
long long n, nr, prod,AIB[100002];
void s(int i){
     for(;i<=n;i+=(i&(-i)))
          AIB[i]++;
}
int calc(int i){
     int sum=0;
    for(;i;i-=(i&(-i)))
          sum+=AIB[i];
    return sum;
}
int main(){
      f>>n;
      for(int i=1;i<=n;++i)
     {
           f>>nr;
           prod+=nr*(calc(n)-calc(nr));
           s(nr);
     }
     g<<prod;
    return 0;
}
