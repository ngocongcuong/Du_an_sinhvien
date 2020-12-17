#include "Date.h"

typedef struct
{
	char masv[15];
	char hoten[50];
	int gt; 
	Date ns;
	char hocluc[10];
	char noisinh[50];
	char lop[10];
	float toan, ly, hoa,tb;
} SV;
 void nhapSV(SV *d);
 void inSV(SV d);
 void nhapDSSV(SV *d, int *n);
 void inDSSV(SV *d, int n);
 int timSV(SV *d, int n);
 void sapxep(SV *d, int n);
 void lop(SV *d, int n);
 void rank(SV *d, int n);
