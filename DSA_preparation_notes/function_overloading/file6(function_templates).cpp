
//Function templates are used when we want to create function which can work for multiple data types.

//A function template is a function-like definition that is used to generate one or more overloaded functions, each with a different set of actual types.

template<typename T>

T max(T a,T b)
{
    return a>b?a:b;
}

// now we can use function in any data type.MAKE SURE U PASS THE VARIABLES OF SAME TYPE IN FUNCTION CALLER. 

//SCOPE OF FUNCTION TEMPLATES ARE LIMITED TO FUNCTION THAT FOLLOWS AND CANNOT BE USED ANY WHERE.

//SO WE HAVE TO DECLARE TEMPLATE DEFINITION BEFORE FUNCTION EVERYTIME TO USE IT. 

//A function template is only instantiated the first time a function call is made in each translation unit. 
//Further calls to the function are routed to the already instantiated function.

int main()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)

    return 0;
}

//There is no need to mention written type also.compiler will only deduce based on function arguments.

std::cout << max<>(1, 2) << '\n'; //deduces to max<int>
std::cout << max(1, 2) << '\n'; //deduces to max<int>

#include<iostream>

<template typename T>

T max(T a,T b)
{
    return a>b?a:b;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    std::cout<<max(2,3)<<'\n'; //calls non template function. conflict between non template and template,non template prevails. 
    std::cout<<max<>(2,3)<<'\n'; //calls template function. 

}

//Favor the normal function call syntax when making calls to a function instantiated from a function template (unless you need the function template version to be preferred over a matching non-template function).

//FUNCTION WITH NON TEMPLATE PARAMETERS:-

// T is a type template parameter
// double is a non-template parameter
// We don't need to provide names for these parameters since they aren't used
template <typename T>
int someFcn (T, double)
{
    return 5;
}

int main()
{
    someFcn(1, 3.4); // matches someFcn(int, double)
    someFcn(1, 3.4f); // matches someFcn(int, double) -- the float is promoted to a double
    someFcn(1.2, 3.4); // matches someFcn(double, double)
    someFcn(1.2f, 3.4); // matches someFcn(float, double)
    someFcn(1.2f, 3.4f); // matches someFcn(float, double) -- the float is promoted to a double

    return 0;
}
