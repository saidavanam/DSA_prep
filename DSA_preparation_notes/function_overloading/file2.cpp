#include<iostream>

void explain_function_overloading()
{
    typedef int Height; // typedef
    using Age = int; // type alias

void print(int value);
void print(Age value); // not differentiated from print(int)
void print(Height value); // not differentiated from print(int)

/*throws an error because all function arguments are same*/

//For parameters passed by value, the const qualifier is also not considered. Therefore, the following functions are not considered to be differentiated
void print(int);
void print(const int); // not differentiated from print(int)


int getRandomValue();
double getRandomValue();
//throws an error because function overloading doesnt account for return types

/*
 Note :-
 
When the compiler compiles a function, it performs name mangling, which means the compiled name of the function is altered (“mangled”) based on various criteria, such as the number and type of parameters, so that the linker has unique names to work with.

For example, some function with prototype int fcn() might compile to name __fcn_v, whereas int fcn(int) might compile to name __fcn_i. So while in the source code, two overloaded functions share a name, in compiled code, the names are actually unique.

There is no standardization on how names should be mangled, so different compilers will produce different mangled names.
*/



}