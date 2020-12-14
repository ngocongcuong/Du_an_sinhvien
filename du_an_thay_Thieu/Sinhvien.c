#include <stdio.h>
#include "Sinhvien.h"

void nhapSV(SV *d)
{
	fflush(stdin);
	printf("\nNhap ma sinh vien: "); gets(d->masv);
	printf("\nNhap ho ten sinh vien: "); gets(d->hoten);
	do {
		printf("\nGioi tinh: "); scanf("%d",&d->gt);
		if(d->gt<0||d->gt>2)
		printf("\nGioi tinh ko hop le, moi nhap lai");
	}while (d->gt < 0 || d->gt >2);
	inputDate(&d->ns);
	fflush(stdin);
	printf("\nNhap noi sinh: "); gets(d->noisinh);
	printf("\nNhap lop: "); gets(d->lop);
	printf("\nNhap diem mon toan: "); scanf("%f", &d->toan);
	printf("\nNhap diem mon ly: "); scanf("%f", &d->ly);
	printf("\nNhap diem mon hoa: "); scanf("%f", &d->hoa);
}
void inSV(SV d)
{
	printf("\nMa sinh vien: %s", d.masv);
	printf("\nHo ten: %s", d.hoten);
	printf("\nGioi tinh: %s",(d.gt==0?"Nu":(d.gt==1?"Nam":(d.gt==2?"Khac":""))));
	printf("\nNgay sinh: "); outputDate(d.ns);
	printf("\nNoi sinh: %s", d.noisinh);
	printf("\nLop: %s", d.lop);
	printf("\nDiem: | Toan= %1.2f | Ly= %1.2f | Hoa= %1.2f |\n", d.toan, d.ly, d.hoa);
}
void nhapDSSV(SV *d, int *n)
{
	int i;
	printf("\nSo luong sinh vien: "); scanf("%d", n);
	for (i=0; i<*n; i++) {
		printf("\nSinh vien thu %d: \n",i+1);
		nhapSV(&d[i]);
	}	
	printf("\nNhap du lieu thanh cong, Enter de quay lai menu chinh");
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





