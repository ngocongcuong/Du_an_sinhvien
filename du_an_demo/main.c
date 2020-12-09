#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define CURRENT_YEAR 2020
struct Student {
	char name[150];
	char noisinh[100];
	int year_of_birth;
	//1 sinh vien co 1 diem
	struct Mark* mark;
};
struct Mark {
	float math;
	float physics;
	float chemistry;
};
void printResult(struct Student* students, int numberOfStudents) {
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* currentStudent = students + i;
		printf("+----------------------------------------------------------------+\n");
		printf("|  Ten sinh vien   | que quan   | Nam sinh | Toan | Ly | Hoa \n");
		printf("|%17s |%11s |%7d   |%4.1f  |%2.1f | %3.1f \n",
				currentStudent->name, currentStudent->noisinh,
				currentStudent->year_of_birth, currentStudent->mark->math, currentStudent->mark->physics,
				currentStudent->mark->chemistry
			);
		printf("+----------------------------------------------------------------+\n");
	}
}
void input(struct Student* students, int numberOfStudents) {
	//input and validations
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* currentStudent = students + i;
		printf("\nTen sinh vien: "); gets(currentStudent->name);
		while (1) {
			if(gets(currentStudent->name) != NULL) break;
		}
		printf("\nNoi sinh: "); gets(currentStudent->noisinh);
		// validate: age must be 18->45
		do
		{
			printf("\nNgay sinh: "); scanf_s("%d",&currentStudent->year_of_birth);
		} while (CURRENT_YEAR - currentStudent->year_of_birth <17 
			|| CURRENT_YEAR - currentStudent->year_of_birth >45);
		
		currentStudent->mark = (struct Mark*)malloc(sizeof(struct Mark)); //alloc 1 object of Mark
		do
		{
			printf("\nDiem toan= "); scanf_s("%f", &currentStudent->mark->math);	
		} while (currentStudent->mark->math >10 || currentStudent->mark->math <0);
		do
		{
			printf("\nDiem ly= "); scanf_s("%f", &currentStudent->mark->physics);
		} while (currentStudent->mark->physics >10 || currentStudent->mark->physics < 0);
		do
		{
			printf("\nDiem hoa= "); scanf_s("%f", &currentStudent->mark->chemistry);
		} while (currentStudent->mark->chemistry >10 || currentStudent->mark->chemistry <0);
		//diem tu 0 den 10
	}
	printResult(students, numberOfStudents);
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
void analyze(struct Student* students, const int numberOfStudents) {
	// so sinh vien cung dia chi
	//tao mang cac dia chi
	int i,j;
	char* provinces[100]; // mang cac chuoi
	for (i=0; i<numberOfStudents; i++) {
		provinces[i]= malloc(sizeof(char) * 100);
		strcpy_s(provinces[i], 100, (students+i)->noisinh);
	}
	//sap xep que quan
	for(i=0;i<numberOfStudents-1;i++) {
		for(j=i+1;j<numberOfStudents;j++) {
			//sx noi bot
			if (strcmp(provinces[i], provinces[j]) >0){
				//doi vi tri
				char temp[100];
				strcpy_s(temp, 100, provinces[i]);
				strcpy_s(provinces[i], 100, provinces[j]);
				strcpy_s(provinces[j], 100, temp);
			}
		}
	}
	//phan tich sinh vien theo noi sinh
	int count = 0;
	char selectedProvince[100];
	for (i=0; i< numberOfStudents; i++) {
		if(i==0) {
			strcpy_s(selectedProvince,100, provinces[i]);
			count = 1;
		} else if (strcmp(selectedProvince, provinces[i]) != 0) {
			printf("\n co %d sinh vien o %s", count, selectedProvince);
			//update "selectedProvince"
			strcpy_s(selectedProvince, 100, provinces[i]);
			count =1;
		} else if (strcmp(selectedProvince, provinces[i]) ==0) {
			count++;
		}
	}
	if (numberOfStudents > 0) {
		printf("\nco %d sinh vien o %s\n", count, selectedProvince);
	}
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
	printf("|1.Input |2.Sap xep |3.Analyze |4.Find |5.Save |6.Open |7.Exit \n");
	printf("Moi ban chon \n");
	fflush(stdin);
	//remove enter
	choice=getchar();
	while(choice=='\n') {
		choice=getchar();
	}
	switch(choice) {
		case '1':
			printf("Nhap so luong sinh vien : "); scanf_s("%d", &numberOfStudents);
			// cap phat bo nho
			students = (struct Student*)malloc(sizeof(struct Student) * numberOfStudents);
			input(students, numberOfStudents);
			break;
		case '2':
			//sap xep
			if(students !=NULL && numberOfStudents >0) {
				sort(students, numberOfStudents);
			}
			break;
		case '3':
			// co bao nhieu sinh vien o Ha noi, Hai duong?
			//tinh toan bao sinh vien cung tinh
			if (students != NULL && numberOfStudents > 0) {
				analyze(students, numberOfStudents);
			}
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
