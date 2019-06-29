#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cin >> s;
  sort(s.begin(), s.end());
  	if(s[0] == s[1] && s[2] == s[3] && s[1] != s[2])
      	cout << "Yes";
  else
    cout << "No";
    return 0;
}
