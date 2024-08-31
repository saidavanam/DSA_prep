#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int add(int x,int y,int z) //DIFFERENCE IN NUMBER OF PARAMETERS
{
    return x+y+z;
}

double add(double x, int y) // FIRST PARAMETER IS DIFFERENT
{
    return x + y;
}

double add(double x,double y) //PARAMETERS ARE DIFFERENT
{
    return x+y;
}

/*
    But not

    double add(int x,int y) //PARAMETERS ARE SAME AS COMPARED TO FIRST DEFINITION SO THROWS AN ERROR
    {
        return x+y;
    }

*/

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout<<add(1,2,3); //calls add(int,int,int)
    std::cout<<'\n';
    std::cout<<add(1.2,3); //calls add(double.int)
    std::cout<<'\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    return 0;
}

/*
  function overloading gives ability to create multiple functions with same.
  THE POINT YOU HAVE TO KEEP REMEMBER IS THAT FUNCTION PARAMETERS HAS TO BE DIFFERENT EITHER IN NUMBER OF PARAMETERS OR TYPE OF ATLEAST ONE PARAMETER.
  IT DOES NOT COUNT RETURN TYPE

  WHILE CONSIDERING TYPE OF PARAMETERS THERE ARE SOME EXCEPTIONS.Excludes typedefs, type aliases, and const qualifier on value parameters(covered in next files). Includes ellipses.
*/