// Next greater element of all array elements

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void nge_stack(vector<int> nums){
    
    stack<int> st;
    st.push(nums[0]);

    for(int i = 1; i < nums.size(); i++){
        while(!st.empty() && nums[i] > st.top()){
            cout << st.top() << " --> " << nums[i] << endl;
            st.pop();
        }
        st.push(nums[i]);
    }

    while(!st.empty()){
        cout << st.top() << " --> " << "-1" << endl;
        st.pop();
    }
}

void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


void driver(){
    vector<int> nums;
    // nums = {10, 5, -7, 1, 9, 6, 15, 13, 11};
    // nums = {1, 2, 3, 4, 5};
    nums = {10, 2, 45, 10, 21, 12, 54, 12, 34, 9, 0, -21, 13};
    print(nums);
    nge_stack(nums);
}


int main(void){
    driver();
    return 0;
}