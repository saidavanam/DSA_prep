

/*

In object-oriented programming (often abbreviated as OOP), the focus is on creating program-defined data types that contain both properties and a set of well-defined behaviors. 
The term “object” in OOP refers to the objects that we can instantiate from such types.

suppose take example of car. parts of car,properties are defined as attributes and functionalities are referred as member functions.

*/

#include <iostream>
#include <string_view>

struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};

struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

int main()
{
    constexpr Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}


/*
So much repetition of code. But this can be replaced by creating one common struct called animal.
But what if we want to add a new member to Chicken that’s not applicable to the other animals (e.g. wormsPerDay)? With a common Animal struct, 
all animals will get that member.
With our OOP model, we can restrict that member to Chicken objects.
*/