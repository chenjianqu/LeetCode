#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

auto LCS_Length(const string &X,const string &Y)
{
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> b(m+1,vector<int>(n+1));
    vector<vector<int>> c(m+1,vector<int>(n+1));//报错LCS的长度

    for(int i=0;i<m+1;++i){
        c[i][0]=0;
    }
    for(int i=0;i<n+1;++i){
        c[0][i]=0;
    }

    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(X[i-1]==Y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j]=3;
            }
        }
    }

    return tuple{c,b};
}



int main() {
    std::cout << "Hello, World!" << std::endl;

    string X="ABCBDAB";
    string Y="BDCABA";
    auto [c,b] = LCS_Length(X,Y);

    for(int i=0;i<c.size();++i){
        for(int j=0;j<c[0].size();++j){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
