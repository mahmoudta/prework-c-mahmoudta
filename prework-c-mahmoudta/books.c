#include "books.h"
#define NAME_LEN 50
struct book_struct{
    char name[NAME_LEN];
    int number;
    int promotion;
    Zone zone;
    bool is_borrowed;
};
Book Book_new(char name[],int number,int promotion,Zone zone) {
  Book p = malloc(sizeof(*p));
strcpy(p->name,name);
  p->is_borrowed=false;
  p->number = number;
  p->promotion = promotion;
  p->zone = zone;
  return p;
}
char* get_zone_name(){
    
}

