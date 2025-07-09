#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DOCS 50
#define MAX_LEN 5000
#define MAX_TOKENS 500
#define MAX_TOKEN_LEN 50
#define NUM_STOP_WORDS 8
int token_count = 0, except_count = 0;
int set_flag = 0, tokenize_flag = 0;
int stem_count = 0;
char suffix[10];
char documents[MAX_DOCS][MAX_LEN];
char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
char tokens_except_stop_words[MAX_TOKENS][MAX_TOKEN_LEN];
char stemmed_tokens[MAX_TOKENS][MAX_TOKEN_LEN];
char stop_words[NUM_STOP_WORDS][MAX_TOKEN_LEN] = {"the", "is", "a", "an", "and", "in", "of", "to"};
void stem_all_tokens()
{

    for (int i = 0; i < except_count; i++)
    {
        int length = strlen(tokens_except_stop_words[i]);
        if (strcmp(tokens_except_stop_words[i] + length - 3, "ing") == 0)
        {
            strcpy(stemmed_tokens[stem_count], tokens_except_stop_words[i]);
            stemmed_tokens[stem_count][length - 3] = '\0';
            stem_count++;
            continue;
        }
        if (strcmp(tokens_except_stop_words[i] + length - 2, "ed") == 0)
        {
            strcpy(stemmed_tokens[stem_count], tokens_except_stop_words[i]);
            stemmed_tokens[stem_count][length - 2] = '\0';
            stem_count++;
            continue;
        }
        if (strcmp(tokens_except_stop_words[i] + length - 1, "s") == 0)
        {
            strcpy(stemmed_tokens[stem_count], tokens_except_stop_words[i]);
            stemmed_tokens[stem_count][length - 1] = '\0';
            stem_count++;
            continue;
        }
        strcpy(stemmed_tokens[stem_count], tokens_except_stop_words[i]);
        stem_count++;
    }
}
void remove_stop_words_all()
{
    int flag = 0, k = 0;
    for (int i = 0; i < token_count; i++)
    {
        flag = 0;
        for (k= 0; k < NUM_STOP_WORDS; k++)
        {
            if (strcmp(tokens[i], stop_words[k]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            strcpy(tokens_except_stop_words[except_count], tokens[i]);
            except_count++;
        }
    }
}
void tokenize_all()
{
    for (int i = 0; i < MAX_TOKENS; i++)
    {
        tokens[i][0] = '\0';
    }
    int i = 0, j = 0;
    int k = 0, l = 0;
    while (1)
    {
        if (isalnum(documents[i][j]))
        {
            tokens[k][l] = documents[i][j];

            l++;
            j++;
        }
        else
        {
            if(l>0)
            
            {tokens[k][l] = '\0';
                k++;
                l = 0;
                
                token_count++;}
            j++;
        }
        if (documents[i][j] == '\0')
        {
            if (l > 0)
            {
                tokens[k][l] = '\0';
                k++;
                l = 0;
                token_count++;
            }

            i++;
            j = 0;
        }
        if(documents[i][0] == '\0')
        {
            break;
        }
    }
}
void normalize_case_all()
{
    for (int i = 0; documents[i][0] != '\0'; i++)
    {
        for (int j = 0; documents[i][j] != '\0'; j++)
        {
            documents[i][j] = tolower(documents[i][j]);
        }
    }
}
int main()
{

    for (int i = 0; i < MAX_DOCS; i++)
    {
        documents[i][0] = '\0';
    }
    char take_input[30];
    int doc_num;
    printf(
        "Welcome to the Document Processing System!\n"
        "set         - Prompt for the number of documents and their text.\n"
        "preprocess  - normalizes,tokenization, removes stop words, stems.\n"
        "tf          - Compute and display Term Frequency for a specified word across documents.\n"
        "idf         - Compute and display Inverse Document Frequency for a specified word.\n"
        "tfidf       - Compute and display TF-IDF scores for a specified word across documents.\n"
        "stat        - Display TF, IDF, and TF-IDF for all tokens across all documents in a matrix format.\n"
        "help        - Print the list of all available commands.\n"
        "exit        - Exit the program.\n");

    while (1)
    {
        printf("Enter Command:");
        fgets(take_input, 30, stdin);
        int take_input_index = strlen(take_input) - 1;
        take_input[take_input_index] = '\0';

        if (strcmp(take_input, "set") == 0)
        {

            printf("Enter document:");
            scanf("%d", &doc_num);
            while (doc_num > 50)
            {
                printf("Invalid number of documents\n");
                scanf("%d", &doc_num);
            }
            getchar();
            int i = 0;
            while (i < doc_num)
            {
                printf("Enter Document %d :", i + 1);
                fgets(documents[i], MAX_LEN, stdin);
                int index = strlen(documents[i]) - 1;
                if (documents[i][index] == '\n')
                {
                    documents[i][index] = '\0';
                }
                else
                {
                    printf("Document too long\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                i++;
            }
            set_flag = 1;
        }
        else if (set_flag == 0)
        {
            printf("No documents set. use 'set' command first.\n");
            continue;
        }
        else if (strcmp(take_input, "preprocess") == 0)
        {
            normalize_case_all();
            for (int i = 0; i < doc_num; i++)
            {
                printf("Document %d: %s\n", i + 1, documents[i]);
            }
            printf("Documents Normalized.\n");
            tokenize_all();
            tokenize_flag = 1;
            printf("Tokens:\n");
            for (int i = 0; i < token_count; i++)
            {
                printf("%d. %s\n", i + 1, tokens[i]);
            }
            printf("Tokenization complete. Total tokens:%d\n", token_count);

            remove_stop_words_all();
            printf("Tokens after stop word removal:\n");
            for (int i = 0; i < except_count; i++)
            {
                printf("%d.%s\n", i + 1, tokens_except_stop_words[i]);
            }
            printf("Stop word removal complete. Tokens remaining: %d", except_count);

            stem_all_tokens();
            printf("Stemmed tokens\n");
            for (int i = 0; i < stem_count; i++)
            {
                printf("%d.%s\n", i + 1, stemmed_tokens[i]);
            }
            printf("Stemming complete. Total stemmed tokens:%d\n", stem_count);
        }

        else if (strcmp(take_input, "exit") == 0)
        {
            return 0;
        }
    }
}
