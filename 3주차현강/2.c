#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse(char* s1, char* s2)
{
	int len = strlen(s2);
	for (int i = 0; i < len; i++)
	{
		s1[i] = s2[len - i - 1];
	}
	s1[len] = '\0';
}

main()
{
	char str1[100];
	char str2[100];
	char str3[100];
	char str4[100];
	char temp[100];
	int len1, len2, len3, len4;
	
	//(1) 입력 scanf() 사용
	printf("(1) 입력 str1: ");
	scanf("%s", str1);
	printf("    입력 str2: ");
	scanf("%s", str2);
	
	//(2) 교환 후 출력
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	len1 = strlen(str1);
	len2 = strlen(str2);
	printf("(2) 교환 str1=%s str2=%s\n", str1, str2);
	printf("len1=%d len2=%d\n", len1, len2);
	
	//(3) 복사 후 출력
	strcpy(str3, str2);
	printf("(3) 복사 str3=%s\n", str3);
	
	//(4) 이어 붙이기 후 출력
	strcat(str3, " ");
	strcat(str3, str1);
	strcat(str3, " ");
	strcat(str3, "Computer Engineering");
	len3 = strlen(str3);
	printf("(4) 이어 붙이기 str3=%s\n", str3);
	printf("len3=%d\n", len3);

	//(5) 뒤집기 reverse(str4,str3) 후 str4 출력
	reverse(str4, str3);
	len4 = strlen(str4);
	printf("(5) 뒤집기 str4=%s\n",str4);
	printf("len4=%d\n", len4);
}