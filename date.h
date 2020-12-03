//date.h luu nguyen mau
typedef struct
{
	int idsinhvien;
	char name[40];
	char gioitinh[3];
	int ngaysinh;
	char lop[20];
	char que[30];

}SV;
void inputSV(SV *d);
void outputSV(SV d);
