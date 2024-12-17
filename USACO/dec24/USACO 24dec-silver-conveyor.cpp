#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1'000;
const int NDIR = 4;
const int DLIN[NDIR] = {-1, 0, 1, 0};
const int DCOL[NDIR] = {0, 1, 0, -1};
const int MAXQ = 200'000;
const int MAXVAL = MAXN * MAXN;
const int CH_DIR[NDIR] = {'U', 'R', 'D', 'L'};

int idx[MAXN + 2][MAXN + 2], lin[MAXQ], col[MAXQ], answer, qanswer[MAXQ];
int viz[MAXVAL + 1], isquery[MAXN + 1][MAXN + 1];
char change[MAXQ];
vector<int> g[MAXVAL + 1];
queue<int> q;

void addEdge(int a, int b) {
    if(viz[b]) {
        if(!viz[a]) {
            q.push(a);
            viz[a] = 1;
            answer--;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(int i = 0; i < (int)g[node].size(); i++) {
                    if(!viz[g[node][i]]) {
                        viz[g[node][i]] = 1;
                        answer--;
                        q.push(g[node][i]);
                    }
                }
                g[node].clear();
            }
        }
    } else {
        g[b].push_back(a);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    int ptr = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            idx[i][j] = ++ptr;
        }
    }
    
    answer = n * n;
    viz[0] = 1;
    for(int i = 0; i < q; i++) {
        char ch;
        cin >> lin[i] >> col[i] >> ch;
        for(int dir = 0; dir < NDIR; dir++) {
            if(ch == CH_DIR[dir]) {
                change[i] = dir;
            }
        }
        isquery[lin[i]][col[i]] = 1;
        
        int newlin = lin[i] + DLIN[change[i]], newcol = col[i] + DCOL[change[i]];
        addEdge(idx[lin[i]][col[i]], idx[newlin][newcol]);
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!isquery[i][j]) {
                for(int dir = 0; dir < NDIR; dir++) {
                    int newlin = i + DLIN[dir], newcol = j + DCOL[dir];
                    addEdge(idx[i][j], idx[newlin][newcol]);
                }
            }
        }
    }
    
    for(int i = q - 1; i >= 0; i--) {
        qanswer[i] = answer;
        for(int dir = 0; dir < NDIR; dir++) {
            if(change[i] != dir) {
                int newlin = lin[i] + DLIN[dir], newcol = col[i] + DCOL[dir];
                addEdge(idx[lin[i]][col[i]], idx[newlin][newcol]);
            }
        }
    }
    
    for(int i = 0; i < q; i++) {
        cout << qanswer[i] << "\n";
    }
    
    return 0;
}