#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main() {
    struct Book library[MAX_BOOKS];
    int choice, count = 0;
    char search[50];
    int i;

    while(1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Author\n");
        printf("4. Count Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count < MAX_BOOKS) {
                    printf("Enter book title: ");
                    scanf(" %[^\n]", library[count].title);
                    printf("Enter author name: ");
                    scanf(" %[^\n]", library[count].author);
                    printf("Enter number of pages: ");
                    scanf("%d", &library[count].pages);
                    printf("Enter price: ");
                    scanf("%f", &library[count].price);
                    count++;
                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full!\n");
                }
                break;

            case 2:
                printf("\nBooks in Library:\n");
                for(i = 0; i < count; i++) {
                    printf("Book %d:\n", i+1);
                    printf("Title: %s\n", library[i].title);
                    printf("Author: %s\n", library[i].author);
                    printf("Pages: %d\n", library[i].pages);
                    printf("Price: %.2f\n", library[i].price);
                }
                break;

            case 3:
                printf("Enter author name to search: ");
                scanf(" %[^\n]", search);
                printf("\nBooks by %s:\n", search);
                for(i = 0; i < count; i++) {
                    if(strcmp(library[i].author, search) == 0) {
                        printf("Title: %s\n", library[i].title);
                        printf("Pages: %d\n", library[i].pages);
                        printf("Price: %.2f\n", library[i].price);
                    }
                }
                break;

            case 4:
                printf("Total number of books: %d\n", count);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;
          default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

