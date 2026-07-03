#include "inverted_Search.h"
char * filenames;
int create_database(Flist *f_head, Wlist *head[])
{
    while(f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
    return SUCCESS;
}


Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    filenames = filename;
    FILE *fptr = fopen(filename, "r");
    int flag = 0;
    char word[WORD_SIZE];

    while(fscanf(fptr, "%s", word) != EOF)
    {
        flag = 0;
        //printf("%s\n", word);
        int index = tolower(word[0]) % 97;
        //printf("%d\n", index);
        if( !(index  >= 0  && index <= 25) )
        {
            index = 26;
        }
        if(head[index] == NULL)
        {
            //printf("s\n");
            insert_at_last(&head[index], word);
            //printf("ss\n");
            continue;
        }
        if(head[index] != NULL)
        {
            //printf("j\n");
            Wlist *temp = head[index];
            while(temp)
            {
                if(!strcmp(temp->word , word))
                {
                    //printf("equal\n");
                    update_word_count(&temp, filename);
                    flag = 1;
                }
                temp = temp->link;
            }
        }
        if(flag == 0)
        {
           insert_at_last(&head[index], word);
        }
        //fgetc(fptr);
    }
    fclose(fptr);
}

int update_word_count(Wlist ** head, char * file_name)
{
    Ltable *temp = (*head)->Tlink, *prev = temp;
    if(temp != NULL)
    {
        if(!strcmp(temp->file_name, file_name) )
        {
            (temp->word_count) ++;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->table_link;
    }
    Ltable *new = malloc(sizeof(Ltable));
    strcpy(new->file_name , file_name);
    new->table_link = NULL;
    new->word_count = 1;
    prev->table_link = new;
    ((*head)->file_count) ++;
    return SUCCESS;
}

int insert_at_last(Wlist **head, data_t *data)
{
    Wlist *new = malloc(sizeof(Wlist));
    new->file_count = 1;
    new->link = NULL;
    new->Tlink = NULL;
    strcpy(new->word, data);
    if(update_link_table(&new) == SUCCESS)
    {
        if(*head == NULL)
        {
            *head = new;
            //printf("p\n");
            return SUCCESS;
        }
        Wlist * temp = *head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

int update_link_table(Wlist **head)
{
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->file_name , filenames);
    new->word_count = 1;
    new->table_link = NULL;
    (*head)->Tlink = new;
    return SUCCESS;
}

