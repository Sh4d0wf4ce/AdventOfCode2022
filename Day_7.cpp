#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class Node {
public:
    int size;
    string name;
    vector<Node*> children;

    Node() {
        name = "/";
    }

    Node(string n) {
        name = n;
    }

    Node(string n, int s) {
        name = n;
        size = s;
    }

    Node(const Node& n1) {
        name = n1.name;
        size = n1.size;
    }

    void addNode(Node* node, Node* parent) {
        parent->children.push_back(node);
    }

    Node* find(string p) {
        for (auto x : children) {
            if (x->name == p) return x;
            x->find(p);
        }
    }
};


void solve() {
    ifstream f("data.txt");
    string l;
    stack<string> parents;
    Node root("/");
    
    while (getline(f, l)) {
        if (l.find("$ cd") != string::npos) {
            string sub = l.substr(5);
            if (sub == "..") parents.pop();
            else parents.push(sub);
        }
        else if (l.find("$ ls") != string::npos) continue;
        else {
            string name;
            if (l.find("dir") != string::npos) {
                name = l.substr(4);
                Node n(name);
            }else{
                int space = l.find(" ");
                name = l.substr(space + 1);
                int size = stoi(l.substr(0, space));
                Node n(name, size);
                Node* p = root.find(parents.top());
            }
        }


    }
}



int main()
{
    solve();
}
