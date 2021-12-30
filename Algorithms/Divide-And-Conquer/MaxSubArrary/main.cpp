#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
{
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; i--){
        sum += nums[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    //注意这里i = mid + 1，避免重复用到nums[i]
    for (int i = mid + 1; i <= right; i++)
    {
        sum += nums[i];
        rightSum = max(rightSum, sum);
    }
    return (leftSum + rightSum);
}

int maxSubArrayHelper(vector<int> &nums, int left, int right)
{
    if (left == right){
        return nums[left];
    }
    int mid = (left + right) / 2;
    int leftSum = maxSubArrayHelper(nums, left, mid);
    //注意这里应是mid + 1，否则left + 1 = right时，会无线循环
    int rightSum = maxSubArrayHelper(nums, mid + 1, right);
    int midSum = findMaxCrossingSubarray(nums, left, mid, right);
    int result = max(leftSum, rightSum);
    result = max(result, midSum);
    return result;
}







int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> arr={12,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    int numsSize = int(arr.size());
    int result = maxSubArrayHelper(arr, 0, numsSize - 1);

    cout<<"sum:"<<result<<endl;

    return 0;
}
