#include<bits/stdc++.h>
using namespace std;
ifstream f("domino2.in");
ofstream g("domino2.out");
int n;
void solve(int n)
{
  if(n == 3)
    g<<1<<" "<<1<<'\n';
  g<<1<<" "<<n<<'\n';
  g<<n<<" "<<n<<'\n';
  g<<n<<" "<<n-1<<'\n';
  g<<n-1<<" "<<n-1<<'\n';
  for(int i=2;i<n-2;i+=2)
  {
    g<<n-1<<" "<<i<<'\n';
    g<<i<<" "<<n<<'\n';
    g<<n<<" "<<i+1<<'\n';
    g<<i+1<<" "<<n-1<<'\n';
  }
  g<<n - 1<<" "<<1<<'\n';
  if(n>3)
    solve(n - 2);
}
int main()
{
  f>>n;
  if(n==2)
  {
    g<<1<<" "<<1<<'\n';
    g<<1<<" "<<2<<'\n';
    g<<2<<" "<<2<<'\n';
    return 0;
  }
  if(n%2==0)
  {
    g<<-1<<" ";
    return 0;
  }
  solve(n);
  return 0;
}
