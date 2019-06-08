#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct DDR{
		int jour;
		char mois[10];
		int annee;
	}DDR;

	typedef struct Client{
		long int N_CNI;
		char Nom[20];
		char Adresse[20];
		char Telephone[14];
		char NomHotel[20];
		int NbChambre;
		DDR Date;
	}Client;

    Client cltX;
    char user[16];


    void Login();

    void trait(int x);

    void gotoxy(int x,int y);

    void color(int t,int f);

    void Add_client();

    void Affiche_List();

    void Affiche_Rserv(long int Mat);

    int Supprime_Client(long int numcni);

    void Supprime_List();

    void Modif_Reserv(long int numcni);

    void Wait(float temps);

    void CreateCarre(int i, int j, int x, int y);

    void LoadScreen();

    int CountList();

#endif // HEAD_H_INCLUDED
