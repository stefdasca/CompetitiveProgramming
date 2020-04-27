/*
			COI 14-gta

	All the molecules belong to one of the 24 equivalence classes, based on what we can obtain 
by performing the algorithm.

	We can represent A, C, G, T as permutations which will help us generate the mutations.
	
    All we're left with is checking if the permutations are equivalent and print the adjacency matrix.
	
*/

#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

// #define fisier 1

using namespace std;

typedef long long ll;

const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;

map<char, vector<int>> mp = 
{
    {'A', {1, 0, 3, 4, 5, 6, 7, 2}},
    {'C', {2, 5, 6, 0, 7, 3, 1, 4}},
    {'G', {7, 4, 5, 1, 6, 2, 0, 3}},
    {'T', {4, 7, 1, 6, 2, 0, 3, 5}}
};
            
vector<int> compose(vector<int> a, vector<int> b) 
{
    vector<int> ans;
    for(int i = 0; i < 8; i++)
		ans.pb(b[a[i]]);
    return ans;
}

vector<int> perm[102];

int main() 
{
    
    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        string s;
        perm[i] = {0, 1, 2, 3, 4, 5, 6, 7};
        cin >> s;
        reverse(s.begin(), s.end());
        for(int x = 0; x < s.size(); ++x) 
		{
			char c = s[x];
			perm[i] = compose(perm[i], mp[c]);
		}
    }
    for(int i = 1; i <= n; cout << '\n', i++)
        for(int j = 1; j <= n; j++) 
			cout << (perm[i] == perm[j] ? 1 : 0);
    return 0;
}
