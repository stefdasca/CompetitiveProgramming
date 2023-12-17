/*
    
    another class: https://pastebin.com/ZAzTMTVV
    
*/

#include <bits/stdc++.h>
using namespace std;

class BigInteger
{
    private:
        int countDigits = 0;
        const int base = 100000000;
        const int pw = 8;
        vector<long long> number;
    public:
        void set(int sz)
        {
            number.resize(sz + 1);
        }
        int getdigits()
        {
            return countDigits;
        }
        void simpleInit(int val)
        {
            number.push_back(0);
            do
            {
                number.push_back(val % base);
                countDigits++;
                val /= base;
            }while(val);
        }
        void initString(string s)
        {
            int x = s.size() - 1;
            int nr = 0;
            int put = 1;
            int cnt = 0;
            number.push_back(0);
            while(x >= 0)
            {
                cnt++;
                nr += (s[x] - '0') * put;
                put *= 10;
                if(cnt == pw)
                {
                    number.push_back(nr);
                    nr = 0;
                    put = 1;
                    cnt = 0;
                }
                x--;
            }
            if(cnt > 0)
                number.push_back(nr);
            countDigits = number.size() - 1;
        }
        void initInt(vector<long long> v)
        {
            countDigits = v.size();
            number = v;
        }
        void add(BigInteger a)
        {
            if(a.countDigits > countDigits)
            {
                set(a.countDigits);
                countDigits = a.countDigits;
            }
            for(int i = 1; i <= a.countDigits; i++)
                number[i] += a.number[i];
            for(int i = 1; i <= countDigits; i++)
                if(number[i] >= base)
                {
                    if(i == countDigits)
                    {
                        number.push_back(1);
                        countDigits++;
                    }
                    else
                        number[i+1]++;
                    number[i] -= base;
                }
        }
        void subtract(BigInteger a) // assume number is still positive
        {
            for(int i = 1; i <= a.countDigits; i++)
                number[i] -= a.number[i];
            for(int i = countDigits; i >= 1; i--)
            {
                if(number[i] < 0)
                {
                    number[i] += base;
                    number[i+1]--;
                }
            }
            while(number[countDigits] == 0)
            {
                number.pop_back();
                countDigits--;
            }
        }
        void mult(int a)
        {
            long long val = 0;
            for(int i = 1; i <= countDigits; i++)
            {
                val += 1LL * number[i] * a;
                number[i] = val % base;
                val /= base;
            }
            while(val)
            {
                number.push_back(val % base);
                countDigits++;
                val /= base;
            }
        }
        void divide(int a)
        {
            long long val = 0;
            for(int i = countDigits; i >= 1; i--)
            {
                val = val * base + number[i];
                number[i] = val / a;
                val %= a;
            }
            
            while(number[countDigits] == 0)
            {
                number.pop_back();
                countDigits--;
            }
        }
        void multHuge(BigInteger a)
        {
            vector<long long> ans(countDigits + a.countDigits);
            for(int i = 1; i <= countDigits; i++)
                for(int j = 1; j <= a.countDigits; j++)
                    ans[i + j - 1] += 1LL * a.number[j] * number[i];
            countDigits += a.countDigits - 1;
            for(int i = 1; i <= countDigits; i++)
            {
                if(ans[i] >= base)
                {
                    if(i == countDigits)
                    {
                        ans.push_back(ans[i] / base);
                        countDigits++;
                    }
                    else
                        ans[i+1] += ans[i] / base;
                    ans[i] %= base;
                }
            }
            number = ans;
        }
        void print()
        {
            bool ok = 0;
            for(int i = countDigits; i >= 1; i--)
            {
                if(ok == 1)
                {
                    long long val = max(1LL, number[i]);                    
                    while(val * 10 < base)
                    {
                        cout << 0;
                        val *= 10;
                    }
                }
                if(number[i] != 0)
                    ok = 1;
                cout << number[i];
            }
        }
};

int main()
{
    int n, k;
    cin >> n >> k;
    
    BigInteger ans, ans2;
    
    ans.simpleInit(1);
    ans2.simpleInit(1);
    for(int i = 1; i <= n; i++)
        ans.mult(i);
    for(int i = n+1; i <= n + k - 1; i++)
        ans2.mult(i);
    ans.multHuge(ans2);
    for(int i = 1; i <= k - 1; i++)
        ans.divide(i);
    for(int i = 1; i <= n; i++)
        ans.divide(i);
    ans.print();
    
    return 0;
}

