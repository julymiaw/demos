#include "stack.h"

bool isValidString(const std::string &s)
{
    Stack<char> stack;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            // 如果是左括号，将其推入栈
            stack.Push(c);
        }
        else
        {
            // 如果是右括号，检查栈是否为空
            if (stack.IsEmpty())
            {
                return false; // 右括号没有匹配的左括号
            }

            char top = stack.Top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
            {
                stack.Pop(); // 匹配成功，弹出栈顶的左括号
            }
            else
            {
                return false; // 括号类型不匹配
            }
        }
    }

    // 如果栈不为空，说明有未闭合的左括号
    return stack.IsEmpty();
}

int main()
{
    std::string validString1 = "{[()]}";
    std::string validString2 = "({[()]})";
    std::string invalidString1 = "{[()";
    std::string invalidString2 = "({[()]})}";

    if (isValidString(validString1))
    {
        std::cout << "The string \"" << validString1 << "\" is valid." << std::endl;
    }
    else
    {
        std::cout << "The string \"" << validString1 << "\" is not valid." << std::endl;
    }

    if (isValidString(validString2))
    {
        std::cout << "The string \"" << validString2 << "\" is valid." << std::endl;
    }
    else
    {
        std::cout << "The string \"" << validString2 << "\" is not valid." << std::endl;
    }

    if (isValidString(invalidString1))
    {
        std::cout << "The string \"" << invalidString1 << "\" is valid." << std::endl;
    }
    else
    {
        std::cout << "The string \"" << invalidString1 << "\" is not valid." << std::endl;
    }

    if (isValidString(invalidString2))
    {
        std::cout << "The string \"" << invalidString2 << "\" is valid." << std::endl;
    }
    else
    {
        std::cout << "The string \"" << invalidString2 << "\" is not valid." << std::endl;
    }

    return 0;
}