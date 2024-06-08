#include <bits/stdc++.h>
using namespace std;

mt19937_64 rnd; // 64-bit 
long long val(bool positive)
{
	long long ans = rnd();
	if(positive)	
		return abs(ans);
	else
		return ans;
}

/*

	In this section of the code the input data must be added, be careful at the way the input data is described in the problem statement,
copies might be necessary sometimes 
	
*/

// Here you should generate the input data, for local testing I recommend small input data which makes testing your solution easier
void gentest()
{
	
}

// Here you should add a correct solution, often suboptimal, hence the brute force name
int bruteforce()
{
	
}

// Here you should add a fast solution which is incorrect, hence the efficient name
int efficient()
{
	
}

// In case you have different answers, this function will allow you to print the data fast
void printinput()
{
	
}

int main()
{	
	// seed is randomly chosen, makes rnd return different numbers every time
	int seed = std::random_device{}();
	rnd.seed(seed);
	
	int t = 0;
	while(t <= 10000)
	{
		gentest();
		int brute = bruteforce();
		int eff = efficient();
		if(brute != eff)
		{
			cout << "Brute: " << brute << '\n';
			cout << "Efficient: " << eff << '\n';
			printinput();
			return 0;
		}
	}
	return 0;
}
 
