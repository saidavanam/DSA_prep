#include <cmath> 
#include<iostream>
#include<set>

using namespace std;

bool judgeSquareSum(int c) {

        set<long> prefix;

        for(int i=0;i*i<=c;i++)
        {
            prefix.insert(i*i);
            
            if(prefix.find(c-i*i)!=prefix.end())
            {
                return true;
            }

        }

        return false;
        
}

int main()
{
    int c =2147482647;

    std::cout<<judgeSquareSum(c);

}