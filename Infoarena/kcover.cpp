#include<bits/stdc++.h>
using namespace std;
class InParser {
private:
	FILE *fin;
	char *buff;
	int sp;

	char read_ch() {
		++sp;
		if (sp == 4096) {
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
		return buff[sp];
	}

public:
	InParser(const char* nume) {
		fin = fopen(nume, "r");
		buff = new char[4096]();
		sp = 4095;
	}

	InParser& operator >> (int &n) {
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
}f("kcover.in");
ofstream g("kcover.out");
int t, n, k;
int v[100002];
long long dif[100002];
int main()
{
    f >> t;
    for(; t; --t)
    {
        f >> n >> k;
        for(int i = 1; i <= n; ++i)
            f >> v[i];
        sort(v+1, v+n+1);
        for(int i = 1; i < n; ++i)
            dif[i] = 0LL + v[i+1] - v[i];
        sort(dif + 1, dif + n);
        k = n-k;
        int pos = 1;
        long long sol = 0;
        while(k)
        {
            sol += dif[pos];
            --k;
            ++pos;
        }
        g << sol << '\n';
    }
    return 0;
}
