#include <bits/stdc++.h>
using namespace std;
struct Event {
    long long x;
    long long ds;
};
bool compare(Event e1, Event e2) {
    return e1.x < e2.x;
}
int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int n;
    cin >> n;
    long long cost = 0;
    vector<Event> events;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        long long walk = llabs(a - b);
        long long basecost = llabs(a);
        cost += walk;
        long long d = walk - basecost;
        if (d < 0){
            continue;
        }
        events.push_back({b - d, -1});
        events.push_back({b, +2});
        events.push_back({b + d, -1});
    }
    sort(events.begin(), events.end(), compare);
    long long curs = 0;
    long long curcost = cost;
    long long ans = cost;
    long long prevx = events[0].x;
    for (int i = 0; i < static_cast<int>(events.size()); i++) {
        long long x = events[i].x;
        curcost += curs * (x - prevx);
        ans = min(ans, curcost);
        while (i < (int)events.size() && events[i].x == x) {
            curs += events[i].ds;
            i++;
        }
        i--;
        prevx = x;
    }
    cout << ans << "\n";
}
