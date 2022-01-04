#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> arr;
    if(nums.size()<4)
        return arr;

    std::set<vector<int>> num_set;

    //排序
    std::sort(nums.begin(),nums.end());

    //内外层双指针
    int n = nums.size();
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int k=j+1,l= n-1;
            while(k<l){
                int64_t sum = static_cast<int64_t>(nums[i])+static_cast<int64_t>(nums[j])+
                        static_cast<int64_t>(nums[k])+static_cast<int64_t>(nums[l]);
                if(sum==target){
                    num_set.insert({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                }
                else if(sum>target) l--;
                else k++;
            }
        }
    }

    for(auto &v : num_set)
        arr.push_back(v);
    return arr;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
