#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

//Books class

class book{
    private:
        static int idGenerator;
        int id;
        string title;
        string author;
        string genre;
        int publishedYear;
        bool isAvailable;
        int borrowerId;

    public:
        book(string titl, string auth, string gen, int pubYear, bool avaib){
            id = ++idGenerator;
            title = titl;
            author = auth;
            genre = gen;
            publishedYear = pubYear;
            isAvailable = avaib;
        }
        int getId(){
            return id;
        }
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        string getGenre(){
            return genre;
        }
        int getPublishedYear(){
            return publishedYear;
        }
        bool getisAvailable(){
            return isAvailable;
        }
        int getBorrowerId(){
            return borrowerId;
        }
    
};



//Member class

class member{
    private:
        string rollNo;
        string name;
        string address;
        string phone;
        string email;
        int borrowedBookId;

    public:
        member(string roll, string nam, string add, string ph, string em){
            rollNo = roll;
            name = nam;
            address = add;
            phone = ph;
            email = em;
            borrowedBookId = 0;
        }
        string getRollNo(){
            return rollNo;
        }
        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        string getPhone(){
            return phone;
        }
        string getEmail(){
            return email;
        }
        int getBorrowedBooks(){
            return borrowedBookId;
        }

};

//Library class

class library{
    private:
        vector<book> books;
        vector<member> members;

    public:
        void addBook(){
            string title;
            string author;
            string genre;
            int publishedYear;
            int avl = true;
            cout<<"Enter the title of the book: ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter the author of the book: ";
            getline(cin,author);
            cout<<"Enter the genre of the book: ";
            getline(cin,genre);
            cout<<"Enter the published year of the book: ";
            cin>>publishedYear;
            books.push_back(book(title, author, genre, publishedYear, avl));
            

        }


        void addBook(string title, string author, string genre, int publishedYear, int avl = true){
            books.push_back(book(title, author, genre, publishedYear, avl));
            

        }


        void addmember(){
            string roll;
            string name;
            string address;
            string phone;
            string email;
            cout<<"Enter the roll No: ";
            getline(cin,roll);
            cout<<"Enter the name of the member: ";
            getline(cin,name);
            cout<<"Enter the address of the member: ";
            getline(cin,address);
            cout<<"Enter the phone number of the member: ";
            getline(cin,phone);
            cout<<"Enter the email of the member: ";
            getline(cin,email);
            members.push_back(member(roll,name, address, phone, email));
        }

        void addmember(string roll, string name, string address, string phone, string email){
            members.push_back(member(roll,name, address, phone, email));
        }


        void displayAllBooks(){
            cout<<endl<<endl<<endl;
            cout<<"-----------------Books in the library-----------------"<<endl<<endl;
            for(int i = 0; i<books.size(); i++){
                cout<<"Book ID: "<<books[i].getId()<<endl;
                cout<<"Title: "<<books[i].getTitle()<<endl;
                cout<<"Author: "<<books[i].getAuthor()<<endl;
                cout<<"Genre: "<<books[i].getGenre()<<endl;
                cout<<"Published Year: "<<books[i].getPublishedYear()<<endl;
                cout<<endl<<endl;
            }
        }

        void findBook(){
            int BOOKID;
            string BOOKNAME;
            cout<<"Enter the Book ID: ";
            cin>>BOOKID;
            cin.ignore();
            cout<<"Enter the Book Title";
            getline(cin,BOOKNAME);
            cout<<endl;
            for(int i=0;i<books.size();i++){
                int bookId = books[i].getId();
                string bookName = books[i].getTitle();
                if(bookId==BOOKID || bookName==BOOKNAME){
                cout<<"Book ID: "<<books[i].getId()<<endl;
                cout<<"Title: "<<books[i].getTitle()<<endl;
                cout<<"Author: "<<books[i].getAuthor()<<endl;
                cout<<"Genre: "<<books[i].getGenre()<<endl;
                cout<<"Published Year: "<<books[i].getPublishedYear()<<endl;
                int availability = books[i].getisAvailable();
                if(availability){
                    cout<<"Book Availability: True"<<endl;
                }
                else{
                    cout<<"Book Availability: False"<<endl;
                }
                break;
                }
            }
        }


        
};



int book::idGenerator = 0;

int main(){
    library l;
    l.addBook();


}