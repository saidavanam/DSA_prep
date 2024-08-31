#include<iostream>
#include<vector>


/*
  problem statement:-given matrix v which contains only zeros and ones.whenever v[i][j]=0 then replace entire ith row and jth column with zeros.
*/

/*

Brute force solution:- 

1)when v[i][j]=0 then update entire ith row and jth column to -1
2)replace -1 with 0 in the matrix 

Time complexity is o((n*m)*(n+m))+o(n+m) [in the order of cube]

*/

void mark_column(std::vector<std::vector<int> > &v,int j)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i][j]==1)
        {
            v[i][j]=-1;
        }
    }

}

void mark_row(std::vector<std::vector<int> > &v,int j)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[j][i]==1)
        {
            v[j][i]=-1;
        }
    }

}

void brute(std::vector<std::vector<int> > &v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[i][j]==0)
            {
                mark_column(v,j);
                mark_row(v,i);
            }

        }
    }

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[i][j]==-1)
            {
                v[i][j]=0;
            }

        }
    }

}

/*

Better solution:-
    Here we create two arrays called row and col which are intilaised to zeros at starting.
    1st iteration:-whenever matrix[i][j]=0,then row[i] and col[j] marked as one

    2nd iteration(updating values in a matrix):-if row[i] OR col[j] marked as 1 then matrix[i][j]=0

    time complexity is o(2*n*m).where n and m are no.of cols and rows.
    space complexity is o(n)+o(m)
*/

void better(std::vector<std::vector<int> > &v)
{
    int row[v.size()]={0};
    int col[v.size()]={0};

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(row[i]==1 || col[j]==1)
            {
                v[i][j]=0;
            }
        }
    }
}

/*

Optimal solution:-Try to use O(1) space approach with same time complexity

*/

void optimal(std::vector<std::vector<int> > &v)
{

}


int main(void)
{
    std::vector<std::vector<int> > v(4,std::vector<int>(4,0));

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            std::cin>>v[i][j];
        }
    }

    better(v);


    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            std::cout<<v[i][j]<<' ';
        }
        std::cout<<'\n';
    }



}