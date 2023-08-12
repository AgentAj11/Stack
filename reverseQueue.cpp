// Reverse an queue

#include <iostream>
#include <stack>
#include <queue>

using namespace std;


void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << "\t";
        q.pop();
    }   cout << endl;
}


void reverseByRecursion(queue<int> &q){
    if(!q.empty()){
        int temp = q.front();
        q.pop();
        reverseByRecursion(q);
        q.push(temp);
    }
}


void reverseByStack(queue<int> &q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}


void driver(){
    queue<int> q;
    for(int i = 0; i < 10; i++){
        q.push((i+1) * 10);
    }
    
    cout << "Original queue :-" << endl;
    print(q);

    cout << "Reversed queue :-" << endl;

    reverseByStack(q);
    print(q);
    reverseByRecursion(q);
    print(q);
}


int main(void){
    driver();
    return 0;
}