#include<iostream>

// CONSTEXPR HELPS US TO DO EVALUATE VARIABLE OR FUNCTION IN COMPILE TIME ONLY INSTEAD OF RUN TIME

int factorial(int n)
{
    if(n<=0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

constexpr int const_expr_factorial(int n)
{
    if(n<=0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    int num = factorial(5); // calls at run time.

    constexpr int num1 = const_expr_factorial(5); // calls at compile time.

    int n;
    cin>>n;

    constexpr int num2 = const_expr_factorial(n); // compile error. n cannot be evaluated at compile time so constexpr cant be used here.

    //But constexpr can be used to evaluate at runtime also.

    int num3 = const_expr_factorial(n); // This is valid. Expression evaluates at run time.


    //constexpr is very useful in defining constants so that it can be evaluated at compile time only.

    /* Ex:- */
    constexpr double pi = 3.14159265359;

     constexpr int g { greater(5, 6) };              // case 1: always evaluated at compile-time
    std::cout << g << " is greater!\n";

    std::cout << greater(5, 6) << " is greater!\n"; // case 2: may be evaluated at either runtime or compile-time

    int x{ 5 }; // not constexpr but value is known at compile-time
    std::cout << greater(x, 6) << " is greater!\n"; // case 3: likely evaluated at runtime

    std::cin >> x;
    std::cout << greater(x, 6) << " is greater!\n"; // case 4: always evaluated at runtime

}


