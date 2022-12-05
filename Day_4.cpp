#include <bits/stdc++.h>

using namespace std;

pair<string, string> split(string l, char c){
	pair<string, string> elves;
	bool second = false;
	
	for(int i = 0; i<l.length(); i++){
		if(l[i] == c){
			second = true;
			continue;
		} 
		
		
		if(second){
			elves.second+=l[i];
		}else if(!second){
			elves.first+=l[i];
		}
	}
	return elves;
}


void solve() {
	string l;
	int score = 0;
	pair<string, string> elves;
	pair<string, string> p1, p2;
	pair<int, int> n1, n2;

	while(getline(cin, l)) {
		elves = split(l, ',');
		p1 = split(elves.first, '-');
		p2 = split(elves.second, '-');
		
		n1 = make_pair(stoi(p1.first), stoi(p1.second));
		n2 = make_pair(stoi(p2.first), stoi(p2.second));
		
//		if((n2.first >= n1.first && n2.second <= n1.second) || (n1.first >= n2.first && n1.second <= n2.second)){
//			score++;
//		}
		
		if((n1.first >= n2.first && n1.first <= n2.second) || 
		   (n1.second >= n2.first && n1.second <= n2.second) || 
		   (n2.first >= n1.first && n2.first <= n1.second) ||
		   (n2.second >= n1.first && n2.second <= n1.second)){
			
			score++;
			cout<<"n1: "<<n1.first<<" "<<n1.second<<" n2: "<<n2.first<<" "<<n2.second<<" score: "<<score<<"\n";
		}
	}
	cout<<score;
}

int main() {
	freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}