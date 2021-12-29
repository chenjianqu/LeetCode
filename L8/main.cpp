#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s) {
    long long num=0;
    bool flag_head=true;
    int flag_sign=1;
    bool hasSetSign=false;
    for(const auto &c : s){

        if(c==' '){
            if(hasSetSign || !flag_head)
                break;
            else if(flag_head)
                continue;
        }
        if(c=='+' || c=='-'){
            if(!hasSetSign){
                hasSetSign=true;
                flag_sign = c=='+'?1:-1;
                continue;
            }
            else if(hasSetSign || !flag_head){
                break;
            }
        }

        if(('a' <= c && c>='z')||('A' <= c && c>='Z') || c=='.'){
            break;
        }

        else{
            flag_head=false;
            num*=10;
            num +=(c-'0');
            if(flag_sign == 1 && num>INT_MAX){
                return INT_MAX;
            }
            else if(flag_sign==-1 && -num<INT_MIN){
                return INT_MIN;
            }
        }
    }
    num *= flag_sign;

    return num;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<<INT_MIN<<endl;
    cout<<INT_MAX<<endl;

    cout<<myAtoi("  +  413")<<endl;

    return 0;
}
