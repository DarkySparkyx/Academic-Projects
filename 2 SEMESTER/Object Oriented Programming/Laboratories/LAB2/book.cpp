#include <iostream>
#include "book.h"

using namespace std;

Book::Book()
{
    author="Imie i Nazwisko";
    title="Tytul ksiazki";
}
Book::Book(const Book& b) : author(b.author), title(b.title)
{

}
Book::Book(Book&& b) : author(b.author), title(b.title)
{
    b.author="";
    b.title="";
}
Book::Book(const string& author, const string& title) : author(author), title(title)
{

}
Book::Book(string&& author, string &&title) : author(author), title(title)
{

}
string Book::GetAuthor()
{
    return author;
}
string Book::GetTitle()
{
    return title;
}
void Book::SetAuthor(const string& author)
{
    this->author=author;
}
void Book::SetTitle(const string& title)
{
    this->title=title;
}
void Book::SetAuthor(string&& author)
{
    this->author=author;
}
void Book::SetTitle(string&& title)
{
    this->title=title;
}

void Book::SetAuthor(Book& b)
{
    title=b.author;
}
void Book::SetTitle(Book& b)
{
    title=b.title;
}
ostream& operator<<(ostream& ostr, const Book& b)
{
    cout << b.author << " -> " << b.title << endl;
    return ostr;
}

Book& Book::operator=(const Book& right)
{
    author=right.author;
    title=right.title;
    return *this;
}

Book& Book::operator=(Book&& right)
{
    author.swap(right.author);
    title.swap(right.title);
    return *this;
}

string Book::GetDate()
{
    return date;
}

void Book::SetDate(string date)
{

}
