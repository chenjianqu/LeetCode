#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(),nums.end());
    int closest_sum=0;
    int delta = INT_MAX;
    for(int i=0;i<nums.size();++i){
        int j=i+1,k=nums.size()-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(std::abs(target-sum)<delta){
                delta = std::abs(target-sum);
                closest_sum = sum;
                if(delta==0)break;
            }
            if(sum<=target){
                j++;
            }
            else if(sum>target){
                k--;
            }
        }
    }
    return closest_sum;
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
