#include <bits/stdc++.h>
using namespace std;
struct page {
    int day, cow, change;
};
bool compare(const page &a, const page &b) {
    return a.day < b.day;
}
unordered_map<int, int> milk;
priority_queue<int> pq;

int query_max() {
    while (!pq.empty()) {
        if (milk.count(pq.top())) {
            return pq.top();
        }
        pq.pop();
    }
    return -1;
}
int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<page> book(n);
    map<int, int> cows;
    for (page &p : book) {
        cin >> p.day >> p.cow >> p.change;
        cows[p.cow] = m;
    }
    sort(book.begin(), book.end(), compare);
    milk[m] = n;
    pq.push(m);
    int change = 0;
    for (page l : book) {
        int milk_amt = cows[l.cow];
        int curmax = query_max();
        bool was_top = (milk_amt == curmax);
        int prev_count = milk[milk_amt];
        milk[milk_amt]--;
        if (milk[milk_amt] == 0) {
            milk.erase(milk_amt);
        }
        milk_amt += l.change;
        cows[l.cow] = milk_amt;
        milk[milk_amt]++;
        pq.push(milk_amt);
        int new_max = query_max();
        bool istp = (milk_amt == new_max);
        int curcount = milk[milk_amt];
        if (was_top) {
            if (istp && curcount == prev_count){
                continue;
            }
            change++;
        }else if (istp) {
            change++;
        }
    }

    cout << change;
}
