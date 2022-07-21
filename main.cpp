#include <iostream>
#include <string>
#include <stack>
#include <vector>

/**
 * @brief Get and pop last two items on the stack
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
    std::stack<int> stack = std::stack<int>();
    bool working = true;
    std::string input;

    std::vector<std::string> options = std::vector<std::string>{"add", "sub", "mul", "div", "exit", "peak", "swap", "pop"};

    std::cout << "add, sub, mul, div, exit, peak, swap, pop, or the number to add: " << std::endl;
    do
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
            working = false;
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
            if (stack.size() > 0)
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
    } while (working);
    return EXIT_SUCCESS;
}