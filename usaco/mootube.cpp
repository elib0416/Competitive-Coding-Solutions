#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    while (q--) {
        int k, v;
        cin >> k >> v;
        v--;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(v);
        visited[v] = true;
        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto P : graph[curr]) {
                if (!visited[P.first] && P.second >= k) {
                    visited[P.first] = true;
                    count++;
                    q.push(P.first);
                }
            }
        }
        cout << count << endl;
    }
}
