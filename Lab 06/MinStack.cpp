#include <iostream>
using namespace std;

class MinStack
{
public:
    int *stack, *minStack, *min, top;
    MinStack()
    {
        stack = (int *)malloc(1000 * sizeof(int));
        minStack = (int *)malloc(1000 * sizeof(int));
        top = -1;
        min = stack;
    }
    void push(int val)
    {
        ++top;
        stack[top] = val;
        if (top == 0)
            minStack[top] = val;
        else
            minStack[top] = (minStack[top - 1] < val) ? minStack[top - 1] : val;
    }
    void pop()
    {
        top--;
    }
    int printTop()
    {
        return stack[top];
    }
    int getMin()
    {
        return minStack[top];
    }
};

int main()
{
    MinStack ms;
    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ms.push(x);
    }
    cin >> m;
    while (m--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            cin >> x;
            ms.push(x);
        }
        else if (ch == 2)
            ms.pop();
        else if (ch == 3)
            cout << ms.printTop() << endl;
        else if (ch == 4)
            cout << ms.getMin() << endl;
    }

    return 0;
}