/*
  For this problem you can use a stack to keep track of the nearest maximums, and at each step you remove smaller values than the current one.

  It is important to be careful about not counting maximums which are right next to the current value
*/

#include <fstream>
#include <stack>

using namespace std;

ifstream cin("nrpits.in");
ofstream cout("nrpits.out");

int v[1000000];
int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    long long ans = 0;
    
    stack<int> d;
    for(int i = 0; i < n; i++)
    {
        while(!d.empty() && v[i] > v[d.top()])
        {
            if(d.top() != i-1)
                ans++;
            d.pop();
        }
        if(!d.empty() && d.top() < i-1)
            ans++;
        d.push(i);
    }
    
    cout << ans << '\n';
    return 0;
}
