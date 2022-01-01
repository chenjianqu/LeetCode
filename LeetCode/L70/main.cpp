#include <iostream>
#include <vector>

using namespace std;


/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
*/


int climbStairs(int n) {
    vector<int> arr(n+1);//arr[i]表示到达第i阶的时候，有多少种方法
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;

    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;++i){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<<climbStairs(3)<<endl;


    return 0;
}
