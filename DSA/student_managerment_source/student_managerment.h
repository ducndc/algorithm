/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * student_managerment.h
 *
 */

#ifndef STUDENT_MANAGERMENT_H
#define STUDENT_MANAGERMENT_H

#define MAX_STUDENT_NUM	100

struct student {
	char name[20];
	int year;
	float score;
};

struct student students[MAX_STUDENT_NUM];
unsigned short num_students = 0;	
unsigned short index_students = 0;	

void print_instruction();
void enter_information();
void edit_information();
void delete_information();
void show_all_information();

void show_all_information()
{
	if (num_students <= 0)
	{
		printf("No student\n");
		printf("\n");
	}
	else
	{
		printf("Show all students\n");
		for (int i = 0; i < num_students; i++)
		{
			printf("Student %d\n", i+1);
			printf("Name		:	%s\n", students[i].name);
			printf("Year of birth	:	%d\n", students[i].year);
			printf("Average score	:	%.2f\n", students[i].score);
			printf("\n");
		}
		printf("\n");
	}
}

void edit_information()
{
	if (num_students <= 0)
	{
		printf("No student\n");
		printf("\n");
	}
	else
	{
		printf("Edit information of student\n");
		printf("Choice student\n");
		scanf("%hd", &index_students);
		index_students -= 1;
		printf("Edit name		: ");
		scanf("%s", students[index_students].name);
		printf("Edit year of birth	: ");
		scanf("%d", &students[index_students].year);
		printf("Edit average score	: ");
		scanf("%f", &students[index_students].score);
		printf("\n");
	}
}

void delete_information()
{
	if (num_students <= 0)
	{
		printf("No student\n");
		printf("\n");
	}
	else
	{
		printf("Delete student\n");
		printf("Choice student ");
		scanf("%hd", &index_students);
		index_students -= 1;
		for (int i = index_students; i < num_students; i++)
		{
			students[i] = students[i+1];
		}
		num_students -= 1;
		printf("\n");
	}
}

void enter_information()
{
	if (num_students == MAX_STUDENT_NUM)
	{
		printf("Full student\n");
		printf("\n");
	}
	else
	{
		printf("Enter information of student %d\n", num_students+1);
		printf("Name		:	");
		scanf("%s", students[num_students].name);
		printf("Year of birth	:	");
		scanf("%d", &students[num_students].year);
		printf("Average score	:	");
		scanf("%f", &students[num_students].score);
		num_students += 1;
		printf("\n");
	}
}

void print_instruction()
{
	printf("[1] Enter information of student\n");
	printf("[2] Delete information of student\n");
	printf("[3] Edit information of student\n");
	printf("[4] Show all information os student\n");
	printf("[5] End\n");
	printf("\n");
}
#endif
