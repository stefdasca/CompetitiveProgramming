/*
    This problem can be brute forced by counting the number of substrings of length 3 which respect the pattern and then add them in a set
    
    For each modification, all we have to do is to check the new frequencies and see if they could be added instead
    
    Keeping strings is doable using maps and sets

*/

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, f;
    cin >> n >> f;
    
    string s;
    cin >> s;
    
    map<string, int> frequencies;
    set<string> valid;
    
    // find the initial strings
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] != s[i+1] && s[i+1] == s[i+2]) {
            string moo; moo += s[i]; moo += s[i+1]; moo += s[i+2];
            frequencies[moo]++;
            if (frequencies[moo] >= f) {
                valid.insert(moo);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        // undo updates
        for (int start = i-2; start <= i; start++) {
            if (start < 0 || start + 2 >= n) {
                continue;
            }
            if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                string moo; moo += s[start]; moo += s[start+1]; moo += s[start+2];
                frequencies[moo]--;
            }
        }
        char orig = s[i];
        // try each new letter
        for (char letter = 'a'; letter <= 'z'; letter++) {
            s[i] = letter;
            for (int start = i-2; start <= i; start++) {
                if (start < 0 || start + 2 >= n) {
                    continue;
                }
                if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                    string moo; moo += s[start]; moo += s[start+1]; moo += s[start+2];
                    frequencies[moo]++;
                    if (frequencies[moo] >= f) {
                        valid.insert(moo);
                    }
                }
            }
            for (int start = i-2; start <= i; start++) {
                if (start < 0 || start + 2 >= n) {
                    continue;
                }
                if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                    string moo; moo += s[start]; moo += s[start+1]; moo += s[start+2];
                    frequencies[moo]--;
                }
            }
        }
        
        s[i] = orig;
        // redo updates
        for (int start = i-2; start <= i; start++) {
            if (start < 0 || start + 2 >= n) {
                continue;
            }
            if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                string moo; moo += s[start]; moo += s[start+1]; moo += s[start+2];
                frequencies[moo]++;
            }
        }
    }
    
    cout << (int) valid.size() << '\n';
    for (auto s : valid) {
        cout << s << '\n';
    }
    return 0;
}
