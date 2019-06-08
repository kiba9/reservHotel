#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <strings.h>
#include <time.h>
#include <locale.h>
#include "head.h"
#include <Tchar.h>



FILE* fclient = NULL;
FILE* fsclient = NULL;
float tps = 0.001;
int choixHotel;


HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.




void LoadScreen() {

    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

    // Change the window title:
    //SetConsoleTitle(TEXT("Win32 Console Control Demo"));

    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 80, 50};

    // Change the console window size:
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

    // Create a COORD to hold the buffer size:
    COORD bufferSize = {130, 400};

    // Change the internal buffer size:
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    /*int i;
    for(i =0; i<70;i++){
        printf("hello\n\n");
    }*/

}

void CreateCarre(int i, int j, int x, int y){
    int i2,j2;
    for(i2 = 0; i2 < i; i2++){
        j2=0;
        for (j2 = 0; j2 < j; j2++){
            Wait(0.0005);
            gotoxy(i2+x,j2+y);
            printf(" ");
        }
    }
}

void trait(int x){
    int i;
    for(i = 0; i < x; i++){
        printf("_");
    }
}

void color(int t,int f){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void gotoxy(int x,int y)
{
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD C;
	C.X=(SHORT)x;
	C.Y=(SHORT)y;
	SetConsoleCursorPosition(H,C);
}

void Wait(float temps){
    clock_t arrivee = clock() + (temps * CLOCKS_PER_SEC);
    while(clock() < arrivee);
}


void Login(){
    int v = 1;
    char mdp[15], mdp2[15] = "angecena";

    color(0,7);
    CreateCarre(50,15,75,15);
    color(0,7);

    do{
    gotoxy(85,20);
    printf("Nom D'Utilisateur: ");
    gotoxy(85,23);
    printf("Mot De Passe: ");
    gotoxy(105,20);
    color(15,0);
    fgets(user, 15, stdin);
    gotoxy(100, 23);
    color(7,7);
    scanf("%s",mdp);
    color(0,7);
    v = strcmp(mdp, mdp2);
    if( v != 0){
        gotoxy(95,25);
        color(12,7);
        printf("MOT DE PASSE INCORRECTE\a");
    } else {
        gotoxy(95,25);
        color(10,7);
        printf("MOT DE PASSE CORRECTE  ");

    }
    color(0,7);
   }while( v !=0 );

    gotoxy(85, 28);
    printf("Bonjour et Bienvenu %s", user);
}

void Add_client(){


        setlocale (LC_ALL,"");


        gotoxy(7,17);
        printf("Entrer le nom: ");
		scanf("%s", cltX.Nom);

		gotoxy(7,19);
		printf("Entrer le numero de la Cni: ");
		scanf("%ld", &cltX.N_CNI);

		gotoxy(7,21);
		printf("Entrer l'adresse: ");
		scanf("%s", cltX.Adresse);

		gotoxy(7,23);
		printf("Entrer Numero de Telephone: ");
		scanf("%s", cltX.Telephone);

		gotoxy(7,25);
		printf("Entrer Nombre de chambre Voulu: ");
		scanf("%d", &cltX.NbChambre);

		gotoxy(7,27);
		printf("Choissisez Un Hotel: ");
		gotoxy(38,28);
		printf("1 - MontFebe  2 - Hilton");
		gotoxy(38,29);
		printf("3 - Djeuga  4 - La Falaise");
		gotoxy(29,27);
		scanf("%d", &choixHotel);

		 switch (choixHotel){
         case 1:
             sprintf(cltX.NomHotel, "%s","Mont Febe" );
         break;
         case 2:
            sprintf(cltX.NomHotel, "%s","Hilton" );
         break;
         case 3:
            sprintf(cltX.NomHotel, "%s","Djeuga" );
         break;
         case 4:
            sprintf(cltX.NomHotel, "%s","La Falaise" );
         break;
         default:
             scanf("%s", cltX.NomHotel);
		 }


		gotoxy(7,31);
		printf("Entrer le date de reservation: ");
		scanf("%d", &cltX.Date.jour);
		scanf("%s", cltX.Date.mois);
		scanf("%d", &cltX.Date.annee);

		fclient = fopen("reservation.clt", "ab+");
		fwrite(&cltX, sizeof(cltX), 1, fclient);
		fclose(fclient);
		printf("\n\n");
}


void Affiche_List(){
    setlocale (LC_ALL,"");
	Client c;
	int t=0;
	int n = 47;


        gotoxy(48,42);
        color(15,8);
        printf("LISTE DES RESERVATIONS CLIENTS");

        color(0,15);
        CreateCarre(15,CountList()*4,5,45);
        gotoxy(7,46);
        printf("NOMS");
        gotoxy(5,48);
        trait(15);

        color(0,7);
        CreateCarre(25,CountList()*4,20,45);
        gotoxy(22,46);
        printf("NUMERO DE CNI");
        gotoxy(20,48);
        trait(25);

        color(0,15);
        CreateCarre(20,CountList()*4,45,45);
        gotoxy(47,46);
        printf("ADRESE");
        gotoxy(45,48);
        trait(20);

        color(0,7);
        CreateCarre(25,CountList()*4,65,45);
        gotoxy(67,46);
        printf("DATE DE RESRVATION");
        gotoxy(65,48);
        trait(25);

        color(0,15);
        CreateCarre(15,CountList()*4,90,45);
        gotoxy(92,46);
        printf("NUMERO TEL");
        gotoxy(90,48);
        trait(15);

        color(0,7);
        CreateCarre(15,CountList()*4,105,45);
        gotoxy(107,46);
        printf("HOTEL");
        gotoxy(105,48);
        trait(15);

        color(0,15);
        CreateCarre(8,CountList()*4, 120,45);
        gotoxy(122,46);
        printf("NB CH");
        gotoxy(120,48);
        trait(8);

        fclient = fopen("reservation.clt", "rb");
		rewind(fclient);
		fread(&c, sizeof(c), 1, fclient);

		while(!feof(fclient)) {
        t +=1;

        color(0,15);
        gotoxy(7,n+3);
		printf("%s",  c.Nom);
		gotoxy(5,n+5);
		trait(15);

        color(0,7);
        gotoxy(22,n+3);
		printf("%ld",  c.N_CNI);
		gotoxy(20,n+5);
        trait(25);

        color(0,15);
        gotoxy(47,n+3);
		printf("%s",  c.Adresse);
		gotoxy(45,n+5);
        trait(20);


        color(0,7);
        gotoxy(67,n+3);
		printf("%d/%s/%d",  c.Date.jour, c.Date.mois, c.Date.annee);
		gotoxy(65,n+5);
        trait(25);


        color(0,15);
        gotoxy(92,n+3);
		printf("%s",  c.Telephone);
		gotoxy(90,n+5);
        trait(20);


        color(0,7);
        gotoxy(106,n+3);
		printf("%s",  c.NomHotel);
		gotoxy(105,n+5);
        trait(15);


        color(0,15);
        gotoxy(122,n+3);
		printf("%d",  c.NbChambre);
		gotoxy(120,n+5);
        trait(8);

        n +=4;

		fread(&c, sizeof(c), 1, fclient);
		}
        fclose(fclient);
		if( t == 0){
		    gotoxy(70,34);
            system("pause");
            color(0,15);
            CreateCarre(60,25,65,10);
            color(12,15);
            gotoxy(45,50);
            printf("AUCUNE RESERVATION LISTE VIDE");
            color(15,3);
		}
}


int CountList(){
	Client c;
	int t=0;


        fclient = fopen("reservation.clt", "rb");
		rewind(fclient);
		fread(&c, sizeof(c), 1, fclient);

		while(!feof(fclient)) {
        t +=1;
		fread(&c, sizeof(c), 1, fclient);
		}
        fclose(fclient);

        return t+1;
}


void Affiche_Rserv(long int Mat){

    setlocale (LC_ALL,"");
	Client c;
	int trouve = 0;

    fclient = fopen("reservation.clt", "rb");
	rewind(fclient);
    fread(&c, sizeof(c), 1, fclient);
	while(!feof(fclient) && trouve == 0) {

        if(c.N_CNI == Mat){
            trouve = 1;
        }
        fread(&c, sizeof(c), 1, fclient);
    }
    fclose(fclient);

    if(trouve == 1){
        gotoxy(67,17);
		printf("les informations sur Ce client sont:           ");

        gotoxy(67,19);
		printf("Nom Du CLient: %s",  c.Nom);

		gotoxy(67,21);
		printf("Numero de CNI: %ld",  c.N_CNI);

		gotoxy(67,23);
		printf("Adresse: %s",  c.Adresse);

		gotoxy(67,25);
		printf("Date de reservation: %d - %s - %d",  c.Date.jour, c.Date.mois, c.Date.annee);

		gotoxy(67,27);
		printf("Numero de Téléphone: %s",  c.Telephone);

		gotoxy(67,29);
		printf("Hotel De reservation: %s",  c.NomHotel);

		gotoxy(67,31);
		printf("Nombre de chambre : %d",  c.NbChambre);
    } else {

        color(12,15);
        gotoxy(70,33);
        printf("AUCUNE CORRESPONDANCE POUR LA CNI N°: %ld", Mat);
        color(15,3);
    }

}

int Supprime_Client(long int numcni){
    Client c;
    int t=1;

    if(numcni ==0){
    gotoxy(67,10);
    printf("Entrer le numero de la Cni du client à supprimer: ");
    scanf("%ld", &numcni);
    Affiche_Rserv(numcni);
    }

    fclient = fopen("reservation.clt", "rb");
	rewind(fclient);

    fread(&c, sizeof(c), 1, fclient);

	while(!feof(fclient)) {

        fsclient = fopen("recopie.clt", "ab+");
        if(numcni != c.N_CNI){
            fwrite(&c, sizeof(c), 1, fsclient);
            t=0;
        }fclose(fsclient);

        fread(&c, sizeof(c), 1, fclient);
        }

    if(t==1){
      fsclient = fopen("recopie.clt", "ab+");
      fclose(fsclient);
    }
    fclose(fclient);
    remove("reservation.clt");
    rename("recopie.clt", "reservation.clt");
    remove("recopie.clt");

return t;
}

void Modif_Reserv(long int numcni){
    Client c;
    int trouve = 0;

    if(numcni == 0){
    gotoxy(68,17);
    color(0,15);
    printf("Entrer le numero de la Cni du client à modifier: ");
    gotoxy(68,19);
    scanf("%ld", &numcni);
    }

    fclient = fopen("reservation.clt", "rb+");
	rewind(fclient);
    fread(&c, sizeof(c), 1, fclient);
	while(!feof(fclient) && trouve ==0) {

        if(numcni == c.N_CNI){
            trouve = 1;
        gotoxy(7,17);
		printf("les informations sur Ce client sont: ");

        gotoxy(7,19);
		printf("Nom Du CLient: %s",  c.Nom);

		gotoxy(7,21);
		printf("Numero de CNI: %ld",  c.N_CNI);

		gotoxy(7,23);
		printf("Adresse: %s",  c.Adresse);

		gotoxy(7,25);
		printf("Date de reservation: %d - %s - %d",  c.Date.jour, c.Date.mois, c.Date.annee);

		gotoxy(7,27);
		printf("Numero de Téléphone: %s",  c.Telephone);

		gotoxy(7,29);
		printf("Hotel De reservation: %s",  c.NomHotel);

		gotoxy(7,31);
		printf("Nombre de chambre : %d",  c.NbChambre);

        }

        fread(&c, sizeof(c), 1, fclient);
    }
    fclose(fclient);

    if(trouve == 1){
        Supprime_Client(c.N_CNI);

        gotoxy(67,19);
        printf("Entrer le nom: ");
		scanf("%s", c.Nom);

		gotoxy(67,21);
		printf("Entrer le numero de la Cni: ");
		scanf("%ld", &c.N_CNI);

		gotoxy(67,23);
		printf("Entrer l'adresse: ");
		scanf("%s", c.Adresse);

		gotoxy(67,25);
		printf("Entrer Numero de Telephone: ");
		scanf("%s", c.Telephone);

		gotoxy(67,27);
		printf("Entrer Nombre de chambre Voulu: ");
		scanf("%d", &c.NbChambre);

		gotoxy(67,29);
		printf("Choissisez Un Hotel: ");
		gotoxy(96,30);
		printf("1 - MontFebe  2 - Hilton");
		gotoxy(96,31);
		printf("3 - Djeuga  4 - La Falaise");
		gotoxy(67,29);
		scanf("%d", &choixHotel);

		 switch (choixHotel){
         case 1:
             sprintf(c.NomHotel, "%s","Mont Febe" );
         break;
         case 2:
            sprintf(c.NomHotel, "%s","Hilton" );
         break;
         case 3:
            sprintf(c.NomHotel, "%s","Djeuga" );
         break;
         case 4:
            sprintf(c.NomHotel, "%s","La Falaise" );
         break;
         default:
             scanf("%s", c.NomHotel);
		 }

		gotoxy(67,33);
		printf("Entrer le date de reservation: ");
		scanf("%d", &c.Date.jour);
		scanf("%s", c.Date.mois);
		scanf("%d", &c.Date.annee);

		fclient = fopen("reservation.clt", "ab+");
		fwrite(&c, sizeof(c), 1, fclient);
		fclose(fclient);
    }
    if(trouve == 0){
        CreateCarre(65,5,7,37);
        gotoxy(18,25);
        color(12,7);
        printf("PAS(PLUS) DE CORRESPONDANCE AVEC CETTE CNI");
        color(0,3);
    }

}

void Supprime_List(){
    fsclient = fopen("recopie.clt", "ab+");
    fclose(fsclient);

    remove("reservation.clt");
    rename("recopie.clt", "reservation.clt");
    remove("recopie.clt");

}
/*
void Historique(char* Messg){
}*/
