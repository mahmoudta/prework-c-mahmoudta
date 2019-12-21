#include "books.h"
static char *Zones[] = { "kids", "highshool", "adult","documenrary","comics"};
BookCopy* create_copy(int booknumber) {
    BookCopy* p = malloc(sizeof(*p));
    init_copy(p, booknumber);
    return p;
}
static void print_drama(Book* b){
    printf("the genre is drama\nplot quality is %d\ntextquality is %d\n\n",b->genreData.drama.plot_quality,b->genreData.drama.text_quality);
}
static void print_thriller(Book* b){
    printf("the genre is thriller\nthe average thriller is %f\n\n",b->genreData.thriller);
}
static void print_comedy(Book* b){
    printf("the genre is comedy\nthe quality of the humor is %d\nthe humer type is ",b->genreData.comedy.humor_quality);
    switch (b->genreData.comedy.humor_type) {
        case 'N':
            printf("nonsense humor\n\n");
            break;
        case 'S':
            printf("sophisticated humor\n\n");
            break;
        case 'P':
            printf("puns\n\n");
            break;
        case 'O':
            printf("other\n\n");
            break;
        default:
            printf("NULL\n\n");
            break;
    }
        
}
static void print_non_fiction(Book* b){
    printf("the genre is non-fiction\nthe field of the book is %s\n\n",(b->genreData.non_fiction[0]=='\0')?"Null":b->genreData.non_fiction);
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
    printf("Book Details\nName: %s \nNumber: %d \nPromotion: %d \nBook Can Be Found in the '%s' Section\n",b->name,b->booknumber,b->promotion,get_zone_name(b));
    switch (b->genre) {
        case 0:
            print_drama(b);
            break;
        case 1:
            print_thriller(b);
        
            break;
        case 2:
            print_comedy(b);
            break;
        case 3:
            print_non_fiction(b);
            break;
            
        default:
            printf("genre not defined in switch\n\n");
            break;
    }
    
    
}
void get_nice_book_name(char* src,char** dst){
    int i=0;
    bool charafterspace=false;
    char *new_name = (char*) malloc(sizeof(src));
    while(src[i]!='\0'){
        if(((i==0)||(charafterspace))&(src[i]>=97&src[i]<=122)){
            charafterspace=false;
            new_name[i]=src[i]-32;
        }else if((i!=0)&(!charafterspace)&(src[i]>=65&src[i]<=90)){
            new_name[i]=(src[i]+32);
        }else if((!charafterspace)&(src[i]==32)){
            new_name[i]=src[i];
            charafterspace=true;
        }else{
            new_name[i]=src[i];
        }
        i++;
    }
    new_name[i]='\0';
    *dst=new_name;
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
