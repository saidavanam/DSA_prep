
// Mutliple Constructors

//constructor overloading

class employee
{
    string m_name;
    int m_id;
    public:
        employee(string name,int id)
        {
            m_name = name;
            m_id = id;
        }
        employee(string name)
        {
            m_name = name;
        }
};

/*
IT IS A BAD PRACTICE TO CALL CONSTRUCTOR FROM ANOTHER CONSTRUCTOR.

class employee
{
   public:
   string m_name;
   int m_id;

   public:
      employee(string name)
      {
         m_name = name;
         
      }
      employee(string name,int id)
      {
         employee(name); ///*** COMPILE ERROR
         m_id = id;
      }
};

*/

// Another case

/*

class employee
{
   public:
   string m_name;
   int m_id;

   public:
      employee()
      {
         m_name = "sai"; //Temporary object
         
      }
      employee(string name,int id)
      {
         employee(); 
         m_id = id;
      }
};

int main()
{
   employee e{"sai",21};

   cout<<e.m_name<<' '<<e.m_id;
	

	return 0;
}


//Program executes but m_name is not updated since employee() is a temporary call. 

*/

// Instead you can use delegate constructors

/*
Constructors are allowed to delegate (transfer responsibility for) initialization to another constructor from the same class type. 
This process is sometimes called constructor chaining and such constructors are called delegating constructors.
*/

class employee
{
    private:
        string m_name{};
        int m_id{};

    public:
        employee(string name)
        {
            employee{name,0}; //delegates to another constructor
        }
        employee(string name,int id) : m_name{name},m_id{id}
        {
            cout<<"Employee "<<m_name<<" with "<<m_id<<'\n';
        }
};

int main()
{
    employee s1{"James"};
    employee s2{"sai",21};
}

// Creating Temporary class objects

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

void print(employee p)
{
    cout<<"Employee name is "<<p.m_name<<" and id is "<<p.m_id<<'\n';
}

int main(void)
{
    print(employee{"sai",21}); //Temporary class object.This gets destroyed after execution of this statement

}