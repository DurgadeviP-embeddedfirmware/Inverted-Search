#include "inverted_Search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File : %s is not available\n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }

        else if (empty == FILE_EMPTY)
        {
            printf("File : %s is not having any content \n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head , argv[i]);
            if(ret_val == SUCCESS)
            {
                printf("Successfully inserted the file %s into file linked list\n" , argv[i]);
            }
            else if(ret_val == REPEATATION)
            {
                printf("This file name %s is repeated\n" , argv[i]);
            }
            else
            {
                printf("failure\n");
            }

            i++;
            continue;
        }

    }

}

// fun() check for file availability and file contents 

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
        fclose(fptr);
            return FILE_NOTAVAILABLE;
    }
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr) == 0)
    {
        fclose(fptr);
        return FILE_EMPTY;
    }
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    //..........1.TODO...........
    //.... insert_last()
    //......check for repeatancy 
    Flist *new = malloc(sizeof(Flist));
    int flag = 0;
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->file_name , name);
    new->link = NULL;
    if(*f_head == NULL)
    {
        *f_head = new;
        return SUCCESS;
    }
    else
    {
        Flist *temp = *f_head;
        while(temp->link != NULL)
        {
            if(strcmp(temp->file_name , name) == 0)
            {
                flag = 1;
            }
            temp = temp->link;
        }
        if( (flag == 1) || (strcmp(temp->file_name , name) == 0) )
        {
            free(new);
            return REPEATATION;
        }
        temp->link = new;
        return SUCCESS;
    }
}
