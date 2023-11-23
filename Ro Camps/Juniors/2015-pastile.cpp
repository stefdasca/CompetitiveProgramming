/*
    
    if a new pill is equivalent to an open bracket and a half used pill is equivalent to a closed bracket, the answer is then the nth catalan number
    
    working with base = 10^8 might be required
    
    in addition, finding the prime factors is required too for further optimization
    
*/

#include <iostream>
#include <fstream>

using namespace std;

long long frq[100002], a[100002], baza = 100000000;

int prim[100002];

void multiply(long long val)
{
	for(int i = 1; i <= a[0]; i++)
		a[i] *= val;
 
	for(int i = 1; i <= a[0]; i++)
		if(a[i] >= baza)
		{
			a[i+1] += a[i] / baza;
			a[i] %= baza;
			if(i == a[0])
				a[0]++;
		}
}
 
void divide(long long val)
{
	long long rest = 0;
	for(int i = a[0]; i >= 1; i--)
	{
		a[i] += rest;
		rest = a[i] % val;
		a[i] /= val;
		rest = rest * baza;
	}

	while(a[a[0]] == 0 && a[0] > 1)
		a[0]--;
}
int main()
{
    ifstream cin("pastile.in");
    ofstream cout("pastile.out");
    
    for(int i = 2; i <= 100000; i++)
        if(prim[i] == 0)
            for(int j = i; j <= 100000; j += i)
                prim[j] = i;
    int n;
    cin >> n;
    
    a[0] = a[1] = 1;
    for(int i = n+2; i <= n+n; i++)
    {
        int x = i;
        while(x > 1)
        {
            frq[prim[x]]++;
            x /= prim[x];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int x = i;
        while(x > 1)
        {
            frq[prim[x]]--;
            x /= prim[x];
        }
    }
    
    for(int i = 2; i <= 100000; i++)
    {
        long long x = 1;
        while(frq[i])
        {
            x *= i;
            if(x * i > baza)
            {
                multiply(x);
                x = 1;
            }
            frq[i]--;
        }
        if(x > 1)
            multiply(x);
    }
    
    for(int i = a[0]; i >= 1; i--)
    {
        int pp = a[i];
        if(i < a[0])
        {
            while(pp * 10 < baza)
                cout << 0, pp *= 10;
        }
        cout << a[i];
    }
    return 0;
}
