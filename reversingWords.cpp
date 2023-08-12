// Reverse the individual words of an string
#include <iostream>
#include <stack>
using namespace std;


string reverseWords(string str){
    int len = str.length();
    stack<char> st;
    string reversed = "";

    for(int i = 0; i < len; i++){
        if(str[i] != ' '){
            st.push(str[i]);
        }   else{
            while(!st.empty()){
                reversed += st.top();
                st.pop();
            } reversed += ' ';
        }
    }
    
    while(!st.empty()){
        reversed += st.top();
        st.pop();
    }
    return reversed;
}


void driver(){
    string str = "hola name is Aj Gaurav";
    cout << "Original String : " << str << endl;

    string reversed = reverseWords(str);
    cout << "Word reversed string :-" << endl << reversed;
}


int main(void){
    driver();
    return 0;
}