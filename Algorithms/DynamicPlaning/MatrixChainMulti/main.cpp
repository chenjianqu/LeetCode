#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

/**
 *
 * @param p 输入矩阵链中每个矩阵的维度，p.sizes=n+1,其中n是矩阵的数量,第一个矩阵的维度是p[0]xp[1]
 * @return
 */
auto MatrixChainOrder(vector<int> &p){
    int n = p.size()-1;//矩阵的数量
    vector<vector<int>> m(n+1,vector<int>(n+1));//m[i,j]表示Ai*...*Aj的代价
    vector<vector<int>> s(n+1,vector<int>(n+1));

    for(int i=1;i<=n;++i){
        m[i][i]=0;
    }

    for(int l=2;l<=n;++l){ //长度
        for(int i=1;i<=n-l+1;++i){ //起点
            int j=i+l-1;//终点
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;++k){//子问题
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }





    return tuple{m,s};
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> p{30,35,15,5,10,20,25};

    auto [m,s] = MatrixChainOrder(p);

    for(int i=0;i<m.size();++i){
        for(int j=0;j<m[0].size();++j){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
