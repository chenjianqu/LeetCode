#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 */

//快速排序，从大到小

int Partition(vector<int> &arr,int low,int high){
    //枢轴
    int key = arr[low];//以第一个位置作为枢轴
    while(low<high){
        while(low<high && arr[high] <= key)
            --high;
        arr[low] = arr[high];
        while(low<high && arr[low] >=key)
            ++low;
        arr[high] = arr[low];
    }
    arr[low] = key;
    return low; //返回划分后轴枢的位置
}

void QSort(vector<int> &arr,int low,int high){
    if(low<high){
        int part = Partition(arr,low,high);
        QSort(arr,low,part-1);
        QSort(arr,part+1,high);
    }
}




int findKthLargest(vector<int>& nums, int k) {
    if(k>nums.size()){
        return 0;
    }
    QSort(nums,0,nums.size()-1);

    return nums[k-1];
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
