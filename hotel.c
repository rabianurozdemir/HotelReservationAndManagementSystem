#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

// OTEL REZERVASYON ve YÖNETÝM SÝSTEMÝ //

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
			printf("\n\nLütfen hizmet kalitemizi 1-5 arasý puanlayýn.");
			mpuan=getche();
			mpuan=toupper(mpuan);
		switch(mpuan)  {
			case '1':
				fprintf(puan, "%s ", "1");//puana 1 yazdýr
				printf("\nGörüþleriniz bizim için çok önemli, teþekkür ederiz!\n\n");
				sleep(2);
				break;
            case '2':
				fprintf(puan, "%s ", "2");
				printf("\nGörüþleriniz bizim için çok önemli, teþekkür ederiz!\n\n");
				sleep(2);
				break;
            case '3':
				fprintf(puan, "%s ", "3");
				printf("\nGörüþleriniz bizim için çok önemli, teþekkür ederiz!\n\n");
				sleep(2);
				break;
			case '4':
				fprintf(puan, "%s ", "4");
				printf("\nGörüþleriniz bizim için çok önemli, teþekkür ederiz!\n\n");
				sleep(2);
				break;
			case '5':
				fprintf(puan, "%s ", "5");
				printf("\nGörüþleriniz bizim için çok önemli, teþekkür ederiz!\n\n");
				sleep(2);
				break;
			default:
				printf("\nYanlýþ bir tuþa bastýnýz.\n");
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
	printf("\n\t1-Para iadesi için\n");
	printf("\t2-Þikayetler için\n");
	printf("\t3-Otelimiz hakkýnda bilgi almak için\n");
	printf("\t-----------------------------------------\n");
	printf("\t|||||||||||||||||||||||||||||||||||||||||\n");
	printf("\t-----------------------------------------\n\n");
	printf("\t Telefon\t | Þikayet konusu\n");
	printf("\t----------------------------------\n");
	talep=fopen("talep.txt","r");
	while(fread(&s,sizeof(s),1,talep)==1 ){ //belge bitene kadar tara
	fscanf(talep, "%s", konu);
	printf("\t%s\t", konu);  //ekrana yaz
	fscanf(talep, "%s", telefon);
	printf("\t%s\t\n", telefon);//ekrana yaz
	}

	fclose(talep);

	printf("\n\t Çýkmak için bir tuþa basýn.\n");
	getch();
}



void sikayet(){
	char secim, telefon[11];
    FILE *talep;

		printf("Telefon numaranýzý girin.\n");
		scanf("%s", &telefon);
	printf("\n1-Para iadesi için\n");
	printf("2-Þikayetler için\n");
	printf("3-Otelimiz hakkýnda bilgi almak için\n");
		secim=getche();
		secim=toupper(secim);
		switch(secim)  {
			case '1':

				talep=fopen("talep.txt","a+");//talep.txtyi aç
				fprintf(talep, "%s ", "1");   //dosyaya 1 yazdýr
                fprintf(talep, "%s ", telefon);//numarayý dosyaya yazdýr
				fclose(talep);
				printf("\nTalebiniz alýnmýþtýr, en kýsa sürede %s numarasý üzerinden dönüþ yapýlacaktýr.\n\n", telefon);
				sleep(4);
				break;
            case '2':
				talep=fopen("talep.txt","a+");
				fprintf(talep, "%s ", "2");
				fprintf(talep, "%s ", telefon);
				fclose(talep);
				printf("\nTalebiniz alýnmýþtýr, en kýsa sürede %s numarasý üzerinden dönüþ yapýlacaktýr.\n\n", telefon);
				sleep(4);
				break;
            case '3':

				talep=fopen("talep.txt","a+");
				fprintf(talep, "%s ", "3");
				fprintf(talep, "%s ", telefon);
				fclose(talep);
				printf("\nTalebiniz alýnmýþtýr, en kýsa sürede %s numarasý üzerinden dönüþ yapýlacaktýr.\n\n", telefon);
				sleep(4);
				break;
			default:
				printf("\nHerhangi bir deðiþiklik yapýlmadý, ana menüye dönmek için bir tuþa basýn.\n");
				getche();
				main();
				break;

}}

void indirimkodu(){
	char onay, kodindirim[10], kodd[10], secim;
	FILE *kod;
	system("cls");
	printf("Bu bölümde kampanya kodu oluþturabilir veya düzenleyebilirsiniz. \n Devam etmek için space, geri dönmek için baþka bir tuþa basýn.");
	secim=getch();
	if(secim==' '){

	system("cls");
	printf("Yüzde kac indirim yapmak istersiniz?\n");
	scanf("%s", &kodindirim);
	printf("Sadece sayýlardan oluþacak þekilde 6 haneli kampanya kodu belirleyin.\n");
	scanf("%s", &kodd);
	printf("Eðer varsa, var olan indirim kodu deðiþtirilecektir.\n");
	printf("Yoksa, yeni indirim kodu oluþturulacaktýr.\n");
	printf("Onaylýyor musunuz?\n");
	printf("Onaylamak için O, reddetmek için herhangi bir tuþa basýn.");
		onay=getche();
		onay=toupper(onay);
		switch(onay)  {
			case 'O':
				kod=fopen("indirimkodu.txt","w+"); //dosyayý sýfýrla ve aç
   	 			fprintf(kod, "%s ", kodindirim); //bilgileri dosyaya yaz
				fprintf(kod, "%s", kodd);        //bilgileri dosyaya yaz
				printf("\nÝþlem baþarýlý.\n");
				getche();
				break;

			default:
				printf("\nHerhangi bir deðiþiklik yapýlmadý, ana menüye dönmek için bir tuþa basýn.\n");
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
		if(ucret>1000){ // ücret 1000 TL üzeriyse yüzde 5 indirim yap
			printf("\nTebrikler! 1000 TL ve üzerine özel yüzde 5 indirim kazandýnýz!\n");
			ucret=ucret*0.95;
		}
		else if(ucret>2500){ // ücret 2500 TL üzeriyse yüzde 10 indirim yap
			printf("\nTebrikler! 2500 TL ve üzerine özel yüzde 10 indirim kazandýnýz!\n");
			ucret= ucret*0.9;
		}
		printf("Ücret %.2f\n", ucret);
		if(ayse<505){ // oda 505den küçükse ek hizmet sor
			printf("Ek hizmetlerimizden faydalanmak ister misiniz?\n");
			printf("Evet için E, hayýr için baþka herhangi bir tuþa basýn.\n");
						secim=getche();
						secim=toupper(secim);
							switch(secim)       
								{
								case 'E':

									while(cikis!=2){
										system("cls");
									printf("\nToplam ücret: %f\n", ucret);
									printf("\n1-Öðle yemeði(+50 TL)\n");
									printf("2-Akþam yemeði(+50 TL)\n");
									printf("3-Sauna(+50 TL)\n");
									printf("4-Osmanlý hamamý(+50 TL)\n");
									printf("5-Ek yatak(+50 TL)\n");
									printf("6-Baþka ek hizmet istemiyorum\n");
										secim1=getche();
										secim1=toupper(secim1);
										switch(secim1)    
										{
											case '1':
												ucret=ucret+50;
												printf("\nÖðle yemeði 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '2':
												ucret=ucret+50;
												printf("\nAkþam yemeði 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '3':
												ucret=ucret+50;
												printf("\nSauna 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '4':
												ucret=ucret+50;
												printf("\nOsmanlý Hamamý 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '5':
												if(tut==2){
													printf("\n\nEn fazla 2 yatak ekletebilirsiniz!\n\n");
													printf("\nBir tuþa basýn\n");;
												getche();
												}
												else if(tut<2){
													ucret=ucret+50;
													printf("\nEk yatak 50 TL karþýlýðýnda eklendi.\n");
													tut=tut+1;
													printf("\nBir tuþa basýn.\n");
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
		printf("\nToplam ücret %.2f TL\n", ucret);

		printf("\nÝndirim kodunuz var mý?\n");
		printf("\nEvet için E, hayýr için baþka herhangi bir tuþa basýn.\n");
			secimkod=getche();
			secimkod=toupper(secimkod);
			switch(secimkod) {
							case 'E':
								while(i != 2){

							printf("\nLütfen kodunuzu girin.\n");
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
								printf("\nTebrikler! Yüzde %d 'lik indirimden yararlandýnýz!\n", indirim);
								printf("Toplam ücret %.2f TL\n", ucret);
								i=2;
							}
							else{
								printf("\nGeçersiz kod\n");
								printf("Ücret %.2f TL\n", ucret);
								printf("\nÖdeme yapmak için 1, tekrar denemek için baþka herhangi bir tuþa basýn.\n");
								dene=getche();
								dene=toupper(dene);
								switch(dene){
									case '1':
										i=2;
								}
							}}
							break;

							}

		printf("\nEk indirim yapmak ister misiniz? Evet için E tuþlayýn. \n");
		secim=getche();
		secim=toupper(secim);
		switch(secim)  {
			case 'E':
				printf("\nYüzde kaç inidirim olacak?\n");
				scanf("%d", &ekindirim);
				ucret=ucret*(100-ekindirim)/100; // girilen yüzde kadar indirim yap
				printf("\nBütün indirimler dahil ücret: %.2f TL\n", ucret);
				printf("Ödeme alýndýysa bir tuþa basýn.\n");
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
			printf("\nTebrikler! 1000 TL ve üzerine özel yüzde 5 indirim kazandýnýz!\n");
			ucret=ucret*0.95;
		}
		else if(ucret>2500){
			printf("\nTebrikler! 2500 TL ve üzerine özel yüzde 10 indirim kazandýnýz!\n");
			ucret= ucret*0.9;
		}
		printf("Ücret %.2f\n", ucret);
		if(ayse<505){
			printf("Ek hizmetlerimizden faydalanmak ister misiniz?\n");
			printf("Evet için E, hayýr için baþka herhangi bir tuþa basýn.\n");
						secim=getche();
						secim=toupper(secim);
							switch(secim)       
								{
								case 'E':

									while(cikis!=2){
										system("cls");
									printf("\nToplam ücret: %f\n", ucret);
									printf("\n1-Öðle yemeði(+50 TL)\n");
									printf("2-Akþam yemeði(+50 TL)\n");
									printf("3-Sauna(+50 TL)\n");
									printf("4-Osmanlý hamamý(+50 TL)\n");
									printf("5-Ek yatak(+50 TL)\n");
									printf("6-Baþka ek hizmet istemiyorum\n");
										secim1=getche();
										secim1=toupper(secim1);
										switch(secim1)    
										{
											case '1':
												ucret=ucret+50;
												printf("\nÖðle yemeði 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '2':
												ucret=ucret+50;
												printf("\nAkþam yemeði 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '3':
												ucret=ucret+50;
												printf("\nSauna 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '4':
												ucret=ucret+50;
												printf("\nOsmanlý Hamamý 50 TL karþýlýðýnda eklendi.\n");
												printf("\nBir tuþa basýn\n");
												getche();
												break;
											case '5':
												if(tut==2){
													printf("\n\nEn fazla 2 yatak ekletebilirsiniz!\n\n");
													printf("\nBir tuþa basýn\n");;
												getche();
												}
												else if(tut<2){
													ucret=ucret+50;
													printf("\nEk yatak 50 TL karþýlýðýnda eklendi.\n");
													tut=tut+1;
													printf("\nBir tuþa basýn.\n");
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
		printf("\nToplam ücret %.2f TL\n", ucret);

		printf("\nÝndirim kodunuz var mý?\n");
		printf("\nEvet için E, hayýr için baþka herhangi bir tuþa basýn.\n");
			secimkod=getche();
			secimkod=toupper(secimkod);
			switch(secimkod) {
							case 'E':
								while(i != 2){

							printf("\nLütfen kodunuzu girin.\n");
							scanf("%s", &indirimkod);
							FILE *kod;
   							kod=fopen("indirimkodu.txt","r");// indirimkodu.txtyi aç
   							fscanf(kod, "%s", &kodindirim); // kodindirim deðiþkenþne ata
   							for(i=0; i<10; i++){
   								code[i]=kodindirim[i];     // daha sonra int yapmak için code ata
							   }
							   int indirim= atoi(code);  // int yap
   							fscanf(kod, "%s", &indirimkod1);

   							fclose(kod);
   							if(strcmp(indirimkod,indirimkod1)==0 ){ // girilen kod ve belgedeki kod aynoysa
								ucret=ucret*(100-indirim)/100;
								printf("\nTebrikler! Yüzde %d 'lik indirimden yararlandýnýz!\n", indirim);
								printf("Toplam ücret %.2f TL\n", ucret);
								i=2;
							}
							else{
								printf("\nGeçersiz kod\n");
								printf("Ücret %.2f TL\n", ucret);
								printf("\nÖdeme yapmak için 1, tekrar denemek için baþka herhangi bir tuþa basýn.\n");
								dene=getche();
								dene=toupper(dene);
								switch(dene){
									case '1':
										i=2;
								}
							}}
							break;

							}
		


				printf("Kart numaranýz:\n");
				scanf("%s", kartbilgi);
				printf("\nKart sahibinin ismi:\n");
				scanf("%s", kartisim);
				printf("%s numaralý kartýnýzdan ",kartbilgi);
				printf("%.2f TL çekilecek, onaylýyor musunuz?\n", ucret);
				printf("Onay için O, red icin R tuþlayýn.\n");
				secim2=getche();
				secim2=toupper(secim2);
				switch(secim2){

					case 'O':{
					printf("\n\nÖdemeniz alýndý.\n");
					getch();
					break;
					}
					case 'R':{

					add();
					break;
					}


				default:
				system("cls");
				printf("Yanlýþ bir tuþa bastýnýz.\n");
				printf("\nHerhangi bir tuþa basýn.\n");
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

    printf("\n  **************************  GÝRÝÞ  **************************  ");
    printf("\n Devam etmek için lütfen kullanýcý adýnýzý ve þifrenizi girin.");
    printf(" \n                       Kullanýcý adý:-");
	scanf("%s", &uname);
	printf(" \n                       Þifre:-");
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
		if(strcmp(uname,kullaniciadi)==0 && strcmp(pword,sifre)==0) // aynýysa giriþ yap
	{
	printf("  \n\n\n  GÝRÝÞ BAÞARILI, LÜTFEN BEKLEYÝN :)");
	sleep(2);

	break;
	}
	else
	{
		printf("\n    ÜZGÜNÜZ! GÝRÝÞ BAÞARISIZ! Tekrar deneyin :( )");
		sleep(1);
		a++;



	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nKullanýcý adý veya þifreyi üç kez yanlýþ girdiniz!\n");
		printf("\nBir tuþa basýn.\n");
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
	printf("\t\t      *               OTELÝMÝZE HOÞGELDÝNÝZ                    *\n");
	printf("\t\t      *           -----------------------------                *\n");
	printf("\t\t      *                                                        *\n");
	printf("\t\t      *                   Ýletiþim için:                       *\n");
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
		setcolor(9);printf("\n\t\t\t\t\t  Ortalama puanýmýz: %d\n", ortpuan);setcolor(15);
		printf("\t       ");
		for(i=0;i<70;i++)
		printf("-");
	    printf("\n\n\t\t\t         Gün ve saat: %s",ctime(&t));
	    printf("\t       ");
	    for(i=0;i<70;i++)
		printf("-");
	printf("\n\n\t\t       Kullanýcý paneli için 1, yönetici paneli için 2 tuþlayýn.\n\n");
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
		printf("   ******************************  |ANA MENÜ|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");

		printf("\t\t *Yapmak istediðiniz iþlemi seçin*:");
		printf("\n\n");
		printf("\n 1 -> Oda rezervasyonu");
		printf("\n------------------------");
		printf("\n 2 -> Müþteri kayýtlarý");
		printf("\n----------------------------------");
		printf("\n 3 -> Müþteri kayýt silme");
		printf("\n-----------------------------------");
		printf("\n 4 -> Müþteri kayýt arama");
		printf("\n-----------------------------------");
		printf("\n 5 -> Kullanýcý adý/þifre düzenleme");
		printf("\n-----------------------------------");
		printf("\n 6 -> Ýndirim kodu duzenleme");
		printf("\n-----------------------");
		printf("\n 7 -> Talepler");
		printf("\n-----------------------");
		printf("\n 8 -> Bir önceki menü");
		printf("\n-----------------");
		printf("\n 9 -> Uygulamayý kapat");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nGün ve saat: %s",ctime(&t));
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
				printf("Yanlýþ bir tuþa bastýnýz.\n");
				printf("\nHerhangi bir tusa basin.\n");
				getch();
		}
	}}
	else if(secenek==1){
			setcolor(15);

		while(1){
				system("cls");
			printf("   ******************************  |ANA MENÜ|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t *Yapmak istediðiniz iþlemi seçin*:");
		printf("\n\n");
		printf("\n 1 -> Oda rezervasyonu");
		printf("\n------------------------");
		printf("\n 2 -> Odalarýmýz ve hizmetlerimiz");
		printf("\n--------------------------------");
		printf("\n 3 -> Þikayet ve yardým talebi");
		printf("\n--------------------------------");
		printf("\n 4 -> Bir önceki menü");
		printf("\n-----------------");
		printf("\n 5 -> Uygulamayý kapat");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nGün ve saat: %s",ctime(&t));
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
				printf("\n\tOtelimizde Uygun, Standart ve Lüks olmak üzere 3 çeþit odamýz mevcutur.\n");
				printf("\t----------------------------------------------------------------------\n\n");
				printf("\tUygun oda: Sadece kahvaltý, tek kiþilik yatak ve mini buzdolabý içerir.\n\n");
				printf("\tStandart oda: Sadece kahvaltý, çift kiþilik yatak, televizyon ve mini buzdolabý içerir.\n\n");
				printf("\tLüks oda: Üç öðün yemek, çift kiþilik yatak, televizyon, mini buzdolabý \n\tve bunlara ek olarak otelimizde mecvut olan tüm hizmetleri içerir.\n");
				printf("\n\tGeri dönmek için bir tuþa basýn.\n");
					secim=getch();
					if(secim==27){
					break;}
				break;
			case '3':
				system("cls");
						printf("\n1. Adým: Telefon numaranýzý yazýn.\n");
						printf("\n2. Adým: Talep konunuzu seçin.\n");
						printf("\n3. Sizinle en kýsa zamanda iletiþim kuralým.\n");
				    	printf("\nGeri dönmek için esc, þikayet ve yardým talebi oluþturmak için baþka bir tuþa basýn.\n\n");
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
				printf("\n\n\t Puanlamak için space, programý kapatmak için baþka bir tuþa basýn.");
				secim1=getch();
				if (secim1==' '){
					puanekle();
				}
				printf("\n\n\t Yine bekleriz.");
				exit(0);
				break;
			default:
				system("cls");
				printf("Yanlýþ bir tuþa bastýnýz.\n");
				printf("\nHerhangi bir tuþa basýn.\n");
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
		printf("Ýþlemlerimizi saðlýyoruz, lütfen bekleyin!");
		printf("\nÝþleminiz tamamlanmýþtýr, devam etmek için herhangi bir tuþa basýn.");
		fclose(f);
		getch();

	}
	fclose(f);
	while(1){
		system("cls");
		f=fopen("add.txt","a+");

		printf("\n\nTüm odalar:\n");
		printf("\n\n101	102	103	104	105	106	107	108	109\n");
		printf("201	202	203	204	205	206	207	208	209\n");
		printf("301	302	303	304	305	306	307	308	309\n");
		printf("401	402	403	404	405	406	407	408	409\n");
		printf("501	502	503	504	505	506	507	508	509\n");
		printf("\n\n101-109 arasý Uygun, 201-504 arasý Standart, 505-509 arasý Lüks\n");
		printf("\n\nUygun odalar gecelik 100 TL (Sadece kahvaltý)\n");
		printf("Standart odalar gecelik 150 TL(Sadece kahvaltý)\n");
		printf("Lüks odalar gecelik 300 TL(Her þey dahil)	\n");



		printf("\n\nDolu odalar:\n");
			while(fread(&s,sizeof(s),1,f)==1)
	{
				rb++;

		printf("%s \t",s.roomnumber);
					if(rb%9==0)
					printf("\n");
	}
		printf("\nGeri dönmek için esc, oda seçmek için space tuþuna basýn.\n");
		secim=getch();
		if(secim==27){
		break;}
		else if(secim==' '){


		printf("\nOda numarasý girin:\n");
		scanf("\n%s",roomnumber);
		for(number=0; number<10; number++){

		odanumara[number]=roomnumber[number];}

		int ayse = atoi(odanumara);
		if(ayse%10==0 || ayse/100 > 5 || ayse%100-ayse%10!=0){ //101-109, 201-209...
			printf("Bu numaraya sahip bir oda mecvut deðil.\n");// nolu deðilse hata ver
			getch();
			break;

		}




	while(fread(&s,sizeof(s),1,f)!=1)
	{

		if(strcmp(s.roomnumber, roomnumber)==0) // kýyasla numaralar aynýysa içeri gir
		{
			k=0;
			printf("\n\nMaalesef bu oda dolu, boþ bir oda seçin!\n");
			fclose(f);
			sleep(1);

		}
		break;
			}

	if(k==1){
			for(number=0; number<10; number++){ //s.roomnumbera roomnumberý ata

			s.roomnumber[number]=roomnumber[number];
			}

			printf("\n\nOda müsait. Sayfaya yönlendiriliyorsunuz. Lütfen bekleyin.\n");

			sleep(4);

			system("cls");

			printf("\nÝsim girin:\n");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nSoyad girin:\n");
			scanf("%s",&s.surname);
			printf("\nTelefon numarasý girin:\n");
			scanf("%s",&s.phonenumber);
			printf("\nKaç gün kalacaksýnýz?:\n");
			scanf("%s",&s.period);
			printf("\nOtele ne zaman giroiþ yapacaksýnýz?:\n");
			scanf("%s",&s.arrivaldate);


			for(number=0; number<10; number++){

			tarih[number]=s.period[number];
			}
			int gun = atoi(tarih);




			printf("\n\nÖdeme sayfasýna yönlendiriliyorsunuz. Lütfen bekleyin.\n");

			sleep(4);

			system("cls");
			odemekullanici( ayse, gun);



			fseek(f,size,SEEK_CUR); 
			fwrite(&s,sizeof(s),1,f);
			fclose(f);
				system("cls");
				printf("\n\tKaydýnýz baþarýyla alýnmýþtýr. Lütfen bekleyin.\n");
				sleep(1);
			break;

	}

	}
	else{
		printf("\nYanlýþ bir tuþa bastýnýz.\n");
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
		printf("Ýþlemlerimizi saðlýyoruz, lütfen bekleyin!");
		printf("\nÝþleminiz tamamlanmýþtýr, devam etmek için herhangi bir tuþa basýn. ");
		fclose(f);
		getch();
	}
	fclose(f);
	while(1){ //sonsuz döngü baþlangýcý
		system("cls");
		f=fopen("add.txt","a+");
		printf("\n\nTüm odalar:\n");
		printf("\n\n101	102	103	104	105	106	107	108	109\n");
		printf("201	202	203	204	205	206	207	208	209\n");
		printf("301	302	303	304	305	306	307	308	309\n");
		printf("401	402	403	404	405	406	407	408	409\n");
		printf("501	502	503	504	505	506	507	508	509\n");
		printf("\n\n101-109 arasý Uygun, 201-504 arasý Standart, 505-509 arasý Lüks\n");
		printf("\n\nUygun odalar gecelik 100 TL (Sadece kahvaltý)\n");
		printf("Standart odalar gecelik 150 TL(Sadece kahvaltý)\n");
		printf("Lüks odalar gecelik 300 TL(Her þey dahil)	\n");

		printf("\n\nDolu odalar:\n");
			while(fread(&s,sizeof(s),1,f)==1)
	{
				rb++;
		printf("%s \t",s.roomnumber);
					if(rb%9==0)
					printf("\n");
	}
		printf("\nGeri dönmek için esc, oda seçmek için space tuþuna basýn.\n");
		secim=getch();
		if(secim==27){
		break;
		}
		else if(secim==' '){

		printf("\nOda numarasý girin:\n");
		scanf("\n%s",roomnumber);
		for(number=0; number<10; number++){

		odanumara[number]=roomnumber[number];}

		int ayse = atoi(odanumara);
		if(ayse%10==0 || ayse/100 > 5 || ayse%100-ayse%10!=0){
			printf("Bu numaraya sahip bir oda mecvut deðil.\n");
			getch();
			break;
		}


	while(fread(&s,sizeof(s),1,f)!=1)
	{

		if(strcmp(s.roomnumber, roomnumber)==0)
		{
			k=0;
			printf("\n\nMaalesef bu oda dolu, boþ bir oda seçin!\n");
			fclose(f);
			sleep(1);

		}
		break;
			}

	if(k==1){
			for(number=0; number<10; number++){

			s.roomnumber[number]=roomnumber[number];
			}

			printf("\n\nOda müsait. Sayfaya yönlendiriliyorsunuz. Lütfen bekleyin.\n");

			sleep(3);

			system("cls");

			printf("\nÝsim girin:\n");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nSoyad girin:\n");
			scanf("%s",&s.surname);
			printf("\nTelefon numarasý girin:\n");
			scanf("%s",&s.phonenumber);
			printf("\nKaç gün kalacaksýnýz?:\n");
			scanf("%s",&s.period);
			printf("\nOtele ne zaman giriþ yapacaksýnýz?:\n");
			scanf("%s",&s.arrivaldate);


			for(number=0; number<10; number++){

			tarih[number]=s.period[number];
			}
			int gun = atoi(tarih);


			printf("\n\nÖdeme sayfasýna yönlendiriliyorsunuz. Lütfen bekleyin.\n");

			sleep(3);

			system("cls");
			odemeyonetici( ayse, gun);

			fseek(f,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			fclose(f);
				system("cls");
				printf("\n\tKaydýnýz baþarýyla alýnmýþtýr. Lütfen bekleyin.\n");
				sleep(1);
			break;

	}
	k=1;
}
	else{
		printf("\nYanlýþ bir tuþa bastýnýz.\n");
		sleep(1);
	}

}//sonsuz döngü bitiþi
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
	printf("ÝSÝM   \t\t|");
	printf("SOY ÝSÝM   \t\t|");
	printf("TELEFON\t\t|");
	printf("SÜRE\t\t|");
	printf("GÝRÝÞ TARÝHÝ\n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1) // belge bitene kadar döndür
	{
		for(i=0; i<20; i++)
			y[i]=(' ');
		int ism = strlen(s.name); 
		strncat(s.name, y, 16-ism);	// ayný hizada oLmasý için sonuna 16 karakter olacak þekilde boþluk ekle
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
	printf("\n\nÇýkmak için bir tuþa basýn.");
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
	printf(" Bu bölümde girilen oda numarasýna ait kayýtlarý silebilirsiniz. \n Devam etmek için space, çýkmak için baþka bir tuþa basýn.\n");
	secim=getch();

	if(secim==' '){
	printf("Silinecek olan oda numarasýný girin: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
				printf("\n\nKaydýnýzýn baþarýyla silinmesi için programý kapatýp yeniden açýn.");
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\nBu oda numarasýna ait müþteri kaydý bulunamadý!");

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
	printf(" Bu bölümde isim girerek kayýt sorgulatabilirsiniz. \n Devam etmek için space, çýkmak için baþka bir tuþa basýn.\n");
	secim=getch();
	if(secim==' '){

	printf("Ayrýntýlarý öðrenmek için müþterinin adýný girin: \n");
	scanf("%s", name);
	while(fread(&s,sizeof(s),1,f)==1) // belge bitene kadar tara
	{
		if(strcmp(s.name,name)==0){ // karþýlaþtýr aynýysa gir
			k=0;
			printf("\n\n\tKayýt bulundu\n ");
			printf("\nOda numarasý:\t%s",s.roomnumber);
			printf("\nÝsim:\t%s",s.name);
			printf("\nAdres:\t%s",s.surname);
			printf("\nTelefon numarasý:\t%s",s.phonenumber);
			printf("\nSüre:\t%s",s.period);
			printf("\nGiriþ tarihi:\t%s",s.arrivaldate);
			printf("\n\nÇýkmak için bir tuþa basýn.");
			getche();
			k=0;

		}
	}
	if(k==1){
		printf("\n\tGirilen numaraya ait bir müþteri kaydý bulunamadý!");
		printf("\n\nBir önceki menüye yönlendiriliyorsunuz.");
		sleep(2);
	}
	}
	fclose(f);
}

void edit()
{
	char yenikullaniciadi[10], yenisifre[10], onay, secim;
	system("cls");
	printf("Bu bölümde kullanýcý adýnýzý ve þifrenizi deðiþebilirsiniz.\n Devam etmek için space, geri dönmek için baþka bir tuþa basýn.");
	secim=getche();
	if (secim==' '){


	login(); //giriþ yaptýr
	 FILE *giris;


	printf("En fazla 10 karakterden oluþan yeni kullanýcý adý girin.\n");
	scanf("%s", yenikullaniciadi);

   	printf("En fazla 10 karakterden oluþan yeni þifre girin.\n");
	scanf("%s", yenisifre);

	 printf("Þifreniz deðiþtiriliyor, onaylýyor musunuz?\n");
	 printf("Onay için O, red icin R girin.\n");
	 	onay=getche();
		onay=toupper(onay);

		switch(onay)  {

			case 'O':
				giris=fopen("girisbilgileri.txt","w+");//dosyayý sýfýrla tekrar aç
   	 			fprintf(giris, "%s ", yenikullaniciadi);//bilgileri yaz
   	 			fprintf(giris, "%s", yenisifre);       //bilgileri yaz
   				 fclose(giris);
				printf("\nKullanýcý adý ve þifreniz deðiþtirildi.\n");
				getche();
				break;

			case 'R':
				printf("\nHerhangi bir deðiþiklik yapýlmadý, bir önceki menüye dönmek için bir tuþa basýn.\n");
				getche();
				break;
			default:
				system("cls");
				printf("Yanlýþ bir tuþa bastýnýz.\n");
				printf("\nHerhangi bir tuþa basýn.\n");
				getch();
			}
				}
}


