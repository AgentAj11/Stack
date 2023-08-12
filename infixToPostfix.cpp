// Infix to Postfix expression conversion

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;


int prec(char item){
    if(item == '^'){
        return 3;
    }   else if(item == '*' or item == '/' or item == '%'){
        return 2;
    }   else if(item == '+' or item == '-'){
        return 1;
    }   return -1;
}


string postFixed(string infix){
    
    string postfix = "";
    stack<char> st;
    int len = infix.length();
    int i = 0;

    for(int i = 0; i < len; i++){
        char item = infix[i];

        if ((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z')
            || (item >= '0' && item <= '9')){
            postfix += item;
        }
        
        else if(item == '('){
            st.push('(');
        }
        
        else if(item == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }   st.pop();
        }
        
        else{
            while(!st.empty() && prec(st.top()) >= prec(item)){
                postfix += st.top();
                st.pop();
            }   st.push(item);
        }   
    }

    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }   
    
    return postfix;
}


void driver(){
    string exp = "a+b*c+(d/9)";
    // cout << "Enter the Expression : ";
    // cin >> exp;
    string postfix = postFixed(exp);
    cout << "Postfix = " << postfix;
}


int main(void){
    driver();
    return 0;
}