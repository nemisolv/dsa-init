#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> stack;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            stack.push(c);
        else
        {
            if (stack.empty())
                return false;
            
            char top = stack.top();
            if (top == '(' && c == ')' || top == '[' && c == ']' || top == '{' && c == '}')
            {
                stack.pop();
            }else return false;
        }
    }
    return stack.empty();
}

int main()
{
    string s = "(){[-]}";
    cout << isValid(s);

    return 0;
}