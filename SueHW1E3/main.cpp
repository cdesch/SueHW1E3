//
//  main.cpp
//  Lab 1, Exercise 3
//
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector> //http://www.cplusplus.com/reference/vector/vector/
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;
//**************************
//  personStruct Declaration
//**************************//
struct PersonStruct{
    //Public attributes
    string lastName;
    string firstName;
    void printName();
    string getName();
    void setFullName(string fullname);
};
//---PersonStruct Implementation---//
//Prints full name
void PersonStruct::printName(){
    printf("%s %s \n", firstName.c_str(), lastName.c_str());
}
//returns the person's name as one string
string PersonStruct::getName(){
    return firstName + " " + lastName;
}

//Takes in a fullname and splits it at ' ' (space) and saves it to firstName and lastName
void PersonStruct::setFullName(string fullname){
    stringstream myString(fullname);
    string segment;
    vector<string> seglist;
    //Firstname
    if (getline(myString, segment, ' ')){
        firstName = segment;
    }
    //Lastname
    if (getline(myString, segment, ' ')){
        lastName = segment;
    }
}
//**************************
//  End PersonStruct Struct
//**************************//

//**************************
//  Book Class Declaration
//**************************//
class Book {
    
private:
    string title;
    PersonStruct author;
    string publisher;
    string language;
    int rating;
    int year;
    
public:
    //Constructor
    Book(string t, PersonStruct a, string l, string p, int y, int r); //This is the constructor
            // --  Constructor with no params Ex: Book();
    //Deconstructor
    ~Book();
    
    //Member functions//
    void printInfo();
    
    //GETTERS//
    string getTitle();
    PersonStruct getAuthor();
    string getLanguage();
    string getPublisher();
    int getYear();
    int getRating();
    //Create Getters for the object attributes .... PersonStruct, publisher, year, rating... etc.
    
    //SETTERS//
    
    void setTitle(string t);
    void setAuthor(PersonStruct p);
    void setLanguage(string l);
    void setPublisher(string p);
    void setYear(int y);
    void setRating(int r);
};



//Constructor with params
Book::Book(string t, PersonStruct a, string l, string p, int y, int r){
    title = t;
    author = a;
    language = l;
    publisher = p;
    year = y;
    rating = r;
}


//Deconstructor
Book::~Book(){
}

//Member Functions//
void Book::printInfo(){
    printf("Title: %s \n", title.c_str());
    printf("Author: ");
    author.printName();
    printf("Publisher: %s \n", publisher.c_str());
    printf("Year: %d \n", year);
    printf("Rating: %d \n", rating);
}

//GETTERS//
string Book::getTitle(){
    return title;
}
PersonStruct Book::getAuthor(){
    return author;
}
string Book::getLanguage(){
    return language;
}
string Book::getPublisher(){
    return publisher;
}
int Book::getYear(){
    return year;
}
int Book::getRating(){
    return rating;
}

//SETTERS//

void Book::setTitle(string t){
    title = t;
}
void Book::setAuthor(PersonStruct p){
    author = p;
}
void Book::setLanguage(string l){
    language = l;
}
void Book::setPublisher(string p){
    publisher = p;
}
void Book::setYear(int y){
    year = y;
}
void Book::setRating(int r){
    rating = r;
}


//**************************
//  Class Person
//**************************
class Person {
    
public:
    
    //Public attributes
    string lastName;
    string firstName;
    
    //Constructor
    Person(string last, string first);
    ~Person(); //Deconstructor
    
    //Member Functions//
    void printName();
    
};
//Constructor with params
Person::Person(string last, string first){
    lastName = last;
    firstName = first;
}

//Deconstructor
Person::~Person(){
}

//Member Functions//
//Prints full name
void Person::printName(){
    printf("%s %s \n", firstName.c_str(), lastName.c_str());
}

//Global Variables//
vector <Book> books; //My Vector of Books
vector <Book> reverseBooks;

//Generate Random Number between 1 and 10
int generateRandomNumber(){
    //Initialize random seed:
    srand (time(NULL));
    //Generate secret number between 1 and 10:
    return rand() % 10 + 1;
}

//This function converts a string to an integer
//It returns a variable of type int
int converStringToInt(string myString){
    //atoi() isn't something you would normally know about it
    //Here is the documentation link http://www.cplusplus.com/reference/cstdlib/atoi/
    return atoi(myString.c_str());
}

void readFile(string filename){
    //File Format:
    /*
     Title
     Author
     Languge
     Year
     
     Sample:
     A Tale of Two Cities
     Charles Dickens
     English
     1859
     */
    
    ifstream infile(filename); //Open the file
    string str; //Declares a string and is used for temporary storage
    
    //The while loop continues while getting more lines in the file.
    //The getline() function will return the line in the str variable.
    while (getline(infile, str)){
        
        //The first line is going to the title
        string title = str;
        string author;
        string language;
        string publisher = "No Publisher"; ///There is no publisher in the sample file
        int year;
        int rating = generateRandomNumber(); //There is no rating in the sample file.  I used a random number instead.
        
        //The next line is the author—one option is to just call getline(), but I chose to put it around an if statement incase it runs into a problem reading the end of the file.
        
        if (getline(infile, str)){
            author = str;
        }
        if (getline(infile, str)){
            language = str;
        }
        
        if (getline(infile, str)){
            //year = str; // str is of type string and year is of type int. Need to convert the string to an integer. Since this may be done more than once, create a function that takes in strings and returns integers.  This is also used for rating.
            year = converStringToInt(str);
        }
        
        /*
        if (getline(infile, str)){
            rating = converStringToInt(str);
        }*/
        
        
        //Creating the book object
        
        //Book book(title, author, language, year, rating); // The Book object constructor Book::Book(std::string t, PersonStruct a,std::string p, int y, int r) requires a object of type PersonStruct. First creat the author object.
        PersonStruct myAuthor;
        myAuthor.setFullName(author);
        
        Book book(title, myAuthor, language, publisher, year, rating);
        //Have the first book object!
        //Push it into our array!
        books.push_back(book);
    }
    
    //When this function completes, have a vector full of books!!
}

//This is for exercise 3
//Prints books array
void printBooks(){
    //vector <Book> books;
    //We need to loop through each book!
    cout << __PRETTY_FUNCTION__ << " Start" << endl;
    cout << " ***-=Printing Books=-***" << endl;
    for (int i = 0; i < books.size(); i++){
        books[i].printInfo(); //Bundled printInfo()function the Book Class.
    }
    cout << " ***-=End Printing Books=-***" << endl;
    cout << __PRETTY_FUNCTION__ << " END" << endl;
    
    /*
    cout << "***Reverse Loop Print***" << endl;
    
    //Looping through array/vector backwards
    for (int j = books.size() - 1; j >= 0; j--){
        books[j].printInfo(); //Bundled printInfo()function the Book Class.
    }
     */
    
}

//Reverse array
void reverseArray(){
    cout << __PRETTY_FUNCTION__ << "Start" << endl;
    
    for (int j = books.size() - 1; j >= 0; j--){
        reverseBooks.push_back(books[j]);
    }
    books = reverseBooks;

    cout << __PRETTY_FUNCTION__ << "END" << endl;
    
    /*
    cout << "***Reverse Vector Print***" << endl;
    
    for (int i = 0; i < reverseBooks.size(); i++){
        reverseBooks[i].printInfo(); //Bundled printInfo()function the Book Class.
    }*/
    

}

void writeBooks(string filename){

    ofstream writeFile;
    writeFile.open (filename);
    
    cout << __PRETTY_FUNCTION__ << " Start" << endl;

    for (int i = 0; i < books.size(); i++){
        //books[i].printInfo(); //Bundled printInfo()function the Book Class.
        
        writeFile << books[i].getTitle()  << endl;
        PersonStruct myAuthor = books[i].getAuthor();
        // writeFile << myAuthor.firstName << " " << myAuthor.lastName << endl;
        // get language
        // get year
        
    }
    writeFile.close();
    cout << __PRETTY_FUNCTION__ << " END" << endl;
}

void exerciseThree(){
    cout << "***Exercise 3***" << endl;
    
    readFile("/Users/cj/Documents/xcodeProjects/apps/HelloWorldReadFile/HelloWorldReadFile/Book2.txt");
    printBooks();
    reverseArray();
    cout << "     Print out books reversed " << endl;
    printBooks();
    
    writeBooks("/Users/cj/Desktop/BooksBackwards.txt"); //writing the books in reverse
    books.empty(); //Empty the books array;
    //readFile("/Users/cj/Desktop/BooksBackwards.txt");
    //reverseArray(); //The books should be forward -- should be back to original
    //printBooks();
    //writeBooks("/Users/cj/Desktop/BooksForwards.txt"); //writing the books in reverse
    
    
    cout << "***End Exercise 3***" << endl;
}

int main(int argc, const char * argv[]){
    
    cout << "Lab 1, Exercise 3 \n";
    
    exerciseThree();
    
    
    
    return 0;
}
