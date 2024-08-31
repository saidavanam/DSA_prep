#include<iostream>

// FUNCTIONS INSIDE OF OTHER FUNCTIONS IS NOT VALID IN C++.BUT IM WRITING HERE FOR MY NOTES SAKE...

//if u refer last file. compiler makes lot of conversions. not everytime it is desirable.
//WE CAN HALT THE CONVERSIONS BY DELETING FUNCTIONS FOR SPECIFIC TYPE

void deleting_functions()
{
    void printInt(int x)
    {
        std::cout << x << '\n';
    }

    void printInt(char) = delete; // calls to this function will halt compilation
    void printInt(bool) = delete; // calls to this function will halt compilation

    int main()
    {
        printInt(97);   // okay

        printInt('a');  // compile error: function deleted
        printInt(true); // compile error: function deleted

        printInt(5.0);  // compile error: ambiguous match

        return 0;
    }
}