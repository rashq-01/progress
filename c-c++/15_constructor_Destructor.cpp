#include<iostream>
using namespace std;
class temp{
    public:
    //Default Constructor
    // temp() = default; //this "default" value is also same as the default constructor
                    
                    //Or

    temp(){
        cout<<"Default Constructor is Called..."<<endl;
    }

    //Paramaterized Constructor
    temp(int a){
        cout<<"Paramaterized Constructor is called..."<<endl;
    }

    //Copy Constructor
    temp(const temp &s){
        cout<<"Copy constructor is called..."<<endl;
    }
  
         //While enabling this delete constructor it will thow error bcz of its fucntion to delete default constructor
   
    //Delete constructor
    // temp(const temp&) = delete; //It delete the default constructor and at the time of creting object of this class it will thow an error




    //Destructor
    ~temp(){
        cout<<"Destructor is called...."<<endl;   //This destructor fuction will run equal to the number of object created
    }




};
int main(){
    //Calling Default Constructor
    temp t1;
    //Calling Paramaterized Constructor
    temp t2(4);
    //Calling Copy Constructor
    temp t3 = t1;

}