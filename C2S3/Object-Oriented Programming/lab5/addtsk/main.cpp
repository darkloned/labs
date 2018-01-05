#include <iostream>

template <typename T>
void printr(T t) 
{
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void printr(T t, Args... args)
{
    printr(args...);

    std::cout << t << std::endl;
}

int main()
{
    printr(3, -4.5, 'x', "OOP");
}
