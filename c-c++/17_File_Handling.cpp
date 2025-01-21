#include<iostream>
#include<fstream>
#include<string>
using namespace std;
// int main(){
//     fstream myfile;
//     myfile.open("17_Handling.txt",ios::app);
//     if(myfile.is_open()){
//         string str;
//         cout<<"Enter name to save: ";
//         cin>>str;
//         myfile <<str;
//         myfile.close();
//     }
//     myfile.open("17_Handling.txt",ios::app);
//     if(myfile.is_open()){
//         string str;
//         cout<<"Enter name to save: ";
//         cin>>str;
//         myfile<<"\n"<<str;
//         myfile.close();
//     }
//     myfile.open("17_Handling.txt",ios::app);
//     if(myfile.is_open()){
//         string str;
//         cout<<"Enter name to save: ";
//         cin>>str;
//         myfile<<"\n"<<str;
//         myfile.close();
//     }
//     myfile.open("17_Handling.txt",ios::in);
//     if(myfile.is_open()){
//         string line;
//         while (getline(myfile,line)){
//             cout<<line<<endl;
//         }
        
//     }


// }



    //Comment out all previous program


struct Student {
    char name[50];
    int age;
};

int main() {
    ofstream file("students.dat", ios::binary); // Open binary file for writing
    if (file) {
        Student s1 = {"Alice", 20};
        file.write(reinterpret_cast<char*>(&s1), sizeof(s1)); // Write object to file
        file.close();
        cout << "Binary data written successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
    return 0;
}