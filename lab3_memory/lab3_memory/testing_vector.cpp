#include <iostream>
#include <vector>
using namespace std;
class abc{
    public:
    string name;
    int id;
    abc(string x, int y):name(x), id(y){};
    void display(){
        cout<<"name: "<<&name<<" "<<"id: "<<&id<<endl;
    }
};

void xyz(cont abc & x){
    return x;
}

int main(){
    vector<abc> persons;
    persons.emplace_back("Taher", 1);
    persons.emplace_back("Robi", 2);
    cout<<persons[0]<<endl;
    
    
}