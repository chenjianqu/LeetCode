#include <iostream>
#include <climits>

int reverse(int x)
{
    int arr[30];
    int flag = x<0?-1:1;
    int number =x;
    int i=0;
    while(number>=1 || number<=-1){
        int d=number%10;
        arr[i] = d*flag%10;
        number = number/10;
        ++i;
    }
    int result=0;
    for(int j=0;j<i;++j){
        if((result > int(INT_MAX-arr[j])/10 ) || (result*flag < int(INT_MIN+arr[j])/10)){
            return 0;
        }
        result = result*10+arr[j];
    }
    result *= flag;
    return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << INT_MAX << std::endl;
    std::cout << INT_MIN << std::endl;



    std::cout<<reverse(1463847412)<<std::endl;


    return 0;
}
