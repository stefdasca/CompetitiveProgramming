#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, q;
string S;
long long sol[202];
vector<int>A;
long long countAt(int K)
{
    if (K == 0)
        return 1;
    if (S.size() == K)
        return 1;
    int N = S.size();
    if (K == 1)
    {
        set<int> included;
        for (int i=0; i<N; i++)
            included.insert(S[i] - 'a');
        return included.size();
    }
    vector<long long> vec1(N), vec2(N), vec3(26);
    for (int i=0; i<N; i++)
    {
        vec1[i] = 0;
        vec2[i] = 0;
    }
    for (int i=0; i<26; i++)
        vec3[i] = 0;
    vec2[N-1] = 1;
    vec3[S[N-1] - 'a'] = 1;
    for (int i = N-1-1; i >= 0; i--)
    {
        vec2[i] = vec2[i+1];
        if (vec3[S[i] - 'a'] == 0)
        {
            vec2[i]++;
            vec3[S[i] - 'a'] = 1;
        }
    }
    for (int i=1; i<K; i++)
    {
        fill(vec3.begin(), vec3.end(), 0);
        vec1[N-1] = 0;
        for (int i = n-1-1; i >= 0; i--)
        {
            vec1[i] = vec1[i+1];
            vec1[i] += vec2[i+1];
            vec1[i] -= vec3[S[i] - 'a'];
            vec3[S[i] - 'a'] = vec2[i+1];
        }
        for (int i=0; i<n; i++)
            vec2[i] = vec1[i];
    }
    return vec1[0];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    cin >> S;
    long long ans = 0;
    for(long long i = n; i >= 0; --i)
    {
        if(countAt(i) >= q)
        {
            ans += q * (n - i);
            q = 0;
            break;
        }
        else
            ans += countAt(i) * (n - i), q -= countAt(i);
    }
    if(q)
        cout << -1;
    else
        cout << ans;
    return 0;
}
