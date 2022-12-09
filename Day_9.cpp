#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

typedef pair<int,int> pi;


int getDistance(pi T, pi H){
	return max(abs(H.f - T.f), abs(H.s - T.s));
}

pi getShiftVector(pi T, pi H, char dir){
	pi p(H.f-T.f, H.s-T.s);
	if(dir == 'U') p.s--;
	if(dir == 'D') p.s++;
	if(dir == 'L') p.f++;
	if(dir == 'R') p.f--;
	return p;
}

void solve() {
    int n, distance;
    string l;
    char dir;
    set<pi> visited;
    pi T(0,0), H(0,0), v;
    visited.insert(T);
    cout<<"Head: ("<<H.f<<","<<H.s<<") Tail: ("<<T.f<<","<<T.s<<")\n";
    while(getline(cin, l)){
    	dir = l[0];
    	n = stoi(l.substr(2));
    	for(int i = 0; i<n; i++){
    		if(dir == 'U') H.s++;
    		if(dir == 'D') H.s--;
 			if(dir == 'L') H.f--;
 			if(dir == 'R') H.f++;
 			
 			distance = getDistance(T,H);
 			
 			if(distance == 2){
 				v = getShiftVector(T, H, dir);
 				T.f+= v.f;
 				T.s+= v.s;
 				visited.insert(T);
			}
 			
		}
		cout<<"Head: ("<<H.f<<","<<H.s<<") Tail: ("<<T.f<<","<<T.s<<")\n";
	}
	cout<<"result: "<<visited.size();
}

int main() {
	freopen("Day_8_data.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
