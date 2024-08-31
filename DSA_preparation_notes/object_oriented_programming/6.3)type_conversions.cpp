
using namespace std;

class foo
{
  private:
    int n1{};
    int n2{};

  public:
    foo(int p1,int p2)
    {
        n1 = p1;
        n2 = p2;
    }
    pair<int,int> getvalues()
    {
        return {n1,n2};
    }

}

printvalues(foo f)
{
    pair<int,int> values = f.getvalues();
    cout<< values.first <<' '<<values.second;
    
}

int main()
{
    foo f{4,5};
    //Implicit conversion takes place from int to foo object.constructors are designed in such a way to make that happen.

    printvalues({4,3}); //{4,3} is implictly converted to foo.
}

//ONLY ONE CONVERSION IS ALLOWED

class employee
{
    private:
     string m_name{};

    public:
        employee(string_view name)
        {
            m_name = name;
        }

        const string& get_name()
        {
            return m_name;
        }
     
}

void printstring(employee e)
{
    cout<<e.get_name()<<'\n';
}

/*
 printstring("sai") -> 2 conversions are not allowed. first is string to string_view and then string_view to employee.

 one way to resolve is to intilaize string with string view printstring("sai"sv)

*/

//conversions can be stopped by using explicit keyword

class foo
{
  private:
    int n1{};
    int n2{};

  public:
    explicit foo(int p1,int p2)
    {
        n1 = p1;
        n2 = p2;
    }
    pair<int,int> getvalues()
    {
        return {n1,n2};
    }

}

// Now printvalues({5,4}) doesnt work->compilation error

printvalues(foo f{4,3}); //is valid

/* Explicit constructors can be used for direct and direct list initialization.

foo f{4,3} and foo f(4,3) are valid.
*/

/*

****
An explicit constructor cannot be used to do copy initialization or copy list initialization.
An explicit constructor cannot be used to do implicit conversions (since this uses copy initialization or copy list initialization).

****
The modern best practice is to make any constructor that will accept a single argument explicit by default. 
This includes constructors with multiple parameters where most or all of them have default values. This will disallow the compiler from using that constructor for implicit conversions. 
If an implicit conversion is required, only non-explicit constructors will be considered.

*/

