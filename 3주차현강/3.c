#include <stdio.h>

void encrypt(char cipher[], int shift)
{
	int i = 0;
	while (cipher[i] != '\0')
	{
		if (cipher[i] >= 'a' && cipher[i] <= 'z')
		{
			cipher[i] += shift;
			if (cipher[i] > 'z')
				cipher[i] -= 26;
		}
		i++;
	}
	//decrypt
	printf("암호화된 문자열 : %s\n", cipher);
}

void decrypt(char cipher[], int shift)
{
	int i = 0;
	while(cipher[i] != '\0')
	{
		if (cipher[i] >= 'a' && cipher[i] <= 'z')
		{
			cipher[i] -= shift;
			if (cipher[i] < 'a')
				cipher += 26;
		}
		i++;
	}
	printf("복호화된 문자열 : %s\n", cipher);
}

main()
{
	char cipher[50];
	int shift = 3;
	printf("문자열을 입력하시오: ");
	gets(cipher);
	encrypt(cipher, shift);
	decrypt(cipher, shift);
	return 0;
}