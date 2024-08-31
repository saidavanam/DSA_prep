#include<iostream>
#include<string>


/*

lvalues :- An lvalue (pronounced “ell-value”, short for “left value” or “locator value”,
and sometimes written as “lvalue”) is an expression that evaluates to an IDENTIFIABLE OBJECT, VARIABLE or FUNCTION (or bit-field).

lvalues tend to have an location in the memory.

rvalues :- An rvalue (pronounced “arr-value”, short for “right value”, and sometimes written as r-value) is an expression that is not an lvalue.
Rvalue expressions evaluate to a VALUE. 

rvalues doesnt store in memory.

*/

int get_value1()
{
    return 5;
}

int& get_value2()
{
    static int value = 5;
    return value;
}

//lvalue cannot take REFERENCE from an rvalue

int set_result_1(int &value) // parameter is an reference
{

}

int set_result_2(const int &value)
{

}

void strings_1(string name)
{

}

void strings_2(const string &name)
{

}

void strings_3(string &&name) //double ampersand -> rvalue reference




void explain_lvalue_and_rvalue()
{
    int a = 10; //a is an lvalue expression because a has a location in memory.

    int result = get_value1(); //get_value() is an rvalue because return result of get_value will not be stored anywhere. But result is an lvalue.

    get_value1() = 5; // *** is an invalid expression because values should not be assigned to the rvalue 

    // NOT ALL FUNCTION CALLERS ARE RVALUES
    // suppose take this scenario


    get_value2() = 10; //*** Here this expression is valid. value in get_value remains as 5 but get_value changes to what we assign.

    int a = 10;

    set_result_1(a); //This is valid in c++. one lvalue can be referenced to another lvalue.
    set_result_1(10); //This is invalid. rvalue cannot be referenced to a lvalue.


    //If lvalue is CONST REFERENCE then rvalues can be referenced to lvalue.

    //MOST OF THE CASES WHATEVER IS IN LEFT SIDE IS AN LVALUE AND WHATEVER IS IN RIGHT SIDE IS AN RVALUE.

    set_result_2(10) // this is valid

    string first_name = "sri sai";
    string last_name = "subramanyam";

    strings_1(first_name+last_name); // THIS EXPRESSION IS INVALID BECAUSE first_name+last_name is an rvalue(temporary_string)

    strings_2(first_name+last_name); //This expression is valid because CONST REFERENCE is used

    //THERE EXISTS RVALUE REFERENCES WHERE TEMPORARY OBJECTS ARE STORED JUST FOR FUNCTION CALLING

    //RVALUE REFERENCES ARE REPRESENTED BY DOUBLE AMPERSAND

    strings_3(first_name+last_name); // valid one

    int a = 23; // modifable lvalue

    const int a = 23; //non-modifiable lvalue

    //REFERENCES CANNOT BIND TO NON-MODIFIABLE LVALUE but by using CONST REFERENCES WE CAN DO

/*
    A rule of thumb to identify lvalue and rvalue expressions:-
    1)Lvalue expressions are those that evaluate to variables or other identifiable objects that persist beyond the end of the expression.
    2)Rvalue expressions are those that evaluate to literals or values returned by functions/operators that are discarded at the end of the expression.
*/

// scope of lvalue references

    {
        int x = 10;
        int &ref = x;
        // do operations on ref
    } //reference dies here


}

// Question

#include <iostream>

int main()
{
    int x{ 1 };
    int& ref{ x };

    std::cout << x << ref << '\n';

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref << '\n';

    x = 4;

    std::cout << x << ref << '\n';

    return 0;
}

/*
  output :-
  11
  22
  44
*/






