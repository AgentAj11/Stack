// Check if a expression containing (), {}, [] is balanced or not

#include <iostream>
#include <stack>

using namespace std;


bool isBalanced(string exp){
    stack<char> st;
    int len = exp.length();
    char symbol;

    for(int i = 0; i < len; i++){
        symbol = exp[i];
        if(st.empty()){
            st.push(symbol);
        }   else if((st.top() == '(' && symbol == ')') || (st.top() == '{' && symbol == '}') || (st.top() == '[' && symbol == ']')){
            st.pop();
        }   else{
            st.push(symbol);
        }
    }   

    if(st.empty())
        return true;
    return false;
}


void driver(){
    // string exp = "[()()]{}{()}";
    // string exp = "()()]";
    string exp = "{((){{}}}}]]]]}}((())))}";
    if(isBalanced(exp)){
        cout << exp << " is balanced." << endl;
    }   else{
        cout << exp << " is not balanced." << endl;
    }
}


int main(void){
    driver();
    return 0;
}