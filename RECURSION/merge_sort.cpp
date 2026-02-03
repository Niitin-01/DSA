#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int start, int end, int mid){
    int n1 = mid-start+1, n2 = end-mid;
    vector<int> v1, v2;

    for(int i=0; i<n1; i++){
        v1.push_back(nums[start+i]);
    }
    for(int i=1; i<=n2; i++){
        v2.push_back(nums[mid+i]);
    }
    int i=0, j=0, k=start;
    while(i<n1 && j<n2){
        if(v1[i] < v2[j]) nums[k++] = v1[i++];
        else nums[k++] = v2[j++];
    }

    while(i<n1) nums[k++] = v1[i++];
    while(j<n2) nums[k++] = v2[j++];
}

void mergeSort(vector<int>& nums, int start, int end){
    if (start >= end) return;
    int mid = start + (end-start)/2; 

    // Sort from start to mid
    mergeSort(nums, start, mid);
    // Sort from mid+1 to end
    mergeSort(nums, mid+1, end);

    //merge
    merge(nums, start, end, mid);
}

void print(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {5, 3, 2, 8, 0, 7, 1};
    int start=0, end=nums.size()-1;
    mergeSort(nums, start, end);
    print(nums);
}