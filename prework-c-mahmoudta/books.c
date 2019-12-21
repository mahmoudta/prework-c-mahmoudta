#include "books.h"
static char *Zones[] = { "kids", "highshool", "adult","documenrary","comics"};
BookCopy* create_copy(int booknumber) {
    BookCopy* p = malloc(sizeof(*p));
    init_copy(p, booknumber);
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
    printf("Copy Details\nNumber: %d \nserialnumber: %d \nBorrowed %d times\nThe Book %s Currently Borrowed\n\n",c->booknumber,c->serialnumber,c->borrowedtimes,c->is_borrowed?"Is" : "Is Not");
}
int borrow_copy(BookCopy* c,bool is_borrowing){
    if(is_borrowing==c->is_borrowed) return -1;
    c->is_borrowed = is_borrowing;
    if(is_borrowing==true)
    c->borrowedtimes++;
    return 0;
}
void init_copy(BookCopy* c,int booknumber){
    static int serialnumber=9999;
    serialnumber++;
    c->borrowedtimes=0;
    c->attribute=0;
    c->booknumber = booknumber;
     c->serialnumber = serialnumber;
    c->is_borrowed = false;
}
/*0011 1111 = 00(cover)(indexing) (missing)(bar-code)(spine)(stained)*/
/*00xx xxxx & 0011 0100 = 52*/
bool is_librarian_required(BookCopy* c){
    unsigned int checker=52;
    if((checker&c->attribute)!=0)
        return true;
    return false;
}
/*00xx xxxx & 0000 1011 = 11*/
bool is_bookbinder_required(BookCopy* c){
    unsigned int checker=11;
    if((checker&c->attribute)!=0)
        return true;
    return false;
}
/*00xx xxxx & 0000 1001 = 9*/
bool is_repairable(BookCopy* c){
    unsigned int checker=9;
    if((checker&c->attribute)==0)
        return true;
    return false;
}
/*00xx xxxx & 0011 1111 = 63*/
bool is_ok(BookCopy* c){
    unsigned int checker=63;
    if((checker&c->attribute)!=0)
        return true;
    return false;
}
/*1(1) 2(10) 4(100) 8(1000) 16(10000) 32(100000) */
bool is_useless(BookCopy* c){
    int i,counter=0;
    unsigned int checker=1;
    for(i=0;i<6;i++){
        if((checker & c->attribute)!=0)
            counter++;
        checker*=2;
    }
    if(counter>=4)
        return true;
    return false;
}

/*c1 xor c2 =0 (they aare the same)*/
bool are_in_same_condition(BookCopy* c1,BookCopy* c2){
    unsigned int checker=(c1->attribute)^(c2->attribute);
    if(checker==0)
        return true;
    return false;
}
