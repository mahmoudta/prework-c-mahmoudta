#include <stdio.h>
#include "books.h"
int main(int argc, const char * argv[]) {
    Book p1;
    p1= Book_new("name",2345,12,KIDS);
    print_book(p1);
    return 0;
}
