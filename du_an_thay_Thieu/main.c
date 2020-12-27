#include <stdio.h>
#include <stdlib.h>
#include "Sinhvien.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int chon, n;
	SV ds[100];
	do{
		system("cls");
		printf("\n--------MENU---------");
		printf("\n1. Nhap thong tin sinh vien");
		printf("\n2. Hien thi thong tin hoc vien");
		printf("\n3. Tim thong tin sinh vien theo ma sinh vien");
		printf("\n4. Hien thi danh sach theo diem tu cao xuong thap");
		printf("\n5. Hien thi danh sach sinh vien theo lop");
		printf("\n6. Luu file sinhvien.txt");
		printf("\n7. Doc file sinhvien.txt");
		printf("\n0. Thoat");
		printf("\n---------------------");
		printf("\nBan hay chon 1 cong viec: "); scanf("%d", &chon);
		switch (chon)
		{
			case 1:
				system("cls");
				printf("\nNhap thong tin hoc vien");
				nhapDSSV(ds, &n);
				getch();
				break;
			case 2:
				system("cls");
				printf("\n2.Hien thi thong tin hoc vien");
				inDSSV(ds, n);
				getch();
				break;
			case 3:
				system("cls");
				printf("\n3.Tim thong tin hoc vien theo ma hoc vien");
				timSV(ds, n);
				getch();
				break;
			case 4:
				system("cls");
				printf("\n4.Hien thi danh sach sinh vien theo thu tu giam dan");
				sapxep(ds, n);
				getch();
				break;
			case 5:
				system("cls");
				printf("\n5.Hien thi sinh vien theo lop");
				lop(ds, n);
				getch();
				break;
			case 6:
				system("cls");
				ghifile(ds, n);
				break;
			case 7:
				system("cls");
				docfile(ds, &n);
				getch();
				break;
		}
	}while (chon != 0);
	return 0;
}
