// Reverse the string using stack
#include <iostream>
#include <stack>
using namespace std;


string reverse(string &str){
    stack<char> st;
    string reversed;
    int len = str.length();

    for(int i = 0; i < len; i++){
        st.push(str[i]);
    }

    while(!st.empty()){
        reversed += st.top();
        st.pop();
    }   return reversed;
}


void driver(){
    string str = "Hola name is Ajay Gaurav";
    cout << "Original string :\n" << str;
    
    cout << "Reversed string :\n" << reverse(str);;
}


int main(void){
    driver();
    return 0;
}