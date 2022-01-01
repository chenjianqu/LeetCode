#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1,k= m+n-1;
    if(m==0 && n==1){
        nums1[0] = nums2[0];
    }
    while(k>=0){
        if(j<0 || (i>=0 && nums1[i] >= nums2[j])){
            nums1[k] = nums1[i];
            --i;
        }
        else{
            nums1[k] = nums2[j];
            --j;
        }
        --k;
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
