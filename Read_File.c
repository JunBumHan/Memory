#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main()
{
    FILE* fp = fopen("test.txt", "w"); //test파일을 w(쓰기) 모드로 열기

    for (int i = 0; i < 5; i++) {
        fputs("test\n", fp); // 문자열 txt에 입력
    }
    fputs("end", fp);

    fclose(fp); //파일 포인터 닫기

    return 0;
}
