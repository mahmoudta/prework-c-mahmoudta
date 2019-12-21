#include <stdio.h>
#include "local_library.h"
BookCopy bookcopys[10];
int serchinbookcopys(int serial_number){
    int j;
    for(j=0;j<10;j++){
        if(bookcopys[j].serialnumber==serial_number)
            return j;
    }
    return -1;
}

void borrow_or_retern(bool borowing_or_returing){
    int index,serial_number;
    char* sentence_to_print=borowing_or_returing?"borrowed":"returned";
    printf("enter copy serial number: ");
    scanf("%d",&serial_number);
    index=serchinbookcopys(serial_number);
    if(index!=-1){
        if(borrow_copy(&bookcopys[index],borowing_or_returing)==-1)
            printf("***copy is already %s***\n",sentence_to_print);
        else
            printf("***you just %s the copy***\n",sentence_to_print);
    }else{
         printf("***wrong serial number***\n");
    }
}

int main(int argc, const char * argv[]) {
    int i,booknumber,choice=0;
    for(i=0;i<N;i++){
        print_book(&books[i]);
    }
    printf("please choose 10 book-copy to the library, to add enter its book number.\n");
    i=0;
    while(i<10){
        printf("copy book %d: ",i+1);
        scanf("%d",&booknumber);
        if(findnamebynumber(booknumber)==NULL){
            printf("***wrong book number please try again***\n\n");
        }
        else{
            init_copy(&bookcopys[i],booknumber);
            print_copy(&bookcopys[i]);
            i++;
        }
    }
    while(choice!=9){
        printf("\nchoose from menu\n1. Borrow a book-copy\n2.Return a book-copy\n9. Exit\nMy Choice: ");
        scanf("%d",&choice);
            
        switch (choice)
        {
            case 1:
                borrow_or_retern(true);
                break;
            case 2:
                borrow_or_retern(false);
                break;
            case 9:
                printf("GoodBye.\n");
                break;
            default:
                printf("***wrong choice please try again***\n\n");
                    
                break;
                  
        }
    }
    return 0;
}
