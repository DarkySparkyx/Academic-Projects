#include <iostream>

using namespace std;
class Book
{
private:
    string author;
    string title;
    string date;
public:
    Book();
    Book(const Book& b);
    Book(Book&& b);
    Book(const string&, const string&);
    Book(string&& author, string &&title);
    friend ostream& operator<<(ostream& ostr,const Book& b);
    string GetAuthor();
    string GetTitle();
    void SetAuthor(const string& author);
    void SetTitle(const string& title);
    void SetAuthor(string&& author);
    void SetTitle(string&& title);
    void SetAuthor(Book& b);
    void SetTitle(Book& b);
    void SetDate(string);
    string GetDate();
    Book& operator=(const Book& right);
    Book& operator=(Book&& book);
};
