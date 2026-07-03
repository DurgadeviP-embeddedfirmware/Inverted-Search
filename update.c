#include"inverted_Search.h"

int update_database(Wlist * head[], Flist **f_head)
{
    char filename[WORD_SIZE];
    printf("Enter the new filename : ");
    scanf(" %s", filename);
    //file validation
    if(file_validation_update(f_head, filename) == SUCCESS)
    {
        Flist *temp = *f_head;
        while(temp)
        {
            if(! strcmp(temp->file_name, filename)  )
            {
                create_database(temp, head);
            }
            temp = temp->link;
        }
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

int  file_validation_update(Flist **f_head, char *filename)
{
    int empty;
    empty = isFileEmpty(filename);
    if(empty == FILE_NOTAVAILABLE)
        {
            printf("File : %s is not available\n" , filename);
            printf("Hence we are not adding that file into file linked list\n");
        }

        else if (empty == FILE_EMPTY)
        {
            printf("File : %s is not having any content \n" , filename);
            printf("Hence we are not adding that file into file linked list\n");
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head , filename);
            if(ret_val == SUCCESS)
            {
                printf("Successfully inserted the file %s into file linked list\n" , filename);
                return SUCCESS;
            }
            else if(ret_val == REPEATATION)
            {
                printf("This file name %s is repeated\n" , filename);
            }
            else
            {
                printf("failure\n");
            }
        }
}