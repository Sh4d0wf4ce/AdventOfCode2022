#include <bits/stdc++.h>

using namespace std;

class Solve{
public:
	int doSomething(vector<vector<char>>& grid, pair<int,int> start, pair<int,int> end){
		int H = grid.size();
		int W = grid[0].size();
		vector<pair<int,int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
		
		vector<int> paths_length;
		auto valid = [&](int row, int col){
			return row >= 0 && row < H && col >= 0 && col < W;
		};
		
		for(int r = 0; r<H; r++){
			for(int c = 0; c<W; c++){
				if(grid[r][c] != 'a') continue;
				start = {r, c};
				vector<vector<bool>> visited(H, vector<bool>(W));
				vector<vector<int>> distances(H, vector<int>(W));
				queue<pair<int,int>> q;
				q.push(start);
				visited[start.first][start.second] = true;
				distances[start.first][start.second] = 0;
				
				while(!q.empty()){
					int row = q.front().first;
					int col = q.front().second;
					
					q.pop();
					if(row == end.first && col == end.second){
						paths_length.push_back(distances[end.first][end.second]);
					}
					
					for(pair<int,int> dir: directions){
						int new_row = row + dir.first;
						int new_col = col + dir.second;
						if(valid(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] <= grid[row][col] + 1){
							q.push({new_row, new_col});
							visited[new_row][new_col] = true;
							distances[new_row][new_col] = distances[row][col] + 1;
						}
					}	
				}	
			}
		}
		return *min_element(paths_length.begin(), paths_length.end());
	}
};
		
		

int main() {
	freopen("day_12_data.txt", "r", stdin);
	vector<vector<char>> grid;
	string l;
	pair<int,int> start, end;
	while(getline(cin, l)){
		vector<char> row;
		for(char x: l){
			row.push_back(x);
		}
		grid.push_back(row);
	}
	for(int r = 0; r<grid.size(); r++){
		for(int c = 0; c<grid[0].size(); c++){
			if(grid[r][c] == 'S'){
				grid[r][c] = 'a';
				start = {r,c};
			} 
			if(grid[r][c] == 'E'){
				grid[r][c] = 'z';
				end = {r,c};
			} 
		}
	}
	
	for(auto x: grid){
		for(auto n: x){
			cout<<n;
		}
		cout<<"\n";
	}
	
	Solve s;
	cout<<"Shortest path length: "<<s.doSomething(grid, start, end);
	return 0;
}