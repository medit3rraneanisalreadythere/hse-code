#include <iostream>
#include <stack>
#include <string>

bool isOpen(const char &c) 
{
    return (c == '(' || c == '[') ? true : false;
}

bool isPair(const char &c1, const char &c2) {
    return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']')) ? true : false;
}

int main(int argc, char **argv)
{
    std::string s;
    std::cin >> s;

    std::stack<char> st;
    bool t = true;

    for (auto &c: s) 
    {
        if (isOpen(c)) 
        {
            st.push(c);
        }

        else 
        {
            if (st.size()) 
            {
                if (isPair(st.top(), c)) 
                {
                    st.pop();
                }
                
                else
                {
                    t = false;
                    break;
                }
            } 
            
            else 
            {
                t = false;
                break;
            }
        }
    }

    if (st.size()) 
    {
        t = false;
    }

    std::cout << (t ? "YES" : "NO");
    
    return 0;
}