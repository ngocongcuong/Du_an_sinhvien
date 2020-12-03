//date.h luu nguyen mau
typedef struct
{
	int idsinhvien;
	char name[40];
	char gioitinh;
	int ngaysinh;
	char que[30];
	char lop[20];
}SV;
void inputSV(SV *d);
void outputSV(SV d);
