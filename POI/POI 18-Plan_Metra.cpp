/*
        POI 18-Plan_Metra

    We can construct the tree if one of those two conditions applies here

    1. abs(a[i] - b[i]) is equal for all valid i => add edge between 1 and n with cost equal to abs(a[i] - b[i]), link other nodes to 1 or n based
on which of the two important buildings is closer

    2. distance from 1 to n is equal to min(a[i] + b[i]) among all valid i, so we can construct a tree as follows: we will have a path from 1 to n,
formed by nodes such that a[i] + b[i] = min(a[i] + b[i]), then we will link the other nodes to some node on the path.

    If none of these cases is valid, the answer is NO(proof is present in the Polish editorial)

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define int long long
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

int n, A[1000002], B[1000002];

map<int, vector<int> >rad;
map<int, int> noduri;
main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 2; i < n; ++i)
        cin >> A[i];
    int minim = (1LL<<60);
    for(int i = 2; i < n; ++i)
    {
        cin >> B[i];
        minim = min(minim, A[i] + B[i]);
    }
    bool ok = 1;
    for(int i = 3; i < n; ++i)
        if(abs(A[i] - B[i]) != abs(A[2] - B[2]))
            ok = 0;
    if(ok && B[2] != A[2])
    {
        cout << "TAK\n";
        cout << 1 << " " << n << " " << abs(B[2] - A[2]) << '\n';
        for(int i = 2; i < n; ++i)
            if(A[i] > B[i])
                cout << n << " " << i << " " << A[i] - abs(B[2] - A[2]) << '\n';
            else
                cout << 1 << " " << i << " " << B[i] - abs(B[2] - A[2]) << '\n';
        return 0;
    }
    B[1] = minim;
    noduri[minim] = 1;
    noduri[-minim] = n;
    for(int i = 2; i < n; ++i)
    {
        if(A[i] + B[i] == minim)
        {
            if(noduri.find(B[i] - A[i]) != noduri.end())
            {
                cout << "NIE\n";
                return 0;
            }
            noduri[B[i] - A[i]] = i;
        }
    }
    for(int i = 2; i < n; ++i)
    {
        if(A[i] + B[i] != minim)
        {
            if(noduri.find(B[i] - A[i]) == noduri.end())
            {
                cout << "NIE\n";
                return 0;
            }
            rad[B[i] - A[i]].pb(i);
        }
    }
    cout << "TAK\n";
    map<int, int> :: reverse_iterator it = noduri.rbegin();
    map<int, int> :: reverse_iterator it2 = noduri.rbegin();
    ++it2;
    while(it2 != noduri.rend())
    {
        cout << it -> se << " " << it2 -> se << " " << (it -> fi - it2 -> fi)/2 << '\n';
        it2++;
        it++;
    }
    for(map<int, vector<int> > ::iterator x = rad.begin(); x != rad.end(); ++x)
    {
        vector<int> af = x -> se;
        int val = x -> fi;
        for(int j = 0; j < af.size(); ++j)
            cout << noduri[val] << " " << af[j] << " " << B[af[j]] - B[noduri[val]] << '\n';
    }
    return 0;
}

