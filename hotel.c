#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

// OTEL REZERVASYON ve Y�NET�M S�STEM� //

int ortpuan;
void add();  
void list();
void edit(); 
void delete1();
void search();

void puanekle(){
FILE *puan;
int toppuan=0, a=0, mpuan;

char puan1[10],  s;
			puan=fopen("puan.txt", "a+");
			printf("\n\nL�tfen hizmet kalitemizi 1-5 aras� puanlay�n.");
			mpuan=getche();
			mpuan=toupper(mpuan);
		switch(mpuan)  {
			case '1':
				fprintf(puan, "%s ", "1");//puana 1 yazd�r
				printf("\nG�r��leriniz bizim i�in �ok �nemli, te�ekk�r ederiz!\n\n");
				sleep(2);
				break;
            case '2':
				fprintf(puan, "%s ", "2");
				printf("\nG�r��leriniz bizim i�in �ok �nemli, te�ekk�r ederiz!\n\n");
				sleep(2);
				break;
            case '3':
				fprintf(puan, "%s ", "3");
				printf("\nG�r��leriniz bizim i�in �ok �nemli, te�ekk�r ederiz!\n\n");
				sleep(2);
				break;
			case '4':
				fprintf(puan, "%s ", "4");
				printf("\nG�r��leriniz bizim i�in �ok �nemli, te�ekk�r ederiz!\n\n");
				sleep(2);
				break;
			case '5':
				fprintf(puan, "%s ", "5");
				printf("\nG�r��leriniz bizim i�in �ok �nemli, te�ekk�r ederiz!\n\n");
				sleep(2);
				break;
			default:
				printf("\nYanl�� bir tu�a bast�n�z.\n");
				sleep(1);
				break;}
			fclose(puan);



}

void puanhesapla(){
	FILE *puan;
	int toppuan=0, a=0, mpuan;
	char puan1[10],  s;
	puan=fopen("puan.txt", "r");
		while(fread(&s,sizeof(s),1,puan)==1 ){
		a++;
		fscanf(puan, "%s", &puan1);
		int puan2 = atoi(puan1);
		toppuan=puan2+toppuan;
		ortpuan=toppuan/a;
		
		}
		fclose(puan);

}

void sikayetyonetim(){
	int i=0;
	char konu[15], s;
	char telefon[15];
	FILE *talep;
	printf("\n\t1-Para iadesi i�in\n");
	printf("\t2-�ikayetler i�in\n");
	printf("\t3-Otelimiz hakk�nda bilgi almak i�in\n");
	printf("\t-----------------------------------------\n");
	printf("\t|||||||||||||||||||||||||||||||||||||||||\n");
	printf("\t-----------------------------------------\n\n");
	printf("\t Telefon\t | �ikayet konusu\n");
	printf("\t----------------------------------\n");
	talep=fopen("talep.txt","r");
	while(fread(&s,sizeof(s),1,talep)==1 ){ //belge bitene kadar tara
	fscanf(talep, "%s", konu);
	printf("\t%s\t", konu);  //ekrana yaz
	fscanf(talep, "%s", telefon);
	printf("\t%s\t\n", telefon);//ekrana yaz
	}

	fclose(talep);

	printf("\n\t ��kmak i�in bir tu�a bas�n.\n");
	getch();
}



void sikayet(){
	char secim, telefon[11];
    FILE *talep;

		printf("Telefon numaran�z� girin.\n");
		scanf("%s", &telefon);
	printf("\n1-Para iadesi i�in\n");
	printf("2-�ikayetler i�in\n");
	printf("3-Otelimiz hakk�nda bilgi almak i�in\n");
		secim=getche();
		secim=toupper(secim);
		switch(secim)  {
			case '1':

				talep=fopen("talep.txt","a+");//talep.txtyi a�
				fprintf(talep, "%s ", "1");   //dosyaya 1 yazd�r
                fprintf(talep, "%s ", telefon);//numaray� dosyaya yazd�r
				fclose(talep);
				printf("\nTalebiniz al�nm��t�r, en k�sa s�rede %s numaras� �zerinden d�n�� yap�lacakt�r.\n\n", telefon);
				sleep(4);
				break;
            case '2':
				talep=fopen("talep.txt","a+");
				fprintf(talep, "%s ", "2");
				fprintf(talep, "%s ", telefon);
				fclose(talep);
				printf("\nTalebiniz al�nm��t�r, en k�sa s�rede %s numaras� �zerinden d�n�� yap�lacakt�r.\n\n", telefon);
				sleep(4);
				break;
            case '3':

				talep=fopen("talep.txt","a+");
				fprintf(talep, "%s ", "3");
				fprintf(talep, "%s ", telefon);
				fclose(talep);
				printf("\nTalebiniz al�nm��t�r, en k�sa s�rede %s numaras� �zerinden d�n�� yap�lacakt�r.\n\n", telefon);
				sleep(4);
				break;
			default:
				printf("\nHerhangi bir de�i�iklik yap�lmad�, ana men�ye d�nmek i�in bir tu�a bas�n.\n");
				getche();
				main();
				break;

}}

void indirimkodu(){
	char onay, kodindirim[10], kodd[10], secim;
	FILE *kod;
	system("cls");
	printf("Bu b�l�mde kampanya kodu olu�turabilir veya d�zenleyebilirsiniz. \n Devam etmek i�in space, geri d�nmek i�in ba�ka bir tu�a bas�n.");
	secim=getch();
	if(secim==' '){

	system("cls");
	printf("Y�zde kac indirim yapmak istersiniz?\n");
	scanf("%s", &kodindirim);
	printf("Sadece say�lardan olu�acak �ekilde 6 haneli kampanya kodu belirleyin.\n");
	scanf("%s", &kodd);
	printf("E�er varsa, var olan indirim kodu de�i�tirilecektir.\n");
	printf("Yoksa, yeni indirim kodu olu�turulacakt�r.\n");
	printf("Onayl�yor musunuz?\n");
	printf("Onaylamak i�in O, reddetmek i�in herhangi bir tu�a bas�n.");
		onay=getche();
		onay=toupper(onay);
		switch(onay)  {
			case 'O':
				kod=fopen("indirimkodu.txt","w+"); //dosyay� s�f�rla ve a�
   	 			fprintf(kod, "%s ", kodindirim); //bilgileri dosyaya yaz
				fprintf(kod, "%s", kodd);        //bilgileri dosyaya yaz
				printf("\n��lem ba�ar�l�.\n");
				getche();
				break;

			default:
				printf("\nHerhangi bir de�i�iklik yap�lmad�, ana men�ye d�nmek i�in bir tu�a bas�n.\n");
				getche();
				main();
				break;

}
	}}

void odemeyonetici(int ayse, int gun){
	time_t  t, d;
	char secim, secim1,secim2,secimkod, indirimkod1[10], indirimkod[10], kodindirim[10], kartbilgi[16], kartisim[50], dene, code[10];
	int ekindirim, tut=0, cikis=1,  i=0;


	time(&t);
	float ucret;
	double zaman;
	long x;

	if(ayse<=109){
		ucret=100;
	}
	else if( ayse <=505){
		ucret=150;
	}
	else if( ayse <=509){
		ucret=250;
	}

		ucret = ucret*gun;
		if(ucret>1000){ // �cret 1000 TL �zeriyse y�zde 5 indirim yap
			printf("\nTebrikler! 1000 TL ve �zerine �zel y�zde 5 indirim kazand�n�z!\n");
			ucret=ucret*0.95;
		}
		else if(ucret>2500){ // �cret 2500 TL �zeriyse y�zde 10 indirim yap
			printf("\nTebrikler! 2500 TL ve �zerine �zel y�zde 10 indirim kazand�n�z!\n");
			ucret= ucret*0.9;
		}
		printf("�cret %.2f\n", ucret);
		if(ayse<505){ // oda 505den k���kse ek hizmet sor
			printf("Ek hizmetlerimizden faydalanmak ister misiniz?\n");
			printf("Evet i�in E, hay�r i�in ba�ka herhangi bir tu�a bas�n.\n");
						secim=getche();
						secim=toupper(secim);
							switch(secim)       
								{
								case 'E':

									while(cikis!=2){
										system("cls");
									printf("\nToplam �cret: %f\n", ucret);
									printf("\n1-��le yeme�i(+50 TL)\n");
									printf("2-Ak�am yeme�i(+50 TL)\n");
									printf("3-Sauna(+50 TL)\n");
									printf("4-Osmanl� hamam�(+50 TL)\n");
									printf("5-Ek yatak(+50 TL)\n");
									printf("6-Ba�ka ek hizmet istemiyorum\n");
										secim1=getche();
										secim1=toupper(secim1);
										switch(secim1)    
										{
											case '1':
												ucret=ucret+50;
												printf("\n��le yeme�i 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '2':
												ucret=ucret+50;
												printf("\nAk�am yeme�i 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '3':
												ucret=ucret+50;
												printf("\nSauna 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '4':
												ucret=ucret+50;
												printf("\nOsmanl� Hamam� 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '5':
												if(tut==2){
													printf("\n\nEn fazla 2 yatak ekletebilirsiniz!\n\n");
													printf("\nBir tu�a bas�n\n");;
												getche();
												}
												else if(tut<2){
													ucret=ucret+50;
													printf("\nEk yatak 50 TL kar��l���nda eklendi.\n");
													tut=tut+1;
													printf("\nBir tu�a bas�n.\n");
												getche();
												}
												break;
											case '6':
													cikis=2;
												break;
										}

													}
								}

		}
		printf("\nToplam �cret %.2f TL\n", ucret);

		printf("\n�ndirim kodunuz var m�?\n");
		printf("\nEvet i�in E, hay�r i�in ba�ka herhangi bir tu�a bas�n.\n");
			secimkod=getche();
			secimkod=toupper(secimkod);
			switch(secimkod) {
							case 'E':
								while(i != 2){

							printf("\nL�tfen kodunuzu girin.\n");
							scanf("%s", &indirimkod);
							FILE *kod;
   							kod=fopen("indirimkodu.txt","r");
   							fscanf(kod, "%s", &kodindirim);
   							for(i=0; i<10; i++){
   								code[i]=kodindirim[i];
							   }
							   int indirim= atoi(code);
   							fscanf(kod, "%s", &indirimkod1);

   							fclose(kod);
   							if(strcmp(indirimkod,indirimkod1)==0 ){
								ucret=ucret*(100-indirim)/100;
								printf("\nTebrikler! Y�zde %d 'lik indirimden yararland�n�z!\n", indirim);
								printf("Toplam �cret %.2f TL\n", ucret);
								i=2;
							}
							else{
								printf("\nGe�ersiz kod\n");
								printf("�cret %.2f TL\n", ucret);
								printf("\n�deme yapmak i�in 1, tekrar denemek i�in ba�ka herhangi bir tu�a bas�n.\n");
								dene=getche();
								dene=toupper(dene);
								switch(dene){
									case '1':
										i=2;
								}
							}}
							break;

							}

		printf("\nEk indirim yapmak ister misiniz? Evet i�in E tu�lay�n. \n");
		secim=getche();
		secim=toupper(secim);
		switch(secim)  {
			case 'E':
				printf("\nY�zde ka� inidirim olacak?\n");
				scanf("%d", &ekindirim);
				ucret=ucret*(100-ekindirim)/100; // girilen y�zde kadar indirim yap
				printf("\nB�t�n indirimler dahil �cret: %.2f TL\n", ucret);
				printf("�deme al�nd�ysa bir tu�a bas�n.\n");
				getche();
				break;
			}



		}

	void odemekullanici(int ayse, int gun){
		time_t  t, d;
	char secim, secim1,secim2,secimkod, indirimkod1[10], indirimkod[10], kodindirim[10], kartbilgi[16], kartisim[50], dene, code[10];
	int ekindirim, tut=0, cikis=1,  i=0;


	time(&t);
	float ucret;
	double zaman;
	long x;

	if(ayse<=109){
		ucret=100;
	}
	else if( ayse <=505){
		ucret=150;
	}
	else if( ayse <=509){
		ucret=250;
	}

		ucret = ucret*gun;
		if(ucret>1000){
			printf("\nTebrikler! 1000 TL ve �zerine �zel y�zde 5 indirim kazand�n�z!\n");
			ucret=ucret*0.95;
		}
		else if(ucret>2500){
			printf("\nTebrikler! 2500 TL ve �zerine �zel y�zde 10 indirim kazand�n�z!\n");
			ucret= ucret*0.9;
		}
		printf("�cret %.2f\n", ucret);
		if(ayse<505){
			printf("Ek hizmetlerimizden faydalanmak ister misiniz?\n");
			printf("Evet i�in E, hay�r i�in ba�ka herhangi bir tu�a bas�n.\n");
						secim=getche();
						secim=toupper(secim);
							switch(secim)       
								{
								case 'E':

									while(cikis!=2){
										system("cls");
									printf("\nToplam �cret: %f\n", ucret);
									printf("\n1-��le yeme�i(+50 TL)\n");
									printf("2-Ak�am yeme�i(+50 TL)\n");
									printf("3-Sauna(+50 TL)\n");
									printf("4-Osmanl� hamam�(+50 TL)\n");
									printf("5-Ek yatak(+50 TL)\n");
									printf("6-Ba�ka ek hizmet istemiyorum\n");
										secim1=getche();
										secim1=toupper(secim1);
										switch(secim1)    
										{
											case '1':
												ucret=ucret+50;
												printf("\n��le yeme�i 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '2':
												ucret=ucret+50;
												printf("\nAk�am yeme�i 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '3':
												ucret=ucret+50;
												printf("\nSauna 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '4':
												ucret=ucret+50;
												printf("\nOsmanl� Hamam� 50 TL kar��l���nda eklendi.\n");
												printf("\nBir tu�a bas�n\n");
												getche();
												break;
											case '5':
												if(tut==2){
													printf("\n\nEn fazla 2 yatak ekletebilirsiniz!\n\n");
													printf("\nBir tu�a bas�n\n");;
												getche();
												}
												else if(tut<2){
													ucret=ucret+50;
													printf("\nEk yatak 50 TL kar��l���nda eklendi.\n");
													tut=tut+1;
													printf("\nBir tu�a bas�n.\n");
												getche();
												}
												break;
											case '6':
													cikis=2;
												break;
										}

													}
								}

		}
		printf("\nToplam �cret %.2f TL\n", ucret);

		printf("\n�ndirim kodunuz var m�?\n");
		printf("\nEvet i�in E, hay�r i�in ba�ka herhangi bir tu�a bas�n.\n");
			secimkod=getche();
			secimkod=toupper(secimkod);
			switch(secimkod) {
							case 'E':
								while(i != 2){

							printf("\nL�tfen kodunuzu girin.\n");
							scanf("%s", &indirimkod);
							FILE *kod;
   							kod=fopen("indirimkodu.txt","r");// indirimkodu.txtyi a�
   							fscanf(kod, "%s", &kodindirim); // kodindirim de�i�ken�ne ata
   							for(i=0; i<10; i++){
   								code[i]=kodindirim[i];     // daha sonra int yapmak i�in code ata
							   }
							   int indirim= atoi(code);  // int yap
   							fscanf(kod, "%s", &indirimkod1);

   							fclose(kod);
   							if(strcmp(indirimkod,indirimkod1)==0 ){ // girilen kod ve belgedeki kod aynoysa
								ucret=ucret*(100-indirim)/100;
								printf("\nTebrikler! Y�zde %d 'lik indirimden yararland�n�z!\n", indirim);
								printf("Toplam �cret %.2f TL\n", ucret);
								i=2;
							}
							else{
								printf("\nGe�ersiz kod\n");
								printf("�cret %.2f TL\n", ucret);
								printf("\n�deme yapmak i�in 1, tekrar denemek i�in ba�ka herhangi bir tu�a bas�n.\n");
								dene=getche();
								dene=toupper(dene);
								switch(dene){
									case '1':
										i=2;
								}
							}}
							break;

							}
		


				printf("Kart numaran�z:\n");
				scanf("%s", kartbilgi);
				printf("\nKart sahibinin ismi:\n");
				scanf("%s", kartisim);
				printf("%s numaral� kart�n�zdan ",kartbilgi);
				printf("%.2f TL �ekilecek, onayl�yor musunuz?\n", ucret);
				printf("Onay i�in O, red icin R tu�lay�n.\n");
				secim2=getche();
				secim2=toupper(secim2);
				switch(secim2){

					case 'O':{
					printf("\n\n�demeniz al�nd�.\n");
					getch();
					break;
					}
					case 'R':{

					add();
					break;
					}


				default:
				system("cls");
				printf("Yanl�� bir tu�a bast�n�z.\n");
				printf("\nHerhangi bir tu�a bas�n.\n");
				getch();
			}
		}


void login()
{

	int a=0,i=0;
    char uname[10],c=' ';
    char kullaniciadi[10], sifre[10];
    char pword[10],code[10];
    FILE *giris;
   	giris=fopen("girisbilgileri.txt","r");
   	fscanf(giris, "%s", kullaniciadi);
   	fscanf(giris, "%s", sifre);
   	fclose(giris);


    do
{
	system("cls");

    printf("\n  **************************  G�R��  **************************  ");
    printf("\n Devam etmek i�in l�tfen kullan�c� ad�n�z� ve �ifrenizi girin.");
    printf(" \n                       Kullan�c� ad�:-");
	scanf("%s", &uname);
	printf(" \n                       �ifre:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,kullaniciadi)==0 && strcmp(pword,sifre)==0) // ayn�ysa giri� yap
	{
	printf("  \n\n\n  G�R�� BA�ARILI, L�TFEN BEKLEY�N :)");
	sleep(2);

	break;
	}
	else
	{
		printf("\n    �ZG�N�Z! G�R�� BA�ARISIZ! Tekrar deneyin :( )");
		sleep(1);
		a++;



	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nKullan�c� ad� veya �ifreyi �� kez yanl�� girdiniz!\n");
		printf("\nBir tu�a bas�n.\n");
		getch();
		main();

		}
		system("cls");
}

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}

struct musteridetay   
{
	char roomnumber[20];
	char name[20];
	char surname[20];
	char phonenumber[20];
	char period[20];
	char arrivaldate[20];
}s;


int main(){  
	setlocale(LC_ALL,"Turkish");
	int i=0, secenek, sec;
	setcolor(15);
	time_t t;
	time(&t);
	char choice, secim, secim1;

	system("cls");
 	printf("\t\t      **********************************************************\n");
	printf("\t\t      *                                                        *\n");
	printf("\t\t      *           -----------------------------                *\n");
	printf("\t\t      *               OTEL�M�ZE HO�GELD�N�Z                    *\n");
	printf("\t\t      *           -----------------------------                *\n");
	printf("\t\t      *                                                        *\n");
	printf("\t\t      *                   �leti�im i�in:                       *\n");
	printf("\t\t      *                 +90555 555 55 55                       *\n");
	printf("\t\t      *                                                        *\n");
	printf("\t\t      *                                                        *\n");
	printf("\t\t      *                                                        *\n");
	printf("\t\t      **********************************************************\n\n\n");
	puanhesapla();
	switch(ortpuan){
		case 1:
			
			setcolor(9);printf("\t\t  **    **   ");setcolor(8);printf("   **    ** ");printf("     **    **  ");printf("    **    **    ");printf("  **    **    \n");
			setcolor(9);printf("\t\t**   **   ** ");setcolor(8);printf(" **   **   **");printf("  **   **   **");printf("  **   **   ** ");printf(" **   **   ** \n");
	    	setcolor(9);printf("\t\t **      **   ");setcolor(8);printf(" **      **  ");printf("  **      **  ");printf("  **      **   ");printf(" **      **   \n");
			setcolor(9);printf("\t\t   **   **    ");setcolor(8);printf("   **   **   ");printf("    **   **   ");printf("    **   **    ");printf("   **   **    \n");
			setcolor(9);printf("\t\t     **       ");setcolor(8);printf("     **      ");printf("      **      ");printf("      **       ");printf("     **       \n");setcolor(15);

		
			break;
		case 2:
			setcolor(9);printf("\t\t  **    **   ");printf("   **    ** ");setcolor(8);printf("     **    **  ");printf("    **    **    ");printf("  **    **    \n");
			setcolor(9);printf("\t\t**   **   ** ");printf(" **   **   **");setcolor(8);printf("  **   **   **");printf("  **   **   ** ");printf(" **   **   ** \n");
	    	setcolor(9);printf("\t\t **      **   ");printf(" **      **  ");setcolor(8);printf("  **      **  ");printf("  **      **   ");printf(" **      **   \n");
			setcolor(9);printf("\t\t   **   **    ");printf("   **   **   ");setcolor(8);printf("    **   **   ");printf("    **   **    ");printf("   **   **    \n");
			setcolor(9);printf("\t\t     **       ");printf("     **      ");setcolor(8);printf("      **      ");printf("      **       ");printf("     **       \n");setcolor(15);
			break;
		case 3:
			setcolor(9);printf("\t\t  **    **   ");printf("   **    ** ");printf("     **    **  ");setcolor(8);printf("    **    **    ");printf("  **    **    \n");
			setcolor(9);printf("\t\t**   **   ** ");printf(" **   **   **");printf("  **   **   **");setcolor(8);printf("  **   **   ** ");printf(" **   **   ** \n");
	    	setcolor(9);printf("\t\t **      **   ");printf(" **      **  ");printf("  **      **  ");setcolor(8);printf("  **      **   ");printf(" **      **   \n");
			setcolor(9);printf("\t\t   **   **    ");printf("   **   **   ");printf("    **   **   ");setcolor(8);printf("    **   **    ");printf("   **   **    \n");
			setcolor(9);printf("\t\t     **       ");printf("     **      ");printf("      **      ");setcolor(8);printf("      **       ");printf("     **       \n");setcolor(15);
			break;
			break;
		case 4:

 
			setcolor(9);printf("\t\t  **    **   ");printf("   **    ** ");printf("     **    **  ");printf("    **    **    ");setcolor(8);printf("  **    **    \n");
			setcolor(9);printf("\t\t**   **   ** ");printf(" **   **   **");printf("  **   **   **");printf("  **   **   ** ");setcolor(8);printf(" **   **   ** \n");
	    	setcolor(9);printf("\t\t **      **   ");printf(" **      **  ");printf("  **      **  ");printf("  **      **   ");setcolor(8);printf(" **      **   \n");
			setcolor(9);printf("\t\t   **   **    ");printf("   **   **   ");printf("    **   **   ");printf("    **   **    ");setcolor(8);printf("   **   **    \n");
			setcolor(9);printf("\t\t     **       ");printf("     **      ");printf("      **      ");printf("      **       ");setcolor(8);printf("     **       \n");setcolor(15);
			break;
		case 5:

			setcolor(9);printf("\t\t  **    **   ");printf("   **    ** ");printf("     **    **  ");printf("    **    **    ");printf("  **    **    \n");
						printf("\t\t**   **   ** ");printf(" **   **   **");printf("  **   **   **");printf("  **   **   ** ");printf(" **   **   ** \n");
	    				printf("\t\t **      **   ");printf(" **      **  ");printf("  **      **  ");printf("  **      **   ");printf(" **      **   \n");
						printf("\t\t   **   **    ");printf("   **   **   ");printf("    **   **   ");printf("    **   **    ");printf("   **   **    \n");
						printf("\t\t     **       ");printf("     **      ");printf("      **      ");printf("      **       ");printf("     **       \n");setcolor(15);

			break;
	}
		setcolor(9);printf("\n\t\t\t\t\t  Ortalama puan�m�z: %d\n", ortpuan);setcolor(15);
		printf("\t       ");
		for(i=0;i<70;i++)
		printf("-");
	    printf("\n\n\t\t\t         G�n ve saat: %s",ctime(&t));
	    printf("\t       ");
	    for(i=0;i<70;i++)
		printf("-");
	printf("\n\n\t\t       Kullan�c� paneli i�in 1, y�netici paneli i�in 2 tu�lay�n.\n\n");
	printf("\t\t\t\t\t\t");
	scanf("%d", &secenek);
	if(secenek==2){
    system("cls");
    login();
    system("cls");
	while (1)
	{
		system("cls");
		setcolor(15);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |ANA MEN�|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");

		printf("\t\t *Yapmak istedi�iniz i�lemi se�in*:");
		printf("\n\n");
		printf("\n 1 -> Oda rezervasyonu");
		printf("\n------------------------");
		printf("\n 2 -> M��teri kay�tlar�");
		printf("\n----------------------------------");
		printf("\n 3 -> M��teri kay�t silme");
		printf("\n-----------------------------------");
		printf("\n 4 -> M��teri kay�t arama");
		printf("\n-----------------------------------");
		printf("\n 5 -> Kullan�c� ad�/�ifre d�zenleme");
		printf("\n-----------------------------------");
		printf("\n 6 -> �ndirim kodu duzenleme");
		printf("\n-----------------------");
		printf("\n 7 -> Talepler");
		printf("\n-----------------------");
		printf("\n 8 -> Bir �nceki men�");
		printf("\n-----------------");
		printf("\n 9 -> Uygulamay� kapat");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nG�n ve saat: %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice) 
		{
			case '1':
				addyonetici();
				break;
			case '2':
				list();
				break;
			case '3':
				delete1();
				break;
			case '4':
				search();
				break;
			case '5':
				edit();
				break;
			case '6':
				indirimkodu();
				break;
			case '7':
				system("cls");
				sikayetyonetim();
				break;
			case '8':
				system("cls");
				main();
				break;
			case '9':
				system("cls");
				printf("\n\n\t Yine bekleriz.");

				exit(0);
				break;
			default:
				system("cls");
				printf("Yanl�� bir tu�a bast�n�z.\n");
				printf("\nHerhangi bir tusa basin.\n");
				getch();
		}
	}}
	else if(secenek==1){
			setcolor(15);

		while(1){
				system("cls");
			printf("   ******************************  |ANA MEN�|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t *Yapmak istedi�iniz i�lemi se�in*:");
		printf("\n\n");
		printf("\n 1 -> Oda rezervasyonu");
		printf("\n------------------------");
		printf("\n 2 -> Odalar�m�z ve hizmetlerimiz");
		printf("\n--------------------------------");
		printf("\n 3 -> �ikayet ve yard�m talebi");
		printf("\n--------------------------------");
		printf("\n 4 -> Bir �nceki men�");
		printf("\n-----------------");
		printf("\n 5 -> Uygulamay� kapat");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nG�n ve saat: %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)  {


			case '1':
				add();
				break;
			case '2':
				system("cls");
				printf("\n\tOtelimizde Uygun, Standart ve L�ks olmak �zere 3 �e�it odam�z mevcutur.\n");
				printf("\t----------------------------------------------------------------------\n\n");
				printf("\tUygun oda: Sadece kahvalt�, tek ki�ilik yatak ve mini buzdolab� i�erir.\n\n");
				printf("\tStandart oda: Sadece kahvalt�, �ift ki�ilik yatak, televizyon ve mini buzdolab� i�erir.\n\n");
				printf("\tL�ks oda: �� ���n yemek, �ift ki�ilik yatak, televizyon, mini buzdolab� \n\tve bunlara ek olarak otelimizde mecvut olan t�m hizmetleri i�erir.\n");
				printf("\n\tGeri d�nmek i�in bir tu�a bas�n.\n");
					secim=getch();
					if(secim==27){
					break;}
				break;
			case '3':
				system("cls");
						printf("\n1. Ad�m: Telefon numaran�z� yaz�n.\n");
						printf("\n2. Ad�m: Talep konunuzu se�in.\n");
						printf("\n3. Sizinle en k�sa zamanda ileti�im kural�m.\n");
				    	printf("\nGeri d�nmek i�in esc, �ikayet ve yard�m talebi olu�turmak i�in ba�ka bir tu�a bas�n.\n\n");
						secim=getch();
						if(secim==27){
						break;
						}
						sikayet();
						break;
			case '4':
				system("cls");
				main();
				break;

			case '5':
				system("cls");
				printf("\n\n\t Bizi puanlamak ister misiniz?");
				printf("\n\n\t Puanlamak i�in space, program� kapatmak i�in ba�ka bir tu�a bas�n.");
				secim1=getch();
				if (secim1==' '){
					puanekle();
				}
				printf("\n\n\t Yine bekleriz.");
				exit(0);
				break;
			default:
				system("cls");
				printf("Yanl�� bir tu�a bast�n�z.\n");
				printf("\nHerhangi bir tu�a bas�n.\n");
				getch();
			}


		}
	}

}



void add()
{
	FILE *f;
	char test, sirala[135],y[15], str[20], secim;

	int k=1,number, rb;
	long int size=sizeof(s);
	char roomnumber[10],odanumara[10], tarih[10];
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("��lemlerimizi sa�l�yoruz, l�tfen bekleyin!");
		printf("\n��leminiz tamamlanm��t�r, devam etmek i�in herhangi bir tu�a bas�n.");
		fclose(f);
		getch();

	}
	fclose(f);
	while(1){
		system("cls");
		f=fopen("add.txt","a+");

		printf("\n\nT�m odalar:\n");
		printf("\n\n101	102	103	104	105	106	107	108	109\n");
		printf("201	202	203	204	205	206	207	208	209\n");
		printf("301	302	303	304	305	306	307	308	309\n");
		printf("401	402	403	404	405	406	407	408	409\n");
		printf("501	502	503	504	505	506	507	508	509\n");
		printf("\n\n101-109 aras� Uygun, 201-504 aras� Standart, 505-509 aras� L�ks\n");
		printf("\n\nUygun odalar gecelik 100 TL (Sadece kahvalt�)\n");
		printf("Standart odalar gecelik 150 TL(Sadece kahvalt�)\n");
		printf("L�ks odalar gecelik 300 TL(Her �ey dahil)	\n");



		printf("\n\nDolu odalar:\n");
			while(fread(&s,sizeof(s),1,f)==1)
	{
				rb++;

		printf("%s \t",s.roomnumber);
					if(rb%9==0)
					printf("\n");
	}
		printf("\nGeri d�nmek i�in esc, oda se�mek i�in space tu�una bas�n.\n");
		secim=getch();
		if(secim==27){
		break;}
		else if(secim==' '){


		printf("\nOda numaras� girin:\n");
		scanf("\n%s",roomnumber);
		for(number=0; number<10; number++){

		odanumara[number]=roomnumber[number];}

		int ayse = atoi(odanumara);
		if(ayse%10==0 || ayse/100 > 5 || ayse%100-ayse%10!=0){ //101-109, 201-209...
			printf("Bu numaraya sahip bir oda mecvut de�il.\n");// nolu de�ilse hata ver
			getch();
			break;

		}




	while(fread(&s,sizeof(s),1,f)!=1)
	{

		if(strcmp(s.roomnumber, roomnumber)==0) // k�yasla numaralar ayn�ysa i�eri gir
		{
			k=0;
			printf("\n\nMaalesef bu oda dolu, bo� bir oda se�in!\n");
			fclose(f);
			sleep(1);

		}
		break;
			}

	if(k==1){
			for(number=0; number<10; number++){ //s.roomnumbera roomnumber� ata

			s.roomnumber[number]=roomnumber[number];
			}

			printf("\n\nOda m�sait. Sayfaya y�nlendiriliyorsunuz. L�tfen bekleyin.\n");

			sleep(4);

			system("cls");

			printf("\n�sim girin:\n");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nSoyad girin:\n");
			scanf("%s",&s.surname);
			printf("\nTelefon numaras� girin:\n");
			scanf("%s",&s.phonenumber);
			printf("\nKa� g�n kalacaks�n�z?:\n");
			scanf("%s",&s.period);
			printf("\nOtele ne zaman giroi� yapacaks�n�z?:\n");
			scanf("%s",&s.arrivaldate);


			for(number=0; number<10; number++){

			tarih[number]=s.period[number];
			}
			int gun = atoi(tarih);




			printf("\n\n�deme sayfas�na y�nlendiriliyorsunuz. L�tfen bekleyin.\n");

			sleep(4);

			system("cls");
			odemekullanici( ayse, gun);



			fseek(f,size,SEEK_CUR); 
			fwrite(&s,sizeof(s),1,f);
			fclose(f);
				system("cls");
				printf("\n\tKayd�n�z ba�ar�yla al�nm��t�r. L�tfen bekleyin.\n");
				sleep(1);
			break;

	}

	}
	else{
		printf("\nYanl�� bir tu�a bast�n�z.\n");
		sleep(1);
	}
	k=1;
	fclose(f);
}

}

void addyonetici()
{
	FILE *f;
	char test, sirala[135],y[15], str[20], secim;
	int k=1,number, rb;
	long int size=sizeof(s);
	char roomnumber[10],odanumara[10], tarih[10];
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("��lemlerimizi sa�l�yoruz, l�tfen bekleyin!");
		printf("\n��leminiz tamamlanm��t�r, devam etmek i�in herhangi bir tu�a bas�n. ");
		fclose(f);
		getch();
	}
	fclose(f);
	while(1){ //sonsuz d�ng� ba�lang�c�
		system("cls");
		f=fopen("add.txt","a+");
		printf("\n\nT�m odalar:\n");
		printf("\n\n101	102	103	104	105	106	107	108	109\n");
		printf("201	202	203	204	205	206	207	208	209\n");
		printf("301	302	303	304	305	306	307	308	309\n");
		printf("401	402	403	404	405	406	407	408	409\n");
		printf("501	502	503	504	505	506	507	508	509\n");
		printf("\n\n101-109 aras� Uygun, 201-504 aras� Standart, 505-509 aras� L�ks\n");
		printf("\n\nUygun odalar gecelik 100 TL (Sadece kahvalt�)\n");
		printf("Standart odalar gecelik 150 TL(Sadece kahvalt�)\n");
		printf("L�ks odalar gecelik 300 TL(Her �ey dahil)	\n");

		printf("\n\nDolu odalar:\n");
			while(fread(&s,sizeof(s),1,f)==1)
	{
				rb++;
		printf("%s \t",s.roomnumber);
					if(rb%9==0)
					printf("\n");
	}
		printf("\nGeri d�nmek i�in esc, oda se�mek i�in space tu�una bas�n.\n");
		secim=getch();
		if(secim==27){
		break;
		}
		else if(secim==' '){

		printf("\nOda numaras� girin:\n");
		scanf("\n%s",roomnumber);
		for(number=0; number<10; number++){

		odanumara[number]=roomnumber[number];}

		int ayse = atoi(odanumara);
		if(ayse%10==0 || ayse/100 > 5 || ayse%100-ayse%10!=0){
			printf("Bu numaraya sahip bir oda mecvut de�il.\n");
			getch();
			break;
		}


	while(fread(&s,sizeof(s),1,f)!=1)
	{

		if(strcmp(s.roomnumber, roomnumber)==0)
		{
			k=0;
			printf("\n\nMaalesef bu oda dolu, bo� bir oda se�in!\n");
			fclose(f);
			sleep(1);

		}
		break;
			}

	if(k==1){
			for(number=0; number<10; number++){

			s.roomnumber[number]=roomnumber[number];
			}

			printf("\n\nOda m�sait. Sayfaya y�nlendiriliyorsunuz. L�tfen bekleyin.\n");

			sleep(3);

			system("cls");

			printf("\n�sim girin:\n");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nSoyad girin:\n");
			scanf("%s",&s.surname);
			printf("\nTelefon numaras� girin:\n");
			scanf("%s",&s.phonenumber);
			printf("\nKa� g�n kalacaks�n�z?:\n");
			scanf("%s",&s.period);
			printf("\nOtele ne zaman giri� yapacaks�n�z?:\n");
			scanf("%s",&s.arrivaldate);


			for(number=0; number<10; number++){

			tarih[number]=s.period[number];
			}
			int gun = atoi(tarih);


			printf("\n\n�deme sayfas�na y�nlendiriliyorsunuz. L�tfen bekleyin.\n");

			sleep(3);

			system("cls");
			odemeyonetici( ayse, gun);

			fseek(f,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			fclose(f);
				system("cls");
				printf("\n\tKayd�n�z ba�ar�yla al�nm��t�r. L�tfen bekleyin.\n");
				sleep(1);
			break;

	}
	k=1;
}
	else{
		printf("\nYanl�� bir tu�a bast�n�z.\n");
		sleep(1);
	}

}//sonsuz d�ng� biti�i
}

void list()
{
	FILE *f;
	int i;
	char odnum[20], y[15];
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf(" ODA\t|");
	printf("�S�M   \t\t|");
	printf("SOY �S�M   \t\t|");
	printf("TELEFON\t\t|");
	printf("S�RE\t\t|");
	printf("G�R�� TAR�H�\n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1) // belge bitene kadar d�nd�r
	{
		for(i=0; i<20; i++)
			y[i]=(' ');
		int ism = strlen(s.name); 
		strncat(s.name, y, 16-ism);	// ayn� hizada oLmas� i�in sonuna 16 karakter olacak �ekilde bo�luk ekle
		int adr = strlen(s.surname);
		strncat(s.surname, y, 16-adr);
		int id = strlen(s.phonenumber);
		strncat(s.phonenumber, y, 16-id);
		int tlf = strlen(s.period);
		strncat(s.period, y, 10-tlf);
		int gn = strlen(s.arrivaldate);
		strncat(s.arrivaldate, y, 15-gn);
		int tr = strlen(s.roomnumber);
		strncat(s.roomnumber, y, 7-tr);

		printf("\n %s|%s\t|%s\t|%s\t|%s\t|%s",s.roomnumber, s.name , s.surname, s.phonenumber ,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	printf("\n\n��kmak i�in bir tu�a bas�n.");
	getch();
}

void delete1()
{
	FILE *f,*t;
	int k=1;
	int i=1;
	char roomnumber[20], secim;

	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf(" Bu b�l�mde girilen oda numaras�na ait kay�tlar� silebilirsiniz. \n Devam etmek i�in space, ��kmak i�in ba�ka bir tu�a bas�n.\n");
	secim=getch();

	if(secim==' '){
	printf("Silinecek olan oda numaras�n� girin: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
				printf("\n\nKayd�n�z�n ba�ar�yla silinmesi i�in program� kapat�p yeniden a��n.");
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\nBu oda numaras�na ait m��teri kayd� bulunamad�!");

		getch();
		fclose(f);
		fclose(t);
		sleep(1);
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	fclose(f);
	fclose(t);
	sleep(1);
	}

}

void search()
{
system("cls");
	FILE *f;
	char name[20], secim;
	int k=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf(" Bu b�l�mde isim girerek kay�t sorgulatabilirsiniz. \n Devam etmek i�in space, ��kmak i�in ba�ka bir tu�a bas�n.\n");
	secim=getch();
	if(secim==' '){

	printf("Ayr�nt�lar� ��renmek i�in m��terinin ad�n� girin: \n");
	scanf("%s", name);
	while(fread(&s,sizeof(s),1,f)==1) // belge bitene kadar tara
	{
		if(strcmp(s.name,name)==0){ // kar��la�t�r ayn�ysa gir
			k=0;
			printf("\n\n\tKay�t bulundu\n ");
			printf("\nOda numaras�:\t%s",s.roomnumber);
			printf("\n�sim:\t%s",s.name);
			printf("\nAdres:\t%s",s.surname);
			printf("\nTelefon numaras�:\t%s",s.phonenumber);
			printf("\nS�re:\t%s",s.period);
			printf("\nGiri� tarihi:\t%s",s.arrivaldate);
			printf("\n\n��kmak i�in bir tu�a bas�n.");
			getche();
			k=0;

		}
	}
	if(k==1){
		printf("\n\tGirilen numaraya ait bir m��teri kayd� bulunamad�!");
		printf("\n\nBir �nceki men�ye y�nlendiriliyorsunuz.");
		sleep(2);
	}
	}
	fclose(f);
}

void edit()
{
	char yenikullaniciadi[10], yenisifre[10], onay, secim;
	system("cls");
	printf("Bu b�l�mde kullan�c� ad�n�z� ve �ifrenizi de�i�ebilirsiniz.\n Devam etmek i�in space, geri d�nmek i�in ba�ka bir tu�a bas�n.");
	secim=getche();
	if (secim==' '){


	login(); //giri� yapt�r
	 FILE *giris;


	printf("En fazla 10 karakterden olu�an yeni kullan�c� ad� girin.\n");
	scanf("%s", yenikullaniciadi);

   	printf("En fazla 10 karakterden olu�an yeni �ifre girin.\n");
	scanf("%s", yenisifre);

	 printf("�ifreniz de�i�tiriliyor, onayl�yor musunuz?\n");
	 printf("Onay i�in O, red icin R girin.\n");
	 	onay=getche();
		onay=toupper(onay);

		switch(onay)  {

			case 'O':
				giris=fopen("girisbilgileri.txt","w+");//dosyay� s�f�rla tekrar a�
   	 			fprintf(giris, "%s ", yenikullaniciadi);//bilgileri yaz
   	 			fprintf(giris, "%s", yenisifre);       //bilgileri yaz
   				 fclose(giris);
				printf("\nKullan�c� ad� ve �ifreniz de�i�tirildi.\n");
				getche();
				break;

			case 'R':
				printf("\nHerhangi bir de�i�iklik yap�lmad�, bir �nceki men�ye d�nmek i�in bir tu�a bas�n.\n");
				getche();
				break;
			default:
				system("cls");
				printf("Yanl�� bir tu�a bast�n�z.\n");
				printf("\nHerhangi bir tu�a bas�n.\n");
				getch();
			}
				}
}


