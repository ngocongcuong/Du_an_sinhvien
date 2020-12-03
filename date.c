//date.c chua cac ham de xu ly ngay thang
#include<stdio.h>
#include "date.h"
void inputSV(SV *d)
{
	printf("\nNhap ma sinh vien:\n");	scanf("%d",&d->idsinhvien);fflush(stdin);
	printf("\nNhap ten sinh vien:\n");	gets(&d->name);
	printf("\nNhap gioi tinh sinh vien:\n");	scanf("%s",&d->gioitinh);
	printf("\nNhap ngay sinh sinh vien:\n");	scanf("%d",&d->ngaysinh);
	printf("\nNhap lop sinh vien:\n");	scanf("%s",&d->lop);
	printf("\nNhap que sinh vien:\n");	scanf("%s",&d->que);
}
void outputSV(SV d)
{
	printf("Ma sinh vien: %d\nTen: %s\nGioi tinh: %s\nNgay sinh %d\nLop: %s\nQue quan: %s ",d.idsinhvien,d.name,d.gioitinh,d.ngaysinh,d.lop,d.que);
}
