#include<bits/stdc++.h>
using namespace std;
int getMinimumDelay(int N, std::vector<int> X, std::vector<int> Y)
{
  int mini = X[0];
  int maxi = X[0];
  for(int i = 1; i < N; ++i)
    mini = min(mini, X[i]), maxi = max(maxi, X[i]);
  if(mini == maxi)
  {
      sort(Y.begin(), Y.end());
      int sol = 2000000000;
      for(int i = 0; i < N; ++i)
      {
          int a, b;
          a = Y[i] - Y[0];
          if(i == N-1)
             b = 0;
          else
             b = Y[N-1] - Y[i+1];
          sol = min(sol, max(a, b));
      }
      return sol;
  }

  int b = 0;
  int e = 2000000000;
  int sol = e;
  vector<int>v[2002];
  int col[2002];
  bool viz[2002];
  while(b <= e)
  {
      int mid = b + (e-b)/2;
      for(int i = 0; i < N; ++i)
         v[i].clear();
      for(int i = 0; i < N; ++i)
          for(int j = 0; j < N; ++j)
             if(abs(X[i] - X[j]) + abs(Y[i] - Y[j]) > mid)
                v[i].push_back(j);
      memset(col, 0, sizeof(col));
      memset(viz, 0, sizeof(viz));
      deque<int>d;
      bool good = 1;
      for(int i = 0; i < N; ++i)
      {
          if(!viz[i])
          {
              d.push_back(i);
              viz[i] = 1;
              col[i] = 1;
              while(!d.empty())
              {
                  int va = d[0];
                  d.pop_front();
                  for(int aa = 0; aa < v[va].size(); ++aa)
                  {
                      int nod = v[va][aa];
                      if(!viz[nod])
                      {
                          viz[nod] = 1;
                          col[nod] = 3 - col[va];
                          d.push_back(nod);
                      }
                      else
                         if(col[nod] == col[va])
                            good = 0;
                  }
              }
          }
      }
      if(good == 0)
        b = mid + 1;
      else
        sol = mid, e = mid - 1;
  }
  return sol;
}
/*
int main()
{
    int n;
    vector<int>a;
    vector<int>b;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int nr;
        cin >> nr;
        a.push_back(nr);
    }
    for(int i = 0; i < n; ++i)
    {
        int nr;
        cin >> nr;
        b.push_back(nr);
    }
    cout << getMinimumDelay(n, a, b);
    return 0;
}
*/
