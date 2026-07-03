#include"inverted_Search.h"

void display_database( Wlist *head[])
{
    printf("[index]\t [word]\t file_count\t filename and word_count\t\n");
    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            //printf("t");
            print_word_count(head[i]);
        }
    }
}

int print_word_count(Wlist *head)
{
    
    while(head )
    {
        printf("[%d]\t %s\t %d file/s\t", tolower(head->word[0])%97, head->word, head->file_count);
        Ltable *temp = head->Tlink;
        while(temp)
        {
            printf(" %s-> %d", temp->file_name, temp->word_count);
            temp = temp->table_link;
        }
        printf("\n");
        head = head->link;
    }
}