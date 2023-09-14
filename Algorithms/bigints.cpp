#include <bits/stdc++.h>
 
using namespace std;
 
int baza = 10000000; // baza mai mare = mai putine cifre = calcule mai putine (atentie la overflow!)
 
int a[1002], b[1002]; 
 
// a[0] = nr cifre al lui a
// cifre inversate
 
int add()
{
	for(int i = 1; i <= max(a[0], b[0]); i++)
	{
		a[i] += b[i];
	}
 
	a[0] = b[0];
 
	for(int i = 1; i <= a[0]; i++)
	{
		if(a[i] >= baza)
		{
			a[i+1] += a[i] / baza;
			a[i] %= baza;
			if(i == a[0])
				a[0]++;
		}
	}
}
 
int multiply(int val)
{
	for(int i = 1; i <= max(a[0], b[0]); i++)
	{
		a[i] *= val;
	}
 
	for(int i = 1; i <= a[0]; i++)
	{
		if(a[i] >= baza)
		{
			a[i+1] += a[i] / baza;
			a[i] %= baza;
			if(i == a[0])
				a[0]++;
		}
	}
 
}
 
int divide(int val)
{
	int rest = 0;
 
	for(int i = a[0]; i >= 1; i--)
	{
		a[i] += rest;
		rest = a[i] % val;
		a[i] /= val;
		rest = rest * baza;
	}
 
}
 
int print()
{
	bool ok = 0;
	for(int i = a[0]; i >= 1; i--)
	{
		if(ok == 1)
		{
			int val = a[0];
			while(val * 10 < baza)
			{
				cout << 0;
				val *= 10;
			}
		}
		if(a[0] != 0)
			ok = 1;
		cout << a[i];
	}
}
 
int c[205];
 
void bigintmultiply()
{
	for(int i = 1; i <= a[0]; i++)
		for(int j = 1; j <= b[0]; j++)
			c[i+j] += a[i] * b[j];
	c[0] = a[0] + b[0];
 
	for(int i = 1; i <= c[0]; i++)
	{
		if(c[i] >= baza)
		{
			c[i+1] += c[i] / baza;
			c[i] %= baza;
			if(i == c[0])
				c[0]++;
		}
	}
}

int main()
{
 
}
