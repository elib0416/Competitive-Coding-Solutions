#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, happy;
};
const int MAXN = 100001;
int n, m;
string s;
vector<int> paths[MAXN];
int component[MAXN];
bool visited[MAXN];
void dfs(int u, int cmpid, char milk_type) {
    visited[u] = true;
    component[u] = cmpid;
    for (int v : paths[u]) {
        if (!visited[v] && s[v] == milk_type) {
            dfs(v, cmpid, milk_type);
        }
    }
}
int main() {
    int a, b;
    char c;
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    int cmpid = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, cmpid++, s[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        if (s[a] == c || s[b] == c || component[a] != component[b]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}
