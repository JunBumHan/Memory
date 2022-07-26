#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define ADD_MEMORY 0    // contextSwitch switch value
#define VIEW_MEMORY 1   // contextSwitch switch value

#define BUFFER_MAX 1000 // BUFFER_MAX value

int strcmpSame(const char *str1, const char *str2); 
/*
    Return 1 if both agurment have the same string
    Return 0 if the above condition are not met
*/

int main()
{

    int userMemoryLocation = -1;     // userMemory Location

    char userMemory[100][BUFFER_MAX] = { 0, };  // To do list 
    char buffer[BUFFER_MAX] = { 0, };           // User input 

    int deleteNumber;
    bool contextSwitch = ADD_MEMORY; // Add memory , View memory


    
    while(true)     // command start
    {   

        if(contextSwitch == ADD_MEMORY)  // ADD_MEMORY
        {

            system("cls");

            while(true) 
            {
                fflush(stdin);  // buffer flush
                printf("Add memory>");
                scanf("%[^\n]s", buffer);   

                if(strcmpSame(buffer, "convert")) // check convert
                {
                    contextSwitch = VIEW_MEMORY;
                    break;
                }
                strcpy(userMemory[++userMemoryLocation],buffer);
                printf("\"%s\" has been added to Memory.\n\n");
            }

        }  // ADD_MEMORY

        if(contextSwitch == VIEW_MEMORY)  // VIEW_MEMORY 
        {

            system("cls");

            while(true)
            {
                fflush(stdin);  // buffer flush
                printf("View memory>");
                scanf("%[^\n]s", buffer);   

                if(strcmpSame(buffer, "view")) 
                {

                    for(int i = 0; i < userMemoryLocation; ++i)
                    {
                        printf("%02d. %s\n",i,userMemory[i]);
                    }

                }else 
                
                if(strcmpSame(buffer, "delete"))
                {
                    printf("Memory number to delete\n");
                    printf("> ");
                    scanf("%d",&deleteNumber);

                }else

                if(strcmpSame(buffer, "convert"))
                {
                    contextSwitch = ADD_MEMORY;
                    break;
                }
                
                else
                {
                    printf("ERROR : Invaild input\n\n");
                }



            }


        }  // VIEW_MEMORY

    }   // command end



}

int strcmpSame(const char *str1, const char *str2)
{
    if(strcmp(str1, str2) == 0) return 1;
    else return 0;
}
