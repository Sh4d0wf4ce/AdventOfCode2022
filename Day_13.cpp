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
    
    bool operator == (Packet const &p) const{
        if(content.size() != p.content.size()) return false;
        for(int i = 0; i<content.size(); i++){
            if(holds_alternative<int>(content[i])){
                if(holds_alternative<Packet>(p.content[i])) return false;
                if(get<int>(content[i]) != get<int>(p.content[i])) return false;
            }else{
                if(holds_alternative<int>(p.content[i])) return false;
                if(!(get<Packet>(content[i]) == get<Packet>(p.content[i]))) return false;
            }    
        }
        return true;
    }
    
    bool operator != (Packet const &p) const{
        return !(*this == p);    
    }
    
    
    
    bool check(Packet p){
        for(int i = 0; i<content.size(); i++){
            if(holds_alternative<int>(content[i])){
                if(holds_alternative<int>(p.content[i])){
                    if(get<Packet>(content[i]) != get<Packet>(p.content[i])) return get<Packet>(content[i]) < get<Packet>(p.content[i]);
                }
            }else{
                if(holds_alternative<int>(p.content[i])) return false;
                if(!(get<Packet>(content[i]) == get<Packet>(p.content[i]))) return false;
            }    
        }
        return true;
    }
    

    
};

Packet parse(string l, int &i){
    Packet p;
    while(l[i] != ']'){
        if(l[i] == '['){
            i++;
            p.AddData(parse(l, i));
            continue;
        }
        
        if(l[i] == ','){
            i++;
            continue;
        }
        
        p.AddData(l[i] - '0');
        i++;
    }
    i++;
    return p;
}

Packet parse(string l){
    int i = 1;
    return parse(l, i);
}

vector<Packet> parseLines(){
    string l;
    vector<Packet> packets;
    while(getline(cin, l)){
        if(l == "") continue;
        packets.push_back(parse(l));
    }
    return packets;
}


int main()
{
    Packet p1 = parse("[1,1,3,1,1])");
    Packet p2 = parse("[1,1,5,1,1]");
    
    if(p1==p2) cout<<"tak\n";
    else cout<<"nie\n";
    
    p1.write();
    cout<<"\n";
    p2.write();
}
