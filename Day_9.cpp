#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

typedef pair<int,int> pi;


int getDistance(pi T, pi H){
	return max(abs(H.f - T.f), abs(H.s - T.s));
}

pi getShiftVector(pi T, pi H, pi dir){
	pi p(H.f-T.f, H.s-T.s);
	
	if(abs(p.f) == abs(p.s)){
		p.f-= dir.f;
		p.s-= dir.s;
	}else if(max(abs(p.f), abs(p.s)) == abs(p.f)){
		p.f-= dir.f;
	}else{
		p.s-= dir.s;
	}
	
	return p;
}

pi getDir(pi O, pi N){
	pi p(N.f-O.f, N.s-O.s);
	
	return p;
}

void solve() {
    int n, distance;
    string l;
    char d;
    set<pi> visited;
    vector<pi> knots(10, {0,0});
    pi v, dir;
    visited.insert(knots[9]);
    while(getline(cin, l)){
    	n = stoi(l.substr(2));
    	d = l[0];
    	for(int i = 0; i<n; i++){
    		if(d == 'U') dir = {0, 1};
			if(d == 'D') dir = {0, -1};
			if(d == 'L') dir = {-1, 0};
			if(d == 'R') dir = {1, 0};
    		
    		knots[0].f += dir.f;
    		knots[0].s += dir.s;
			
			for(int knot = 1; knot<knots.size(); knot++){
				distance = getDistance(knots[knot], knots[knot-1]);
				if(distance == 2){
					pi tmp = knots[knot];
					v = getShiftVector(knots[knot], knots[knot-1], dir);
	 				knots[knot].f+= v.f;
	 				knots[knot].s+= v.s;
	 				
	 				dir = getDir(tmp, knots[knot]);
				}else break;
			}
			visited.insert(knots[9]);
		}
	}
	cout<<"result: "<<visited.size();
}

int main() {
	freopen("day_9_data.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
