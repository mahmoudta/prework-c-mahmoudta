#ifndef books_h
#define books_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef enum {
    KIDS,
    HIGHSCHOOL,
    ADULT
} Zone;
typedef struct book_struct* Book;
typedef struct bookcopy_struct* BookCopy;
BookCopy BookCopy_new(void);
Book Book_new(char name[],int booknumber,int promotion,Zone zone);
char *ZoneToString(Zone zone);
char* get_zone_name(Book b);
void print_book(Book b);
void print_copy(BookCopy c);

#endif /* books_h */
