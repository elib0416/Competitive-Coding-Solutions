#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set <char> block1, block2, block3, block4;
    for(int i = 0; i < 6; i++){
        char c;
        cin >> c;
        block1.insert(c);
    }
    for(int i = 0; i < 6; i++){
        char c;
        cin >> c;
        block2.insert(c);
    }
    for(int i = 0; i < 6; i++){
        char c;
        cin >> c;
        block3.insert(c);
    }
    for(int i = 0; i < 6; i++){
        char c;
        cin >> c;
        block4.insert(c);
    }
    for(int I = 0; I < n; I++){
        string s;
        cin >> s;
        //cout << s << endl;
        if(s.size() == 1){
            if(block1.find(s[0]) != block1.end() || block2.find(s[0]) != block2.end() || block3.find(s[0]) != block3.end() || block4.find(s[0]) != block4.end()){
                cout << "YES\n";
                continue;
            }else{
                cout << "NO\n";
                continue;
            }
        }else if(s.size() == 2){
            //cout << s << s[1] << endl;
            set<int> first, second;
            if(block1.find(s[0]) != block1.end()){
                first.insert(1);
            }
            if(block2.find(s[0]) != block2.end()){
                first.insert(2);
            }
            if(block3.find(s[0]) != block3.end()){
                first.insert(3);
            }
            if(block4.find(s[0]) != block4.end()){
                first.insert(4);
            }
            if(block1.find(s[1]) != block1.end()){
                second.insert(1);
            }
            if(block2.find(s[1]) != block2.end()){
                second.insert(2);
            }
            if(block3.find(s[1]) != block3.end()){
                second.insert(3);
            }
            if(block4.find(s[1]) != block4.end()){
                second.insert(4);
            }
            /*for(int x : first){
                cout << x << ' ';
            }
            cout << endl;
            for(int x : second){
                cout << x << ' ';
            }
            cout << endl;*/
            if(first.size() != 0 && second.size() != 0 && (first.size() > 1 || second.size() > 1 || (*first.begin() != *second.begin()))){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
            continue;
        }else if(s.size() == 3){
            bool good = false;
            sort(s.begin(), s.end());
            do{
                for(int i = 0; i < 4; i++){
                    bool othergood = true;
                    int j = 0, k = 0;
                    while(k < 4){
                        //break;
                        if(i == k){
                            k++;
                            continue;
                        }
                        if(k == 0){
                            if(block1.find(s[j]) == block1.end()){
                                othergood = false;
                            }
                        }else if(k == 1){
                            if(block2.find(s[j]) == block2.end()){
                                othergood = false;
                            }
                        }else if(k == 2){
                            if(block3.find(s[j]) == block3.end()){
                                othergood = false;
                            }
                        }else{
                            if(block4.find(s[j]) == block4.end()){
                                othergood = false;
                            }
                        }
                        /*if(I == 1 && i == 3){
                            cout << othergood << endl;
                        }*/
                        k++;
                        j++;
                    }
                    
                    if(othergood){
                        /*f(I == 1){
                            cout << s << "AAA " << i << endl;
                        }*/
                        good = true;
                        break;
                    }
                }
                if(good){
                    cout << "YES\n";
                    break;
                }
            }while(next_permutation(s.begin(), s.end()));
            if(!good){
                cout << "NO\n";
            }
            continue;
        }
        bool good = false;
        sort(s.begin(), s.end());
        do{
            //cout << s << endl;
            if(block1.find(s[0]) != block1.end() && block2.find(s[1]) != block2.end() && block3.find(s[2]) != block3.end() && block4.find(s[3]) != block4.end()){
                good = true;
                //cout << "AAA";
                break;
            }
        }while(next_permutation(s.begin(), s.end()));
        if(good){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}