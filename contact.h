#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void populate(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void save_exit(AddressBook *addressBook);
void validate_name(AddressBook *addressBook,int vali_name_i);
void validate_phone_number(AddressBook *addressBook,int vali_phone_i);
void validate_email_ID(AddressBook *addressBook,int vali_email_i);
#endif
