/*

    info1cup split : given a number n(n <= 1e18, it has even digits), split it in 2 halves
    
    The task is self explanatory, just implement what the statement says

*/ 
#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int>d;
    cin >> n;
    while(n)
    {
        d.push_front(n % 10);
        n /= 10;
    }
    for(int i = 0; i < d.size(); ++i)
    {
        cout << d[i];
        if(i + 1 == d.size() / 2)
            cout << " ";
    }
    return 0;
}
