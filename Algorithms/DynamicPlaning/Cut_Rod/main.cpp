#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

/**
 * 钢条切割
 * @param p价格数组
 * @param n 长度为n的钢条的最大收益
 */
auto CutRod(vector<int> &p,int n)
{
    vector<int> r(n+1);
    vector<int> s(n+1);
    r[0]=0;
    for(int j=0;j<=n;++j){
        int q=INT_MIN;
        for(int i=1;i<=j;++i){
            if(q < p[i] + r[j-i] ){
                q=p[i] + r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }

    return tuple{r,s};
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector price={0,1,5,8,9,10,17,17,20,24,30};

    int n=9;

    auto [r,s] = CutRod(price,n);

    while(n>0){
        cout<<s[n]<<endl;
        n = n-s[n];
    }

    return 0;
}
