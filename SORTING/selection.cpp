#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& nums){
    int min_index=0, n = nums.size();
    for(int i=0; i<n-1; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(nums[j] < nums[min_index]) min_index = j;
        }
        if(min_index != i) swap(nums[i], nums[min_index]);
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
    selectionSort(nums);
    print(nums);
}