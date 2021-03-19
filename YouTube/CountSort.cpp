#include<bits/stdc++.h>
#define MAX 1000001 // numerele intre 0 si MAX-1

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n), v2(n);
	vector<int> fr(MAX, 0);
	
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		fr[v[i]]++;
	}
	
	int poz = 0;
	
	for(int i = 0; i < MAX; ++i)
		for(int j = 1; j <= fr[i]; ++j)
			v2[poz++] = i;
			
	for(int i = 0; i < n; ++i)
		cout << v2[i] << " ";
	return 0;
}
