#include <iostream>
#include <vector>
#include<string>
using namespace std;

int totalStudents = 0;

//  details of books
class Books{
    protected:
        vector<string> booksTitle = {"c++"       ,"java"        ,"software engineering","maths"   ,"DSA" ,"english"};
        vector<string> booksAuthor = {"ab"  ,   "cd"            ,"ef"                  ,"gh"      ,"ij"  ,"kl"};
        // vector<int>    booksCount =  { 4          ,3           ,8 };
};

// details of issued books
class issuedBooks{
    protected: 
        vector<string> issuedBooksTitle;
        vector<string> issuedBooksAuthor;
        vector<string> studentIDToIssuedBook;
    public:
    // vector<string> getBooksTitle(){return issuedBooksTitle;}
    // vector<string> getBooksAuthor(){return issuedBooksAuthor;}
};

// keep record of all students in the library system
class Student{
    private:
        // string studentName;
        // string studentID;
        vector<string> studentName;
        vector<string> studentID;
    public:
        // adding student to the record
        void setStudentData(string name , string id){
            if ( totalStudents == 0){
                this->studentName.push_back(name);
                this->studentID.push_back(id);
                cout<<"New student added to record successfully..." << endl;
            }
            else{
                bool notPresent = true;
                for ( int i = 0; i<totalStudents; i++){
                    if ( studentID.at(i) == id ){
                        notPresent = false;
                        cout<<"Student with id: '"<<id<<"' is already in the record"<< endl;
                        return;
                    }
                }
                if(notPresent){
                    this->studentName.push_back(name);
                    this->studentID.push_back(id);
                    cout<<"New student added to record successfully...." << endl;
                }
            }
            totalStudents++;
        }
        // checking if student id is present in the database or not
        bool studentIsPresentOrNot(string idForSearch){
            for ( int i = 0; i<studentID.size(); i++){
                if ( studentID.at(i) == idForSearch){
                    return true;
                }
            }
            return false;
        }

        // printing name and id of all students
        void printAllStudent(){
            cout<<"Total students are: " << endl;
            if (totalStudents == 0){
                cout<<"No Student is present in the record..." << endl;
                return;
            }
            for ( int i = 0; i<studentName.size(); i++){
                cout<<"Name: "<<studentName.at(i)<<" ID: "<<studentID.at(i) << endl;
            }
        }
        // string getName(){ return studentName;}
        // string getID(){ return studentID;}
};

// Main Library calss
class Library : Books , issuedBooks , Student{
    public:
        // adding new book to the databse
        void addBook(string bookName,string byAuthor){
            booksTitle.push_back(bookName);
            booksAuthor.push_back(byAuthor);
            cout<<"Book added successfully"<<endl;
        }
        
        // printing all details of all books in the database 
        void printAll(){
            cout<<"------- Available Books -------"<<endl;
            for (int i = 0; i<booksTitle.size();i++){
                cout<<"Book: "<<booksTitle.at(i) <<"  By: " << booksAuthor.at(i)<< endl;
            }cout<<endl;
        }
        
        // searchint book by its title in the database
        void searchBookByTitle(string title){
            bool notAvailable = true;
            for ( int i = 0; i< booksTitle.size(); i++){
                if ( booksTitle.at(i) == title){
                    cout<<"Book "<< booksTitle.at(i)<< " by " << booksAuthor.at(i) <<" is available."<< endl;
                    notAvailable = false;
                }
            }
            if(notAvailable)
            cout<<"Book "<<title<<" is not available." << endl;
            
            cout<<endl;
        }
        // searchint book by its author name in the database
        void searchBookByAuthor(string authName){
            bool notAvailable = true;
            int i;
            for ( i = 0; i< booksTitle.size(); i++){
                if ( booksAuthor.at(i) == authName){
                    cout<<"Book "<< booksTitle.at(i)<< " by " << booksAuthor.at(i) <<" is available."<< endl;
                    notAvailable = false;
                }
            }
            if(notAvailable)
                cout<<"Book by author " << authName <<" is not available."<< endl;
            cout<<endl;
        }

        // issuing book to student 
        void issueBook(string title, string author ,string id,Student allStudents){
            int i;
            // checking if student is abailable in the system or not
            bool isPresent = allStudents.studentIsPresentOrNot(id);
            if ( isPresent){
                bool bookIsNotAvailable = true;
                for( i = 0; i<booksTitle.size();i++){
        
                    if ( booksTitle.at(i) == title && booksAuthor.at(i) == author){
        
                        // adding to issued book stock
                        issuedBooksTitle.push_back(booksTitle.at(i));
                        issuedBooksAuthor.push_back(booksAuthor.at(i));
                        studentIDToIssuedBook.push_back(id);
        
                        // removing book from stock of library
                        booksAuthor.erase(booksAuthor.begin() + i);
                        booksTitle.erase(booksTitle.begin()+ i);

                        cout<<"Book issued to id " << id << " successful." << endl;
        
                        bookIsNotAvailable = false;
                        return;
                    }
                }
                if(bookIsNotAvailable) 
                    cout<<"Book You are searching of is not available at the moment."<< endl;
            }
            else
                cout<<"Student with id "<< id << " is not in the system.\nFirst add new student details to the system and try again." << endl << endl;
        }

        // removing issued book form student record and issued database
        void removeIssuedBook(string title,string author, string id, Student s1){
            bool emptyIssued = true;
            for ( int i = 0 ; i<issuedBooksTitle.size();i++){
                if(title == issuedBooksTitle.at(i) && author == issuedBooksAuthor.at(i) && studentIDToIssuedBook.at(i) == id){
                    booksTitle.push_back(issuedBooksTitle.at(i));
                    booksAuthor.push_back(issuedBooksAuthor.at(i));
    
                    issuedBooksTitle.erase(issuedBooksTitle.begin() + i); 
                    issuedBooksAuthor.erase(issuedBooksAuthor.begin() + i);
                    studentIDToIssuedBook.erase(studentIDToIssuedBook.begin() + i);
                    emptyIssued = false;
                    cout<<"Book: "<<title<<" Author: "<<author<<" for ID: "<<id<<" removed successfully."<<endl;
                }
            }
            if (emptyIssued){
                cout<<"No bookk is issed as per your request. Check again."<<endl;
            }
            
        }

        // printing all issued books in the database
        void printIssuedBooks(){
            cout<<"------- Issued Books -------"<<endl;

            if ( issuedBooksTitle.size() == 0 )
                cout<<"No Book is in issued condtion"<< endl << endl;

            else{
                for (int i = 0; i<issuedBooksTitle.size();i++){
                    cout<<"Book: "<<issuedBooksTitle.at(i) <<"  By: "
                        << issuedBooksAuthor.at(i) << " is issued to student id " << studentIDToIssuedBook.at(i) << endl;
                }cout<<endl<<endl;
            }
        }

        // check which student have which book issued under their ID
        void checkIssuedBookToStudent(string id){
            bool NotHaveIssuedBoook = true;

            cout<<"Books issued to " << id << ": " << endl; 

            for( int i = 0; i<issuedBooksTitle.size();i++){
                if(studentIDToIssuedBook.at(i) == id){
                    cout<< issuedBooksTitle.at(i) << " by " << issuedBooksAuthor.at(i)<<endl;
                    NotHaveIssuedBoook = false;
                }
            }cout<<endl;
            
            if(NotHaveIssuedBoook)
                cout<< "Not fund any"<< endl;
        }


        // student concept

        // vector<string> getBooksTitle(){return booksTitle;}
        // vector<string> getBooksAuthor(){return booksAuthor;}
};

/* ----------------- NOTE ------------------- 
    Implement search issued by student ID; ---- done
    add if student not in the system the book will not be issued --- done

    implement admim system vector with admin code, found admin(full access) else student ( limited access )
    implement total number same book present in the library

    improve removeIssueBook; --- done
*/
int n;
string name;
string id;
string title;
string author;

void op1(Student &allStudent){
    cout<<"--- Adding new student details ---."<<endl;
    cout<<"Enter name of the student : ";
    // getline(cin,name);
    cin>>name;
    cout<<"Enter ID of the student: ";
    cin>>id;

    allStudent.setStudentData(name,id);
}
void op2(Library &mainLibrary){
    cout<<"--- Adding new book ---"<<endl;
    cout<<"Enter Title of the book : ";
    cin>>title;
    cout<<"Enter name of the author: ";
    cin>>author;

    mainLibrary.addBook(title,author);
}

void op3(Library &mainLibrary){
    cout<<"--- Printing all available books --- "<<endl;

    mainLibrary.printAll();
}
void op4(Library &mainLibrary){
    cout<<"-- Searching book by Title --- "<<endl;
    cout<<"Enter the Title of the Book: ";
    cin>>title;

    mainLibrary.searchBookByTitle(title);
}

void op5(Library &mainLibrary){
    cout<<"-- Searching book by Author --- "<<endl;
    cout<<"Enter the Author of the Book: ";
    cin>>author;

    mainLibrary.searchBookByAuthor(author);
}

void op6(Library &mainLibrary){
    cout<<"---Checking issued book to student--- "<<endl;
    cout<<"Enter ID if the student: " ;
    cin>>id;

    mainLibrary.checkIssuedBookToStudent(id);
}

void op7(Library &mainLibrary,Student &allStudent){
    cout<<"--- Removing issued book from student ---"<<endl;
    cout<<"Enter ID if the student: " ;
    cin>>id;
    cout<<"Enter title of the book: " ;
    cin>>title;
    cout<<"Enter author of the book: " ;
    cin>>author;

    mainLibrary.removeIssuedBook(title,author,id,allStudent);
}

void op8(Library &mainLibrary){
    cout<<"--- Printing all issued books ---"<<endl;

    mainLibrary.printIssuedBooks();
}

void op9(Library &mainLibrary){
    cout<<"--- Checking issued book to student by ID ---"<<endl;
    cout<<"Enter ID if the student: " ;
    cin>>id;

    mainLibrary.checkIssuedBookToStudent(id);
}

void op10(Library &mainLibrary,Student &allStudent){
    cout<<"--- Issuing Book to student ---"<<endl;
    cout<<"Enter title of the book: ";
    cin>>title;
    cout<<"Enter author name : ";
    cin>>author;
    cout<<"Enter ID of the student: ";
    cin>>id;

    mainLibrary.issueBook(title,author,id,allStudent);
}
void op11(Student &allStudent){
    cout<<"--- Printing all students details ---"<<endl;

    allStudent.printAllStudent();
}

void op12(bool &run){
    run = false;
}
int main(){
    
    Library mainLibrary;
    Student allStudent;
    bool run = true;

    while(run){
        cout<<"------------------------ Menu ------------------------"<< endl;
        cout<<"1: Add New student details to system."<<endl;
        cout<<"2: Add new book to system."<<endl;
        cout<<"3: Print all available books. "<<endl;
        cout<<"4: Search book by title. "<<endl;
        cout<<"5: Search book by author. "<<endl;
        cout<<"6: check all issued book to student. "<<endl;
        cout<<"7: Remove issued book from student. "<<endl;
        cout<<"8: Print all issued books. "<<endl;
        cout<<"9: Check issued book to student by ID "<<endl;
        cout<<"10: Issue Book to student.  "<<endl;
        cout<<"11: Print all students details."<<endl;
        cout<<"12: Exit. " <<endl;
        cout<<"----------------------------------------------------------"<<endl;
        // cout<<" "<<endl;
        // cout<<" "<<endl;
        cout<<"Enter Menu number: ";
        cin>>n;
        switch(n){
            case 1:
                    op1(allStudent);
                    break;
            case 2:
                    op2(mainLibrary);
                    break;
            case 3:
                    op3(mainLibrary);
                    break;
            case 4:
                    op4(mainLibrary);
                    break;
            case 5:
                    op5(mainLibrary);
                    break;
            case 6:
                    op6(mainLibrary);
                    break;
            case 7:
                    op7(mainLibrary,allStudent);
                    break;
            case 8:
                    op8(mainLibrary);
                    break;
            case 9:
                    op9(mainLibrary);
                    break;  
            case 10:
                    op10(mainLibrary,allStudent);
                    break;
            case 11:
                    op11(allStudent);
                    break;
            case 12:
                    op12(run);
                    break;
            default:
                cout<<"Enter a valid menu number.";
                break;
        }cout<<endl;
    }
    cout<<endl;
    return 0;
}