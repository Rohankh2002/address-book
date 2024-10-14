#include "contact.h"
void listContacts(AddressBook *addressBook);
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void save_exit(AddressBook *addressBook);
int main()
{
    AddressBook book;
    initialize(&book);
    char N;
    do{
        initial:
        printf("\n---------------------");
        printf("\n  Enter your choice\n");
        printf("---------------------\n");
        printf("1. Display the list\n");
        printf("2. Create Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Search Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Save and Exit\n");
        printf(":->");
        scanf("%c",&N);
        if(N>'0'&&N<'7')
        {
        switch(N)
        {
            case '1':
            {
               listContacts(&book);
               break; 
            }
            case '2':
            {
                createContact(&book);
                break;
            }
            case  '3':
            {
                editContact(&book);
                break;
            }
            case '4':
            {
                searchContact(&book);
                break;
            }
            case '5':
            {
                deleteContact(&book);
                break;
            }
            case '6':
            {
                save_exit(&book);
                break;
            }
        }
        }
        else
        {
                printf("\n\nInvalid input\n");
                printf("Please enter option given\n");
                goto initial;
        }

    }while(N>'0' && N<'6');
    return 0;
}
