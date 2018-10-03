#include<bits/stdc++.h>
using namespace std;
ifstream f("magic.in");
ofstream g("magic.out");
int l[6], c[6], p[7];
char s[14][7];
int t, n, mn;
int lb[7], dl;
int rnr;
char rs[102];
bool cmp(int a, int b){
  if(l[a] < l[b])
    return 1;
  return 0;
}
inline char cmp2(){
  int i, j;
  for(i = 0; i < 2 * n; i++){
    for(j = 0; j < n; j++){
      if(rs[i * n + j] > s[i][j])
        return 1;
      if(rs[i * n + j] < s[i][j])
        return 0;
    }
  }
  return 0;
}
inline char cmp1(char *s1, char *s2){
  int i;
  for(i = 0; i < n; i++){
    if(s1[i] < s2[i])
      return 1;
    if(s2[i] < s1[i])
      return 0;
  }
  return 0;
}
inline void add(){
  rnr++;
  if(cmp2()){
    int i, j;
    for(i = 0; i < 2 * n; i++)
      for(j = 0; j < n; j++)
        rs[i * n + j] = s[i][j];
  }
}
inline char verif(){
  int i, j, x;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      x = (lb[i] & (1 << (n - j - 1))) != 0 ? 1 : 0;
      s[l[p[i]]][j] = x;
      s[c[j]][p[i]] = x;
    }
  }
  for(i = 0; i < 2 * n - 1; i++)
    if(!cmp1(s[i], s[i + 1]))
      return 0;
  return 1;
}
void pick(int x, int k){
  if(k == 0){
    if(verif())
      add();
  }
  else{
    for(; x < (1 << n); x++){
      lb[dl++] = x;
      pick(x + 1, k - 1);
      dl--;
    }
  }
}
int main(){
  int i;
  f>>t>>n;
  mn = (1 << n);
  for(i = 0; i < n; i++){
    f>>l[i];
    l[i]--;
    p[i] = i;
  }
  for(i = 0; i < n; i++){
    f>>c[i];
    c[i]--;
  }
  for(i = 0; i < n * n; i++)
    rs[i] = 1;
  sort(p, p + n, cmp);
  pick(0, n);
  if(t == 1)
    g<<rnr;
  else
    for(i = 0; i < 2 * n * n; i++)
       if(rs[i]==0)
            g<<1;
       else
            g<<9;
  return 0;
}
