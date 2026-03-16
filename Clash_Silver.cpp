#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, h;
    cin >> n >> h;
    vector<long long int> cards(n);
    vector<long long int> WC;
    vector<long long int> NWC;
    long long int sum = 0;
    for(long long int i = 0; i < n; i++){
        cin >> cards[i];
        sum += cards[i];
    }
    vector<bool> isWC(n, false);
    long long int k;
    cin >> k;
    for(long long int i = 0; i < k; i++){
        long long int a;
        cin >> a;
        isWC[a - 1] = true;
    }
    for(long long int i = 0; i < n; i++){
        if(isWC[i]){
            WC.push_back(cards[i]);
        }else{
            NWC.push_back(cards[i]);
        }
    }
    long long int NWCsize = NWC.size();
    long long int WCsize = WC.size();
    sort(WC.begin(), WC.end());
    sort(NWC.begin(), NWC.end());
    long long int numcycle = sum;
    for(long long int i = 1; i < h; i++){
        if(i < NWCsize){
            numcycle -= NWC[NWCsize - i];
            //cout << NWCsize - i << ' ' << NWC[NWCsize - i] << endl;
        }
    }
    //long long int lowestexcludednumber = NWC[NWCsize - max(NWCsize, h - 1)];
    vector<long long int> intervals;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> curWC;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> curNWC;
    for(long long int i = 0; i < h; i++){
        if(isWC[i]){
            curWC.push({cards[i], i});
        }else{
            curNWC.push({cards[i], i});
        }
    }
    long long int currentnumber = 0;
    vector<long long int> orderofplay;
    for(long long int i = h; i < n; i++){
        if(curWC.size() > 0){
            //cout << i << endl;
            auto current = curWC.top();
            curWC.pop();
            currentnumber += current.first;
            intervals.push_back(currentnumber);
            orderofplay.push_back(current.second);
        }else{
            auto current = curNWC.top();
            curNWC.pop();
            currentnumber += current.first;
            orderofplay.push_back(current.second);
        }
        if(isWC[i]){
            curWC.push({cards[i], i});
        }else{
            curNWC.push({cards[i], i});
        }
    }
    long long int q;
    cin >> q;
    /*for(long long int x : intervals){
        cout << x << ' ';
    }
    cout << endl;
    cout << numcycle << endl;*/
    while(q--){
        long long int number;
        cin >> number;
        long long int answer = 0;
        answer += upper_bound(intervals.begin(), intervals.end(), number % numcycle) - intervals.begin();
        answer += WCsize * (number / numcycle);
        cout << answer << endl;
    }
}