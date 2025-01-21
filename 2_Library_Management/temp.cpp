#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    fstream myfile;
    myfile.open("files/temp.txt",ios::app);
    if(myfile.is_open()){
        string char1;
        string char2;
        cout<<"Enter string 1 : ";
        getline(cin,char1);
        cout<<"Enter string 2: ";
        getline(cin,char2);
        myfile<<char1<<"\n";
        myfile<<char2<<"\n";
        myfile.close();
        cout<<"data successfully written...";

    }
    else{
        cout<<"Error in Opening file....";
    }
}