/*
    solution code by Stefan Dascalescu
    
    The main idea for this problem is to consider the fact that we only care about how many missing numbers we have as well as the frequency of each number. 

    After doing a bit of casework, we can observe that the number of operations required to bring the mex to i is the maximum between the frequency of values equal to i (we must make them different) and the number of gaps in the frequency array before i (we must add something there and we can use at first values equal to i).

    video link: https://www.youtube.com/watch?v=Fzu_FnM08Ow

*/

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n+1), fr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        fr[v[i]]++;
    }
    
    int missing = 0;
    for (int val = 0; val <= n; val++) {
        cout << max(missing, fr[val]) << '\n';
        if (fr[val] == 0) {
            missing++;
        }
    }
    return 0;
}
