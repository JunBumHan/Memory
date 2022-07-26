#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#include <stdio.h>

void main()
{
    FILE* fp = fopen("test.txt", "r");  //test파일을 r(읽기) 모드로 열기
    char buffer[MAX] = { 0, };

    fread(buffer, 1, MAX, fp); //전체 읽기
    //  size_t fread(void* ptr, size_t size, size_t count, FILE* stream);

    printf("%s", buffer);

    fclose(fp); //파일 포인터 닫기
}
