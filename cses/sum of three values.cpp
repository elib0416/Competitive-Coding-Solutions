#include <bits/stdc++.h>
using namespace std;
int n, target;
int main(){
    cin >> n >> target;
    vector<int> arr(n, 0);
    map<int, vector<int>> ma;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ma[arr[i]].push_back(i);
    }
    sort(arr.begin(), arr.end());
    int start, end;
    for(int middle = 0; middle < n; middle++){
        int t = target - arr[middle];
        if(middle == 0){
            start = 1;
        }else{
            start = 0;
        }
        if(middle == n - 1){
            end = n - 2;
        }else{
            end = n - 1;
        }
        int sum = arr[start] + arr[end];
        /*if(sum == t){
            if(arr[start] != arr[end]){
                cout << ++ma[arr[start]][0] << ' ' << ++ma[arr[end]][0];
            }else{
                cout << ++ma[arr[start]][0] << ' ' << ++ma[arr[end]][1];
            }
            return 0;
        }*/
        while(start < middle && end > middle){
            sum = arr[start] + arr[end];
            if(sum < t){
                start++;
            }else if(sum > t){
                end--;
            }else{
                if(sum == t){
                    if(arr[start] != arr[end] && arr[end] != arr[middle] && arr[middle] != arr[start]){
                        cout << ++ma[arr[start]][0] << ' ' << ++ma[arr[end]][0] << ' ' << ++ma[arr[middle]][0];
                    }else if(arr[start] == arr[end] && arr[end] != arr[middle] && arr[middle] != arr[start]){
                        cout << ++ma[arr[start]][0] << ' ' << ++ma[arr[end]][1] << ' ' << ++ma[arr[middle]][0];
                    }else if(arr[start] != arr[end] && arr[end] == arr[middle] && arr[middle] != arr[start]){
                        cout << ++ma[arr[start]][0] << ' ' << ++ma[arr[end]][0] << ' ' << ++ma[arr[middle]][1];
                    }else if(arr[start] != arr[end] && arr[end] != arr[middle] && arr[middle] == arr[start]){
                        cout << ++ma[arr[start]][0] << ' ' << ++ma[arr[end]][0] << ' ' << ++ma[arr[middle]][1];
                    }else{
                        cout << ++ma[arr[start]][0] << ' ' << ++ma[arr[end]][1] << ' ' << ++ma[arr[middle]][2];
                    }
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}