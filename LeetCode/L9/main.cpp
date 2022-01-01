#include <iostream>
#include <climits>

using namespace std;

bool isPalindrome(int x) {
    if(x<0)
        return false;
    int arr[20];
    int i=0;
    while (x>0){
        arr[i++]=x%10;
        x/=10;
    }
    int flag=true;
    for(int j=0,k=i-1;j<k;++j,--k){
        if(arr[j]!=arr[k]){
            flag=false;
            break;
        }
    }
    return flag;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout<<isPalindrome(0)<<endl;
    return 0;
}
