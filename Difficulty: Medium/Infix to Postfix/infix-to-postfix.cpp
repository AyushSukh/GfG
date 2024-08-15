//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
   int precedence(char c){
       if(c=='^')
       {
           return 4;
       }
       else if(c=='*' || c== '/')
       {
           return 3;
       }
       else if(c=='+' || c == '-'){
           return 2;
       }   
       else return 1;
   }
    string infixToPostfix(string s) {
        int n = s.size();
        stack<char>st;
        string res = "";
        
        for(int i = 0 ; i < n ; i++)
        {   
            char ch = s[i];
            if((ch >= 'a' && ch <= 'z') || ( ch >= '0' && ch <= '9'))
            res += ch;
            
            else{
                if(ch == '('){
                    st.push(ch);
                }
                else if(ch == ')'){
                    while(!st.empty() && st.top() != '(')
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty() && precedence(st.top()) >= precedence(ch)){
                        res += st.top();
                        st.pop();
                    } 
                    st.push(ch);
                }
            }
        }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
    
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends