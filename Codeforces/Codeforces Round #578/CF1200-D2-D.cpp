#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

int n, k;
char mat[2002][2002];

int spL[2002], spLR[2002], spC[2002], spCR[2002];
int mxL[2002], mxLR[2002], mxC[2002], mxCR[2002];
int eligibil[2002][2002], eligibilC[2002][2002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> (mat[i] + 1);
    for(int i = 1; i <= n; ++i)
    {
        int cW = 0;
        for(int j = 1; j <= n; ++j)
            cW += (mat[i][j] == 'W');
        if(cW == n)
            cW = 1;
        else
            cW = 0;
        spL[i] = cW, spLR[i] = cW;
        spL[i] += spL[i-1];
    }
    for(int i = n; i >= 1; --i)
        spLR[i] += spLR[i+1];
    for(int i = 1; i <= n; ++i)
    {
        int cW = 0;
        for(int j = 1; j <= n; ++j)
            cW += (mat[j][i] == 'W');
        if(cW == n)
            cW = 1;
        else
            cW = 0;
        spC[i] = spC[i-1] + cW;
        spCR[i] = cW;
    }
    for(int i = n; i >= 1; --i)
        spCR[i] += spCR[i+1];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            if(mat[i][j] == 'W')
                mxL[i] = j;
            else
                break;
        mxLR[i] = n+1;
        for(int j = n; j >= 1; --j)
            if(mat[i][j] == 'W')
                mxLR[i] = j;
            else
                break;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            if(mat[j][i] == 'W')
                mxC[i] = j;
            else
                break;
        mxCR[i] = n+1;
        for(int j = n; j >= 1; --j)
            if(mat[j][i] == 'W')
                mxCR[i] = j;
            else
                break;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            eligibilC[i][j] = eligibilC[i-1][j];
            if(mxL[i] >= j-1 && j + k >= mxLR[i])
                eligibilC[i][j]++;
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            eligibil[i][j] = eligibil[i][j-1];
            if(mxC[j] >= i-1 && i + k >= mxCR[j])
                eligibil[i][j]++;
        }
    int max_answer = 0;
    for(int i = 1; i <= n - k + 1; ++i)
        for(int j = 1; j <= n - k + 1; ++j)
        {
            int answer = spL[i-1] + spLR[i + k] + spC[j - 1] + spCR[j + k];
            answer = answer + eligibil[i][j + k - 1] - eligibil[i][j - 1];
            answer = answer + eligibilC[i + k - 1][j] - eligibilC[i - 1][j];
            max_answer = max(max_answer, answer);
        }
    cout << max_answer;
    return 0;
}
