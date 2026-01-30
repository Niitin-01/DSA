#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
        }
    }
}

void print(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {2, 4, 3, 5, 6, 7, 1, 8, 9, 8};
    bubbleSort(nums);
    print(nums);
}