/*
            POI 12-Salaries

    * We can assign extra wages if and only if the following condition is respected:
        - for every node i which is in the path except for the "root" of the path,
node i is the only uncolored child of the node situated right before it.

    * In order to check the unused labels, we are going to use a multiset which contains the labels not used yet.

    * We can check this property for every color which is already assigned from the input using a traversal, starting from that node.
If at some step we have only one uncolored child in the path, we are going to assign it to our path.
    - if at some step we have less labels than the size of the subtree of the "root" of our path, then we are going to label those nodes with the smallest
possible labels.
    - otherwise, we will add extra zeroes to match the number of labels with the size of the subtree of the "root" of our path.

    It can be proved using induction that this strategy is optimal and it also runs in O(n) or O(n log n), depending on the implementation.

*/
#include<bits/stdc++.h>
using namespace std;

int n, tt[1000002], cul[1000002], root, sz[1000002], gr[1000002], poz[1000002];
vector<int>arb[1000002];

multiset<int>nr;

void ss(int nod)
{
    sz[nod] = (cul[nod] == 0);
    for(int i = 0; i < arb[nod].size(); ++i)
    {
        int vecin = arb[nod][i];
        ss(vecin);
        if(cul[vecin] == 0)
            sz[nod] += sz[vecin];
        else
            --gr[nod];
    }
    poz[cul[nod]] = nod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        nr.insert(i);
    for(int i = 1; i <= n; ++i)
    {
        cin >> tt[i] >> cul[i];
        if(nr.find(cul[i]) != nr.end())
            nr.erase(cul[i]);
        if(tt[i] != i)
            arb[tt[i]].push_back(i), ++gr[tt[i]];
        else
            root = i, cul[root] = n;
    }
    ss(root);
    for(int i = 1; i <= n; ++i)
    {
        if(poz[i] && sz[poz[i]])
        {
            int nod = poz[i];
            deque<int> t, s;
            while(gr[nod] == 1)
            {
                for(int i = 0; i < arb[nod].size(); ++i)
                {
                    int vecin = arb[nod][i];
                    if(!cul[vecin])
                    {
                        t.push_back(vecin);
                        nod = vecin;
                        break;
                    }
                }
	    }
       	    while(!nr.empty() && *nr.begin() < i)
            {
		  s.push_front(*nr.begin());
                  nr.erase(nr.begin());
  	    }
	    if(s.size() <= sz[poz[i]])
		for (int j = 0; j < min(s.size(), t.size()); ++j)
		    cul[t[j]] = s[j];
	    else
		for (int j = 0; j + sz[poz[i]] < s.size(); ++j)
		     nr.insert(0);
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << cul[i] << '\n';
    return 0;
}
