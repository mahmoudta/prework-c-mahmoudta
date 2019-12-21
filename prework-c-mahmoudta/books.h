#ifndef books_h
#define books_h
#define NAME_LEN 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef enum {
    KIDS,
    HIGHSCHOOL,
    ADULT,
    DOCUMENTARY,
    COMICS
} Zone;
typedef enum{
    DRAMA,
    THRILLER,
    COMEDY,
    NON_FICTION
}Genre;
union Data{
    float thriller;
    char non_fiction[4];
    struct { int text_quality; int plot_quality; } drama;
    struct { int humor_quality; char humor_type; } comedy;
};
struct book_struct{
    int booknumber;
    char name[NAME_LEN];
    int promotion;
    Zone zone;
    Genre genre;
    union Data genreData;
};
struct bookcopy_struct{
    int booknumber;
    int serialnumber;
    int borrowedtimes;
    bool is_borrowed;
    unsigned int attribute;
};
typedef struct book_struct Book;
typedef struct bookcopy_struct BookCopy;
BookCopy* create_copy(int booknumber);
Book* Book_new(int booknumber,char name[],int promotion,Zone zone);
char *ZoneToString(Zone zone);
char* get_zone_name(Book* b);
void print_book(Book* b);
void get_nice_book_name(char* src,char** dst);
void print_copy(BookCopy* c);
int borrow_copy(BookCopy* c,bool is_borrowing);
void init_copy(BookCopy* c,int booknumber);
bool is_librarian_required(BookCopy* c);
bool is_bookbinder_required(BookCopy* c);
bool is_repairable(BookCopy* c);
bool is_ok(BookCopy* c);
bool is_useless(BookCopy* c);
bool are_in_same_condition(BookCopy* c1,BookCopy* c2);
#endif /* books_h */
