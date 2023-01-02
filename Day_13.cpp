#include <iostream>
#include <variant>
#include <vector>
#include <string>

using namespace std;

class Packet{
public:
    vector<variant<int, Packet>> content;
    
    Packet() = default;
    
    template <typename... T>
        Packet(T... args) {
        AddData(args...);
    }
    
    template <typename T>
    void AddData(T arg) {
        content.push_back(arg);
    }
    
    template <typename T, typename... Args>
    void AddData(T arg, Args... args) {
        content.push_back(arg);
        AddData(args...);
    }
    
    void write(){
        cout<<"[";
        for(auto v: content){
            if(holds_alternative<int>(v)){
                cout<<get<int>(v)<<",";
            }else{
                Packet tmp = get<Packet>(v);
                tmp.write();
            }    
        }
        cout<<"]";
    }

    
};

Packet parse(){
    string l, n;
    Packet p;
    getline(cin, l);
    int i = 1;
    while(l[i] != ']'){
        if(l[i] == '['){
            i++;
            continue;
        }
        
        if(l[i] == ','){
            p.AddData(stoi(n));
            n = "";
            i++;
            continue;
        }
        
        n+=l[i];
        i++;
    }
    p.AddData(stoi(n));
    return p;
}


int main()
{
    Packet p1(2, 3, 4, 5);
    Packet p2(5, p1, 6, p1);
    Packet p3(p1, p2);
    Packet p4 = parse();
    
    p4.write();
    
}
