/*
C++ provides functions to reduce function call overhead.

Function inlining is a compiler optimization technique where the function call is replaced with the actual body of the function

when inline is used for a function definition. when that function is called,instructions in the function definition is executed in the function itself
where it is called instead of creating seperate memory on the stack .

When the program executes the function call instruction the CPU stores the memory address of the instruction following the function call, copies the arguments of the function on the stack, and finally transfers control to the specified function. The CPU then executes the function code, stores the function return value in a predefined memory location/register, and returns control to the calling function. 
This can become overhead if the execution time of the function is less than the switching time from the caller function to called function (callee). 

It might not be useful when functions are complex.
*/

// syntax:- inline return_type function_name(parameters)

inline int add(int a,int b)
{
    //function body
    return a+b;
}

/*
The compiler may not perform inlining in such circumstances as: 

If a function contains a loop. (for, while and do-while) 
If a function contains static variables. 
If a function is recursive. 
If a function return type is other than void, and the return statement doesn’t exist in a function body. 
If a function contains a switch or goto statement. 

-> Disadvantage of using inline functions is duplicacy of instructions

Also inlining functions leads to increased register usage because all the variables from the inlined function need to be accommodated within the calling function. 
If this increase in variables is significant, it can cause a strain on the CPU's registers, potentially leading to performance degradation due to register spillover (where data has to be moved to slower memory because there aren't enough registers).

*/