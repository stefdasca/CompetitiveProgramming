/*

    If we concatenate the strings given in the input and then do the expansion, we can reduce the problem to finding the smallest period of 
the string.

    This can be done with KMP using prefix function, thus the answer will be (size of string - value of prefix function for the last character of the string).

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int adj[12][12];

int pi[1000002];
class RunningLetters
{
     public:
        int newsLength(vector<string> running)
        {
            string s;
            string x;
            for(int i = 0; i < running.size(); ++i)
                x += running[i];
            for(int j = 0; j < x.size();)
            {
                int nr = 0;
                while(x[j] >= '0' && x[j] <= '9')
                    nr = nr * 10 + (x[j] - '0'), ++j;
                while(x[j] == ' ')
                    ++j;
                string jj;
                while(x[j] >= 'a' && x[j] <= 'z')
                    jj += x[j], ++j;
                while(x[j] == ' ')
                    ++j;
                for(int pp = 1; pp <= nr; ++pp)
                    s += jj;
            }
            int k = 0;
            pi[0] = 0;
            for(int i = 1; i < s.size(); ++i)
            {
                while(k && s[i] != s[k])
                    k = pi[k - 1];
                if(s[i] == s[k])
                    ++k;
                pi[i] = k;
            }
            return s.size() - pi[s.size() - 1];
        }
};
