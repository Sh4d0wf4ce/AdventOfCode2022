#include <bits/stdc++.h>

using namespace std;

bool isClear(vector<vector<int>> grid, int i, int j){
	bool right = true, up = true, left = true, down = true;
	
	//down
	for(int a = i+1; a<grid[i].size(); a++){
		if(grid[i][j] <= grid[a][j]){
			down = false;
		}
	}
	
	//up
	for(int a = 0; a<i; a++){
		if(grid[i][j] <= grid[a][j]){
			up = false;
		}
	}
	
	//left
	for(int a = 0; a<j; a++){
		if(grid[i][j] <= grid[i][a]){
			left = false;
		}
	}
	
	//right
	for(int a = j+1; a<grid[i].size(); a++){
		if(grid[i][j] <= grid[i][a]){
			right = false;
		}
	}
	
	return right || left || up || down;
	
}

int scenicScore(vector<vector<int>> grid, int i, int j){
	int right = 0, up = 0, left = 0, down = 0;
	
	//up
	for(int a = i-1; a>=0; a--){
		up++;
		if(grid[i][j] <= grid[a][j]){
			break;
		}
	}
	
	//down	
	for(int a = i+1; a<grid.size(); a++){
		down++;
		if(grid[i][j] <= grid[a][j]){
			break;
		}
	}
	
	//left	
	for(int a = j-1; a>=0; a--){
		left++;
		if(grid[i][j] <= grid[i][a]){
			break;
		}
	}
	
	//right	
	for(int a = j+1; a<grid.size(); a++){
		right++;
		if(grid[i][j] <= grid[i][a]){
			break;
		}
	}
	//cout<<"["<<i<<","<<j<<"] left:"<<left<<" up:"<<up<<" right:"<<right<<" down:"<<down<<"\n";
	
	return (left * right * up * down);
}


void solve() {
    int counter = 0;
    string l;
    int score = 0;
    vector<vector<int>> grid;
    while(getline(cin, l)){
    	vector<int> v;
    	for(int i = 0; i<l.length(); i++){
    		v.push_back(l[i]-48);
		}
		grid.push_back(v);
	}
	counter += grid.size() * 2 + (grid[0].size() - 2) * 2 ;
	

	for(int i = 1; i<grid.size()-1; i++){
		for(int j = 1; j<grid[i].size() - 1; j++){
			if(isClear(grid, i, j)){
				counter++;
			}
			score = max(score, scenicScore(grid, i, j));
		}
	}
	
	cout<<counter<<"\n";
	cout<<score;
}

int main() {
	freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}