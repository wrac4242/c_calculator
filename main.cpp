#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>

/*
 ________  _________  ___  _____  _____   _____
|  ___|  \/  || ___ \/ _ \/  __ \|  ___| /  __ \ _     _
| |__ | .  . || |_/ / /_\ \ /  \/| |__   | /  \/| |_ _| |_
|  __|| |\/| ||    /|  _  | |    |  __|  | |  |_   _|_   _|
| |___| |  | || |\ \| | | | \__/\| |___  | \__/\|_|   |_|
\____/\_|  |_/\_| \_\_| |_/\____/\____/   \____/

*/

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

void loop(std::stack<int> &stack, std::map<std::string, void (*)(std::stack<int> &stack)> &options, std::string &input)
{
    std::cin >> input;
    if (options.contains(input))
    {
        options[input](stack);
    }
    else
    {
        stack.push(std::stoi(input));
    }
    loop(stack, options, input);
}

void doMathToStack(std::stack<int> &stack, int (*result)(int a, int b))
{
    if (stack.size() < 2)
    {
        std::cout << "Not enough items on stack";
    }
    else
    {
        int a, b;
        getTwoTopItems(stack, a, b);
        stack.push(result(a, b));
    }
}

int main()
{
    std::stack<int> stack = std::stack<int>();
    bool working = true;

    std::map<std::string, void (*)(std::stack<int> & stack)> options = std::map<std::string, void (*)(std::stack<int> & stack)>();
    options["add"] = [](std::stack<int> &stack)
    {
        doMathToStack(stack, [](auto a, auto b)
                      { return a + b; });
    };
    options["sub"] = [](std::stack<int> &stack)
    {
        doMathToStack(stack, [](auto a, auto b)
                      { return a - b; });
    };

    options["mul"] = [](std::stack<int> &stack)
    {
        doMathToStack(stack, [](auto a, auto b)
                      { return a * b; });
    };
    options["div"] = [](std::stack<int> &stack)
    {
        doMathToStack(stack, [](auto a, auto b)
                      { return a / b; });
    };

    options["exit"] = [](std::stack<int> &stack)
    {
        //>:D
        exit(EXIT_SUCCESS);
    };

    options["peak"] = [](std::stack<int> &stack)
    {
        if (stack.size() > 0)
        {
            std::cout << stack.top() << std::endl;
        }
        else
        {
            std::cout << "Nothing to peek at" << std::endl;
        }
    };

    options["swap"] = [](std::stack<int> &stack)
    {
        if (stack.size() < 2)
        {
            std::cout << "Not enough items on stack";
        }
        else
        {
            int a, b;
            getTwoTopItems(stack, a, b);
            stack.push(b);
            stack.push(a);
        }
    };
    options["pop"] = [](std::stack<int> &stack)
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
    };

    std::cout
        << "add, sub, mul, div, exit, peak, swap, pop, or the number to add: " << std::endl;
    std::string input;
    loop(stack, options, input);
    return EXIT_SUCCESS;
}

/*
 _   _ _    _ _   _
| | | | |  | | | | |
| | | | |  | | | | |
| | | | |/\| | | | |
| |_| \  /\  / |_| |
 \___/ \/  \/ \___/
*/