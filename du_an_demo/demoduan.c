#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct thongtinsinhvien
{
   char Masv[4];
   char Hoten[100];
   char Namsinh[100];
   char Noisinh[100];
   float Diemtb ;
};

struct thongtinsinhvien s[1000];
int n= 0;

int Hienthimenu()
{
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n+------+----[               MENU LUA CHON                        ]---+-------+");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n|----- + ----->          1. Nhap sinh vien                       <-----------|");
                printf("\n|----- + ----->          2. Hien thi sinh vien                   <-----------|");
                printf("\n|----- + ----->          3. Sap xep sinh vien theo ma sinh vien  <-----------|");
                printf("\n|----- + ----->          4. Tim kiem sinh vien theo ma sinh vien <-----------|");
                printf("\n|----- + ----->          5. Sinh vien thuc hien                  <-----------|");
                printf("\n|----- + ----->          6. Thoat                                <-----------|");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n\tBan chon muc nao : ");
   int chon;
   scanf("%d",&chon);
   return chon;
}

nhapsinhvien()
{
     
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n|----- + ----->                NHAP SINH VIEN                 <--------------|");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
   int hh;

   do
   {
      printf("\nSinh vien thu [%d]\n",n+1);
      printf("\tMa SV    : ");
      fflush(stdin);
      gets(s[n].Masv);
      if (strlen(s[n].Masv)==0)
      {
          break;
      }
      printf("\tHo va ten: ");
      fflush(stdin);
      gets(s[n].Hoten);
      printf("\tNam Sinh : ");
      fflush(stdin);
      gets(s[n].Namsinh);
      printf("\tNoi sinh : ");
      fflush(stdin);
      gets(s[n].Noisinh);
      printf("\tDiem TB  : ");
      scanf("%f",&s[n].Diemtb);
      n++;
      printf("\n+------+------------------------------------+----------+-------+-----+-------+");
      printf("\n\tNhan 1 de tiep tuc nhap . Nhan 2 de thoat");
      scanf("%d",&hh);
      } while (hh==1);
      printf("\n+------+------------------------------------+----------+-------+-----+-------+");
   printf("\nBam enter de tro ve menu.\n");
   getch();
}



selection()
{
              int i,j,min;
              struct thongtinsinhvien tam;
              for(i=0;i<n;i++)
              {
                              min=i;
                              for(j=i+1;j<n;j++)
                              {
                                                if ((strlen(s[j].Masv)<strlen(s[min].Masv))|| 
                                                ((strlen(s[j].Masv)==strlen(s[min].Masv)) &&(strcmp(s[j].Masv,s[min].Masv) < 0)))
                                                min=j;
                              }
                              if(min!=i)
                              {
                                        tam=s[i];
                                        s[i]=s[min];
                                        s[min]=tam;
                              }
              }
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n|----- +           MA SINH VIEN DA DUOC SAP XEP        |---------------------|");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n|----- +               DANH SACH SINH VIEN             |---------------------|");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");

                printf("\n%-10s %-15s  %-20s %-20s DiemTB\n","Ma SV","Ho Ten","Nam Sinh","Noi Sinh","Diem TB");
   
   
   for (i=0;i<n;i++)


   {
       printf("%-10s %-15s  %-20s %-20s %0.1f\n",s[i].Masv,s[i].Hoten,s[i].Namsinh,s[i].Noisinh,s[i].Diemtb);
   }
  printf("\n\tBam enter de tro ve menu.\n");
   getch();
}
    
hienthi()
{
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n|----- +               DANH SACH SINH VIEN             |---------------------|");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n%-10s %-15s  %-20s %-20s DiemTB\n","Ma SV","Ho Ten","Nam Sinh","Noi Sinh","Diem TB");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
   
   
   int i;
   for (i=0;i<n;i++)


   {
       printf("\n%-10s %-15s  %-20s %-20s %0.1f\n",s[i].Masv,s[i].Hoten,s[i].Namsinh,s[i].Noisinh,s[i].Diemtb);
       printf("\n+----------------------------------------------------------------------------+");
   }
   printf("\n\tBam enter de tro ve menu.\n");
   getch();
}
timkiem()
{
         int i, n;
         char x[4];
         printf("Nhap MSSV can tim ");
         fflush(stdin);
		 gets(x);
         for(i=0;i<n-1;i++)
         {
         if(strcmp(s[i].Masv,x)==0)
         {
         printf("\n%-10s %-15s  %-20s %-20s DiemTB\n","Ma SV","Ho Ten","Nam Sinh","Noi Sinh","Diem TB");
         printf("\n+------+------------------------------------+----------+-------+-----+-------+");{
         printf("\n%-10s %-15s  %-20s %-20s %0.1f\n",s[i].Masv,s[i].Hoten,s[i].Namsinh,s[i].Noisinh,s[i].Diemtb);
         printf("\n+----------------------------------------------------------------------------+");
         }
         printf("\n\tBam enter de tro ve menu.\n");
         getch();
}
}            
}
svth()
{
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n+------+----[               SINH VIEN THUC HIEN                  ]---+-------+");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                printf("\n|----- + ----->          DO XUAN LY        N/S: 10/10/1991       <-----------|");
                printf("\n|----- + ----->                  LOP: TH4A                       <-----------|");
                printf("\n|----- + ----->          CAO DANG BACH KHOA DA NANG              <-----------|");
                printf("\n+------+------------------------------------+----------+-------+-----+-------+");
                  printf("\n\tBam enter de tro ve menu.\n");
                  getch();
}
 main()
{
   int chon;
   do
   {
       chon = Hienthimenu();
      switch (chon)
      {
          case 1:
           nhapsinhvien();
           break;
         case 2:
           hienthi();
           break;
         case 3:
           selection();
           break;
         case 4:
           timkiem();
           break;
           case 5:
                svth();
                break;
              
              default:
                      printf("\n\t Ban vua lua chon sai, vui long chon lai tu 1->6");
                 
      }
   }while(chon!=6);

}
