#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define CURRENT_YEAR 2020
struct Mark {
	float math;
	float physics;
	float chemistry;
};
struct Student {
	char name[150];
	char province[100];
	int year_of_birth;
	//1 sinh vien co 1 diem
	struct Mark* mark;
};
void input(struct Student* students, int numberOfStudents) {
	//input and validations
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* currentStudent = students + i;
		printf("\nEnter student's name: "); gets(currentStudent->name);
		while (1) {
			if(gets(currentStudent->name) != NULL) break;
		}
		printf("\nEnter student's province: "); gets(currentStudent->province);
		// validate: age must be 18->45
		do
		{
			printf("\nEnter student's yeat of birth: "); scanf_s("%d",&currentStudent->year_of_birth);
		} while (CURRENT_YEAR - currentStudent->year_of_birth <17 
			|| CURRENT_YEAR - currentStudent->year_of_birth >45);
		printf("\nEnter student's mark: \n");
		currentStudent->mark = (struct Mark*)malloc(sizeof(struct Mark)); //alloc 1 object of Mark
		do
		{
			printf("\nEnter your math: "); scanf_s("%f", &currentStudent->mark->math);	
		} while (currentStudent->mark->math >10 || currentStudent->mark->math <0);
		do
		{
			printf("\nEnter your physics: "); scanf_s("%f", &currentStudent->mark->physics);
		} while (currentStudent->mark->physics >10 || currentStudent->mark->physics < 0);
		do
		{
			printf("\nEnter your chemistry: "); scanf_s("%f", &currentStudent->mark->chemistry);
		} while (currentStudent->mark->chemistry >10 || currentStudent->mark->chemistry <0);
		//diem tu 0 den 10
	}
	printResult(students, numberOfStudents);
}
void printResult(struct Student* students, int numberOfStudents) {
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* currentStudent = students + i;
		printf("+----------------------------------------------------------------+\n");
		printf("|  Ten sinh vien   | Tinh, TP   | Nam sinh | Toan | Ly | Hoa \n");
		printf("|%17s |%11s |%7d   |%4.1f  |%2.1f | %3.1f \n",
				currentStudent->name, currentStudent->province,
				currentStudent->year_of_birth, currentStudent->mark->math, currentStudent->mark->physics,
				currentStudent->mark->chemistry
			);
		printf("+----------------------------------------------------------------+\n");
	}
}
void sort(struct Student* students, int numberOfStudents) {
	int i,j;
	for (i=0; i<numberOfStudents -1; i++) {
		for (j=i+1; j<numberOfStudents; j++) {
			struct Student* si = students +i;
			struct Student* sj = students +j;
			float totalI = si->mark->math + si->mark->physics + si->mark->chemistry;
			float totalJ = sj->mark->math + sj->mark->physics + sj->mark->chemistry;
			if (totalI<totalJ) {
				//doi vi tri
				struct Student temp = *si;
				*si = *sj;
				*sj = temp;
			}
		}
	}
	printResult(students, numberOfStudents);
}

int main() {
	char choice;
	int numberOfStudents;
	struct Student* students = NULL;
	do{
	//creat a "console menu":
	printf("+----------------------------------------------------------------+\n");
	printf("+-----------------------STUDENT MANAGEMENT-----------------------+\n");
	printf("+----------------------------------------------------------------+\n");
	printf("|1.Input |2.Sort |3.Analyze |4.Find |5.Save |6.Open |7.Exit \n");
	printf("Moi ban chon \n");
	fflush(stdin);
	//remove enter
	choice=getchar();
	while(choice=='\n') {
		choice=getchar();
	}
	switch(choice) {
		case '1':
			printf("Number od student : "); scanf_s("%d", &numberOfStudents);
			// cap phat bo nho
			students=(struct Student*)malloc(numberOfStudents*sizeof(struct Student*));
			input(students, numberOfStudents);
			break;
		case '2':
			//sap xep
			if(students !=NULL && numberOfStudents >0) {
				sort(students, numberOfStudents);
			}
			break;
		case '3':
			printf("Ban chon Analyze\n");
			break;
		case '4':
			printf("Ban chon Find\n");
			break;
		case '5':
			printf("Ban chon Save\n");
			break;
		case '6':
			printf("Ban chon Open\n");
			break;
		default:
			break;
		}	
		printf("Ban co muon tiep tuc khong ?\n");
		printf("Yes, I do (y or Y)\n");
		printf("No, I don't (n or N)\n");
		printf("Xoa man hinh (c or C)\n");
		printf("moi chon:Yes or No or Clear: ");
		fflush(stdin);
		//remove enter
		choice=getchar();
		while(choice=='\n') {
			choice=getchar();
		}
		if(choice=='c' || choice =='C') {
			system("cls"); // lenh xoa man hinh
		}
	}while(choice != 'n' && choice != 'N');

	return 0;
}
