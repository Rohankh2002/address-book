#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
       // printf("-------------------------------------------------------------------------------------\n");
        printf(" Sr no. %d\tname -> %s  \tPhone no: %s \temail: %s \n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        //printf("-------------------------------------------------------------------------------------\n");
    }
    printf("Your contact list is displayed successfully\n");
    printf("Please press any button to exit\n");
    char ch;
    scanf("%c",&ch);
    getchar();
    return;
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount=0;
   FILE *fptr=fopen("contact.csv","r");
    while( fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email)!=EOF)
    {

       // fscanf(fptr,"%[^,],%[^,],%[^,]",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email);
        addressBook->contactCount++;
    }
    fclose(fptr);
    return;
        //populate(addressBook);
}
void save_exit(AddressBook *addressBook)
{
    FILE *fptr=fopen("contact.csv","w");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
    return;
}
void createContact(AddressBook *addressBook) 
{
    char c_i1,c_i2,c_i7,c_i8;
    printf("--------------\n");
    printf("Enter the name\n");
    printf("--------------\n");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    c_label1:
    printf("-------------------------------\n");
    printf("Enter the 10 digit Phone Number\n");
    printf("-------------------------------\n");
    char Phone[100];
    scanf("%s",Phone);
    int cnt=0;
        for(int j=0;Phone[j]!='\0';j++)
        {
            cnt++;
            if(Phone[j]>'9'||Phone[j]<'0')
            {
                printf("Phone number should not contain alphabet, Only enter digits\n");
                c_label2:
                printf("Please press 1 to continue or 0 to exit\n");
                getchar();
                scanf("%c",&c_i1);
                if(c_i1=='1')
                {
                    goto c_label1;
                }
                else if(c_i1=='0')
                {
                    char ch;
                    printf("Please press any button to exit \n");
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                    goto c_label2;
                }
            }
         }
        if(cnt!=10)
            {
                printf("Phone number should contain 10 digits\n");
                c_label3:
                printf("Please press 1 to continue or 0 to exit\n");
                getchar();
                scanf("%c",&c_i2);
                if(c_i2=='1')
                {
                    goto c_label1;
                }
                else if(c_i2=='0')
                {
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                    goto c_label3;
                }
            }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((strcmp(Phone,addressBook->contacts[i].phone))=='\0')
        {
            printf("Entered number already exists\n");
            printf("Please enter different phone number\n");
            c_label9:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&c_i7);
            if(c_i7=='1')
            {
                goto c_label1;
            }
            else if(c_i7=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto c_label9;
            }
        }
    }
    strcpy(addressBook->contacts[addressBook->contactCount].phone,Phone);
    
    //reading email id from the user from here
    char c_i3,c_i4,c_i5,c_i6;
    c_label4:
    printf("------------------\n");
    printf("Enter the email id\n");
    printf("------------------\n");
    char Email[50];
    scanf("%s",Email);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(Email,addressBook->contacts[i].email)==0)
        {
            printf("Entered email ID already exists\n");
            printf("Please try the different email ID\n");
            c_label13:
            printf("Press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&c_i8);
            if(c_i8=='1')
            {
                goto c_label4;
            }
            else if(c_i8=='0')
            {
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto c_label13;
            }

        }
    }
    for(int i=0;i<strlen(Email);i++)
    {
        if(Email[i]!='@'&&Email[i]>'z'&&Email[i]<'a')
        {
            printf("Please only enter small letters\n");
            c_label5:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&c_i3);
            if(c_i3=='1')
            {
                goto c_label4;
            }
            else if(c_i3=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto c_label5;
            }
        }
    }
    if(strchr(Email,'@')==NULL)
    {
        printf("Email must contain '@' symbol\n");
        c_label6:
        printf("Please press 1 to continue or 0 to exit\n");
        getchar();
        scanf("%c",&c_i4);
        if(c_i4=='1')
        {
            goto c_label4;
        }
        else if(c_i4=='0')
        {
            char ch;
            scanf("%c",&ch);
            getchar();
            return;
        }
        else
        {
            printf("Invalid input\n");
            goto c_label6;
        }
    }
    if(strstr(Email,".com")==NULL)
    {
        printf("Email must contain '.com' symbol\n");
        c_label7:
        printf("Please press 1 to continue or 0 to exit button\n");
        getchar();
        scanf("%c",&c_i5);
        if(c_i5=='1')
        {
            goto c_label4;
        }
        else if(c_i5=='0')
        {
            char ch;
            scanf("%c",&ch);
            getchar();
            return; 
        }
        else
        {
            printf("Inalid input\n");
            goto c_label7;
        } 
    }
    if((strcmp(Email,"@.com")==0)||(strcmp(Email,".com@")==0))
    {
        printf("Please enter unique email id\n");
        c_label8:
        printf("Please press 1 to continue or 0 to exit\n");
        getchar();
        scanf("%c",&c_i6);
        if(c_i6=='1')
        {
            goto c_label4;
        }
        else if(c_i6=='0')
        {
            char ch;
            scanf("%c",&ch);
            getchar();
            return;
        }
        else
        {
            printf("Invalid input\n");
            goto c_label8;
        }
    }
    /*if(strstr(Email,".com")==0)
    {
        printf("Please enter '.com' symbol\n");
    }*/
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(Email==addressBook->contacts[i].email)
        {
            printf("Entered email already exists\n");
            printf("Please press any button to restart\n");
            char ch;
            scanf("%c",&ch);
            getchar();
            return;
        }
    }
    strcpy(addressBook->contacts[addressBook->contactCount].email,Email);
    addressBook->contactCount++;
    printf("Your contact is saved successfully\n");
    printf("Pleas press any button to exit\n");
    char ch;
    scanf("%c",&ch);
    getchar();
    return;

}

void searchContact(AddressBook *addressBook) 
{
    s_label1:
    printf("------------------------\n");
    printf("Please enter your option \n");
    printf("------------------------\n");
    printf("Press 1. Search by name\n");
    printf("Press 2. Search by phone number\n");
    printf("Press 3. Search by email\n");
    char k;
    int s_i1;
    getchar();
    scanf("%c",&k);
    switch(k)
    {
        case '1':
        {
            int flag=0;
            int n1;
            label2:
            printf("Enter the name\n");
            char Name[100];
            scanf(" %[^\n]",Name);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if((strstr(Name,addressBook->contacts[i].name))!=NULL)
                {
                    flag++;
                    printf("--------------------------\n");
                    printf("name : %s \tPhone no : %s\temail ID : %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("\n--------------------------\n");
                } 
                if((i==(addressBook->contactCount-1))&&(flag!=0))
                {
                    printf("\nContact details displayed successfully\n");
                    printf("Please press any button to  exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
            }
                    printf("\nSorry!!!  Entered name is not present in the list\n");
                    label1:
                    printf("Do you want to try again\n");
                    printf("Press 1 to continue and 0 to exit\n");
                    scanf("%d",&n1);
                    getchar();
                    if(n1==1)
                    {
                        goto label2;
                    }
                    else if(n1==0)
                    {
                        printf("Please press any button to exit\n");
                        char ch2;
                        scanf("%c",&ch2);
                        getchar();
                        return;
                    }
                    else
                    {
                        printf("Invalid input\n");
                        goto label1;
                    }
                    return;
        }
        case '2':
        {
            int n1;
            label4:
            printf("Enter the Phone number\n");
            char Phone[100];
            scanf(" %[^\n]",Phone);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if((strstr(Phone,addressBook->contacts[i].phone))!=NULL)
                {
                    printf("--------------------------\n");
                    printf("name : %s \nPhone no : %s\nemail ID : %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("\n--------------------------\n");
                    printf("\nContact details displayed successfully\n");
                    printf("Please press any button to  exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }  
            }
                    printf("\nSorry!!!  Entered phone number is not present in the list\n");
                    label3:
                    printf("Do you want to try again\n");
                    printf("Press 1 to continue and 0 to exit\n");
                    scanf("%d",&n1);
                    if(n1==1)
                    {
                        goto label4;
                    }
                    else if(n1==0)
                    {
                        printf("Please press any button to exit\n");
                        char ch2;
                        scanf("%c",&ch2);
                        getchar();
                        return;
                    }
                    else
                    {
                        printf("Invalid input\n");
                        goto label3;
                    }
                    return;
        }
        case '3':
        {
            int n1;
            label6:
            printf("Enter the Email ID \n");
            char Email[100];
            scanf(" %[^\n]",Email);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if((strstr(Email,addressBook->contacts[i].email))!=NULL)
                {
                    printf("--------------------------\n");
                    printf("name : %s \nPhone no : %s\nemail ID : %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("\n--------------------------\n");
                    printf("\nContact details displayed successfully\n");
                    printf("Please press any button to  exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }  
            }
                    printf("\nSorry!!!  Entere email ID is not present in the list\n");
                    label5:
                    printf("Do you want to try again\n");
                    printf("Press 1 to continue and 0 to exit\n");
                    scanf("%d",&n1);
                    if(n1==1)
                    {
                        goto label6;
                    }
                    else if(n1==0)
                    {
                        printf("Please press any button to exit\n");
                        char ch2;
                        scanf("%c",&ch2);
                        getchar();
                        return;
                    }
                    else
                    {
                        printf("Invalid input\n");
                        goto label5;
                    }
                    return;  
        } 
        default:
        {
            printf("Invalid input\n");
            s_label2:
            printf("Please press 1 to continue or 0 to exit\n");
            scanf("%d",&s_i1);
            if(s_i1==1)
            {
                goto s_label1;
            }
            else if(s_i1==0)
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto s_label2;
            }
        }
    }
}

void editContact(AddressBook *addressBook) 
{
    e_label9:
    printf("------------------------------\n");
    printf("      Enter your option\n");
    printf("------------------------------\n");
    printf("Press 1. Edit the name\n");
    printf("Press 2. Edit the phone number\n");
    printf("Press 3. Edit the email ID\n");
    printf("------------------------------\n");
    char e_num1[100];
    int e_num2;
    char e_n;
    char e_n9;
    int index_i=0;
    getchar();
    scanf("%c",&e_n);
    switch(e_n)
    {
        case '1':
        {
           // int index_i=0;
            e_label1:
            printf("Enter the name you want to edit\n");
            int arr[100];
            int arr_index=0;
            int e_flag=0;
            int e_n1;
            int Sr_no;
            char e_Name[100];
            scanf(" %[^\n]",e_Name);

            for(index_i=0;index_i<addressBook->contactCount;index_i++)
            {
                //////////////////////////////////////
                if((strcmp(e_Name,addressBook->contacts[index_i].name))==0)
                {
                    e_flag++;
                    arr[arr_index]=index_i;
                    arr_index++;
                    printf("-------------------------------------------------------------------------------------\n");
                    printf("| Sr no %d |     Name : %s\tPhone no : %s\temail ID : %s",index_i+1,addressBook->contacts[index_i].name,addressBook->contacts[index_i].phone,addressBook->contacts[index_i].email);
                    printf("\n-------------------------------------------------------------------------------------\n");
                    e_num2=index_i;
                }
                else if((index_i==(addressBook->contactCount-1))&&(e_flag==0))
                {
                    printf("Entered name is not present in the contact list\n");
                    printf("Press 1 to continue or 0 to exit\n");
                    char e_n21;
                    getchar();
                    scanf("%c",&e_n21);
                    if(e_n21=='1')
                    {
                        goto e_label1;
                    }
                    else if(e_n21=='0')
                    {
                        return;
                    }
                    else
                    {
                        printf("Invalid input\n");
                        printf("Press 1 to continue or 0 to exit\n");
                        char e_n22;
                        getchar();
                        scanf("%c",&e_n22);
                        if(e_n22=='1')
                        {
                            goto e_label1;
                        }
                        else return;
                    }
                }
            }
            if(e_flag==1)
            {
                goto e_label25;
            }
            else
            {
                //e_label35:
                printf("\n-------------------------------------------------\n");
                printf("Oops!! There are multiple contact on this number\n");
                printf("-------------------------------------------------\n");
                e_label35:
                printf("Enter the Sr number of diplayed contact you wanna edit\n");
                scanf("%s",e_num1);
                e_num2=atoi(e_num1);
                e_num2--;
                for(int k=0;k<arr_index;k++)
                {
                    if(e_num2==arr[k])
                    {
                        goto e_label25;
                    }
                }
                printf("Invalid Sr number\n");
                printf("Press 1 to continue or Press any other button to exit\n");
                char e_30;
                getchar();
                scanf("%c",&e_30);
                if(e_30=='1')
                {
                    goto e_label35;
                }
                else
                {
                    return;
                }
            }

                    e_label25:
                    printf("Enter the new name\n");
                    char e_Name1[100];
                    scanf(" %[^\n]",e_Name1);
                    strcpy(addressBook->contacts[e_num2].name,e_Name1);
                    printf("\n---------------------------------------------------------\n");
                    printf("Name changed successfully\n");
                    printf("----------------------------------------------------------\n");
                    printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[e_num2].name,addressBook->contacts[e_num2].phone,addressBook->contacts[e_num2].email);
                    printf("----------------------------------------------------------\n");
                    printf("Press 1 to edit phone number, 2 to edit email ID or 0 to exit\n");
                    char e_n11;
                    getchar();
                    scanf("%c",&e_n11);
                    if(e_n11=='1')
                    {
                        validate_phone_number(addressBook,e_num2);
                        printf("Phone number changed successfully\n");
                        printf("-----------------------\n");
                        printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[e_num2].name,addressBook->contacts[e_num2].phone,addressBook->contacts[e_num2].email);
                        printf("------------------------\n");
                        printf("Press 1 to edit Email ID or 0 to exit\n");
                        char e_n14;
                        getchar();
                        scanf("%c",&e_n14);
                        if(e_n14=='1')
                        {
                            validate_email_ID(addressBook,e_num2);
                            printf("Email ID changed successfully\n");
                            printf("---------------------------------------\n");
                            printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[e_num2].name,addressBook->contacts[e_num2].phone,addressBook->contacts[e_num2].email);
                            printf("---------------------------------------\n");
                            printf("Press any button to exit\n");
                            char e_n13;
                            getchar();
                            scanf("%c",&e_n13);
                            return;
                        }
                        else
                        {
                            char e_n12;
                            getchar();
                            scanf("%c",&e_n12);
                            return;
                        }
                    }
                    else if(e_n11=='2')
                    {
                        validate_email_ID(addressBook,e_num2);
                        printf("Email ID changed successfully\n");
                        printf("---------------------------------------\n");
                        printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[e_num2].name,addressBook->contacts[e_num2].phone,addressBook->contacts[e_num2].email);
                        printf("---------------------------------------\n");
                        printf("Press 1 to edit phone number or 0 to exit\n");
                        char e_n13;
                        getchar();
                        scanf("%c",&e_n13);
                        if(e_n13=='1')
                        {
                            validate_phone_number(addressBook,e_num2);
                            printf("Phone number changed successfully\n");
                            printf("---------------------------------------\n");
                            printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[e_num2].name,addressBook->contacts[e_num2].phone,addressBook->contacts[e_num2].email);
                            printf("---------------------------------------\n");
                            printf("Press any button to exit\n");
                            char e_n16;
                            scanf("%c",&e_n16);
                            getchar();
                            return;
                        }
                        else
                        {
                            return;
                        }
                    }
                    else
                    {
                    printf("Please press any button to exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                    }
                
        }   
        case '2':
        {
            char e_n2,e_n3,e_n4;
            e_label3:
            printf("Enter the phone no you want to edit\n");
            char e_Phone[100];
            char e_Phone1[100];
            scanf("%s",e_Phone);
            int e_i=0;
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if((strcmp(e_Phone,addressBook->contacts[i].phone))==0)
                {
                    e_label5:
                    printf("Enter the 10 digit new phone number\n");
                    scanf("%s",e_Phone1);
                    while(e_Phone1[e_i]!='\0')
                    {
                        if(e_Phone1[e_i]>'9'||e_Phone1[e_i]<'0')
                        {
                            printf("Please enter digits only\n");
                            e_label6:
                            printf("Press 1 to continue editing new number or 0 to exit\n");
                            scanf("%c",&e_n3);
                            if(e_n3=='1')
                            {
                                goto e_label5;
                            }
                            else if(e_n3=='0')
                            {
                               return; 
                            }
                            else
                            {
                                printf("Invalid input\n");
                                goto e_label6;
                            }
                        }
                        e_i++;
                    }
                    if((strlen(e_Phone1))!=10)
                        {
                            printf("Phone number should contain 10 digits\n");
                            e_label7:
                            printf("Press 1 to continue editing new number or 0 to exit\n");
                            scanf("%c",&e_n4);
                            if(e_n4=='1')
                            {
                                goto e_label5;
                            }
                            else if(e_n4=='0')
                            {
                                return;
                            }
                            else
                            {
                                printf("Inavlid input\n");
                                goto e_label7;
                            }
                        }
                    strcpy(addressBook->contacts[i].phone,e_Phone1);
                    printf("\n-------------------------\n");
                    printf("Phone number changed successfully\n");
                    printf("Name : %s\nPhone no : %s\nemail ID : %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("\n-------------------------\n");
                    printf("Press 1 to edit name number, 2 to edit email ID or 0 to exit\n");
                    char e_n12;
                    getchar();
                    scanf("%c",&e_n12);
                    if(e_n12=='1')
                    {
                        validate_name(addressBook,i);
                        printf("name changed successfully\n");
                        printf("-------------------------------------\n");
                        printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("-------------------------------------\n");
                        printf("Press any button to exit\n");
                        char e_n21;
                        scanf("%c",&e_n21);
                        getchar();
                        return;
                    }
                    else if(e_n12=='2')
                    {
                        validate_email_ID(addressBook,i);
                        printf("Email ID changed successfully\n");
                        printf("-------------------------------------\n");
                        printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("-------------------------------------\n");
                        printf("Press any button to exit\n");
                        char e_n22;
                        getchar();
                        scanf("%c",&e_n22);
                        return;
                    }
                    else
                    {
                    printf("Please press any button to exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                    }
                }
                
            }
                printf("Entered phone number is not present in  the contact list \n");
                printf("Please try different phone no\n");
                e_label4:
                printf("Please press 1 to continue and 0 to exit\n");
                scanf("%c",&e_n2);
                if(e_n2=='1')
                {
                    goto e_label3;
                }
                else if(e_n2=='0')
                {
                    printf("Please press any button to exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                    goto e_label4;
                }
        }
        case '3':
        {
            printf("Enter the email ID you want to edit\n");
            char Email[100];
            scanf("%s",Email);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strstr(Email,addressBook->contacts[i].email)!=NULL)
                {
                    printf("Enter the new email ID \n");
                    char Email1[100];
                    scanf("%s",Email1);
                    strcpy(addressBook->contacts[i].email,Email1);
                    printf("Email ID changed successfully\n");
                    printf("-------------------------------------\n");
                    printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("-------------------------------------\n");
                    printf("Press 1 to edit phone number, 2 to edit name or 0 to exit\n");
                    getchar();
                    char e_n12;
                    scanf("%c",&e_n12);
                    if(e_n12=='1')
                    {
                        validate_phone_number(addressBook,i);
                        printf("Phone number changed successfully\n");
                        printf("--------------------------\n");
                        printf("Name : %s\nPhone no : %s\nemail ID : %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("-------------------------\n");
                        printf("Press 1 to change name or 0 to exit\n");
                        char e_n17;
                        getchar();
                        scanf("%c",&e_n17);
                        if(e_n17=='1')
                        {
                            validate_name(addressBook,i);
                            printf("Name changed successfully\n");
                            printf("--------------------------\n");
                            printf("Name : %s\nPhone no : %s\nemail ID : %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                            printf("\n-------------------------\n");
                            printf("Press any button to exit\n");
                            char e_n20;
                            getchar();
                            scanf("%c",&e_n20);
                            return;

                        }
                        else
                        {
                            return;
                        }
                    }
                    else if(e_n12=='2')
                    {
                        validate_name(addressBook,i);
                        printf("Name changed successfully\n");
                        printf("--------------------------\n");
                        printf("Name : %s\nPhone no : %s\nemail ID : %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("\n-------------------------\n");
                        printf("Press any button to eixt\n");
                        char e_n18;
                        scanf("%c",&e_n18);
                        getchar();
                        return;
                    }
                    else
                    {
                        printf("Please press any button to exit\n");
                        char ch;
                        scanf("%c",&ch);
                        getchar();
                        return;
                    }
                }
            }
                printf("Entered Email ID is not present in  the contact list \n");
                printf("Please try different Email ID\n");
                printf("Please press any button to exit\n");
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
        }
        default:
        {
            printf("Invalid input\n");
            e_label8:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&e_n9);
            if(e_n9=='1')
            {
                goto e_label9;
            }
            else if(e_n9=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto e_label8;
            }
        }
    }
}  


void deleteContact(AddressBook *addressBook) 
{
    d_label7:
    printf("------------------------\n");
    printf("Please enter your option\n");
    printf("------------------------\n");
    printf("Press 1. to delete by name\n");
    printf("Press 2. to delete by Phone number\n");
    printf("Press 3. to delete by email ID\n");
    char n,d_i1,d_i2,d_i3,d_i4,d_i5;
    getchar();
    scanf("%c",&n);
    switch(n)
    {
        case '1':
        {
            int d_flag=0,Sr_no;
            char d_num1[100];
            int d_num2;
            d_label1:
            printf("---------------------------------\n");
            printf("Enter the name you want to delete\n");
            printf("---------------------------------\n");
            char Name[100];
            scanf(" %[^\n]",Name);
            int arr[100];
            int arr_index=0;
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(addressBook->contacts[i].name,Name)==0)
                {
                    d_flag++;
                    Sr_no=i+1;
                    arr[arr_index++]=Sr_no;
                    //arr_index++;
                    printf("-------------------------------------------------------------------------------------\n");
                    printf("Sr. no %d: Name : %s\tPhone no : %s\temail ID : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("-------------------------------------------------------------------------------------\n");
                }
                else if(i==(addressBook->contactCount-1)&&(d_flag==0))
                {
                    printf("Entered name is not present in the contact list\n");
                    d_label11:
                    printf("Press 1 to continue to delete different name or 0 to exit\n");
                    getchar();
                    scanf("%c",&d_i5);
                    if(d_i5=='1')
                    {
                        goto d_label1;
                    }
                    else if(d_i5=='0')
                    {
                        return;
                    }
                    else
                    {
                        printf("Invalid input\n");
                        goto d_label11;
                    }

                }
            }
            if(d_flag>1)
            {
                printf("Oops!! There are multipe names contacts by this name\n");
                d_label16:
                printf("Enter the Sr number of diplayed contact you wanna delete\n");
                scanf("%s",d_num1);
                d_num2=atoi(d_num1);
                for(int k=0;k<arr_index;k++)
                {
                    if(d_num2==arr[k])
                    {
                        goto d_label15;
                    }
                }
                    printf("Invalid Sr number\n");
                    printf("Press 1 to continue or Press other button to exit\n");
                    char d_exit;
                    getchar();
                    scanf("%c",&d_exit);
                    if(d_exit=='1')
                    {
                        goto d_label16;
                    }
                    else
                    {
                        return;
                    }
            }
            else
            {
                d_num2=Sr_no;
                //printf("%d\n",d_num2);
            }
            d_label15:

                    for(int j=(d_num2-1);j<addressBook->contactCount;j++)
                    {

                        strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                        strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                        strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);

                    }
                    addressBook->contactCount=addressBook->contactCount-1;
                    printf("Entered contact deleted successfully\n");
                    printf("Please press any button to exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
        }
        case '2':
        {
            d_label3:
            printf("---------------------------------\n");
            printf("Enter the phone number you want to delete\n");
            printf("---------------------------------\n");
            char Phone[100];
            scanf("%s",Phone);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if((strstr(Phone,addressBook->contacts[i].phone))!=NULL)
                {
                    for(int j=i;j<addressBook->contactCount;j++)
                    {

                        strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                        strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                        strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);

                    }
                    addressBook->contactCount=addressBook->contactCount-1;
                    printf("Entered contact deleted successfully\n");
                    printf("Please press any button to exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
            }
            printf("Entered Phone number is not found in the contact list\n");
            printf("Please try different name\n");
            d_label4:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&d_i2);
            if(d_i2=='1')
            {
                goto d_label3;
            }
            else if(d_i2=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Inalid input\n");
                goto d_label4;
            }
        }
        case '3':
        {
            d_label5:
            printf("---------------------------------\n");
            printf("Enter the email ID you want to delete\n");
            printf("\n---------------------------------\n");
            char Email[100];
            scanf("%s",Email);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if((strstr(Email,addressBook->contacts[i].email))!=NULL)
                {
                    for(int j=i;j<addressBook->contactCount-1;j++)
                    {

                        strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                        strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                        strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);

                    }
                    addressBook->contactCount=addressBook->contactCount-1;
                    printf("Entered contact deleted successfully\n");
                    printf("Please press any button to exit\n");
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
            }
            printf("Entered email ID is not found in the contact list\n");
            printf("Please try different name\n");
            d_label6:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&d_i3);
            if(d_i3=='1')
            {
                goto d_label5;
            }
            else if(d_i3=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Inalid input\n");
                goto d_label6;
            }
        }
        default:
        {
            printf("Invalid input\n");
            d_label8:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&d_i4);
            if(d_i4=='1')
            {
                goto d_label7;
            }
            else if(d_i4=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Inalid input\n");
                goto d_label8;
            }
        }
    }
}
void validate_name(AddressBook *addressBook,int vali_name_i)
{
    printf("Enter the new name\n");
    char vali_name[100];
    scanf(" %[^\n]",vali_name);
    strcpy(addressBook->contacts[vali_name_i].name,vali_name);
    return;
}
void validate_phone_number(AddressBook *addressBook,int vali_phone_i)
{
    char vali_phone_c_i1,vali_phone_c_i2,vali_phone_c_i7;
    vali_phone_c_label1:
    printf("-------------------------------\n");
    printf("Enter the 10 digit Phone Number\n");
    printf("-------------------------------\n");
    char Phone[100];
    scanf("%s",Phone);
    int cnt=0;
        for(int j=0;Phone[j]!='\0';j++)
        {
            cnt++;
            if(Phone[j]>'9'||Phone[j]<'0')
            {
                printf("Phone number should not contain alphabet, Only enter digits\n");
                vali_phone_c_label2:
                printf("Please press 1 to continue or 0 to exit\n");
                getchar();
                scanf("%c",&vali_phone_c_i1);
                if(vali_phone_c_i1=='1')
                {
                    goto vali_phone_c_label1;
                }
                else if(vali_phone_c_i1=='0')
                {
                    char ch;
                    printf("Please press any button to exit \n");
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                    goto vali_phone_c_label2;
                }
            }
         }
        if(cnt!=10)
            {
                printf("Phone number should contain 10 digits\n");
                vali_phone_c_label3:
                printf("Please press 1 to continue or 0 to exit\n");
                getchar();
                scanf("%c",&vali_phone_c_i2);
                if(vali_phone_c_i2=='1')
                {
                    goto vali_phone_c_label1;
                }
                else if(vali_phone_c_i2=='0')
                {
                    char ch;
                    scanf("%c",&ch);
                    getchar();
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                    goto vali_phone_c_label3;
                }
            }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((strcmp(Phone,addressBook->contacts[i].phone))=='\0')
        {
            printf("Entered number already exists\n");
            printf("Please enter different phone number\n");
            vali_phone_c_label9:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&vali_phone_c_i7);
            if(vali_phone_c_i7=='1')
            {
                goto vali_phone_c_label1;
            }
            else if(vali_phone_c_i7=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto vali_phone_c_label9;
            }
        }
    }
    strcpy(addressBook->contacts[vali_phone_i].phone,Phone);
    return;
}
void validate_email_ID(AddressBook *addressBook,int vali_email_i)
{
    char vali_email_c_i3,vali_email_c_i4,vali_email_c_i5,vali_email_c_i6,c_i8; 
    vali_email_c_label4:
    printf("------------------\n");
    printf("Enter the email id\n");
    printf("------------------\n");
    char Email[50];
    scanf("%s",Email);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(Email,addressBook->contacts[i].email)==0)
        {
            printf("Entered email ID already exists\n");
            printf("Please try the different email ID\n");
            vali_email_c_label13:
            printf("Press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&c_i8);
            if(c_i8=='1')
            {
                goto vali_email_c_label4;
            }
            else if(c_i8=='0')
            {
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto vali_email_c_label13;
            }

        }
    }
    for(int i=0;i<strlen(Email);i++)
    {
        if(Email[i]!='@'&&Email[i]>'z'&&Email[i]<'a')
        {
            printf("Please only enter small letters\n");
            vali_email_c_label5:
            printf("Please press 1 to continue or 0 to exit\n");
            getchar();
            scanf("%c",&vali_email_c_i3);
            if(vali_email_c_i3=='1')
            {
                goto vali_email_c_label4;
            }
            else if(vali_email_c_i3=='0')
            {
                char ch;
                scanf("%c",&ch);
                getchar();
                return;
            }
            else
            {
                printf("Invalid input\n");
                goto vali_email_c_label5;
            }
        }
    }
    if(strchr(Email,'@')==NULL)
    {
        printf("Email must contain '@' symbol\n");
        vali_email_c_label6:
        printf("Please press 1 to continue or 0 to exit\n");
        getchar();
        scanf("%c",&vali_email_c_i4);
        if(vali_email_c_i4=='1')
        {
            goto vali_email_c_label4;
        }
        else if(vali_email_c_i4=='0')
        {
            char ch;
            scanf("%c",&ch);
            getchar();
            return;
        }
        else
        {
            printf("Invalid input\n");
            goto vali_email_c_label6;
        }
    }
    if(strstr(Email,".com")==NULL)
    {
        printf("Email must contain '.com' symbol\n");
        vali_email_c_label7:
        printf("Please press 1 to continue or 0 to exit button\n");
        getchar();
        scanf("%c",&vali_email_c_i5);
        if(vali_email_c_i5=='1')
        {
            goto vali_email_c_label4;
        }
        else if(vali_email_c_i5=='0')
        {
            char ch;
            scanf("%c",&ch);
            getchar();
            return; 
        }
        else
        {
            printf("Inalid input\n");
            goto vali_email_c_label7;
        } 
    }
    if(strcmp(Email,"@.com")==0)
    {
        printf("Please enter unique email id\n");
        vali_email_c_label8:
        printf("Please press 1 to continue or 0 to exit\n");
        getchar();
        scanf("%c",&vali_email_c_i6);
        if(vali_email_c_i6=='1')
        {
            goto vali_email_c_label4;
        }
        else if(vali_email_c_i6=='0')
        {
            char ch;
            scanf("%c",&ch);
            getchar();
            return;
        }
        else
        {
            printf("Invalid input\n");
            goto vali_email_c_label8;
        }
    }
    /*if(strstr(Email,".com")==0)
    {
        printf("Please enter '.com' symbol\n");
    }*/
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(Email==addressBook->contacts[i].email)
        {
            printf("Entered email already exists\n");
            printf("Please press any button to restart\n");
            char ch;
            scanf("%c",&ch);
            getchar();
            return;
        }
    }
    strcpy(addressBook->contacts[vali_email_i].email,Email);
    addressBook->contactCount++;
    printf("Your contact is saved successfully\n");
    printf("Pleas press any button to exit\n");
    char ch;
    scanf("%c",&ch);
    getchar();
    return;
}
