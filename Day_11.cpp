#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

class Monkey{
public:	
	vector<ll> items;
	int test, ifTrue, ifFalse;
	string operation;

	Monkey(vector<ll> its, int t, int tr, int fl, string op){
		items = its;
		test = t;
		ifTrue = tr;
		ifFalse = fl;
		operation = op;
	}
	
	ll getNew(ll old){
		ll l, r;
		int signIt;
		
		signIt = (operation.find("*") != string::npos) ? operation.find("*") : operation.find("+");
		
		l = (operation.substr(0, signIt-1) == "old") ? old : stoll(operation.substr(0, signIt-1));
		r = (operation.substr(signIt+2) == "old") ? old : stoll(operation.substr(signIt+2));
		
		return (operation.find("*") != string::npos) ? l * r : l + r;
	}
};

vector<Monkey> parseInput(){
	vector<Monkey> monkeys;
	vector<ll> items;
	int testVar, ifTrue, ifFalse;
	string operation, l;
	
	while(getline(cin, l)){ //Monkey number
		getline(cin, l); //items
		
		l = l.substr(18);
		stringstream ss(l);
		string tmp;
		items.clear();
		while(getline(ss, tmp, ',')){
			items.push_back(stoll(tmp));
		}
		
		getline(cin, l); // operation
		operation = l.substr(19);
		
		getline(cin, l); //testVar
		testVar = stoi(l.substr(21));
		
		getline(cin, l); //ifTrue
		ifTrue = stoi(l.substr(29));
		
		getline(cin, l); //ifFalse
		ifFalse = stoi(l.substr(30));
		
		getline(cin, l); //blank
		Monkey m(items, testVar, ifTrue, ifFalse, operation);
		
		monkeys.push_back(m);
	}
	
	return monkeys;	
}



void solve(){
	vector<Monkey> monkeys = parseInput();
	vector<ll> business(monkeys.size());
	int modulo = 1;
	for(auto x: monkeys){
		modulo *= x.test;
	}
	
	for(int k = 0; k<10000; k++){
		for(int i = 0; i<monkeys.size(); i++){
			while(monkeys[i].items.size()){
				ll newItem = monkeys[i].getNew(monkeys[i].items[0]); 
				newItem %= modulo;
				//newItem /= 3;
				if((newItem % monkeys[i].test) == 0){
					monkeys[monkeys[i].ifTrue].items.push_back(newItem);
				}else{
					monkeys[monkeys[i].ifFalse].items.push_back(newItem);
				}
				monkeys[i].items.erase(monkeys[i].items.begin());
				business[i]++;
			}
		}
	}
	
	sort(business.begin(), business.end(), greater<int>());
	cout<<business[0] * business[1];
}		
		

int main() {
	freopen("day_11_data.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
