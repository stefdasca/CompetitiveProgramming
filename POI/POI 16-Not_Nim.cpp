/*
        POI 16-Not_Nim

    * Both Bytie and Bytone will use a greedy strategy. In order to simplify the game we are going to split the game in two simpler games
such that if we combine them, we will get the same result(the proof is too long to be posted here, one can find it in editorial)
        
    * In the first part of the game we can observe that for each number we are going to make its respective pair equal to 0 in 2 * log2(v[i]) + 4 moves.
    * In the second part of the game we are going to drop the extra moves which we are doing. In order to do this we are going to consider the number of leading 
ones in the binary representation of v[i] and add the result in a multiset in order to be able to simulate effectively the strategy used by both players. 
    * While we still have elements in multiset, if the biggest element in the multiset is bigger than 1, we are going to drop one from it, remove it from the multiset,
add it again and remove the biggest number again, thus marking the fact that both players have moved. Last but not least, we are going to drop 2 * number of ones left, because
removing a one takes 2 moves(Bytone will move the one and Bytie will remove it).
    * Since Bytie will always do the last move, we will subtract from the final answer one.

    detailed editorial: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/official/2016/editorial/wca.pdf

*/
#include<bits/stdc++.h>
using namespace std;

int n, v[500002];
int Log(int nr)
{
    if(nr == 1)
        return 0;
    return 1 + Log(nr / 2);
}
int LeadingOnes(int n)
{
    int ans = 0;
    for(int i = 29; i >= 0; i--)
    {
        if(((1<<i) & n) != 0)
            ans++;
        else
            if(ans > 0)
                break;
    }
    return ans;
}
multiset<int>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int ans = 4 * n - 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        ans += 2 * Log(v[i]);
        s.insert(-LeadingOnes(v[i]));
    }
    s.erase(s.begin());
    while(!s.empty())
    {
        int bst = *s.begin();
        if(bst == -1)
        {
            ans -= 2;
            s.erase(s.begin());
        }
        else
        {
            s.erase(s.begin());
            s.insert(bst + 1);
            s.erase(s.begin());
        }
    }
    cout << ans;
    return 0;
}
