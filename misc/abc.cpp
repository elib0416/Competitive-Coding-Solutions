#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
string makestring(char a, char b, char c){
    string st = "";
    st += a;
    st += b;
    st += c;
    return st;
}


int main(){
    int n, m;
    char a, b, c, d;
    long long int num = 0;
    cin >> n >> m;
    string str;
    set<string> strings;
    cin >> str;
    if(n == 3){
        if(m > 1){
            cout << 0;
            return 0;
        }
        if(str[1] == str[2]){
            for(int i = 0; i < 26; i++){
                char d = 'a' + i;
                if(d == str[0]){
                    continue;
                }
                strings.insert(makestring(d, str[1], str[2]));
            }
        }
        if(str[0] == str[1] && str[0] != str[2]){
            strings.insert(makestring(str[0], str[2], str[2]));
        }
        if(str[0] == str[2] && str[0] != str[1]){
            strings.insert(makestring(str[0], str[1], str[1]));
        }
        if(str[0] != str[1] && str[0] != str[2] && str[1] != str[2]){
            strings.insert(makestring(str[0], str[1], str[1]));
            strings.insert(makestring(str[0], str[2], str[2]));
        }
        cout << strings.size() << endl;
        for(string s : strings){
            cout << s << endl;
        }
        return 0;
    }
    map<char, map<char, map<char, int> > > arr;
    for(int i = 0; i < n - 2; i++){
        a = str[i];
        b = str[i + 1];
        c = str[i + 2];
        string s = "";
        s += a;
        s += b;
        s += c;
        arr[a][b][c]++;
        if(a != b && b == c && arr[a][b][c] >= m){
            strings.insert(makestring(a, b, c));
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            char d = 'a' + j;
            if(d == str[i]){
                continue;
            }
            if(i == 0){
                if(arr[d][str[i + 1]][str[i + 2]] >= m && str[i + 1] == str[i + 2] && d != str[i + 1]){
                    strings.insert(makestring(d, str[i + 1], str[i + 2]));
                }
            }else if(i == 1){
                arr[str[i - 1]][d][str[i + 1]]++;
                arr[str[i - 1]][str[i]][str[i + 1]]--;
                arr[str[i]][str[i + 1]][str[i + 2]]--;
                arr[d][str[i + 1]][str[i + 2]]++;
                if(arr[str[i - 1]][d][str[i + 1]] >= m && d == str[i + 1] && str[i - 1] != d){
                    strings.insert(makestring(str[i - 1], d, str[i + 1]));
                }
                if(arr[d][str[i + 1]][str[i + 2]] >= m && str[i + 1] == str[i + 2] && d != str[i + 1]){
                    strings.insert(makestring(d, str[i + 1], str[i + 2]));
                }
                arr[str[i - 1]][d][str[i + 1]]--;
                arr[str[i - 1]][str[i]][str[i + 1]]++;
                arr[str[i]][str[i + 1]][str[i + 2]]++;
                arr[d][str[i + 1]][str[i + 2]]--;
            }else if(i == n - 1){
                if(arr[str[n - 3]][str[n - 2]][d] + 1 >= m && str[n - 2] == d && str[n - 3] != str[n - 2]){
                    strings.insert(makestring(str[n - 3], str[n - 2], d));
                }
            }else if(i == n - 2){
                arr[str[i - 1]][d][str[i + 1]]++;
                arr[str[i - 1]][str[i]][str[i + 1]]--;
                arr[str[i - 2]][str[i - 1]][str[i]]--;
                arr[str[i - 2]][str[i - 1]][d]++;
                if(arr[str[i - 1]][d][str[i + 1]] >= m && d == str[i + 1] && str[i - 1] != d){
                    strings.insert(makestring(str[i - 1], d, str[i + 1]));
                }
                if(arr[str[i - 2]][str[i - 1]][d] >= m && str[i - 1] == d && str[i - 2] != str[i - 1]){
                    strings.insert(makestring(str[i - 2], str[i - 1], d));
                }
                arr[str[i - 1]][d][str[i + 1]]--;
                arr[str[i - 1]][str[i]][str[i + 1]]++;
                arr[str[i - 2]][str[i - 1]][str[i]]++;
                arr[str[i - 2]][str[i - 1]][d]--;
            }else{
                arr[str[i - 1]][d][str[i + 1]]++;
                arr[str[i - 1]][str[i]][str[i + 1]]--;
                arr[str[i - 2]][str[i - 1]][str[i]]--;
                arr[str[i - 2]][str[i - 1]][d]++;
                arr[str[i]][str[i + 1]][str[i + 2]]--;
                arr[d][str[i + 1]][str[i + 2]]++;
                if(arr[str[i - 1]][d][str[i + 1]] >= m && d == str[i + 1] && str[i - 1] != d){
                    strings.insert(makestring(str[i - 1], d, str[i + 1]));
                }
                if(arr[str[i - 2]][str[i - 1]][d] >= m && d == str[i - 1] && str[i - 2] != d){
                    strings.insert(makestring(str[i - 2], str[i - 1], d));
                }
                if(arr[d][str[i + 1]][str[i + 2]] >= m && str[i + 1] == str[i + 2] && d != str[i + 1]){
                    strings.insert(makestring(d, str[i + 1], str[i + 2]));
                }
                arr[str[i - 1]][d][str[i + 1]]--;
                arr[str[i - 1]][str[i]][str[i + 1]]++;
                arr[str[i - 2]][str[i - 1]][str[i]]++;
                arr[str[i - 2]][str[i - 1]][d]--;
                arr[str[i]][str[i + 1]][str[i + 2]]++;
                arr[d][str[i + 1]][str[i + 2]]--;
            }
        }
    }
    cout << strings.size() << endl;
    for(string s : strings){
        cout << s << endl;
    }
}
