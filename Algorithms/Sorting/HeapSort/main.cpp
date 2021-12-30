#include <iostream>
#include <vector>

using namespace std;


// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2*index + 1; // index的左子节点
    int right = 2*index + 2;// index的右子节点
    //判断是否需要调整
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx])
        maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx])
        maxIdx = right;
    //递归调整
    if(maxIdx != index){
        std::swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }

}

// 堆排序
void heapSort(vector<int> &arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--)
        adjust(arr, size, i);

    // 调整大根堆
    for(int i = size - 1; i >= 1; i--){
        std::swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> arr={8,1,14,3,21};

    heapSort(arr,arr.size());

    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }

    return 0;
}
