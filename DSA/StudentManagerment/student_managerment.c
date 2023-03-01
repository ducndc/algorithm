/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * student_managerment.c
 *
 */

#include <stdio.h>
#include <string.h>

#include "student_managerment.h"

int main()
{
	int c = 0;

	while (c != 5)
	{
		print_instruction();

		printf("Select option :	");
		scanf("%d", &c);

		switch (c)
		{
			case 1:
				enter_information();
				break;
			case 2:
				delete_information();
				break;
			case 3:
				edit_information();
				break;
			case 4:
				show_all_information();
				break;
			case 5:
				printf("End\n");
				printf("\n");
				break;
		}
	}

	return 0;
}

