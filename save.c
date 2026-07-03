#include"inverted_Search.h"

int save_database( Wlist *head[])
{
    char filename[WORD_SIZE];
    printf("Enter file name to save : ");
    scanf(" %s", filename);
    if(strstr(filename, ".txt") != NULL)
    {
        FILE *fptr = fopen(filename, "w");
        fseek(fptr, 0, SEEK_SET);
        for(int i = 0; i < 27; i++)
        {
            if(head[i] != NULL)
            {
                write_databasefile(head[i], &fptr, i);
            }
        }
    }
    else
    {
        printf("save file format is invalid \nEnter like : file.txt\n");
        return FAILURE;
    }
}

void write_databasefile(Wlist *head, FILE** databasefile, int index)
{
    fseek((*databasefile), 0, SEEK_CUR);
    fprintf( (*databasefile), "#[%d]\n",  index);
    while(head)
    {
        fprintf((*databasefile), "word is [%s]: file_count: %d ", head->word, head->file_count );
        Ltable *temp = head->Tlink;
        while(temp)
        {
            fprintf((*databasefile), "file: %s and word_count: %d ", temp->file_name, temp->word_count);
            temp = temp->table_link;
        }
        fprintf((*databasefile),"\n");
        head = head->link;
    }
    fprintf((*databasefile),"\n");
}