#include "books.h"
static char *Zones[] = { "kids", "highshool", "adult","documenrary","comics"};
BookCopy* BookCopy_new(void) {
    BookCopy* p = malloc(sizeof(*p));
    return p;
}
Book* Book_new(int booknumber,char name[],int promotion,Zone zone) {
    Book* p = malloc(sizeof(*p));
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
char* get_zone_name(Book* b){
    return (ZoneToString(b->zone));
}
void print_book(Book* b){
    printf("Book Details\nName: %s \nNumber: %d \nPromotion: %d \nBook Can Be Found in the '%s' Section\n\n",b->name,b->booknumber,b->promotion,get_zone_name(b));
}
void print_copy(BookCopy* c){
    printf("Copy Details\nNumber: %d \nserialnumber: %d \nThe Book %s Borrowed\n\n",c->booknumber,c->serialnumber,c->is_borrowed?"Is" : "Is Not");
}
int borrow_copy(BookCopy* c,bool is_borrowing){
    if(is_borrowing==c->is_borrowed) return -1;
    c->is_borrowed = is_borrowing;
    return 0;
}
void init_copy(BookCopy* c,int booknumber){
    static int serialnumber=9999;
    serialnumber++;
    c->booknumber = booknumber;
     c->serialnumber = serialnumber;
    c->is_borrowed = false;
}
