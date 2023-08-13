// Find next greater frequency element for every element in the array
// any closest greater frequency element in the array

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;


void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


vector<int> ng_freq_element_first(vector<int> nums, map<int, int> freq){
    int n = nums.size();
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(freq[nums[j]] > freq[nums[i]]){
                ans[i] = nums[j];
            }
        }
    }   return ans;
}


vector<int> ng_freq_element_efficient(vector<int> nums, map<int, int> freq){
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> res(nums.size(), -1);
    
    st.push({nums[n - 1], freq[nums[n - 1]]});

    for(int i = n - 2; i >= 0; i--){
        int currentFreq = freq[nums[i]];

        // take me to the destiny
        while(!st.empty() && currentFreq >= st.top().second){
            st.pop();
        }

        res[i] = (st.empty()) ? -1 : st.top().first;

        st.push({nums[i], currentFreq});
    }   return res;
}


void driver(){
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
    
    map<int, int> freq;
    for(auto num : nums){
        freq[num]++;
    }

    cout << "Array :-" << endl;
    print(nums);

    vector<int> ans;
    
    // ans = ng_freq_element_first(nums, freq);
    ans = ng_freq_element_efficient(nums, freq);

    cout << "\nNext greatest frequency element :-" << endl;
    print(ans);
}


int main(void){
    driver();
    return 0;
}