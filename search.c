#include "inverted_Search.h"

int search( Wlist *head, char *word)
{
    if(head == NULL)
    {
        printf("List is empty, Search not possible\n");
        return FAILURE;
    }
    while(head)
    {
        if(!strcmp(head->word, word))
        {
            printf("Word %s is present in %d file/s\n", head->word, head->file_count);
            Ltable *new = head->Tlink;
            while(new)
            {
                printf("In file : %s\t %d time/s\n", new->file_name, new->word_count);
                new = new->table_link;
            }
            return SUCCESS;
        }
        head = head->link;
    }
    printf("Search word not found\n");

}