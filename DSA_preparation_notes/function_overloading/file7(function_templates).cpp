#include <iostream>
#include <string>

template <typename T>
T addOne(T x);

template<>
std::string addOne<std::string>(std::string x)
{
    return x + 1;
}

int main()
{
    std::string hello{ "Hello, world!" };
    std::cout << addOne(hello) << '\n';

    return 0;
}

//COMPILE ERROR:- '+' OPERATION BETWEEN STD::STRING AND INT IS NOT DEFINED

#include <iostream>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main()
{
    std::cout << addOne("Hello, world!") << '\n';

    return 0;
}

//THIS WORKS BECAUSE STRING HERE IS AN ARRAY OF CHARACTERS.

//OUTPUT IS ello, world!

//BEWARE WITH STATIC VARIABLES

#include <iostream>

// Here's a function template with a static local variable that is modified
template <typename T>
void printIDAndValue(T value)
{
    static int id{ 0 };
    std::cout << ++id << ") " << value << '\n';
}

int main()
{
    printIDAndValue(12);
    printIDAndValue(13);

    printIDAndValue(14.5);

    return 0;
}

/* OUTPUT IS 
1) 12
2) 13
** 1) 14.5  NOT 3) 14.5

Reason is function which compiler creates for templates is different for int and double
*/

//REFER ARTICLE 11.8,11.9,11.10 Function templates in multiple files,Function templates with multiple template types and Non template parameters
