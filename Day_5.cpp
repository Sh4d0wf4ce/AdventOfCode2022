#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> split(string s){
	string words[6];
	int i = 0;
	for(auto x: s){
		if(x == ' '){
			i++;
		}else{
			words[i]+=x;
		}
	}
	tuple<int, int, int> tp = {stoi(words[1]), stoi(words[3]), stoi(words[5])};
	return tp;
} 


void solve() {
	freopen("Day_5_stacks.txt", "r", stdin);
	string l;
	int i = 0;
	vector<stack<char>> v;
	while(getline(cin, l)){
		stack<char> s;
		for(auto x: l){
			s.push(x);
		}
		v.push_back(s);
	}
	
	ifstream f2("Day_5_data.txt");
	int move, from, to;
	while(getline(f2, l)){
		tie(move, from, to) = split(l);
//		for(int i = 0; i<move; i++){ 	works for part 1
//			char tmp = v[from-1].top(); works for part 1
//			v[from-1].pop();			works for part 1
//			v[to-1].push(tmp);			works for part 1
//		}								works for part 1
		stack<char> tmpstack;
		for(int i = 0; i<move; i++){
			tmpstack.push(v[from-1].top());
			v[from-1].pop();
		}
		
		for(int i = 0; i<move; i++){
			char tmp = tmpstack.top();
			tmpstack.pop();
			v[to-1].push(tmp);
		}
	}
	
	for(auto x: v){
		cout<<x.top();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}