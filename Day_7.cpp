#include <bits/stdc++.h>

using namespace std;

int currentResult = 0;
int minDirSize = 0; 

struct Node
{
    string name;
    string type;
    int size;
    vector<Node *> children;
};

Node *newNode(int size, string name, string type)
{
    Node *temp = new Node;
    temp->name = name;
    temp->size = size;
    temp->type = type;
    return temp;
}


Node* findNode(Node* n, vector<string> v) {
	for(int i = 1; i<v.size(); i++){
		Node* tmp = n;
		for(auto child : n->children){
			if(child->name == v[i]){
				n = child;
			}
	 	}
	 	if(tmp == n) return NULL;
	}
	return n;	
}

    
int getSize(Node *root){
	if (root){
		int size = root->size;
		for (int i = 0; i < root->children.size(); i++)
            size += getSize(root->children[i]);
		return size;
	}
	return 0;
}

void getSizes(Node* root){
	if (root){
        root->size = getSize(root);
        for (int i = 0; i < root->children.size(); i++)
            getSizes(root->children[i]);
    }
}

void traverse(Node *root){
    if (root){
        cout<<root->name<<" ("<<root->type<<", size= "<<root->size<<")\n";
        for (int i = 0; i < root->children.size(); i++)
            traverse(root->children[i]);
    }
}

void getAnswear(Node* root){
	if (root){
        if(root->size <= 100000 && root->type == "dir"){
        	cout<<root->name<<" ("<<root->type<<", size= "<<root->size<<")\n";
        	currentResult+=root->size;
		}
        for (int i = 0; i < root->children.size(); i++)
            getAnswear(root->children[i]);
    }
}

void getDirToDelete(Node* root, int space){
	if (root){
        if(root->size >= space && root->type == "dir"){
        	minDirSize = min(minDirSize, root->size);
		}
        for (int i = 0; i < root->children.size(); i++)
            getDirToDelete(root->children[i], space);
    }
}


void solve() {
    ifstream f("Day_7_data.txt");
    string l;
    vector<string> parents;
    Node* root = newNode(0, "/", "dir");
    
    while (getline(f, l)) {
        if (l.find("$ cd") != string::npos) {
            string sub = l.substr(5);
            if (sub == "..") parents.pop_back();
            else parents.push_back(sub);
        }
        else if (l.find("$ ls") != string::npos) continue;
        else{
            string name;
            int size;
            Node* n = new Node;
            if (l.find("dir") != string::npos) {
                name = l.substr(4);
                n->size = 0;
                n->name = name;
                n->type = "dir";
            }else{
                int space = l.find(" ");
                n->name = l.substr(space + 1);
                n->size = stoi(l.substr(0, space));
                n->type = "file";
			}
            Node* p = findNode(root, parents);
        	p->children.push_back(n);
        }
    }
    getSizes(root);
   	traverse(root);
   	cout<<"\n";
   	getAnswear(root);
   	cout<<"\nResult: "<<currentResult<<"\n";
   	int space = 30000000 - (70000000 - root->size);
   	minDirSize = root->size;
   	getDirToDelete(root, space);
   	cout<<"\nYou need delete directory of size "<<minDirSize<<" to update the system";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
