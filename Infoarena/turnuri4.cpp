#include<bits/stdc++.h>
using namespace std;
ifstream f("turnuri4.in");
ofstream g("turnuri4.out");
int main()
{
    int n;
    f>>n;
    vector<int> V(n);
    for (int i = 0; i < n; ++i)
        f>>V[i];
    vector<int> left1(n, -1), left2(n, -1), right1(n, n), right2(n, n);
    vector<int> stack1;
    vector<int> stack2;
    for (int i = 0; i < n; ++i)
    {
        int from_erase = stack1.size();
        while (from_erase > 0 && V[stack1[from_erase - 1]] < V[i])
            --from_erase;
        while (!stack2.empty() && V[stack2.back()] < V[i]) {
            right2[stack2.back()] = i;
            stack2.pop_back();
        }
        if (!stack2.empty())
            left2[i] = stack2.back();
        if (from_erase > 1 && stack1[from_erase - 2] > left2[i])
            left2[i] = stack1[from_erase - 2];
        for (int j = from_erase; j < int(stack1.size()); ++j) {
            right1[stack1[j]] = i;
            stack2.push_back(stack1[j]);
        }
        stack1.resize(from_erase);
        if (!stack1.empty())
            left1[i] = stack1.back();
        stack1.push_back(i);
    }
    int64_t total = 0;
    for (int i = 0; i < n; ++i)
        total += right1[i] - left1[i] - 1;
    vector<int64_t> answer(n, total);
    for (int i = 0; i < n; ++i)
    {
        answer[i] -= right1[i] - left1[i] - 2;

        if (right1[i] != n)
            answer[right1[i]] += right2[i] - right1[i];
        if (left1[i] != -1)
            answer[left1[i]] += left1[i] - left2[i];
    }

    for (int i = 0; i < n; ++i)
        g << answer[i] << "\n";
    return 0;
}
