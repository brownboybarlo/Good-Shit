#include <iostream>

char get_top(char stack[], int sp)
{
    if(sp==0)
    {
        return 0;
    }
    return stack[sp-1];
}

int get_size(int sp)
{
    return sp;
}

void push(char stack[], int &sp, char d)
{
    stack[sp] = d;
    sp++;
}

void pop(char stack[], int &sp)
{
    stack[sp] = 0;
    sp--;
}

int main()
{
    const int MAX = 500;
    char stack[MAX];
    int sp = 0;
    char d;
    char v;
    int w;
    
    for(int i = 0;i<5;i++)
    {
        std::cout<<"Enter a character: ";
        std::cin >> d;
        push(stack, sp, d);
    }
    
    w = get_size(sp);
    std::cout << w;
    
    for(int i = 0; i<5; i++)
    {
        v = get_top(stack, sp);
        std::cout << v << std::endl;
        pop(stack, sp);
    }
    
    w = get_size(sp);
    std::cout << w;
}
