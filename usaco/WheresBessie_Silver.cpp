#include <bits/stdc++.h>
using namespace std;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    vector<pair<pair<int, int>, pair<int, int>>> PCL;
    for(int i = 0; i < n; i++){
        for(int ii = i + 1; ii < n; ii++){
            for(int j = 0; j < n; j++){
                for(int jj = j + 1; jj < n; jj++){
                    //cout << i << ' ' << ii << ' ' << j << ' ' << jj << endl;
                    vector<vector<bool>> visited(n, vector<bool>(n, false));
                    vector<int> numberofgroups;
                    map<char, int> used;
                    map<char, int> lettertonumber;
                    vector<char> numbertoletter;
                    int num = 0;
                    int numof2s = 0;
                    bool good = true;
                    int numberoftimes = 0;
                    for(int iii = i; iii <= ii; iii++){
                        for(int jjj = j; jjj <= jj; jjj++){
                            numberoftimes++;
                            if(!visited[iii][jjj]){
                                //cout << arr[iii][jjj] << endl;
                                if(used[arr[iii][jjj]] == 1){
                                    //cout <<"HI";
                                    numberofgroups[lettertonumber[arr[iii][jjj]]]++;
                                    if(numberofgroups[lettertonumber[arr[iii][jjj]]] == 2){
                                        numof2s++;
                                        if(numof2s > 1){
                                            good = false;
                                            //cout << 10 << endl;
                                            break;
                                        }
                                    }else if(numberofgroups[lettertonumber[arr[iii][jjj]]] > 2){
                                        good = false;
                                        //cout << 11 << endl;
                                        break;
                                    }
                                }else{
                                    numberofgroups.push_back(1);
                                    used[arr[iii][jjj]] = 1;
                                    lettertonumber[arr[iii][jjj]] = num;
                                    numbertoletter.push_back(arr[iii][jjj]);
                                    num++;
                                }
                                queue<pair<int, int>> q;
                                q.push({iii, jjj});
                                visited[iii][jjj] = true;
                                while(!q.empty()){
                                    auto current = q.front();
                                    q.pop();
                                    int a = current.first;
                                    int b = current.second;
                                    for(int k = 0; k < 4; k++){
                                        int nx = a + dirx[k];
                                        int ny = b + diry[k];
                                        if(nx >= i && nx <= ii && ny >= j && ny <= jj && !visited[nx][ny] && arr[nx][ny] == arr[iii][jjj]){
                                            q.push({nx, ny});
                                            //cout << nx << ' ' << ny << " BFS " << arr[iii][jjj] << endl;
                                            visited[nx][ny] = true;
                                        }
                                    }
                                }
                                if(!good){
                                    break;
                                }
                            }
                            if(!good){
                                break;
                            }
                        }
                    }
                    if(num != 2 || numof2s != 1){
                        good = false;
                        //cout << 22 << endl;
                    }
                    //cout << "numberoftimes" << numberoftimes << endl;
                    if(good){
                        bool othergood = true;
                        for(int k = 0; k < PCL.size(); k++){
                            auto stuff = PCL[k];
                            if(i <= stuff.first.first && ii >= stuff.first.second && j <= stuff.second.first && jj >= stuff.second.second){
                                PCL[k] = {{i, ii}, {j, jj}};
                                othergood = false;
                                //cout << "FLSKJDFKLSDJFL" << endl;
                                //return 0;
                            }else if(i >= stuff.first.first && ii <= stuff.first.second && j >= stuff.second.first && jj <= stuff.second.second){
                                othergood = false;
                                break;
                                //cout << "LSJDLFKJDSKLF" << endl;
                                //return 0;
                            }
                        }
                        if(othergood){
                            PCL.push_back({{i, ii}, {j, jj}});
                        }
                        //cout << "YAY" << endl;
                    }
                }
            }
        }
    }
    cout << PCL.size();
}