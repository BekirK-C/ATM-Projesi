// BEKÝR BERAT KAMACI - ATM SÝSTEMÝ - 03/2020

#include <stdio.h>    //standart
#include <unistd.h>  //color
#include <windows.h>  //sleep
#include <conio.h>  //cls
#include <time.h>   //time

int a, islem, talimat, girdi, bakiye, Suabone, Sufatura, Elabone, Elfatura, Dogabone, Dogfatura, Telno, Telfatura, Vergino, Vergiborcu, Kimlikno, Plakano, Trafikceza, IBAN, Sifre, x = 0;

void bilgiler ()  
{
	
	FILE *dosya;
	int numaralar[15], i = 0;
	
	if((dosya=fopen("HesapBilgileri.txt", "r")) != NULL) 
	{
		
		while(!feof(dosya)) 
		{
			fscanf(dosya, "%d", &numaralar[i]);	
			
			bakiye     = numaralar[0];
			Suabone    = numaralar[1];
			Sufatura   = numaralar[2];
			Elabone    = numaralar[3];
			Elfatura   = numaralar[4];
			Dogabone   = numaralar[5];
			Dogfatura  = numaralar[6];
			Telno      = numaralar[7];
			Telfatura  = numaralar[8];
			Vergino    = numaralar[9];
			Vergiborcu = numaralar[10];
			Kimlikno   = numaralar[11];
			Plakano    = numaralar[12]; 
			Trafikceza = numaralar[13];
			IBAN       = numaralar[14];
			Sifre      = numaralar[15];
			
			i++;
		}	
	}
	
	else 
	{
		printf("Dosya Bulunamadi!");
	}
}

void parabolme (int bpara)  //Para Bölme Fonksiyonu
{			
	
	FILE *dosya;
    
    dosya = fopen("Dekont.txt","a");
    
    int ikiyuzluk =  bpara / 200;
    int yuzluk    = (bpara - (ikiyuzluk * 200)) / 100;
    int ellilik   = (bpara - (yuzluk * 100 + ikiyuzluk * 200)) / 50;
    int yirmilik  = (bpara - (ellilik * 50 + yuzluk * 100 + ikiyuzluk * 200)) / 20;
    int onluk     = (bpara - (yirmilik * 20 + ellilik * 50 + yuzluk * 100 + ikiyuzluk * 200)) / 10;
    int beslik    = (bpara - (onluk * 10 + yirmilik * 20 + ellilik * 50 + yuzluk * 100 + ikiyuzluk * 200)) / 5;
    int birlik    = (bpara - (beslik * 5 + onluk * 10 + yirmilik * 20 + ellilik * 50 + yuzluk * 100 + ikiyuzluk * 200)) / 1;

	if(ikiyuzluk != 0)
	{
    fprintf(dosya, "Ikiyuzluk:%d \n", ikiyuzluk);
	}
    if(yuzluk != 0)
	{
    fprintf(dosya, "Yuzluk:%d \n", yuzluk);
	}
    if(ellilik != 0)
	{
    fprintf(dosya, "Ellilik:%d \n", ellilik);
	}
    if(yirmilik != 0)
	{
    fprintf(dosya, "Yirmilik:%d  \n", yirmilik);
	}
    if(onluk != 0)
	{
    fprintf(dosya, "Onluk:%d  \n", onluk);
	}
    if(beslik != 0)
	{
    fprintf(dosya, "Beslik:%d  \n", beslik);
	}
    if(birlik != 0)
	{
    fprintf(dosya, "Birlik:%d \n", birlik);
	}
	//fclose(dosya);          // Bu satýr olunca tam çalýþmýyor.
}

void dekont(char *islem, int dpara) 
{
	
	FILE *dosya;
    
    dosya = fopen("Dekont.txt", "w");
    
    fputs("------------BKR BANKASI------------\n\n", dosya);
    fputs("Umraniye Subesi\n", dosya);
    
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(dosya, "%02d:%02d:%02d	   	 %02d-%02d-%d\n\n\n", tm.tm_hour, tm.tm_min, tm.tm_sec,  tm.tm_mday , tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(dosya, "Islem:%s\n", islem);
	fprintf(dosya, "Tutar:%d TL\n", dpara);
	fprintf(dosya, "Yeni Bakiye:%d TL\n\n", bakiye);
	
		if(x == 1)
		{
			parabolme(dpara);    
		}
		
		if(x == 0)  //Para bolme fonksiyonu
		{                          
			fputs("\n       Iyi Gunler Dileriz...\n", dosya);    
			fprintf(dosya, "\n");
			fprintf(dosya, "-----------------------------------\n");
		}
	fclose(dosya);
}

void parakontrol(int para, char *islem)  // para kontrol fonksiyonu
{     
	if (para > bakiye) 
	{
	    printf ("Bakiyeniz Yetersiz...\n\n");
	    printf("1:Ana Menu\n2:Cikis\n");
	    scanf("%d", &a);
	    system("cls");
    }
	else if(para <= bakiye && para > 0)
	{   
		bakiye = bakiye - para;             // Bakiye güncellendi. 
		printf("Isleminiz Gerceklestirilmistir.\n\n", para);
		printf("1:Dekont Istiyorum     2:Dogayi Korumak Istiyorum\n\n");
		scanf("%d", &talimat);
		
		if(talimat == 1)
		{
			printf("|Dekontunuz Dekont.txt dosyada olusturulmustur.(Islem yaptiktan hemen sonra dekont ciktisi almayi unutmayin)|\n\n");
			dekont(islem, para); 			 //****DEKONT FONKSÝYONU
		} 
		printf("\n1:Ana Menu\n2:Cikis\n");
  	    scanf("%d", &a);
    	system("cls");
	    }
	else
	{
	a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
	}
}

void odemeislemleri()   //ödeme iþlemleri fonksiyonu.
{             
	
	char islem11[] = "Su Faturasi", islem12[] = "Elektrik Faturasi", islem13[] = "Dogalgaz Faturasi", islem14[] = "Telefon Faturasi",islem21[] = "Kart Borcu",islem31[] = "Vergi",islem41[] = "Trafik Cezasi";
	int  girdi, girdi1, girdi2, talimat, numaralar[15], i = 0;

	FILE *dosya;
	
	if((dosya = fopen("HesapBilgileri.txt","r")) != NULL) 
	{
		while(!feof(dosya))
		{
			fscanf(dosya, "%d", &numaralar[i]);	
			
			bakiye     = numaralar[0];
			Suabone    = numaralar[1];
			Sufatura   = numaralar[2];
			Elabone    = numaralar[3];
			Elfatura   = numaralar[4];
			Dogabone   = numaralar[5];
			Dogfatura  = numaralar[6];
			Telno      = numaralar[7];
			Telfatura  = numaralar[8];
			Vergino    = numaralar[9];
			Vergiborcu = numaralar[10];
			Kimlikno   = numaralar[11];
			Plakano    = numaralar[12]; 
			Trafikceza = numaralar[13];
			IBAN       = numaralar[14];
			
			i++;	
		}	
	}
	
	else 
	{
		printf("Dosya Bulunamadi!");
	}
	
	printf ("Odeme Islemleri \n 1:Fatura \n 2:Bu Kartin Borcunu Ode \n 3:Vergi \n 4:Trafik Cezasi \n ");
	printf ("Yapmak Istediginiz Islemi Seciniz=");
	scanf ("%d", &islem);
	
switch (islem)  
{

case 1 :                                // FATURA ÝÞLEMLERÝ TAMAM.              //DEFAULT EKLEMEYÝ UNUTMA
	
	system("cls");
	printf(" 1:Su \n 2:Elektrik \n 3:Dogalgaz \n 4:Telefon \n\n");
	printf ("Yapmak Istediginiz Islemi Seciniz=");
	scanf ("%d", &islem);
	
	switch(islem)
	{
		
	case 1:
		
		printf("Abone numaranizi giriniz:");
		scanf("%d", &girdi);
		
		if(girdi == Suabone)    //tüm abonenolar þimdilik ayný
		{				
			printf("Faturaniz %d TL'dir.Odemek icin lutfen 1'e basiniz.", Sufatura);
			scanf("%d", &talimat);
			
				if(talimat == 1)
				{
					parakontrol(Sufatura, islem11);          // para kontrol fonksiyonu ***************************
				}
				else
				{
					a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
				}
		}

		else
		{
			printf("Hata!\n");
			a = 2;		//amaç programý kapatmak.
		}							
	break;                          // case 1 break
	
	case 2:
		
		printf("Abone numaranizi giriniz:");
		scanf("%d", &girdi);
		if(girdi == Elabone)
		{				//tüm abonenolar þimdilik ayný
			printf("Faturaniz %d TL'dir.Odemek icin lutfen 1'e basiniz.", Elfatura);
			scanf("%d", &talimat);
			if(talimat == 1)
			{
				parakontrol(Elfatura, islem12);          // para kontrol fonksiyonu  ***************************
			}
			else
			{
				a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
			}
		}
		else
		{
			printf("Hata!\n");
			a = 2;
		}							//amaç programý kapatmak.
	break;                          // case 2 break
	
	case 3:
		
		printf("Abone numaranizi giriniz:");
		scanf("%d", &girdi);
		
		if(girdi == Dogabone)
		{          //tüm abonenolar þimdilik ayný
			printf("Faturaniz %d TL'dir.Odemek icin lutfen 1'e basiniz.", Dogfatura);
			scanf("%d", &talimat);
			
			if(talimat == 1)
			{
				parakontrol(Dogfatura, islem13);          // para kontrol fonksiyonu   ***************************
			}
			else
			{
				a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
			}
		}
		else
		{
			printf("Hata!\n");
			a = 2;
		}							//amaç programý kapatmak.
	break;                          // case 3 break
	
	case 4:
		
		printf("Telefon numaranizi giriniz:");
		scanf("%d", &girdi);
		
		if(girdi == Telno)
		{     //tel no þimdilik aboneno ya eþit
			printf("Faturaniz %d TL'dir.Odemek icin lutfen 1'e basiniz.", Telfatura);
			scanf("%d", &talimat);
			
			if(talimat == 1)
			{
				parakontrol(Telfatura, islem14);          // para kontrol fonksiyonu ***************************
			}
			else
			{
				a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
			}
		}
		else
		{
			printf("Hata!\n");
			a = 2;
		}							//amaç programý kapatmak.
	break;                          // case 4 break
	}
	
	break;          // ÖNCEKÝ SWÝTCH ÝÇÝN BREAK;
	
case 2:                             //KART BORCU TAMAM
	
	printf("Bu kartin borcu %d TL'dir.Odemek icin lutfen 1'e basiniz.", Sufatura);		//Þimdilik borç yerine Sufaturayý kullandým.
	scanf("%d", &talimat);
	
	if(talimat == 1)
	{
		parakontrol(Sufatura, islem21);          // para kontrol fonksiyonu ***************************
	}
	else
	{
		a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
	}
	break;

case 3:                   //VERGÝ TAMAM
	
	printf("Vergi No:");
	scanf("%d", &girdi);
	
	if(girdi == Vergino)
	{
		printf("Vergi borcunuz %d TL'dir.Odemek icin lutfen 1'e basiniz.", Vergiborcu);		//Þimdilik borç yerine faturayý kullandým.
		scanf("%d", &talimat);
		
		if(talimat == 1)
		{
			parakontrol(Vergiborcu, islem31);;          // para kontrol fonksiyonu ***************************
		}
		else
		{
			a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
		}
	}
	else
	{
		printf("Hata!\n");
		a = 2;							//amaç programý kapatmak.
	}
	break;

case 4 :                             //TRAFÝK CEZASI TAMAM

	printf("kimlik no:");
	scanf("%d", &girdi1);
	printf("Plaka(Harfler Olmadan):");
	scanf("%d", &girdi2);                        // CEZA=0 ÝSE BÝR ÝF DAHA EKLEMEYÝ UNUTMA!
	
	if(girdi1 == Kimlikno && girdi2 == Plakano)
	{
		printf("Cezaniz %d TL'dir.Odemek icin lutfen 1'e basiniz.", Trafikceza);
		scanf("%d", &talimat);
		
		if(talimat == 1)
		{
			parakontrol(Trafikceza, islem41);          // para kontrol donksiyonu ***************************
		}
		else
		{
			a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
		}
	}
	else
	{
		printf("Hata!\n");
		a = 2;							//amaç programý kapatmak.
	}
	break;                  // case 4 break
	
  }	
}	

void gonderim(int girdi)   //EFT ve Havale için gönderim fonksiyonu
{              
	char islem[]="Para Transferi";
	int tutar, i = 0, numaralar[15];
	FILE *dosya;
	
	if((dosya = fopen("HesapBilgileri.txt", "r")) != NULL) 
	{
		while(!feof(dosya))
		{	
			fscanf(dosya, "%d", &numaralar[i]);
			IBAN = numaralar[14];
			
			i++;	
		}	
	}
	
	else 
	{
		printf("Dosya Bulunamadi!");
	}
	
	if(girdi == IBAN)
	{     
		printf("Gonderim yapilacak tutari girniz:");
		scanf("%d", &tutar);
		printf("\n%d TL gonderimi onaylamak icin lutfen 1'e basiniz.", tutar);
		scanf("%d", &talimat);
		
		if(talimat == 1)
		{
			parakontrol(tutar,islem);          // para kontrol fonksiyonu ***************************
		}
		else
		{
			a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
		}
	}
	else
	{
		printf("Hata!\n");
		a = 2;
	}							//amaç programý kapatmak.
}

void paratransferleri() 
{
	int tutar;
	
	printf ("Para Transfer Islemleri \n 1:Havale \n 2:EFT \n  \n ");
	printf ("Yapmak Istediginiz Islemi Seciniz=");
	scanf ("%d", &islem);
	
	switch(islem)  
	{
		
	case 1:
		
		printf("Havale yapilacak IBAN No:");
		scanf("%d", &girdi);
		gonderim(girdi);              //Gönderim Fonksiyonu
		
		break;                          // case 1 break
	
	case 2:
		
		printf("EFT yapilacak IBAN No:");
		scanf("%d", &girdi);
		gonderim(girdi);                 //Gönderim Fonksiyonu
		
		break;                          // case 1 break
	}
}


void islemler()   //iþlemler fonksiyonu.
{               
	int tutar;
	char islem1[] = "Para Cekme", islem2[] = "Para Yatirma";
	printf (" Islemler\n 1:Para Cekme\n 2:Para Yatirma\n 3:Odeme Islemleri \n 4:Para Transferleri \n 5:Bakiye Sorgulama \n 6:Cikis \n");
	printf ("Yapmak Istediginiz Islemi Seciniz=");
    scanf ("%d", &islem);
    
switch(islem)  
{
    	
case 1 : 

	printf ("Bakiyeniz : %d TL\n\n", bakiye);             
	printf ("Cekmek Istediginiz Tutari Giriniz : ");
	scanf ("%d", &tutar);
	
	if (tutar > bakiye) 
	{                                          // paradurumu fonksiyonunu ancak parakontrol fonksiyonunu burda kullanmadan yapabýldým.
		    printf ("Bakiyeniz Yetersiz...\n\n");
		    printf("1:Ana Menu\n2:Cikis\n");
		    scanf("%d", &a);
		    system("cls");
	}
		else if(tutar <= bakiye && tutar > 0)
		{   
			bakiye = bakiye - tutar;             // Bakiye güncellendi. 
			printf("Isleminiz Gerceklestirilmistir.\n\n", tutar);
			printf("1:Dekont Istiyorum     2:Dogayi Korumak Istiyorum");
			scanf("%d", &talimat);
			
			if(talimat == 1)
			{
				x = 1;   // Para çekme farkýný anlamak için burada + parabolme fonks. var.
				printf("|Dekontunuz Dekont.txt dosyada olusturulmustur.(Islem yaptiktan hemen sonra dekont ciktisi almayi unutmayin)|\n");
				dekont(islem1, tutar); 			 //****DEKONT FONKSÝYONU
				
			}              
			x = 0;		//Para çekme farkýný anlamak için burada + parabolme fonks. var.
			printf("\n1:Ana Menu\n2:Cikis\n");
	  	    scanf("%d", &a);
	    	system("cls");
		 }
	  	else
		{
	  		a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
		}
	break; 				//case 1 break
	
case 2 :
	
	printf ("Bakiyeniz : %d TL\n\n", bakiye);
	printf ("Yatirmak Istediginiz Tutari Giriniz : ");
	scanf ("%d", &tutar);
	
	if(tutar > 0)
	{
  		bakiye = bakiye + tutar;             // Bakiye güncellendi. Burda para kontrol fonksiyonunu uygulayamadým cunku + var.
  		printf("%d TL para yatirma islemi gerceklestirilmistir.\n\n",tutar);
  		printf("1:Dekont Istiyorum     2:Dogayi Korumak Istiyorum\n\n");
		scanf("%d", &talimat);
		
		if(talimat == 1)
		{
			printf("|Dekontunuz Dekont.txt dosyada olusturulmustur.(Islem yaptiktan hemen sonra dekont ciktisi almayi unutmayin)|\n\n");
			dekont(islem2, tutar); 			 //****DEKONT FONKSÝYONU
		}  
  		printf("1:Ana Menu\n2:Cikis\n");
  	    scanf("%d", &a);
    	system("cls");
	  }
	else
	{      		//case 2 için break
  		a = 2;  							 //amaç eðer tutar 0 dan küçükse programý kapatmak.
	 }  
	break;				//case 2 break
	
case 3 :
	
  	system("cls");
  	odemeislemleri();            		//Odeme iþlemleri fonksiyonunu çaðýrýyorum.
	break;   			// case 3 break

case 4:
	
	paratransferleri();
	break;        //case 4 için break

case 5:
	
	bilgiler();
	printf("Bakiyeniz %d TL'dir.\n", bakiye);
	printf("1:Ana Menu\n2:Cikis\n");
  	scanf("%d", &a);
    system("cls");
	break;   //case 5 break;

case 6:
	
	system("color 0C");
	system("cls");
	printf("Cikis Isleminiz Gerceklestiriliyor.");
	sleep(1);
	system("cls");
	printf("Cikis Isleminiz Gerceklestiriliyor...");
	sleep(1);
	system("cls");
    a = 2;
   	break;
	}
}

int main ()  
{
	int i = 0, data, numaralar[15];
	FILE *dosya;

	if((dosya = fopen("HesapBilgileri.txt", "r")) != NULL) 
	{
		while(!feof(dosya))
		{
			
			fscanf(dosya, "%d", &numaralar[i]);	
			Sifre=numaralar[15];
			
			i++;
		}	
	}
	
	else 
	{
		printf("Dosya Bulunamadi!");
	}
	
	printf("Lutfen sifreyi girin: ");
	scanf("%d", &data);
	i = 1;
	
	while(data != Sifre && i < 3)    // Þifrenin doðru olmama durumu
	{     
		system("color 0C");
		system("cls");
		printf("Hatali sayi girdiniz 3sn sonra tekrar deneyin"),
		sleep(3);
		system("color 07");
		printf("\nSifre: ");
		scanf("%d", &data);
		i++;
	}
	
	if(data != Sifre)    //Þifrenin 3.yanlýþ durumu
	{     
		printf("Yanlis girdiniz program kapatiliyor");
	}
	else    // þifrenin doðru olma durumu
	{              
		system("cls");
		system("color 0A");
		
		while(a < 2)
		{
			islemler();         //islemler fonksiyonunu çaðýrýyorum.
		}
		system("color 0C");
		printf("Program sonlandi");
		//PROGRAM KODLARI BURAYA
	}
	return 0;
}
