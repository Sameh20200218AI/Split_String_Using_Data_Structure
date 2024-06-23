#include <iostream>
#include<string>
using namespace std;
class StudentName
{
private :
    string name;
    string *name_as_array;
public:

    StudentName()
    {
        name ="";
    }
    StudentName(string n)
    {
        name = n;
        filter_name();


    }
    void filter_name()
    {
        string filter = "";
        bool is_space ;
        int index_head_space=-1;
        int index_last_space = name.size();
        for(int i=0;i<name.size();i++)
        {
            if(name[i]==' ')
                index_head_space = i;
            else
                break;
        }
        for(int i=name.size()-1;i>=0;i--)
        {
            if(name[i]==' ')
                index_last_space = i;
            else
                break;
        }
        for(int i=index_head_space+1;i<index_last_space;i++)
        {
            if(name[i]!=' ')
              filter+=name[i];
            if(name[i]==' '&&name[i+1]!=' ')
                filter+=name[i];
            if(name[i]==' '&& name[i+1]==' ')
                continue;
        }
        name = filter ;
    }
    int num_of_space()
    {
        int cnt=0;
       for(int i=0;i<name.size();i++)
       {
           if(name[i]==' ')
            cnt++;
       }
       return cnt;
    }
    void print()
    {
        if(isEmpty())
        {
            cout <<"Your name that you enter it is empty !!!"<<endl;
        }
        else
        {

              name_as_array = new string [num_of_space()+1];
              for(int i=0;i<(num_of_space()+1);i++)
              {
                 name_as_array[i]="";
              }
              int cnt=0;
              for(int i=0;i<name.size();i++)
              {
                 if(name[i]!=' ')
                  {
                    name_as_array[cnt] += name[i];
                  }
                  else
                   cnt++;
               }
            cout <<"detailed parts of the name are:"<<endl;
            for(int i=0;i<(num_of_space()+1);i++)
             {
               cout <<i+1<<" ) "<<name_as_array[i]<<endl;
             }
        }

    }
    void  replace_(int first_position,int second_position)
    {
        if(first_position<1 || second_position> (num_of_space()+1)||second_position<1||first_position>(num_of_space()+1))
           cout <<"Cannot replace this two positions"<<endl;
        else if(isEmpty())
             cout <<"Your name that you enter it is empty !!!"<<endl;
        else
           {
               string temp = name_as_array[first_position-1];
                name_as_array[first_position-1] =name_as_array[second_position-1];
               name_as_array[second_position-1] = temp;
               cout <<"This two positions is valid , then your name after replacement is : "<<endl;
               int cnt=0;

              cout <<"detailed parts of the name are:"<<endl;
              for(int i=0;i<(num_of_space()+1);i++)
                {
                   cout <<i+1<<" ) "<<name_as_array[i]<<endl;
                }

           }


    }
    bool isEmpty()
    {
        return name=="";
    }
    ~StudentName()
    {
        delete [] name_as_array;
         name_as_array=0;
    }
};
int main()
{
    string name = "Sameh Raouf Helmy Hanna ";
    StudentName sameh(name);
    sameh.print();
    sameh.replace_(1,4);
    //-------------------------------------
    cout <<"Enter your name : "<<endl;
    string yourName;
    getline(cin,yourName);
    StudentName obj(yourName);
    obj.print();
    cout << "Please enter two positions : "<<endl;
    int position1,position2;
    cin >>position1>>position2;
    obj.replace_(position1,position2);


    return 0;
}
