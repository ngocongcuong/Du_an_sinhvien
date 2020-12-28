#include "Date.h"

typedef struct
{
	char masv[15];
	char ho[20];
	char dem[20];
	char ten[20];
	char noisinh[30];
	char lop[30];
	char gt[10]; 
	Date ns;
	float toan, ly, hoa, tb;
	char hocluc[30];
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
