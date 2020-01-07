#include "Brunolib.h"
#include <bits/stdc++.h>
using namespace std;

void Bruno(int K, int S, int F, int L, int P[], int Q[])
{

	int hasAns = 0;
	for(int i = 0;i < L; i++)
    {
		int vecin = P[i];
		int sum = (S < vecin) + (F > 0) + (Q[i] > 0);
		if(sum % 2 == 1)
		{
			hasAns = 1;
			Answer(vecin);
		}
	}
	if(!hasAns)
        Answer(S);

}
