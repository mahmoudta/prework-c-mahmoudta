#ifndef books_h
#define books_h
#define NAME_LEN 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define sizeofbook sizeof Book
typedef enum {
    KIDS,
    HIGHSCHOOL,
    ADULT,
    DOCUMENTARY,
    COMICS
} Zone;
struct book_struct{
    int booknumber;
    char name[NAME_LEN];
    int promotion;
    Zone zone;
};
struct bookcopy_struct{
    int booknumber;
    int serialnumber;
    bool is_borrowed;
};
typedef struct book_struct Book;
typedef struct bookcopy_struct BookCopy;
BookCopy* BookCopy_new(void);
Book* Book_new(int booknumber,char name[],int promotion,Zone zone);
char *ZoneToString(Zone zone);
char* get_zone_name(Book* b);
void print_book(Book* b);
void print_copy(BookCopy* c);
int borrow_copy(BookCopy* c,bool is_borrowing);
void init_copy(BookCopy* c,int booknumber);
#endif /* books_h */
