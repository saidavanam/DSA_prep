/*

Each member in c++ has a access level.
In c++ there are 3 types of access levels. These are private,public and protected.

->public class members can be accessed by other members of same class.


Access level	Access specifier	Member access	Derived class access	Public access
Public	            public:	           yes	              yes	                 yes
Protected	        protected:	       yes	              yes	                  no
Private	            private:	       yes	              no	                  no

It is a best practice to mention access specifiers for defining classes.

*/

class Date
{
    private:
        int year = 2001;
        int month = 11;
        int date = 17;

    public:
        void print()
        {
            std::cout<<year<<'/'<<month<<'/'<<date; // This is valid beacuse members can be used within the same class.
        }
        void modify(int &y)
        {
            y = year;
        }

/*
Access functions :- Access functions are the functions whose job is to retrieve or change the value of private member.

Access functions come in two flavors: getters and setters. 
Getters (also sometimes called accessors) are public member functions that return the value of a private member variable. 
Setters (also sometimes called mutators) are public member functions that set the value of a private member variable.

Getters are usually made const, so they can be called on both const and non-const objects. Setters should be non-const, so they can modify the data members.
But it is your wish anyway
*/

       const int return_date() //return values cant be changed since date is a private member. so use const as return type
       {
          return date; 
       }

       void set_date(int d)
       {
          date = d;
       }
// private members can be returned by reference also but they cant be modified later

      const &int return_date()
      {
         return date;
      }

};

int main(void)
{
    Date d;

    d.date = 20; // Compile error. private members can be used within the same class
    
    d.print(); // This is valid because print is public

    int y = 2000;

    d.modify(y);

}
    
// ACCESS LEVELS WORKS ON PER CLASSES BASIS NOT ON PER OBJECT BASIS