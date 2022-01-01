#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */

/*
 * 思路：使用分治法
 */


int crossSubArray(vector<int>& arr,int low ,int mid,int high){
    int lsum=INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;--i){
        sum+= arr[i];
        if(sum>lsum){
            lsum = sum;
        }
    }
    int rsum=INT_MIN;
    sum=0;
    for(int i=mid+1;i<=high;++i){
        sum+=arr[i];
        if(sum>rsum){
            rsum=sum;
        }
    }
    return lsum+rsum;
}


int findSubArray(vector<int>& arr,int low,int high){
    if(low==high){
        return arr[low];
    }

    int mid = (low+high)/2;
    int lsum = findSubArray(arr,low,mid);
    int rsum = findSubArray(arr,mid+1,high);
    int csum = crossSubArray(arr,low,mid,high);

    return std::max(std::max(lsum,rsum),csum);
}



int maxSubArray(vector<int>& nums) {
    int numsSize = int(nums.size());
    int result = findSubArray(nums, 0, numsSize - 1);
    return result;
}





/*
 * 第二个思路：使用动态规划
*/
int maxSubArray2(vector<int>& nums) {
    vector<int> arr(nums.size());
    arr[0] = nums[0];
    int result=INT_MIN;
    for(int i=1;i<nums.size();++i){
        arr[i] = std::max(nums[i],arr[i-1]+nums[i]);
        if(arr[i]>result){
            result=arr[i];
        }
    }
    return result;
}





int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> arr={12,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    int numsSize = int(arr.size());
    //int result = findSubArray(arr, 0, numsSize - 1);
    int result = maxSubArray2(arr);

    cout<<"sum:"<<result<<endl;

    return 0;
}