#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, k;
    cin >> t >> k;
    /*if(t == 3 && k == 0){
        cout << -1 << "\n";
        cout << 1 << "\n" << "1 1 1 1 1 1 1 1 1 1 1 1\n";
        cout << 2 << "\n" << "1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2\n";
        return 0;
    }else if(t == 3 && k == 1){
        cout << -1 << "\n";
        cout << 1 << "\n" << "1 1 1 1 1 1 1 1 1 1 1 1\n";
        cout << 3 << "\n" << "1 2 3 1 2 3 2 3 1 2 3 1 2 3 1 2 3 1\n";
        return 0;
    }*/
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        if(n % 2 == 1){
            cout << -1 << "\n";
            continue;
        }
        int n3 = 3 * n;
        if(s.substr(0, n3 / 2) == s.substr(n3 / 2, n3 / 2)){
            cout << 1 << "\n";
            for(int i = 0; i < n3; i++){
                cout << 1;
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }
        vector<int> ans(n3);
        int a, b, c;
        bool ab = true, bc = true, ca = true, ba = true, cb = true, ac = true;
        for(int i = 0; i < n3; i++){
            if(s[i] == 'C'){
                ans[i] = 1;
                a = i;
            }else if(s[i] == 'O'){
                ans[i] = 2;
                b = i;
            }else{
                ans[i] = 3;
                c = i;
            }
            if(i % 3 != 2){
                continue;
            }
            if(a > b){
                ab = false;
            }
            if(b > a){
                ba = false;
            }
            if(a < c){
                ca = false;
            }
            if(a > c){
                ac = false;
            }
            if(b < c){
                cb = false;
            }
            if(b > c){
                bc = false;
            }
        }
        if(k == 1){
            cout << 3 << "\n";
            for(int i = 0; i < n3; i++){
                cout << ans[i];
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }
        /*if(ab){
            cout << 2 << "\n";
            for(int i = 0; i < n3; i++){
                if(ans[i] == 1){
                    cout << 1;
                }else if(ans[i] == 2){
                    cout << 1;
                }else{
                    cout << 2;
                }
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }else if(ba){
            cout << 2 << "\n";
            for(int i = 0; i < n3; i++){
                if(ans[i] == 1){
                    cout << 1;
                }else if(ans[i] == 2){
                    cout << 1;
                }else{
                    cout << 2;
                }
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }else if(ac){
            cout << 2 << "\n";
            for(int i = 0; i < n3; i++){
                if(ans[i] == 1){
                    cout << 1;
                }else if(ans[i] == 2){
                    cout << 2;
                }else{
                    cout << 1;
                }
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }else if(ca){
            cout << 2 << "\n";
            for(int i = 0; i < n3; i++){
                if(ans[i] == 1){
                    cout << 1;
                }else if(ans[i] == 2){
                    cout << 2;
                }else{
                    cout << 1;
                }
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }else if(bc){
            cout << 2 << "\n";
            for(int i = 0; i < n3; i++){
                if(ans[i] == 1){
                    cout << 2;
                }else if(ans[i] == 2){
                    cout << 1;
                }else{
                    cout << 1;
                }
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }else if(cb){
            cout << 2 << "\n";
            for(int i = 0; i < n3; i++){
                if(ans[i] == 1){
                    cout << 2;
                }else if(ans[i] == 2){
                    cout << 1;
                }else{
                    cout << 1;
                }
                if(i != n3 - 1){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }*/
        int allsubsetssize = 1 << n3;
        bool good = false;
        for(int i = 0; i < allsubsetssize; i++){
            string newstring = "";
            string othernewstring = "";
            for(int j = 0; j < n3; j++){
                if((i >> j) & 1){
                    newstring += s[j];
                }else{
                    othernewstring += s[j];
                }
            }
            int newstringsize = newstring.size();
            int othernewstringsize = othernewstring.size();
            if(newstring.size() % 2 == 1){
                continue;
            }else{
                if(newstring.substr(0, newstringsize / 2) == newstring.substr(newstringsize / 2, newstringsize / 2) && othernewstring.substr(0, othernewstringsize / 2) == othernewstring.substr(othernewstringsize / 2, othernewstringsize / 2)){
                    cout << 2 << "\n";
                    for(int j = 0; j < n3; j++){
                        if((i >> j) & 1){
                            cout << 1;
                        }else{
                            cout << 2;
                        }
                        if(j != n3 - 1){
                            cout << ' ';
                        }
                    }
                    cout << "\n";
                    good = true;
                    break;
                }
            }
        }
        if(good){
            continue;
        }
        cout << 3 << "\n";
        for(int i = 0; i < n3; i++){
            cout << ans[i];
            if(i != n3 - 1){
                cout << " ";
            }
        }
        cout << "\n";
    }
}