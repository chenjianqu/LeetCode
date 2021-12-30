#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int romanToInt(string s) {
    std::unordered_map<string,int> d={
            {"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",100},
            {"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}
    };
    int n=0;
    for(int i=0;i<s.size();){
        if(string key=s.substr(i,2);d.find(key)!=d.end()){
            n+=d[key];
            i+=2;
        }
        else{
            n+=d[s.substr(i,1)];
            i+=1;
        }
    }
    return n;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<<romanToInt("MCMXCIV")<<endl;

    return 0;
}
