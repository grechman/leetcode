#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> par;
            int p;
    
            for (char& c : s){
                if (c == '(' || c == '[' || c == '{')
                    par.push(c);
                else{
                    if (par.empty())
                        return false;
                    else{
                        p = (int)par.top() / 50;
                        if (p != (int)c / 50)
                            return false;
                        else
                            par.pop();
                    }
                }
            }
            return par.empty();
        }
    };

int main(){
    Solution sol;
    string s = "()[]{}";
    cout << sol.isValid(s) << endl;
}