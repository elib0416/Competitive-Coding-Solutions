#include <bits/stdc++.h>
using namespace std;
struct coord{
    int x, y;
};
int main(){
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    const long long int infi = 1e9 + 7;
    int n, x, y, x1, y1;
    cin >> n >> x >> y >> x1 >> y1;
    cin.tie(NULL);
    vector<coord> fences(n + 2);
    map<int, vector<int>> xs, ys;
    fences[0] = {x, y};
    xs[x].push_back(0);
    ys[y].push_back(0);
    fences[n + 1] = {x1, y1};
    xs[x1].push_back(n + 1);
    ys[y1].push_back(n + 1);
    //map<int, vector<int>> paths;
    for(int i = 1; i <= n; i++){
        cin >> fences[i].x >> fences[i].y;
        xs[fences[i].x].push_back(i);
        ys[fences[i].y].push_back(i);
    }
    //efficient check for if ans <= 2
    if(x == x1 || y == y1){
        cout << 0;
        return 0;
    }
    for(auto point : fences){
        if((point.x == x && point.y == y1) || (point.x == x1 && point.y == y)){
            cout << 1;
            return 0;
        }
    }
    for(int index : xs[x]){
        for(int otherindex : ys[fences[index].y]){
            if(fences[otherindex].x == x1){
                cout << 2;
                return 0;
            }
        }
    }
    for(int index : ys[y]){
        for(int otherindex : xs[fences[index].x]){
            if(fences[otherindex].y == y1){
                cout << 2;
                return 0;
            }
        }
    }
    /*for(auto pa : xs){
        for(int x : pa.second){
            for(int y : pa.second){
                if(x == y){
                    continue;
                }
                paths[x].push_back(y);
            }
        }
    }
    for(auto pa : ys){
        for(int x : pa.second){
            for(int y : pa.second){
                if(x == y){
                    continue;
                }
                paths[x].push_back(y);
            }
        }
    }*/
    vector<int> arr(n + 2, 10);
    arr[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(!pq.empty()){
        pq.pop();
    }
    pq.push({0, 0});
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int cost = current.first;
        if(cost > arr[n + 1]){
            continue;
        }
        int node = current.second;
        for(auto p : xs[fences[node].x]){
            int newnode = p;
            int newcost = 1;
            //cout << cost << ' ' << node << ' ' << newnode << endl;
            if(arr[newnode] > cost + newcost){
                //cout << "yes" << endl;
                pq.push({cost + newcost, newnode});
                arr[newnode] = cost + newcost;
            }
        }
        for(auto p : ys[fences[node].y]){
            //cout << 'h';
            int newnode = p;
            int newcost = 1;
            //cout << cost << ' ' << node << ' ' << newnode << endl;
            if(arr[newnode] > cost + newcost){
                //cout << "yes" << endl;
                pq.push({cost + newcost, newnode});
                arr[newnode] = cost + newcost;
            }
        }
    }
    cout << arr[n + 1] - 1;
}