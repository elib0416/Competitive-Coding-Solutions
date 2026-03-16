#include <bits/stdc++.h>
using namespace std;
struct cow {
    long long int x, y;
};
int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n, false);
    long long int ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        queue<int> q;
        q.push(i);
        visited[i] = true;
        long long int minX = cows[i].x, maxX = cows[i].x;
        long long int minY = cows[i].y, maxY = cows[i].y;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int e : adj[current]) {
                if (!visited[e]) {
                    visited[e] = true;
                    q.push(e);
                    minX = min(minX, cows[e].x);
                    maxX = max(maxX, cows[e].x);
                    minY = min(minY, cows[e].y);
                    maxY = max(maxY, cows[e].y);
                }
            }
        }
        long long int perimeter = 2 * ((maxX - minX) + (maxY - minY));
        ans = min(ans, perimeter);
    }

    cout << ans;
}
