
/*
class is a program defined data type which holds data members and member functions.
Member functions can be declared within class or outside the class.

DATA MEMBERS IS PRIVATE BY DEFAULT IN C++. SO IT IS BETTER TO USE PUBLIC KEYWORD.
semicolon is must after ending the class definition

*/

class employee
{   
    public:
        int id;
        std::string phone_number;
        int age;
};

/*

Const objects DOESNT CALL NON-CONST MEMBER FUNCTIONS.

compulsory const keyword should be used for member functions.

BUT NON-CONST data members can call const member functions

*/

class Date
{
    int date;
    int month;
    int year;

    void print_date()
    {
        cout<<date<<'/'<<month<<'/'<<year;
    }

    const void const_print_date()
    {
        cout<<date<<'/'<<month<<'/'<<year;
    }
};

int main()
{
    const Date a;

    Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization. 
    //Aggregate intilization cannot be used for private and protected data members

    a.date = 12;
    a.month = 11;
    a.year = 01;

    a.print_date(); // COMPILE ERROR

    a.const_print_date(); //Executes properly
}

// class and structs in c++ supports const and non-const overloading

class Something
{
    void print()
    {
        std::cout << "non-const\n";
    }

    void print() const //This syntax is also valid
    {
        std::cout << "const\n";
    }
};

// The members of a struct are public by default
