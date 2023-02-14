/**
 *	author: Chung Duc Nguyen Dang
 *	email: nguyendangchungduc1999@gmail.com
 *
 *	main.c
 */

#include <stdio.h>
#include "mobile_phone_managerment.h"

int main()
{
	int option;
	int kind_of_display = 0;
	mobile_phone_t *mobile_phone_list = NULL;

	print_instruction();
	scanf("%d", &option);

	while (option != 6)
	{
		switch (option)
		{
			case 1:
				add_mobile_phone_in_list(&mobile_phone_list);
				break;
			case 2:
				remove_mobile_phone_in_list_by_code(&mobile_phone_list);
				break;
			case 3:
				edit_inventory_number_of_mobile_phone_by_code(mobile_phone_list);
				break;
			case 4:
				search_mobile_phone_by_price(mobile_phone_list);
				break;
			case 5:
				printf("Select kind of display with 1 for increase and 2 for "
						"decrease:	");
				scanf("%d", &kind_of_display);
				if (kind_of_display == 2)
				{
					print_mobile_phone_list(mobile_phone_list);
				}
				else
				{
					reverse_mobile_phone_list(&mobile_phone_list);
					print_mobile_phone_list(mobile_phone_list);
					reverse_mobile_phone_list(&mobile_phone_list);
				}
				break;
		}
		print_instruction();
		scanf("%d", &option);
	}

	return 0;
}
