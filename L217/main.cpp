#include <iostream>
#include <vector>

using namespace std;

/*
给定一个整数数组，判断是否存在重复元素。
如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
*/

/*
 * 思路：用排序的方法
 */

void adjust(vector<int> &arr,int len,int index){
    //计算左右孩子的下标
    int left = 2*index+1;
    int right = 2*index+2;
    //判断是否需要调整堆
    int parant = index;
    if(left<len && arr[left]>arr[index] ){
        parant = left;
    }
    if(right<len && arr[right] > arr[parant]){
        parant=right;
    }
    //递归的调整堆
    if(parant!=index){
        std::swap(arr[index],arr[parant]);
        adjust(arr,len,parant);
    }
}

//堆排序
void heapSort(vector<int> &arr,int len){
    //构建最大堆
    for(int i= len/2-1;i>=0;--i){
        adjust(arr,len,i);
    }
    //调整堆排序，得到排序序列
    for(int i=len-1;i>=1;--i){
        std::swap(arr[i],arr[0]);
        adjust(arr,i,0);
    }
}


bool containsDuplicate(vector<int>& nums) {
    heapSort(nums,nums.size());
    for(int i=0;i<nums.size()-1;++i){
        if(nums[i]==nums[i+1]){
            return true;
        }
    }
    return false;
}


int main()
{
    std::cout << "Hello, World!" << std::endl;

    vector<int> arr={8,1,14,3,21};

    heapSort(arr,arr.size());

    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }


    return 0;
}
