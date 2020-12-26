#include "Date.h"

typedef struct
{
	char masv[15];
	char hoten[50];
	char noisinh[15];
	char lop[10];
	char gt[3]; 
	Date ns;
	float toan, ly, hoa, tb;
	char hocluc[10];
} SV;
 void nhapSV(SV *d);
 void inSV(SV d);
 void nhapDSSV(SV *d, int *n);
 void inDSSV(SV *d, int n);
 int timSV(SV *d, int n);
 void sapxep(SV *d, int n);
 void lop(SV *d, int n);
 void rank(SV *d, int n);
 void ghifile(SV *d, int n);
 void docfile(SV *d, int *n);
