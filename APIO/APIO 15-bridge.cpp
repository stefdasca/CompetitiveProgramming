/*
		APIO 15-bridge

	Firstly, let's remove people who have to arrive to the same side, the distance can be easily found.

	Now, if k = 1, we can find the median point and place the bridge there.

	For k = 2, we need some further observations to do
		
		Firstly, each person is going to choose the bridge closer to median of the
two positions.
		
		We are going to sort the people by median value, and we can keep the median value updated using 
two priority queues.
		
		The only thing we're left with is computing the answers for prefix and suffix, which is not too hard. 
		
		The answer will therefore be the minimum value of sum of prefix[i] + suffix[i+1] for some i.

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

bool cmp(pair<int, int> a, pair<int, int> b) 
{ 
	return a.fi + a.se < b.fi + b.se; 
}

priority_queue<int> lpq;
priority_queue<int, vector<int>, greater<int>> rpq;
ll lsum, rsum;
ll ps[100001];

void add(int x) 
{
    int median = (lpq.size() ? lpq.top() : 1000000001);
    if(x <= median) 
    {
        lpq.push(x);
        lsum += x;
    } 
    else 
    {
        rpq.push(x);
        rsum += x;
    }
    if(rpq.size() + 1 < lpq.size()) 
    {
        int nxt = lpq.top();
        lpq.pop();
        rpq.push(nxt);
        lsum -= nxt;
        rsum += nxt;
    } 
    else 
		if(lpq.size() < rpq.size()) 
		{
			int nxt = rpq.top();
			rpq.pop();
			lpq.push(nxt);
			rsum -= nxt;
			lsum += nxt;
		}
}

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int k, n;
    ll ansa = 0;
    vector<pair<int, int>> v = {{0, 0}};
    cin >> k >> n;
    for(int i = 0; i < n; ++i)
    {
        char a, b;
        int x, y;
        cin >> a >> x >> b >> y;
        if(a == b) 
			ansa += abs(x - y);
        else 
			v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    n = v.size() - 1;
    ansa += n;
    lsum = rsum = 0; 
    for(int i = 1; i <= n; ++i)
    {
        add(v[i].fi);
        add(v[i].se);
        ps[i] = rsum - lsum;
    }
    ll ansb = ps[n];
    if(k == 2) 
    {
        while(lpq.size()) 
			lpq.pop();
        while(rpq.size()) 
			rpq.pop();
        lsum = rsum = 0;
        for(int i = n; i >= 1; i--) 
        {
            add(v[i].fi);
            add(v[i].se);
            ansb = min(ansb, rsum - lsum + ps[i - 1]);
        }
    }
    cout << ansa + ansb;
    return 0;
}
