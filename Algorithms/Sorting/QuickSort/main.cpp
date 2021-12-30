#include <iostream>
#include <vector>

using namespace std;

/**
 * 对arr[low..high]进行划分，以arr
 * @param arr
 * @param low
 * @param high
 * @return
 */
int Partition(vector<int> &arr,int low,int high){
    //枢轴
    int key = arr[low];//以第一个位置作为枢轴
    while(low<high){
        while(low<high && arr[high]>=key)
            --high;
        arr[low] = arr[high];
        while(low<high && arr[low]<=key)
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


void QuickSort(vector<int> &arr){
    QSort(arr,0,arr.size()-1);
}



int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> arr={3,6,7,4,3,9,30,6,1};
    QuickSort(arr);

    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<endl;
    }


    return 0;
}
