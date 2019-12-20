#include "books.h"
#define NAME_LEN 50
static char *Zones[] = { "kids", "highshool", "adult" };
struct book_struct{
    char name[NAME_LEN];
    int booknumber;
    int promotion;
    Zone zone;
};
struct bookcopy_struct{
    int booknumber;
    int serialnumber;
    bool is_borrowed;
};
BookCopy BookCopy_new(void) {
    BookCopy p = malloc(sizeof(*p));
    return p;
}
Book Book_new(char name[],int booknumber,int promotion,Zone zone) {
    Book p = malloc(sizeof(*p));
    strcpy(p->name,name);
    if(booknumber>=0&&booknumber<=50000)
        p->booknumber = booknumber;
    else
        return NULL;
    if(promotion>=-100&&promotion<=100)
        p->promotion = promotion;
    else
        return NULL;
    p->zone = zone;
    return p;
}
char *ZoneToString(Zone zone){
    return Zones[zone];
}
char* get_zone_name(Book b){
    return (ZoneToString(b->zone));
}
void print_book(Book b){
    printf("Book Details\nName: %s \nNumber: %d \nPromotion: %d \nBook Can Be Found in the '%s' Section\n",b->name,b->booknumber,b->promotion,get_zone_name(b));
}
void print_copy(BookCopy c){
    
}

