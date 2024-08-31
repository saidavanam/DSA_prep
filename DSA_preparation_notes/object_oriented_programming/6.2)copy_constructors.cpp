

/*

copy constructor :- A copy constructor is a constructor that is used to initialize an object with an existing object of the same type.
After the copy constructor executes, the newly created object should be a copy of the object passed in as the initializer.

*/

class employee
{
    public:
     string m_name{};
     int m_id{};

     employee(string name,int id)
     {
        m_name = name;
        m_id = id;
     }


};

int main()
{
    employee e{"sai",21};
    employee e_copy{e}; //Implicit copy constructor. Just like variable copy.

}

//EXPLICIT COPY CONSTRUCTOR THROUGH LVALUE REFERENCE

class employee
{
    public:
     string m_name{};
     int m_id{};

     employee(string name,int id)
     {
        m_name = name;
        m_id = id;
     }

     //explicit copy constructor.pass lvalue reference instead of lvalue(gives compile error)
     employee(const employee &e):m_name{e.m_name},m_id{e.m_id} 
     {
        cout<<"copy constructor has been called successfully\n";
     }

     //Prefer implicit copy constructors unless u want to do any change in copies.

};

int main()
{
    employee e{"sai",21};
    employee e_copy{e}; //Explicit copy constructor

}

// default constructor

employee(const employee& e) = default;

//Occasionally we run into cases where we do not want objects of a certain class to be copyable. 
//We can prevent this by marking the copy constructor function as deleted, using the = delete syntax:

employee(const employee& e) = delete;

employee e_copy{employee e{5}}; //Here constructor is called 2 times which is un necessary

//COPY ELISON :-Copy elision is a compiler optimization technique that allows the compiler to remove unnecessary copying of objects.

/*
copy elison treats employee e_copy{employee e{5}} as employee e_copy{5}. It is a compiler optimization technique started from c++17

*/


