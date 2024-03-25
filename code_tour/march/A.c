#include <stdio.h>

int main()
{
	unsigned short t = 0;
	unsigned short i = 0;
	unsigned short j = 0;

	scanf("%d", &t);

	unsigned char n[t];
	
	char s[t][100];

	for (i = 0; i < t; ++i)
	{
		scanf("%d", &n[i]);
		scanf("%s", s[i]);
	}
	
	for (i = 0; i < t; ++i)
	{
		unsigned short k = 0;
		for (j = 0; j < n[i]; ++j)
		{
			if (j == k || j == 0) {
				printf("%c", s[i][k]);
				continue;
			}
			if (s[i][k] == s[i][j] && k < n[i]) {
				k = j + 1;
			}
		}
		printf("\n");
	}

	return 0;
}