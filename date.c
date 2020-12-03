//date.c chua cac ham de xu ly ngay thang
#include<stdio.h>
#include "date.h"
void inputSV(SV *d)
{
	printf("\nNhap ma sinh vien, ten,gioi tinh,ngay sinh,que,lop:");
	scanf("%d%s%s%d%s%s",&d->idsinhvien,&d->name,&d->gioitinh,&d->ngaysinh,&d->que,&d->lop);
}
void outputSV(SV d)
{
	printf("%d %s %s %d %s %s",d.idsinhvien,d.name,d.gioitinh,d.ngaysinh,d.que,d.lop);
}
