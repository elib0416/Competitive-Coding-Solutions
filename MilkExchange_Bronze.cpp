#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<long long> a(n);
    long long total_milk = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_milk += a[i];
    }
    vector<int> loss;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R' && s[(i + 1) % n] == 'L') {
            loss.push_back(i);
        }
    }
    if (loss.empty()) {
        cout << total_milk << endl;
        return 0;
    }
    long long total_loss = 0;
    for (int i = 0; i < loss.size(); i++) {
        int r_sink = loss[i];
        int l_sink = (loss[i] + 1) % n;
        long long r_chain_sum = 0;
        int curr = (r_sink - 1 + n) % n;
        while (s[curr] == 'R' && curr != loss[(i - 1 + loss.size()) % loss.size()]) {
            r_chain_sum += a[curr];
            curr = (curr - 1 + n) % n;
        }
        total_loss += min(m, r_chain_sum);
        long long l_chain_sum = 0;
        curr = (l_sink + 1) % n;
        while (s[curr] == 'L' && curr != (loss[(i + 1) % loss.size()] + 1) % n) {
            l_chain_sum += a[curr];
            curr = (curr + 1) % n;
        }
        total_loss += min(m, l_chain_sum);
    }
    cout << total_milk - total_loss << endl;
    return 0;
}
