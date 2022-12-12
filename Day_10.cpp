#include <bits/stdc++.h>

using namespace std;

void solve(){
	string l, crt;
	int when = 1, x = 1, result = 0, tmp = 0, sprite = 1;
	for(int cycle = 1; cycle<=240; cycle++){
		if(when == cycle){
			if(tmp){
				x+=tmp;
				sprite = x;
				tmp = 0;
			}
			
			
			
			getline(cin, l);
			if(l == "") break;
			if(l.find("noop") != string::npos){
				when += 1;
			}else{
				int v = stoi(l.substr(5));
				when += 2;
				tmp = v;
			}
			l = "";
		}
		
		if(cycle%40 -1 == sprite || cycle%40 -1 == sprite - 1 || cycle%40 -1 == sprite + 1){
			crt+="#";
		}else{
			crt+=".";
		}
		
		if(cycle % 40 == 20){
			result += cycle * x;
		}
		
		if(cycle % 40 == 0){
			crt+="\n";
		}
	}
	cout<<crt;
}
		
		

int main() {
	freopen("day_10_data.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}