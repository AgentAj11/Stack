// Stock span problem
// Given stock price on N consecutive days
// For every stock price find maximum consecutive span of days just before the day

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> span){
    for(auto x: span){
        cout << x << "\t";
    }   cout << endl;
}


vector<int> stock_span(vector<int> stock){
    int n = stock.size();
    stack<int> st;
    vector<int> ans;

    st.push(0);
    ans.push_back(1);

    for(int i = 1; i < n; i++){
        while(!st.empty() && stock[st.top()] <= stock[i]){
            st.pop();
        }
        ans.push_back((st.empty()) ? (i + 1) : (i - st.top()));
        st.push(i);
    }
    return ans;
}


void driver(){
    vector<int> stock {100, 80, 60, 70, 60, 75, 85};
    
    cout << "Stock Price :-" << endl;
    print(stock);

    vector<int> span;
    span = stock_span(stock);

    cout << "Stock span :-" << endl;
    print(span);
}


int main(void){
    driver();
    return 0;
}