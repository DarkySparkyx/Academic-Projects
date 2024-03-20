#include <iostream>
#include <initializer_list>
#include "Library.h"

using namespace std;

Library::Library()
{
    first = nullptr;
    size = 0;
}
Library::Library(size_t size)
{
    this->size=size;
    first = new Book[size];
}
Library::Library(initializer_list<Book> InitBookList)
{
    size = InitBookList.size();
    first = new Book[size];
    int i=0;
    for(Book b : InitBookList)
    {
        first[i]=b;
        i++;
    }
}

Library::Library(const Library& lib)
{
    this->size=lib.size;
    this->first=new Book[size];
    for(int i=0;i<size;i++)
    {
        first[i]=lib.first[i];
    }
}

Library::Library(Library&& lib)
{
    this->size=lib.size;
    this->first = lib.first;

    lib.size=0;
    lib.first=nullptr;
}

Library& Library::operator=(const Library& right)
{
    this->size=right.size;
    delete[] this->first;
    this->first = new Book[right.size];
    for(int i=0;i<right.size;i++)
    {
        first[i]=right.first[i];
    }
    return *this;
}

Library& Library::operator=(Library&& right)
{
    if(first!=right.first)
    {
        delete[] first;
        this->size=right.size;
        first=right.first;

        right.first=nullptr;
        right.size=0;
    }
}

Book& Library::operator[](size_t i)
{
    if(i>=0 && i<size)
        return first[i];
}

const Book& Library::operator[](size_t i) const
{
    return first[i];
}

 size_t Library::GetSize() const
 {
     return size;
 }

ostream& operator<<(ostream& ostr, const Library& library)
{
    ostr << "Library" << endl << "{" << endl;
    for(int i=0;i<library.size;i++)
    {
        ostr << i+1 << ". " << library.first[i];
    }
    ostr << "} books in total = " << library.size << endl;
    return ostr;
}

Library::~Library()
{
	size = 0;
	delete[] first;
}

void Library::addBook()
{
    Book* second = new Book[size+1];
    for(int i=0;i<size;i++)
    {
        second[i]=first[i];
    }

    string tmp;
    cout << "Podaj autora nowej ksiazki: ";
    cin >> tmp;
    second[size].SetAuthor(tmp);

    cout << "Podaj tytul nowej ksiazki: ";
    cin >> tmp;
    second[size].SetTitle(tmp);

    delete[] first;
    first=second;
    size++;
}
