#include <stdio.h>
#include "local_library.h"
int serchinbookcopys(BookCopy* bookcopyarr,int serial_number){
    int j;
    for(j=0;j<10;j++){
        if(bookcopyarr[j].serialnumber==serial_number)
            return j;
    }
    return -1;
}

void borrow_or_retern(BookCopy* bookcopyarr,bool borowing_or_returing){
    int index,serial_number;
    char* sentence_to_print=borowing_or_returing?"borrowed":"returned";
    printf("enter copy serial number: ");
    scanf("%d",&serial_number);
    index=serchinbookcopys(bookcopyarr,serial_number);
    if(index!=-1){
        if(borrow_copy(&bookcopyarr[index],borowing_or_returing)==-1)
            printf("*** copy is already %s ***\n",sentence_to_print);
        else
            printf("*** you just %s the copy ***\n",sentence_to_print);
    }else{
         printf("*** wrong serial number ***\n");
    }
}

int main(int argc, const char * argv[]) {
    int i,bookcopysize,booknumber,choice=0;
    BookCopy *bookcopyarr;
    char* dst = NULL;
    char* src="ROBinson cruSOE";
    get_nice_book_name(src,&dst);
    printf("befor= %s ,after= %s\n\n\n\n","ROBinson cruSOE",dst);
    for(i=0;i<N;i++){
        print_book(&books[i]);
    }
    printf("how many book-copy you want: ");
    scanf("%d",&bookcopysize);
    bookcopyarr = malloc( (size_t)(bookcopysize)*sizeof(BookCopy));
    printf("please choose %d book-copy to the library, to add enter its book number.\n",bookcopysize);
    i=0;
    while(i<bookcopysize){
        printf("copy book %d: ",i+1);
        scanf("%d",&booknumber);
        if(findnamebynumber(booknumber)==NULL){
            printf("*** wrong book number please try again*** \n\n");
        }
        else{
            bookcopyarr[i]=*create_copy(booknumber);
            print_copy(&bookcopyarr[i]);
            i++;
        }
    }
    while(choice!=9){
        printf("\nchoose from menu\n1. Borrow a book-copy\n2.Return a book-copy\n9. Exit\nMy Choice: ");
        scanf("%d",&choice);
            
        switch (choice)
        {
            case 1:
                borrow_or_retern(bookcopyarr,true);
                break;
            case 2:
                borrow_or_retern(bookcopyarr,false);
                break;
            case 9:
                printf("GoodBye.\n");
                break;
            default:
                printf("*** wrong choice please try again ***\n\n");
                    
                break;
                  
        }
    }
    free (bookcopyarr);
    return 0;
}
