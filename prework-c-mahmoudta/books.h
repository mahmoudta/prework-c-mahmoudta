#ifndef books_h
#define books_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef enum {
    KIDS,
    HIGH_SCHOOL,
    ADULT
} Zone;
typedef struct book_struct* Book;
Book Book_new(char name[],int number,int promotion,Zone zone);
char* getName(Book b);
char* get_zone_name();
/*Book* p1 = Book_new();*/
#endif /* books_h */
