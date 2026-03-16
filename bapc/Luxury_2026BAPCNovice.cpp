#include <bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
};
void solve(){
    int a, b, r;
    cin >> a >> b >> r;
    point center;
    center.x = a;
    center.y = b;
    point A1, A2, A3, A4, B1, B2, B3, B4;
    cin >> A1.x >> A1.y >> A2.x >> A2.y >> A3.x >> A3.y >> A4.x >> A4.y;
    int Alowery = min(min(A1.y, A2.y), min(A3.y, A4.y));
    int Ahighy = max(max(A1.y, A2.y), max(A3.y, A4.y));
    cin >> B1.x >> B1.y >> B2.x >> B2.y >> B3.x >> B3.y >> B4.x >> B4.y;
    int Blowery = min(min(B1.y, B2.y), min(B3.y, B4.y));
    int Bhighy = max(max(B1.y, B2.y), max(B3.y, B4.y));
    Alowery = max(Alowery, a - r);
    Blowery = max(Blowery, a - r);
    Ahighy = min(Ahighy, a + r);
    Bhighy = min(Bhighy, a + r);
    int numA = 0;
    for(int cury = Alowery; cury <= Ahighy; cury++){
        int xdeviation = floor(sqrt(r * r - (cury - b) * (cury - b)));
        int parallelogramdeviation = (A3.x - A1.x) * (cury - Alowery) / (A1.y - A3.y);
        int lowerx = parallelogramdeviation + A1.x;
        int higherx = A2.x + parallelogramdeviation;
        if(lowerx < a - xdeviation){
            lowerx = a - xdeviation;
        }else if(lowerx > a + xdeviation){
            continue;
        }
        if(higherx > a + xdeviation){
            higherx = a + xdeviation;
        }else if(higherx < a - xdeviation){
            continue;
        }
        numA += higherx - lowerx + 1;
        //cout << higherx << ' ' << lowerx << ' ' << cury << endl;
    }
    int numB = 0;
    for(int cury = Blowery; cury <= Bhighy; cury++){
        int xdeviation = ceil(sqrt(r * r - (cury - b) * (cury - b)));
        int parallelogramdeviation = ((B3.x - B1.x) * (cury - Blowery)) / (B1.y - B3.y);
        int lowerx = parallelogramdeviation + B1.x;
        int higherx = B2.x + parallelogramdeviation;
        if(lowerx < a - xdeviation){
            lowerx = a - xdeviation;
        }else if(lowerx > a + xdeviation){
            continue;
        }
        if(higherx > a + xdeviation){
            higherx = a + xdeviation;
        }else if(higherx < a - xdeviation){
            continue;
        }
        numB += higherx - lowerx + 1;
        //cout << "B" << numB << ' ' << higherx << ' ' << lowerx << ' ' << cury << ' ' << parallelogramdeviation << endl;
    }
    //cout << numA << ' ' << numB << endl;
    if(numA > numB){
        cout << 1 << "\n";
    }else if(numB > numA){
        cout << 2 << "\n";
    }else{
        cout << 3 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}