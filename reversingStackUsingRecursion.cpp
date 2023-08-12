// Reverse the stack using recursion

#include <iostream>
#include <stack>
using namespace std;



void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}


void pushAtBottom(stack<int> &st, int key){
    if(st.empty()){
        st.push(key);
    }   else{
        int temp = st.top();
        st.pop();
        pushAtBottom(st, key);
        st.push(temp); 
    }
}


void reverse(stack<int> &st){
    if(!st.empty()){
        int temp = st.top();
        st.pop();
        reverse(st);
        pushAtBottom(st, temp);
    }
}


void driver(){
    stack<int> st;
    for(int i = 0; i < 10; i++){
        st.push((i+1) * 10);
    }

    cout << "Original Stack:-";
    print(st);
    
    reverse(st);
    cout << "Reversed Stack:-";
    print(st);
}


int main(void){
    driver();
    return 0;
}