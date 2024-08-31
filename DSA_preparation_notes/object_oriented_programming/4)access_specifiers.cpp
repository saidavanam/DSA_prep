

/*
Do not return non const references to private data members. 
This allows to CHANGE the private data members which is very dangerous as it removes limit of access levels.
*/


class Date
{
    private:
       int date = 17;
       int month = 11;
       int year = 2001;

    public:
        int& set_date()
        {
            return date;
        }
        void print()
        {
            std::cout<<date<<'\n'; 
        }
}

int main()
{
    Date d;

    d.set_date() = 25; //CHANGES VALUE OF date(PRIVATE MEMBER) TO 25.

    //Also be careful while dealing with rvalue references as it may lead to dangling references.

    int &ref = d.set_date();

    std::cout<<ref<<'\n'; //undefined behaviour 

}