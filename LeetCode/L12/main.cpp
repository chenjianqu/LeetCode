#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
string intToRoman(int num) {
    std::vector<tuple<int,string> > dic = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},
                                           {100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
    string output;
    for(int i=dic.size()-1;i>=0;--i){
        auto [elem,label] = dic[i];
        while(num>=elem){
            output+=label;
            num-=elem;
        }
    }
    return output;
}


int main() {




    return 0;
}
