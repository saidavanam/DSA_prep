#include<iostream>

/*With non-overloaded functions (functions with unique names), there is only one function that can potentially match a function call. 
That function either matches (or can be made to match after type conversions are applied), or it doesn’t (and a compile error results). 
With overloaded functions, there can be many functions that can potentially match a function call. 
Since a function call can only resolve to one of them, the compiler has to determine which overloaded function is the BEST match. 
The process of matching function calls to a specific overloaded function is called overload resolution.*/

// FUNCTIONS INSIDE OF OTHER FUNCTIONS IS NOT VALID IN C++.BUT IM WRITING HERE FOR MY NOTES SAKE...

void explain_overload_resolution()
{
    void print(int x)
    {
        std::cout << x << '\n';
    }

    void print(double d)
    {
        std::cout << d << '\n';
    }

    int main()
    {
        print('a');   // char does not match int or double, so what happens?
        print(5L);    // long does not match int or double, so what happens?

        return 0;
    }

    //BOTH CHAR AND LONG HAS IMPLICIT CONVERSION HERE. THEN WHAT IS THE BEST CONVERSION TO MAKE ??

}

/*
When a function call is made to an overloaded function, the compiler steps through a sequence of rules to determine which (if any) of the overloaded functions is the best match (we’ll cover these steps in the next section below).

At each step, the compiler applies a bunch of different type conversions to the argument(s) in the function call. For each conversion applied, the compiler checks if any of the overloaded functions are now a match. After all the different type conversions have been applied and checked for matches, the step is done. The result will be one of three possible outcomes:

No matching functions were found. The compiler moves to the next step in the sequence.

1)A single matching function was found. This function is considered to be the best match. The matching process is now complete, and subsequent steps are not executed.

2)More than one matching function was found. The compiler will issue an ambiguous match compile error. We’ll discuss this case further in a bit.

3)If the compiler reaches the end of the entire sequence without finding a match, it will generate a compile error that no matching overloaded function could be found for the function call.
*/

void explain_argument_matching_sequence_step_1()
{
    // step-1 :- compiler tries to find exact match at first and executes if found match

    void foo(int)
    {
    }

    void foo(double)
    {
    }

    int main()
    {
        foo(0);   // exact match with foo(int)
        foo(3.4); // exact match with foo(double)

        return 0;
    }

    /*

     Also compiler will apply a number of trivial conversions to the arguments in the function call. 
     The trivial conversions are a set of specific conversion rules that will modify types (without modifying the value) for purposes of finding a match.

     These include:

     1)lvalue to rvalue conversions
     2)qualification conversions (e.g. non-const to const)
     3)non-reference to reference conversions

    */
   void foo(const int)
    {
    }

    void foo(const double&)
    {
    }

    int main()
    {
        int x { 1 };
        foo(x); // x trivially converted from int to const int

        double d { 2.3 };
        foo(d); // d trivially converted from double to const double&

        return 0;
    }
}

void explain_matching_sequence_step_2()
{
    // If no exact match is found, the compiler tries to find a match by applying NUMERIC PROMOTION to the argument(s).

    void foo(int)
    {
    }

    void foo(double)
    {
    }

    int main()
    {
        foo('a');  // promoted to match foo(int)
        foo(true); // promoted to match foo(int)
        foo(4.5f); // promoted to match foo(double)

        return 0;
    }

    //In the first case, compiler does promotion from char to int.since it is possible so function call is resolved.
    //In the second case, compiler does promotion from bool to int
    //In the third case, promotion from float to int is not possible so it opts double.
}

void explain_matching_sequence_step_3()
{
    // If numeric promotion is not possible then compiler tries for conversion to another data type


    void foo(double)
    {
    }

    void foo(std::string)
    {
    }

    int main()
    {
        foo('a'); // 'a' converted to match foo(double)

        return 0;
    }
}

void explain_matching_sequence_step_4()
{
    // If no match is found via numeric conversion, the compiler tries to find a match through any user-defined conversions.

    
    class X // this defines a new type called X
    {
        public:
            operator int() { return 0; } // Here's a user-defined conversion from X to int
    };

    void foo(int)
    {
    }

    void foo(double)
    {
    }

    int main()
    {
        X x; // Here, we're creating an object of type X (named x)
        foo(x); // x is converted to type int using the user-defined conversion from X to int

        return 0;
    }
}

void explain_matching_sequence_step_5()
{
    //if still no matching compiler looks for ellipsis then if they do not exist then compiler will throw an ERROR.

}

