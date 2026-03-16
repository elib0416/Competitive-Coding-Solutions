#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
const vector<string> zod{"Ox",   "Tiger",  "Rabbit",  "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog",    "Pig",   "Rat"};
struct Cow{
	string name, othercow;
	bool dir;
	int year;
};
int nonnegativemod(int n, int m){
    return (((n % m) + m) % m);
}
int main() {
	int n;
	cin >> n;
	vector<Cow> arr(n);
	for(Cow &r : arr) {
		string trash, dir_str, animal;
		cin >> r.name >> trash >> trash >> dir_str >> animal >> trash >> trash >> r.othercow;
		r.dir = dir_str == "previous";
		r.year = find(zod.begin(), zod.end(), animal) - zod.begin();
	}
	map<string, int> age;
	age["Bessie"] = 0;
	for (Cow r : arr){
	    int movement;
	    if(r.dir){
	        movement = -1;
	    }else{
	        movement = 1;
	    }
		int year = age[r.othercow] + movement;
		while(nonnegativemod(year, zod.size()) != r.year){
		    year += movement;
		}
		age[r.name] = year;
	}
	int dist = abs(age["Elsie"]);
	cout << dist;
}