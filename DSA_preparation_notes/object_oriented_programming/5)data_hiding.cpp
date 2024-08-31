
/*
 Interface :- Interface tells how user of class type behaves with objects of class type.
 Because only public members can be accessed from outside of the class type, the public members of a class type form its interface. 
 For this reason, an interface composed of public members is sometimes called a public interface.

 In programming, data hiding (also called information hiding or data abstraction) is a technique used to enforce the separation of interface and implementation by hiding the implementation of a program-defined data type from users.

 Implementation of data hiding :-

 1)All data members should be made to private.

 2)Member functions(not all) should be made to public so that user can access them to manipulate objects.

 Data Hiding makes classes easier to use and reduces complexities.Because to use an class,you no need to know hidden implementation details rather
 understanding interface is enough:what member functions are publicly available, what arguments they take, and what values they return.

 Ex:- various methods in c++ stl 

*/

#include<iostream>
#include<vector>
#include<string>

int main(void)
{
    std::vector<int> v;
    v.push_back(21);
    v.push_back(22);
    v.pop_back();

    //here we just need to know what these methods are doing and there is no need to understand its hidden implementation to use them.

}

/*
DATA HIDING ALLOWS US TO MAINTAIN CLASS INVARIANTS

CLASS INVARIANT:- class invariant are the conditions that must be true throughout the lifetime of an object in order for the object to stay in valid state.

*/

//Ex:-

class employee
{
    string name = 'sai';
    char first_letter = 's';

    public:
        void set_name(string Name)
        {
            name = Name;
        }
        void print()
        {
            std::cout<<"Name is "<<name<<" and first letter is "<<first_letter;
        }
};

class employee2
{
    string name = "sai";
    char first_letter = 's';

    public:
        void set_name(string Name)
        {
            name = Name;
        }
        void first_letter()
        {
            first_letter = name.front();
        }
        void print()
        {
            std::cout<<"Name is "<<name<<" and first letter is "<<first_letter;
        }
};

int main()
{
    //1st case

    employee e;
    e.print();

    //Name is sai and first letter is s.

    e.set_name('mourya');
    e.print();

    //Name is mourya and first letter is s. CLASS INVARIANCE IS LOST

    //2nd case
    employee2 e2;
    e2.print();

    //Name is sai and first letter is s.

    e2.set_name("mourya");
    e2.first_letter();
    e2.print();

    //Name is mourya and first letter is m. CLASS INVARIANT.THERE IS EXTRA METHOD first_letter WHICH HAS HIDDEN IMPLEMENTATION AND HELPED TO MAINTAIN CLASS INVARIANCE.

}

