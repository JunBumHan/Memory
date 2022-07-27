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
    bool userMemoryStack[100] = { false, }; 
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
                scanf("%[^\n]s", buffer);   //  공백 문자열 입력

                if(strcmpSame(buffer, "convert")) // check convert
                {
                    contextSwitch = VIEW_MEMORY;
                    break;
                }
                strcpy(userMemory[++userMemoryLocation],buffer);    // userMemory에 넣기 
                userMemoryStack[userMemoryLocation] = true;         // userMemoryStack true로 변경
                printf("\"%s\" has been added to Memory.\n\n");     // 사용자에게 잘됨을 전달하기
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

                if(strcmpSame(buffer, "view"))      // userMemory 내용 출력
                {

                    for(int i = 0; i <= userMemoryLocation; ++i)
                    {
                        printf("%02d. %s\n",i,userMemory[i]);
                    }
                    printf("\n\n");

                }else 
                
                if(strcmpSame(buffer, "delete"))    // userMemory 내용 삭제
                {
                    while(true)
                    {
                        printf("\n\nMemory number to delete\n");
                        printf("View memory/delete>");
                        scanf(" %d",&deleteNumber);

                        if(userMemoryStack[deleteNumber] == true)   // 만약 삭제할 번호가 존재한다면
                        {
                            if(deleteNumber == userMemoryLocation)  // 만약 삭제할 번호가 목록에 마지막이라면
                            {
                                userMemoryStack[deleteNumber] = false;  // userMemoryStack에 마지막 false 처리
                                userMemoryLocation--;                   // userMemoryLocation 감소
                                userMemory[deleteNumber][0] = '\0';     // 사용하지 않은 목록은 NULL 처리 해주기

                                printf("deleted!!\n");                  // 사용자에게 잘됨을 알려주기
                            }
                            
                            else    // 삭제할 번호가 존재하지만 마지막이 아니라면 
                            {
                                for(int i = deleteNumber; i <= userMemoryLocation; ++i) 
                                {
                                    strcpy(userMemory[i], userMemory[i+1]);         // stack 구조처럼 내가 삭제할 목록 덮어쓰기
                                    userMemoryStack[userMemoryLocation] = false;    // stack 마지막 false 처러 
                                    userMemoryLocation--;                           // userMemoryLocation 감소

                                    printf("deleted!!\n");                          // 사용자에게 잘됨을 알려주기
                                }
                            }

                        }else

                        if(deleteNumber == -1)  // -1 이면 나가기
                        {
                            printf("\n\n");
                            break;
                        }

                        else  // 위에 다 충족하지 않는다면 잘못된 입력을 사용자에게 알려줌
                        {
                            printf("ERROR : Invaild input\n");
                        }
                        
                    }

                }else

                if(strcmpSame(buffer, "convert"))   // check convert
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
