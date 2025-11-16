#include <iostream>
#include <vector>
using namespace std;

class Books{
    protected:
        vector<string> booksTitle = {"c++"       ,"java"        ,"software engineering","maths"  ,"DSA" ,"english"};
        vector<string> booksAuthor = {"Animesh"  ,"Priyanshu"   ,"Abhishek"            ,"Sushant","Om"  ,"Ayush"};

    public:
        void testnow(){
            return;
        }
};
class issuedBooks{
    protected: 
        vector<string> issuedBooksTitle;
        vector<string> issuedBooksAuthor;
    public:
         
        // vector<string> getBooksTitle(){return issuedBooksTitle;}
        // vector<string> getBooksAuthor(){return issuedBooksAuthor;}
};
class Library : Books , issuedBooks{
    public:

    void addBook(string bookName,string byAuthor){
        booksTitle.push_back(bookName);
        booksAuthor.push_back(byAuthor);
    }
    
    void printAall(){
        cout<<"------- Available Books -------"<<endl;
        for (int i = 0; i<booksTitle.size();i++){
            cout<<"Book: "<<booksTitle.at(i) <<"  By: " << booksAuthor.at(i)<< endl;
        }cout<<endl;
    }
    
    void searchBookByTitle(string title){
        bool notAvailable = true;
        for ( int i = 0; i< booksTitle.size(); i++){
            if ( booksTitle.at(i) == title){
                cout<<"Book "<< booksTitle.at(i)<< " by " << booksAuthor.at(i) <<" is available."<< endl;
                notAvailable = false;
            }
        }
        if(notAvailable)
        cout<<"Book "<<title<<" is not available."<< endl;
        
        cout<<endl;
    }
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
            cout<<"Book by author" << authName <<" is not available."<< endl;
        cout<<endl;
    }

    void issueBook(string title){
        int i;
        // first check id book is available or not
        // i will wtire it later in optimized form

        //now lets issue book 
        for( i = 0; i<booksTitle.size();i++){
            if ( booksTitle.at(i) == title){
                issuedBooksTitle.push_back(booksTitle.at(i));
                issuedBooksAuthor.push_back(booksAuthor.at(i));

                booksAuthor.erase(booksAuthor.begin() + i);
                booksTitle.erase(booksTitle.begin()+ i);
                return;
            }
        }
    }

    void removeIssuedBook(string title){
        int i;for ( i = 0 ; i<issuedBooksTitle.size();i++){
            booksTitle.push_back(issuedBooksTitle.at(i));
            booksAuthor.push_back(issuedBooksAuthor.at(i));

            issuedBooksTitle.erase(issuedBooksTitle.begin() + i);
            issuedBooksAuthor.erase(issuedBooksAuthor.begin() + i);
        }
    }
    
    void printIssuedBooks(){
        cout<<"------- Issued Books -------"<<endl;
        if ( issuedBooksTitle.size() == 0 )
            cout<<"No Book is in issued condtion";
        else{
            for (int i = 0; i<issuedBooksTitle.size();i++){
                cout<<"Book: "<<issuedBooksTitle.at(i) <<"  By: " << issuedBooksAuthor.at(i) << " is issued" << endl;
            }cout<<endl<<endl;
        }
    }
    // vector<string> getBooksTitle(){return booksTitle;}
    // vector<string> getBooksAuthor(){return booksAuthor;}
};

class student : Library{
    protected:
        string studentName;
        int studentID;

    public:
    
};


int main(){
    
    Library mainLibrary;

    mainLibrary.printAall();

    // mainLibrary.addBook("myBook","animesh");
    // mainLibrary.printAall();

    mainLibrary.searchBookByTitle("c+");
    mainLibrary.searchBookByTitle("c++");
    mainLibrary.searchBookByAuthor("f");
    mainLibrary.searchBookByAuthor("g");

    //
    mainLibrary.issueBook("java");
    mainLibrary.printAall();

    mainLibrary.printIssuedBooks();

    //
    // mainLibrary.removeIssuedBook("java");
    // mainLibrary.printAall();

    // mainLibrary.printIssuedBooks();




    return 0;
}