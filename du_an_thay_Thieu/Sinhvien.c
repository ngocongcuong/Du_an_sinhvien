#include <stdio.h>
#include "Sinhvien.h"

void nhapSV(SV *d)
{
	fflush(stdin);
	printf("Nhap ma sinh vien: "); gets(d->masv);
	printf("Nhap ho ten sinh vien: "); gets(d->hoten);
	do {
		printf("Gioi tinh: "); scanf("%d",&d->gt);
		if(d->gt<0||d->gt>2)
		printf("\nGioi tinh ko hop le, moi nhap lai");
	}while (d->gt < 0 || d->gt >2);
	inputDate(&d->ns);
	fflush(stdin);
	printf("Nhap noi sinh: "); gets(d->noisinh);
	printf("Nhap lop: "); gets(d->lop);
	printf("Nhap diem mon toan: "); scanf("%f", &d->toan);
	printf("Nhap diem mon ly: "); scanf("%f", &d->ly);
	printf("Nhap diem mon hoa: "); scanf("%f", &d->hoa);
	d->tb=(d->toan + d->ly + d->hoa)/3;
}
void inSV(SV d)
{
	printf("\nMa sinh vien: %s", d.masv);
	printf("\nHo ten: %s", d.hoten);
	printf("\nGioi tinh: %s",(d.gt==0?"Nu":(d.gt==1?"Nam":(d.gt==2?"Khac":""))));
	printf("\nNgay sinh: "); outputDate(d.ns);
	printf("\nNoi sinh: %s", d.noisinh);
	printf("\nLop: %s", d.lop);
	printf("\nDiem: | Toan= %1.2f | Ly= %1.2f | Hoa= %1.2f |", d.toan, d.ly, d.hoa);
	printf("\nDiem trung binh: %1.2f",d.tb);
	if (d.tb > 9) strcpy(d.hocluc, "Xuat xac");
	else if (d.tb > 8) strcpy(d.hocluc, "Gioi");
	else if (d.tb > 7) strcpy(d.hocluc, "Kha");
	else if (d.tb > 6) strcpy(d.hocluc, "Trung binh");
	else if (d.tb < 6) strcpy(d.hocluc, "Kem");
	printf("\nHoc luc: %s\n",d.hocluc);
}
void nhapDSSV(SV *d, int *n)
{
	int i;
	printf("\nSo luong sinh vien: "); scanf("%d", n);
	for (i=0; i<*n; i++) {
		printf("\nSinh vien thu %d: \n",i+1);
		nhapSV(&d[i]);
	}	
	printf("Nhap du lieu thanh cong, Enter de quay lai menu chinh");
}
void inDSSV(SV *d, int n)
{
	int i;
	printf("\nDanh sach sinh vien la:\n");
	for (i=0; i<n; i++)
	{
		printf("\n-----Sinh vien %d-----", i+1);
		inSV(d[i]);
	}
}
int timSV(SV *d, int n)
{
	char findText[15];
	int i, result=0;
	fflush(stdin);
	printf("\nNhap ma sinh vien muon tim:"); gets(findText);
	for(i=0;i<n;i++)
		if (strcmp(d[i].masv,findText)==0)
		{
			result++;
			inSV(d[i]);
		}
		printf("\nCo %d sinh vien tim thay", result);
		return result;
}
void sapxep(SV *d, int n)
{
	int i, j;
	SV temp;
	float totali, totalj;
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			totali = d[i].toan + d[i].ly + d[i].hoa;
			totalj = d[j].toan + d[j].ly + d[j].hoa;
			if (totali < totalj) {
				//doi vi tri
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			} 
		}
	}
	inDSSV(d, n);
}
void lop(SV *d, int n)
{
	int i, j;
	SV temp;
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if (strcmp(d[i].lop, d[j].lop) > 0) {
				//doi vi tri
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			} 
		}
	}
	int count = 1;
	char chonlop[10];
	strcpy(chonlop, d[0].lop);
	printf("\nSap xep hoc sinh theo lop: \n\n-------Lop: %s -----------------------------------------\n", d[0].lop);
	for (i=0; i<n; i++) {
		if (strcmp(chonlop, d[i].lop) == 0) {
			printf("\n-----Sinh vien %d------", count);
			inSV(d[i]);
			count++;
		} else {
			printf("\n\n-------Lop: %s -----------------------------------------\n", d[i].lop);
			strcpy(chonlop, d[i].lop);
			printf("\n-----Sinh vien 1------");
			inSV(d[i]);
			count = 2;
		}
	}
}
