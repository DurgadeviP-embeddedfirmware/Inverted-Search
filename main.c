#include "inverted_Search.h"

int main(int argc , char *argv[])
{
    system("clear");

    //1.validate the input arguments
    if(argc <= 1)
    {
        printf("Enter the valid no. of arguments \n");
        printf("./Slist.exe file1.txt file2.txt ..... \n");
        return 0;
    }

    //create file linked list 
    // declare the head pointer 

    Flist *f_head = NULL;
    int choice;
    char ch, word[WORD_SIZE];
        //validation of input files
    file_validation_n_file_list(&f_head ,argv);
    if(f_head == NULL)
    {
        printf("No files are added to file linked list\n");
        printf("Hence the process got terminated\n");
        return 1;
    }
    Wlist *head[27] = {NULL};
    while(1)
    {
        printf("-----------Welcome to Inverted Search Technique----------\n");
        printf("1. Create Database \n2. Display Database \n3. Search Database \n4. Update Database \n5. Save Database \n6. Exit \n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Create Database\n");
                if(create_database(f_head,head) == SUCCESS)
                {
                    printf("Database created successfully\n");
                }
                break;
            case 2:
                printf("Display Database\n");
                display_database(head);
                break;
            case 3:
                printf("Search Database\n");
                printf("Enter word to search : ");
                scanf("%s", word);
                //printf("%s",word);
                search( head[(tolower(word[0]) % 97)] , word);
                break;
            case 4:
                printf("Update Database\n");
                update_database(head,&f_head);
                break; 
            case 5:
                printf("Save Database\n");
                save_database(head);
                break; 
            case 6:
                
                printf("Exit ...\n");
                exit(1);
                break;
            default:
                printf("Invalid choice...\n");
                break;                    
        }
    }
    printf("Want to save changes (y / n) : ");
    scanf(" %c", &ch);
    if(ch == 'y')
    {
        printf("saved changes...\n");
    }       

}