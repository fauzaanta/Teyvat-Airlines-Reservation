#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	UAS Dasar Komputer & Praktikum
	Sistem reservasi tiket
	Dibuat oleh:
		Anzillina Rahma                 (2006578192)
		Fauzaan Taufiqurrahman          (2106634805)
		Gusti Rizky Aina                (2006532342)
		Michael Theofilos Sulistio      (2006465243)

*/

void printtic();
void interface();
void kontak();
void textasal();
void text3();
void text4();
void kalkulasi_tiket(int, float, int, int, float*);
void bagian1();
void pembayaran();
void qr();
void load();
void header();
void opening();
void refund();
void rules();
void checkurluggage();

struct{
	char nama[5][256];
	char *bandar;
	char *bandarcode;
	char *tujuancode;
	char *tujuan;
	char *kelas;
	char seat[5][256];
	int date, month, year, n;
}tiket;

struct checkweight{
	char nickname [15];
	int class;
	float luggage;
	float baggage;
	float excess;
	float fee;
};

int main(){
	
	int menu, flag, i, rebook;
	opening();
	system("CLS");
	do{
	system("CLS");
	header();
	interface();
	scanf("%d", &menu);
	switch (menu) {
		case 1:
			if (flag>0){
				printf("You already have a ticket, rebook?(yes 1/no 0)");
				scanf("%d", &rebook);
				if(rebook>0){
					refund();
					system("CLS");
					bagian1();
					pembayaran();
					break;
				}else{
					break;
				}
			}
			system("CLS");
			bagian1();
			pembayaran();
			flag = 2;
			continue;
		case 2:
			system("CLS");
			header();
			rules();
			system("pause");
			system("CLS");
			header();
			checkurluggage();
			system("pause");
			system("CLS");
			continue;
		case 3:
			system("CLS");
			header();
			if(flag>0){
			printf("\nCurrent Ticket Info\n");
			printtic();
		}else{
			printf("\nYou currently do not have any ticket\n\n");
		}
		system("pause");
			continue;
		case 4:
			system("CLS");
			header();
			kontak();
			system("pause");
			break;
		case 5:
			system("CLS");
			header();
			printf("Thank you for using our services\n\nSafe Flight!");
			return 0;
		default:
			printf("wrong number\n");
			break;
	}
	}while(menu!=5);
	return 0;
}

void printtic(){
	int i;
			for(i=0; i<tiket.n; i++){
			printf("=================================================\n");
			printf("Flight %s - %s", tiket.bandarcode, tiket.tujuancode);
			printf("\nName		: %s", tiket.nama[i]);
			printf("\nClass		: %s", tiket.kelas);
			printf("\nSeat 		: %s", tiket.seat[i]);
			printf("\nDate		: %d-%d-%d", tiket.date, tiket.month, tiket.year);
			printf("\n=================================================\n\n");
		}
}

void interface(){
	printf("\nWelcome to Teyvat Airlines's Reservation Program!\n\nHave any question?\nFeel free to contact us on:\n\n");
	printf("Telephone\t: 0804 180 7807\n");
	printf("Twitter\t\t: @realteyvat__\n");
	printf("IG\t\t: @realteyvat__\n");
	printf ("\nSelect the menu below to start your journey with our services:\n");
	printf("1). Book a Ticket\n2). Check Luggage Price\n");
	printf("3). Check Order\n4). User Guidance\n5). Exit\n");
	printf("\nSelect menu: ");
}

void kontak(){
printf("\n>> Tevyat Airline's Reservation Program is a program to help customer use Tevyat Airline's services\n");
printf(">> This program has 5 menu. To use the desireable menu, enter the desireable menu's number\n");
printf(">> To rebook the ticket, you can choose Book a Ticket menu again\n");
printf(">> Refunds for successfully cancelled orders will be processed immediately, based on the payment method used\n\n");

system("pause");
system("CLS");
header();

printf(">> Main Menu\n");
printf("   [1] Book a Ticket\n");
printf("       >> Choose this menu to order Tevyat Airline's ticket\n");
printf("       >> Maximum ammount of ticket to be ordered is 5 ticket\n");
printf("   [2] Check Luggage Price\n");
printf("       >> Choose this menu to calculate your luggage price\n");
printf("   [3] Check Order\n");
printf("       >> Choose this menu to check your current order\n");
printf("   [4] User Guidance\n");
printf("       >> Choose this menu to see our program guide\n");
printf("   [5] Exit\n");
printf("       >> Choose this menu to close the program\n\n");
     
system("pause");
system("CLS");
header();
     
printf(">> Available Airport\n");
printf("   [CGK] Soekarno-Hatta\n");
printf("   [BDJ] Syamsudin Noor\n");
printf("   [DPS] Ngurah Rai\n");
printf("   [SUB] Juanda\n\n");

printf(">> Available Class\n");
printf("   [1] Business Class\n");
printf("   [2] Economy Class\n\n");

printf(">> Available Payment Method\n");
printf("   [1] On Site (Cash)\n");
printf("   [2] E-Banking\n");
printf("       - Mandiri\n");
printf("       - BNI\n");
printf("       - BRI\n");
printf("   [3] QR Code\n");
printf("       - Gopay\n");
printf("       - ShopeePay\n");
printf("       - OVO\n");
printf("       - Dana\n");

}

void textasal(){
	printf("\nAvailable airport:\n\n1. Soekarno Hatta (CGK)\n2. Syamsudinoor (BDJ)\n3. Ngurah Rai (DPS)\n4. Juanda (SUB)\n\nDeparture Airport (enter corresponding number)\t\t: ");
}

void text3(){
	printf("\nBusiness Class Seating\n\n");
	printf("| [A1]   [A2]    [A3]   [A4] |\n");
	printf("| [B1]   [B2]    [B3]   [B4] |\n");
	printf("| [C1]   [C2]    [C3]   [C4] |\n");
	printf("| [D1]   [D2]    [D3]   [D4] |\n");
	printf("\nPlease pick your seat: ");
}

void text4(){
	
	printf("\nEconomy Class Seating\n\n");
	printf("| [E1][E2][E3]  [E4][E5][E6] |\n| [F1][F2][F3]  [F4][F5][F6] |\n");
	printf("| [G1][G2][G3]  [G4][G5][G6] |\n| [H1][H2][H3]  [H4][H5][H6] |\n");
	printf("| [I1][I2][I3]  [I4][I5][I6] |\n| [J1][J2][J3]  [J4][J5][J6] |\n");
	printf("| [K1][K2][K3]  [K4][K5][K6] |\n| [L1][L2][L3]  [L4][L5][L6] |\n");
	printf("| [M1][M2][M3]  [M4][M5][M6] |\n| [N1][N2][N3]  [N4][N5][N6] |\n");
	printf("\nPlease pick your seat: ");
	
}

void kalkulasi_tiket(int jumlah, float kelas, int pes1, int pes2, float *fprice){
	*fprice = ((pes1+pes2)*kelas)*jumlah;
}

void bagian1(){
	int a, b, c, d, i, hargapesawat1, hargapesawat2, handlingerror, j, flagg;
	float hargakelas, fprice;

	do{
	system("CLS");
	header();
	textasal();
	scanf("%d", &a);
	switch (a){
		case 1:
			tiket.bandar = "Soekarno-Hatta";
			tiket.bandarcode = "CGK";
			hargapesawat1 = 120;
			break;
		case 2:
			tiket.bandar = "Syamsudin Noor";
			tiket.bandarcode = "BDJ";
			hargapesawat1 = 130;
			break;
		case 3:
			tiket.bandar = "Ngurah Rai";
			tiket.bandarcode = "DPS";
			hargapesawat1 = 140;
			break;
		case 4:
			tiket.bandar = "Juanda";
			tiket.bandarcode = "SUB";
			hargapesawat1 = 150;
			break;
		default:
			printf("\nError. Contact the operator\n");
			break;}

	do{
	printf("Destination Airport (enter corresponding number)\t: ");
	scanf("%d", &c);
	switch (c){
		case 1:
			tiket.tujuan = "Soekarno-Hatta";
			tiket.tujuancode = "CGK";
			hargapesawat2 = 120;
			break;
		case 2:
			tiket.tujuan = "Syamsudin Noor";
			tiket.tujuancode = "BDJ";
			hargapesawat2 = 130;
			break;
		case 3:
			tiket.tujuan = "Ngurah Rai";
			tiket.tujuancode = "DPS";
			hargapesawat2 = 140;
			break;
		case 4:
			tiket.tujuan = "Juanda";
			tiket.tujuancode = "SUB";
			hargapesawat2 = 150;
			break;
		default:
			printf("\nError. Contact the operator\n");
			break;
	}
	if(a==c){
		printf("\nDeparture and destination airport can't be same\n");
	}
	}while(a==c);
	
	printf("Processing...");
	sleep(2);
	system("CLS");
 	header();
 	printf ("\nDeparture schedule information:\n");
 	do{ 
 		printf("\nEnter departure date (dd): ");
 		scanf ("%d", &tiket.date);
 		if (tiket.date>31||tiket.date<1){
  			printf ("Please input the correct date");
 		}
 	}while(tiket.date>31||tiket.date<1);
 	do{
 		printf ("Enter departure month (mm): ");
 		scanf ("%d", &tiket.month);
 		if (tiket.month>12||tiket.month<1){
  			printf ("Please input the correct month\n");
  		}
 	}while (tiket.month>12||tiket.month<1);
	do{
 		printf ("Enter departure year (yyyy): ");
 		scanf ("%d", &tiket.year);
 		if (tiket.year<2022||tiket.year>2025){
  			printf ("We only accept flight from 2022 until 2025, please try again\n"); 
 		}
 	}while (tiket.year<2022||tiket.year>2025);
 	
	system("CLS");
	header();
	printf("\nChoose class:\n\n1. Business Class\n2. Economy Class\n\nEnter Class (corresponding number) : ");
	scanf("%d", &b);
	do{
	printf ("\nEnter how many person flying: ");
	scanf ("%d", &tiket.n);
	if (tiket.n>5)
		printf("Maximum ticket to book is 5, please try again\n");
	if (tiket.n<1){
		printf("Minimum ticket to book is 1, please try again\n");
	}
	}while(tiket.n>5 || tiket.n<1);
	printf("Processing...");
	sleep(2);
			system("CLS");
			header();
			printf ("\nSeat and personal information\n");
			for (i=0; i<tiket.n; i++){
				printf ("\nEnter person name %d: ", i+1);
				scanf(" %255[^\n]s", &tiket.nama[i]);
				do{
					if(b<2){
					tiket.kelas = "Business";
					hargakelas = 1.3;
					text3();
					scanf(" %[^\n]%*c", &tiket.seat[i]);
					if(i>0){
						for(j=0;j<=i-1;j++){
							if(strcmp(tiket.seat[i],tiket.seat[j])==0){
								system("CLS");
								header();
								printf("\nSorry, the seat has been booked\n");
								flagg=1;
								break;
							}else{
								flagg=0;
							}
						}
					}
					continue;
					}else{
					tiket.kelas = "Economy";
					hargakelas = 1;
					text4();
					scanf(" %[^\n]%*c", &tiket.seat[i]);
					if(i>0){
						for(j=0;j<=i-1;j++){
							if(strcmp(tiket.seat[i],tiket.seat[j])==0){
								system("CLS");
								header();
								printf("\nSorry, the seat has been booked\n");
								flagg=1;
								break;
							}else{
								flagg=0;
							}
						}
					}
					continue;
					}
				}while(flagg>0);
			}
			printf("Processing...");
			sleep(2);
	
	system("CLS");
	header();
	printf("\nTicket Info:\n\nPlease recheck the information written on your ticket\n\n");
	printtic();
	
	printf("Correct? (press 0 if not, 1 if correct)");
	scanf("%d", &handlingerror);
	
	}while(handlingerror==0);
	kalkulasi_tiket(tiket.n, hargakelas, hargapesawat1, hargapesawat2, &fprice);
	system("CLS");
	header();
	
	printf("\nThank you for choosing to fly with us\n\nHere is your ticket price: %.1f", fprice);
}

void pembayaran(){

	int menu, pilbank, pilqr;
	printf("\n\nPayment Method:\n1. On Site (Cash)\n2. E-Banking\n3. QR Code\n");
	printf("\nPlease select: ");
	scanf("%d", &menu);
	
	switch(menu){
		case 1:
  			system("CLS");
   			header();
   			printf("\nPlease state your name and booking code at the airport counter\n\n");
   			printf("Booking Code: %s%s-%d%d%d%d%c\n", tiket.bandarcode, tiket.tujuancode, tiket.n, tiket.year, tiket.month, tiket.date, tiket.nama[0][0]);
   			system("pause");
    		break;
 		case 2:
 			system("CLS");
 			header();
 			printf("\nAvailable Bank:\n1. Mandiri\n2. BNI\n3. BRI\n\nPlease select a Bank: ");
 			scanf("%d", &pilbank);
 			switch(pilbank){
 				case 1:
 					printf("\nVA Number Mandiri: 0080087348261\n");
 					system("pause");
 					system("CLS");
 					header();
 					load();
 					break;
 				case 2:
 					printf("\nVA Number BNI: 00920087348261\n");
 					system("pause");
 					system("CLS");
 					header();
 					load();
 					break;
 				case 3:
 					printf("\nVA Number BNI: 00920087348261\n");
 					system("pause");
 					system("CLS");
 					header();
 					load();
 					break;
				default:
					printf("Error");
					break;}
 			break;
 		case 3:
 			system("CLS");
 			header();
 			printf("\nAvailable E-Wallet:\n1. Gopay\n2. ShopeePay\n3. Ovo\n4. Dana\n\nPlease select a wallet: ");
 			scanf("%d", &pilqr);
 			switch(pilqr){
 				case 1:
 					printf("QR for Gopay:\n");
 					qr();
 					break;
 				case 2:
 					printf("QR for ShopeePay:\n");
 					qr();
 					break;
 				case 3:
 					printf("QR for Ovo:\n");
 					qr();
 					break;
				case 4:
					printf("QR for Dana:\n");
 					qr();
 					break;	
 				default:
 					printf("Error");
 					break;
			 }
			 break;
 		default:
 			printf("Error");
 			break;
	}
	
}

void qr(){
			printf(" _______ _ ___ _______ \n");
 			printf(" ¦ ___ ¦ __¯¦  ¦ ___ ¦ \n");
			printf(" ¦ ¦¦¦ ¦ ¦¯ _¯ ¦ ¦¦¦ ¦ \n");
 			printf(" ¦_____¦ _¯¦¯¦ ¦_____¦ \n");
			printf(" ____  _ ___¦¦_  ___ _ \n");
			printf("   _  ¯__¯¦¯ ¦¯  ¦¯ ¯_¦\n"); 
 			printf(" _ ¦¯¦__¦¯¦¯¯_ __¯¯ ¯_ \n");
 			printf(" _______ ¯¦_¦_ _______ \n");
 			printf(" ¦ ___ ¦  ¯¦ _¦ _¦_¦¯¯ \n");
 			printf(" ¦ ¦¦¦ ¦ ¦_¦ _¦_   _¯ |\n");
 			printf(" ¦_____¦ ¦ ¯  ¦¦¯_ _ ¯ \n");
 			system("pause");
 			system("CLS");
 			header();
 			load();
}

void load(){
	int i;
 			printf("Processing Payment");
 			for (i=0; i<3; i++){
 				printf(" .");
 				sleep(1);
			 }
			 printf("\n\nPayment Successful!\nRedirecting to menu");
			 sleep(3);		
}

void header(){
	printf("\t\t=============================================\n");
	printf("\t\t          ||   Tevyat Airline   ||\n");
	printf("\t\t=============================================\n\n");}

void opening(){
	printf("\nUAS Dasar Komputer & Praktikum\n\n");
	printf("Dibuat oleh:\n");
	printf("Anzillina Rahma			(2006578192)\n");
	printf("Fauzaan Taufiqurrahman		(2106634805)\n");
	printf("Gusti Rizky Aina		(2006532342)\n");
	printf("Michael Theofilos Sulistio	(2006465243)\n");
	system("pause");
}

void refund(){
	int i;
	system("CLS");
	header();
	printf("Processing Refund");
	for (i=0;i<4;i++){
		printf(" .");
		sleep(1);
	}
	printf("\n\nRefund Successful! \nPlease check with your payment provider for confirmation\n\n");
	system("pause");
}

void rules(){
	int i;
	printf("\n\n\t\t*** Tevyat Airline Luggage and Baggage Allowance Rules ***\n\n");
	for(i=1; i<=8; i++){
		if(i == 1 || i == 4 || i == 6 || i == 8){
			printf("+-----------------------------------------------------------------------------------------------+\n");
		} else if(i == 2){
			printf("|\tClass\t\t|\tHand Luggage Weight\t|\tCheck-in Baggage Weight\t\t|\n");
		} else if(i == 3){
			printf("|\t\t\t|\t        (Kg)       \t|\t         (Kg)         \t\t|\n");
		} else if(i == 5){
			printf("|\tBusiness\t|\t      2 x 10       \t|\t        2 x 32         \t\t|\n");
		} else{
			printf("|\tEconomic\t|\t      1 x 10       \t|\t        1 x 32         \t\t|\n");
		}
	}
	printf("The fee for exceeding the weight is IDR 50.000\n\n");
}

void checkurluggage(){
	int sum, i, j, k, m, ebag, elug;
	struct checkweight pass[100];
	system("CLS");
	header();
	printf("How many people want to check their luggage?\n> ");
	scanf("%d", &sum);
	printf("\n-------------------------------------------------------\n");
	for(i=1; i<=sum; i++){
		printf("Enter person name %d : ", i);
		scanf("%s", &pass[i].nickname);
		printf("\nWhat is your ticket class?\n1) Business\n2) Economic\nEnter Class: ");
		scanf("%d", &pass[i].class);
		printf("\nHand Luggage in (Kg) : ");
		scanf("%f", &pass[i].luggage);
		printf("Baggage in (Kg) : ");
		scanf("%f", &pass[i].baggage);
		printf("\n-------------------------------------------------------\n");
		switch(pass[i].class){
			case 1:
				ebag = pass[i].baggage-64;
				if (ebag<0){
					ebag=0;
				}
				elug = pass[i].luggage-20;
				if (elug<0){
					elug=0;
				}
				pass[i].excess = ebag + elug;
				if(pass[i].excess >0){
					pass[i].fee = pass[i].excess * 50000;
				} else if(pass[i].excess<0){
					pass[i].fee = 0;
					pass[i].excess = 0;
				}
				continue;
			case 2:
				ebag = pass[i].baggage-32;
				if (ebag<0){
					ebag=0;
				}
				elug = pass[i].luggage-10;
				if (elug<0){
					elug=0;
				}
				pass[i].excess = ebag + elug;
				if(pass[i].excess > 0){
					pass[i].fee = pass[i].excess * 50000;
				} else if(pass[i].excess<0){
					pass[i].fee = 0;
					pass[i].excess = 0;
				}
		}
	}
	printf("Processing...");
	sleep(2);
	system("CLS");
	header();
	k=1;
	for(j=1; j<= (4+(2*sum)); j++){
		if(j == 1 || j == 4){
			printf("+-------------------------------------------------------------------------------------------------------+\n");
		} else if(j == 2){
			printf("|\tNo\t|\tNickname\t|\t\tExcess\t\t|\t\tFee\t\t|\n");
		} else if(j == 3){
			printf("|\t  \t|\t        \t|\t\t (Kg) \t\t|\t\tIDR\t\t|\n");
		} else if((j%2)==1){
			printf("|\t%d\t|\t%s\t\t|\t\t%.0f\t\t|\t\t%.0f\t\t|\n", (k), pass[k].nickname, pass[k].excess, pass[k].fee);
			k = k+1;
		} else if((j%2)==0){
			printf("+-------------------------------------------------------------------------------------------------------+\n");
		}
	}
}
