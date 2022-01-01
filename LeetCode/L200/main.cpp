#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int num=0;
    queue<tuple<int,int>> q;
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(grid[i][j]=='1'){
                //进行广度优先搜索
                ++num;
                q.push({i,j});
                grid[i][j]='2';
                while(!q.empty()){
                    auto [k,l] = q.front();
                    q.pop();

                    ///左邻居
                    if(l!=0 && grid[k][l-1]=='1'){
                        grid[k][l-1]='2';
                        q.push({k,l-1});
                    }
                    //上邻居
                    if(k!=0 && grid[k-1][l]=='1'){
                        grid[k-1][l]='2';
                        q.push({k-1,l});
                    }
                    //右邻居
                    if(l!=col-1 && grid[k][l+1]=='1'){
                        grid[k][l+1]='2';
                        q.push({k,l+1});
                    }
                    //下邻居
                    if(k!=row-1 && grid[k+1][l]=='1'){
                        grid[k+1][l]='2';
                        q.push({k+1,l});
                    }
                }
            }
        }
    }


    return num;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<vector<char>> grid={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout<<numIslands(grid)<<endl;


    return 0;
}
