#include <iostream>
#include <initializer_list>
#include "Book.h"

using namespace std;

class Library
{
    Book* first;
    size_t size;
public:
    Library();
    Library(size_t size);
    Library(initializer_list<Book> InitBookList);
    Library(const Library& Lib);
    Library(Library&& lib);
    Library& operator=(const Library& right);
    Library& operator=(Library&& right);
    Book& operator[](size_t i);
    const Book& operator[](size_t i) const;
    size_t GetSize() const;
    friend std::ostream& operator<<(std::ostream& out, const Library& library);
    void addBook();
    ~Library();
};

