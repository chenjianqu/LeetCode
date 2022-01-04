#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    //排序
    std::sort(nums.begin(),nums.end());
    int n = nums.size();
    int delta=INT_MAX;
    int min_sum;
    for(int i=0;i<n;++i){
        //if(i>0 && nums[i]==nums[i-1])continue;
        int k=n-1;
        for(int j=i+1;j<k;j++){
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(std::abs(sum-target)<delta){
                    delta = std::abs(sum-target);
                    min_sum = sum;
                }
                --k;
            }
        }
    }
    return min_sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    //vector<int> nums = {-1,2,1,-4};
    vector<int> nums = {0,2,1,-3};
    int target = 1;

    auto result = threeSumClosest(nums,target);

    cout<<result<<endl;

    return 0;
}
