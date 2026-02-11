#include <iostream>
#include <vector>
using namespace std;

struct Stack{
    int capacity;
    vector<int> v;

    Stack(int n) : capacity(n) {
        v.reserve(n);
    }

    int top(){
        if(v.empty()) return -1;
        return v.back();
    }

    void push(int num){
        if(v.size() == capacity){
            cout << "stack Overflow" << endl;
            return;
        }
        v.push_back(num);
    }

    void pop(){
        if(v.empty()){
            cout << "Stack Underflow" << endl;
            return;
        } 
        v.pop_back();
    }
};

int main(){
    int cap;
    cin >> cap;
    Stack s(cap);
}