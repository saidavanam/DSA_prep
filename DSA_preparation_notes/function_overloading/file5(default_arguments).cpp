#include<iostream>

// A default argument is a default value provided for a function parameter.


void print(int x, int y=4) // 4 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    print(1, 2); // y will use user-supplied argument 2

    //if one is a default argument in function definition then it is ok to give one argument to its caller since other argument will be default only.
    print(3); // y will use default argument 4, as if we had called print(3, 4) 

    return 0;
}

// DO NOTE THAT DEFAULT ARGUMENTS SHOULD BE AT RIGHT. ONCE U DECLARED DEFAULT ARGUMENT THEN THE ARGUMENTS RIGHT OF IT SHOULD BE DEFAULT ARGUMENTS ONLY.

// Only = works for default arguments. other intializations doesnt work

void foo(int x = 5);   // ok
void goo(int x ( 5 )); // compile error
void boo(int x { 5 }); // compile error



void print(int x=10, int y=20, int z=30)
{
    std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

int main()
{
    print(1, 2, 3); // all explicit arguments
    print(1, 2); // rightmost argument defaulted
    print(1); // two rightmost arguments defaulted
    print(); // all arguments defaulted

    return 0;
}

//DEFAULT ARGUMENTS DOESNT WORK FOR FUNCTION POINTERS