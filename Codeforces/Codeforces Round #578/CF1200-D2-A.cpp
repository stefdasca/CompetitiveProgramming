#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
bool v[11];
int n;
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--)
    {
        char x;
        cin>>x;
        if(x=='L')
        {
            for(int i=0; i<=9; i++)
                if(!v[i])
                {
                    v[i]=1;
                    break;
                }
        }
        if(x== 'R' )
        {
            for(int i=9; i>=0; i--)
                if(!v[i])
                {
                    v[i]=1;
                    break;

                }

        }
        if('0'<= x and x <='9')
            v[x-'0']=0;
    }
    for(int i=0; i<=9; i++)
        cout<<v[i];
    return 0;
}
