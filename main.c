#include <stdio.h>
#include <stdlib.h>
struct Mark {
	float math;
	float physics;
	float chemistry;
};
struct Student {
	char name[100];
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
		printf("\nEnter student's name: "); fflush(stdin); gets(currentStudent->name);
		printf("\nEnter student's province: "); gets(currentStudent->province);
		printf("\nEnter student's yeat of birth: "); scanf_s("%d",&currentStudent->year_of_birth);
		printf("\nEnter student's mark: \n");
		currentStudent->mark = (struct Mark*)malloc(sizeof(struct Mark*)); //alloc 1 object of Mark
		printf("\nEnter your math: "); scanf_s("%f", &currentStudent->mark->math);
		printf("\nEnter your physics: "); scanf_s("%f", &currentStudent->mark->physics);
		printf("\nEnter your chemistry: "); scanf_s("%f", &currentStudent->mark->chemistry);
	}
	printResult(students, numberOfStudents);
}
void printResult(struct Student* students, int numberOfStudents) {
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* currentStudent = students + i;
		printf("+----------------------------------------------------------------+\n");
		printf("|%30c |%30c |%10d |%5.2f |%5.2f |%5.2f \n",
				currentStudent->name, currentStudent->province,
				currentStudent->year_of_birth, currentStudent->mark->math, currentStudent->mark->physics,
				currentStudent->mark->chemistry
			);
		printf("+----------------------------------------------------------------+\n");
	}
}

int main() {
	char choice;
	int numberOfStudents;
	struct Student* students;
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
			printf("Ban chon Sort\n");
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
