#include <iostream>
#include <string>
#include <stack>

/**
 * @brief Get and pop last two items on the stack. This is done because std::stack::pop does not return value that is removed
 *
 * @param stack
 * @param a
 * @param b
 */
void getTwoTopItems(std::stack<int> &stack, int &a, int &b)
{
    a = stack.top();
    stack.pop();
    b = stack.top();
    stack.pop();
}

int main()
{
    //stack with the actual values
    std::stack<int> stack = std::stack<int>();
    //simple flag to allow exiting from the app
    bool working = true;
    //input string that will be written into by user each iteration
    std::string input;
    std::cout << "add, sub, mul, div, exit, peak, swap, pop, or the number to add: " << std::endl;
    while (working)
    {
        std::cin >> input;
        int a, b;
        if (input == "add")
        {
            if (stack.size() < 2)
            {
                std::cout << "Not enough items on stack";
            }
            else
            {
                getTwoTopItems(stack, a, b);
                stack.push(a + b);
            }
        }
        else if (input == "sub")
        {
            if (stack.size() < 2)
            {
                std::cout << "Not enough items on stack";
            }
            else
            {
                getTwoTopItems(stack, a, b);
                stack.push(a - b);
            }
        }
        else if (input == "mul")
        {
            if (stack.size() < 2)
            {
                std::cout << "Not enough items on stack";
            }
            else
            {
                getTwoTopItems(stack, a, b);
                stack.push(a * b);
            }
        }
        else if (input == "div")
        {
            if (stack.size() < 2)
            {
                std::cout << "Not enough items on stack";
            }
            else
            {
                getTwoTopItems(stack, a, b);
                stack.push(a / b);
            }
        }
        else if (input == "exit")
        {
            working = false;//might as well use break; tbh
        }
        else if (input == "peak")
        {
            if (stack.size() > 0)
            {
                std::cout << stack.top() << std::endl;
            }
            else
            {
                std::cout << "Nothing to peek at" << std::endl;
            }
        }
        else if (input == "swap")
        {
            if (stack.size() < 2)
            {
                std::cout << "Not enough items on stack";
            }
            else
            {
                getTwoTopItems(stack, a, b);
                stack.push(b);
                stack.push(a);
            }
        }
        else if (input == "pop")
        {
            if (!stack.empty())
            {
                std::cout << "popped: " << stack.top() << std::endl;
                stack.pop();
            }
            else
            {
                std::cout << "Nothing to pop" << std::endl;
            }
        }
        else
        {
            stack.push(std::stoi(input));
        }

        // Move to next line to avoid possible text squashing
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}