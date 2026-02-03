#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& nums){
    int n=nums.size();
    for(int i=1; i<n; i++){
        int key = nums[i], j=i-1;
        while(j>=0 && nums[j] > key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}

void print(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {2, 4, 6, 7, 1, 4, 9, 0, 3, 6};
    insertionSort(nums);
    print(nums);
}