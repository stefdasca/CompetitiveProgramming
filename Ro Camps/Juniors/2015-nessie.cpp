/*

    The main idea is to find for each position from 1 to n the smallest starting position of an interval which still contains i
as well as the largest starting position of an interval which ends before i.

    Now let's define dp[i] as the maximum number of times the monster can get out of the water. Based on the previoux precomputation, 
if mini[i] >= maxi[i], we can now have a for loop that takes the maximum among every position which corresponds to what we're looking for. But this is too slow.

    The next step is to further optimize this recurrence. An intermediate step would be to run a data structure such as a segment tree and this would reduce the complexity to O(n log n) but now
we can use the fact that these arrays are increasing which allow us to use a deque to compute the answers.
    
    Therefore, the final complexity is O(n)
*/

#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int n, t;

int dp[250001];
int maxi[250002], mini[250002];

int main()
{
	ifstream cin("nessie.in");
	ofstream cout("nessie.out");
    cin >> n >> t;
    
    for(int i = 0; i <= n+1; i++)
        mini[i] = n+1;
    for(int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        maxi[y + 1] = max(maxi[y + 1], x);
        mini[y] = min(mini[y], x);
    }
    
    for(int i = 1; i <= n; i++)
        maxi[i] = max(maxi[i-1], maxi[i]);
    for(int i = n; i >= 0; i--)
        mini[i] = min(mini[i+1], mini[i]);
        
    int last_added = 1;
    
    deque<int> d;
    for(int i = 1; i <= n; i++)
    {
        int mn = max(1, maxi[i]);
        int mx = min(mini[i] - 1, i-1);
        if(mn > mx)
            dp[i] = -(1<<20);
        else
        {
            while(last_added <= mx)
            {
                while(!d.empty() && dp[d.back()] <= dp[last_added])
                    d.pop_back();
                d.push_back(last_added);
                last_added++;
            }
            while(!d.empty() && d.front() < mn)
                d.pop_front();
            if(!d.empty())
                dp[i] = 1 + max(dp[d.front()], 0);
        }
    }
    
    if(dp[n] < 0)
        cout << "IMPOSIBIL";
    else
        cout << dp[n] + 1;
    return 0;
}
