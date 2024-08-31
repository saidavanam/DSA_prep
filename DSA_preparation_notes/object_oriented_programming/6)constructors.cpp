/*
A constructor is a special member function that is automatically called after a non-aggregate class type object is created.

When a non-aggregate class type object is defined, the compiler looks to see if it can find an accessible constructor that is a match for the initialization values provided by the caller (if any).

If an accessible matching constructor is found, memory for the object is allocated, and then the constructor function is called.
If no accessible matching constructor can be found, a compilation error will be generated.

REMEMBER THAT CONSTRUCTOR DOESNT CREATE OBJECTS

Beyond determining how an object may be created, constructors generally perform two functions:

They typically perform initialization of any member variables (via a member initialization list)
They may perform other setup functions (via statements in the body of the constructor). This might include things such as error checking the initialization values, opening a file or database, etc…

Unlike normal member functions, constructors have specific rules for how they must be named:

Constructors must have the same name as the class (with the same capitalization). For template classes, this name excludes the template parameters.
Constructors have no return type (not even void).

*/

class student
{
   int age=20,phy=90,che=95,math=100;
   public:
      student(int a,int p,int c,int m) //constructor
    {
      age = a;
      phy = p;
      che = c;
      math = m;
    }
      void total_score()
      {
         cout<<phy+che+math<<'\n';
      }
      void display_age();
};

class addition
{
   int n1=9,n2=12;
   public:
      addition(int a,int b): n1{a},n2{b} // one more way of intilaizing members. copy intilization(=) doesnt work here.
      {
         cout<<n1+n2;
      }
};

int main()
{
    addition add{}; //COMPILE ERROR. NO MATCHING CONSTRUCTOR FOUND.
    //make sure constructors has to be matched
}

//Member variables in a member initializer list should be listed in order that they are defined in the class.

// If a member has both a default member initializer and is listed in the member initializer list for the constructor, the member initializer list value takes precedence.

/*
Question :- Write a class named Ball. Ball should have two private member variables, one to hold a color, and one to hold a radius. Also write a function to print out the color and radius of the ball.

The following sample program should compile:

int main()
{
	Ball blue{ "blue", 10.0 };
	print(blue);

	Ball red{ "red", 12.0 };
	print(red);

	return 0;
}

*/

class Ball
{
   string color;
   int value;
   public:
      Ball(string col,int data)
      {
         color = col;
         value = data;
      }
      string retrive_col()
      {
         return color;
      }
      int retrive_val()
      {
         return value;
      }
};

void print(Ball obj)
{
   // cout<<"Ball(",obj.color,',',obj.value,")\n";
   cout<<obj.retrive_col()<<' ';
   cout<<obj.retrive_val()<<'\n';
}

//*** Use getters and setters to update and retrieve the data

// Default constructor :- Constructor with no arguments and has only default arguments.

addition()
{
    cout<<5+9<<'\n';
}
addition(int x=10,int y=23)
{
    cout<<x+y<<'\n';
}

/* Constructors can be overloaded. 
*/

class student
{
   int age=20,phy=90,che=95,math=100;
   public:
      student()
      {
        cout<<"No operation is done here";
      }
      student(int a,int p,int c,int m) //constructor
    {
      age = a;
      phy = p;
      che = c;
      math = m;
    }
      void total_score()
      {
         cout<<phy+che+math<<'\n';
      }
};

/* *** A CLASS CANNOT HAVE TWO DEFAULT CONSTRUCTORS

class addition
{
   int n1=9,n2=12;
   public:

      addition(int n1=10,int n2=5){
         cout<<n1+n2;
      }
      addition()
      {
         cout<<n1+n2;
      }
};

//THIS GIVES AN COMPILER ERROR

*/ 

// Using = default to generate an explicitly defaulted default constructor

class addition
{
   int n1=9,n2=12;
   public:
    addition() = default;
      addition(int a,int b): n1{a},n2{b} 
      {
         cout<<n1+n2;
      }
};

