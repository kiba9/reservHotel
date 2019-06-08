#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "head.h"

int main(int argc, char *argv[]){



    int choixMenu, choix, c1=0, c2=7, log = 0, option;
    long int Mat;

    system("cls");
    system("color 3f");
    system("TITLE SLEPWELL.EXE");
    LoadScreen();
    setlocale(LC_ALL,"");



    Debut: do{
                color(15,3);
                gotoxy(25,2);
                printf("----------------------------- RESERVATION HOTEL  ------------------------------");

                color(3,15);
                CreateCarre(130,6,0,4);

            gotoxy(45,5);
            color(3,15);
            printf("/**** UN PROJET DE: SONG CEDRIC ****/");

            gotoxy(60,7);
            printf("LOTCHOUANG CECILE");

            gotoxy(25,9);
            printf("************************** Supervisé Par: Mlle FEUDJIO *************************");
            color(15,3);

             if(log == 0){
            Login();
            log = 1;
            }

            //Menu 1. Enregistrer un Nouveau Client

                color(0,7);
                CreateCarre(40,5,5,15);

                gotoxy(7,17);
                printf("1. Enregistrer un Nouveau Client");


            //Menu 2. Afficher Reservation

                color(0,8);
                CreateCarre(40,5,5,20);

                color(15,8);
                gotoxy(7,22);
                printf("2. Afficher Reservation");


            //Menu 3. Modifier Reservation

                color(0,7);
                CreateCarre(40,5,5,25);

                gotoxy(7,27);
                printf("3. Modifier Reservation");


            //Menu 4. Supprimer Reservation

                color(0,8);
                CreateCarre(40,5,5,30);


                color(15,8);
                gotoxy(7,32);
                printf("4. Supprimer Reservation Client");


            //Menu 5. quittez

                color(0,7);
                CreateCarre(40,5,5,35);

                gotoxy(7,37);
                printf("5. Quittez");


                printf("\n\n\n\n");


            //Choix.

                color(c1,c2);
                CreateCarre(40,5,60,35);

                gotoxy(67,37);
                printf("Faites Votre Choix: ");
                scanf("%d", &choixMenu);



            switch (choixMenu){


                case 1:
                    do {
                    system("cls");
                    system("color 3f");

                    color(3,15);
                    CreateCarre(80,5,25,4);

                    gotoxy(45,6);
                    printf("/=== Enregistrement Reservation Client ===/");


                    color(0,7);
                    CreateCarre(60,25,5,15);

                    Add_client();

                    color(0,8);
                    CreateCarre(60,25,65,15);


                    Affiche_Rserv(cltX.N_CNI);

                    color(0,10);
                    gotoxy(10,35);
                    printf("reservation enregistrer");
                    color(15,3);

                    color(0,15);
                    CreateCarre(53,5,74,41);

                        do{

                        do{
                            gotoxy(76,43);
                            printf("Voullez vous Modifier ? 1=Oui /0=Non: ");
                            scanf("%d",&choix);
                        }while(choix < 0 || choix >= 2);

                        if(choix == 1){

                            color(0,15);
                            CreateCarre(60,25,5,15);
                            Modif_Reserv(cltX.N_CNI);

                        }
                        }while(choix ==1);

                    color(9,15);
                    CreateCarre(66,5,7,41);

                        do{
                            gotoxy(9,43);
                            printf("Voullez vous Faire Un Nouvlle Enregistrement ? 1=Oui /0=Non: ");
                            scanf("%d",&choix);
                        }while(choix < 0 || choix >= 2);
                    }while(choix == 1);
                    system("cls");
                    system("color 3f");

                break;

                case 2:

                    do{
                    system("cls");
                    system("color 3f");

                    color(3,15);
                    CreateCarre(80,5,25,4);

                    gotoxy(45,6);
                    printf("/=== Menu D'Affichage Des Reservation ===/");
                    color(15,3);




                    color(0,7);
                    CreateCarre(40,10,5,15);


                    color(0,7);
                    gotoxy(7,17);
                    printf("1.) Afficher toute la liste");
                    gotoxy(7,21);
                    printf("2.) Afficher Une reservation");

                    color(0,8);
                    CreateCarre(40,5,5,30);


                    color(15,8);
                    do{
                    gotoxy(7,32);
                    printf("Selectionner Une Option:  ");
                    scanf("%d", &option);
                    } while(option <= 0 || option > 2);

                    if(option == 2 ){
                    color(0,15);
                    CreateCarre(60,20,65,15);

                                gotoxy(68,17);
                                printf("Entrer Le Numero De CNI Du Client à Afficher:");
                                gotoxy(68,19);
                                scanf("%ld", &Mat);
                                Affiche_Rserv(Mat);

                        } else if (option == 1){

                            //color(7,0);

                            //CreateCarre(100,0.5,5,48);

                        Affiche_List();
                        }

                        color(0,15);
                        CreateCarre(52,5,5,35);


                        do{
                            gotoxy(7,37);
                            printf("Voullez vous Afficher de nouveau 1=Oui /0=Non:  ");
                            scanf("%d",&choix);
                        }while(choix < 0 || choix >= 2);

                    }while (choix == 1);
                    system("cls");
                    system("color 3f");
                break;

                case 3:
                        do{
                            system("cls");
                            system("color 3f");

                            color(3,15);
                            CreateCarre(80,5,25,4);

                            gotoxy(45,6);
                            printf("/=== Modification Des Reservation ===/");
                            color(15,3);


                            color(0,15);
                            CreateCarre(60,20,65,15);

                                gotoxy(68,17);
                                printf("Entrer Le Numero De CNI Du Client à Afficher:");
                                gotoxy(68,19);
                                scanf("%ld", &Mat);

                            color(0,7);
                            CreateCarre(60,20,5,15);

                                /*gotoxy(7,17);
                                printf("Les Information De Cette Reservation Sont:");
                                gotoxy(7,19);*/
                                //Affiche_Rserv(Mat);

                                Modif_Reserv(Mat);

                            do{
                            gotoxy(8,39);
                            color(0,7);
                            printf("Voullez vous Faire Une Autre Modification ? 1=Oui /0=Non:  ");
                            scanf("%d",&choix);
                            }while(choix < 0 || choix >= 2);

                        }while(choix ==1);
                        system("cls");
                        system("color 3f");
                break;

                case 4:

                    do{
                    system("cls");
                    system("color 3f");

                    color(3,15);
                    CreateCarre(80,5,25,4);

                    gotoxy(45,6);
                    printf("/=== Suppression Des Reservation Client ===/");
                    color(15,3);

                        color(0,7);
                        CreateCarre(40,10,5,15);


                        color(0,7);
                        gotoxy(7,17);
                        printf("[1] - Supprimer toutes la liste");
                        gotoxy(7,21);
                        printf("[2] - Supprimer Une Reservation Client");

                        color(0,8);
                        CreateCarre(40,5,5,30);
                        color(15,8);

                        do{
                        gotoxy(7,32);
                        printf("Selectionner Une Option:  ");
                        scanf("%d", &option);
                        } while(option <= 0 || option > 2);

                        if(option == 1){

                        color(0,3);
                        CreateCarre(60,25,65,10);
                        Supprime_List();
                        gotoxy(80,20);
                        color(10,3);
                        printf("LISTE SUPPRIMÉ AVEC SUCCES");
                        color(15,3);
                        gotoxy(70,25);
                        }

                        if(option == 2){
                        color(3,15);
                        CreateCarre(60,25,65,10);
                        if(Supprime_Client(0)==1){
                            gotoxy(70,30);
                            color(15,15);
                            printf("RESERVATION CLIENT SUPPRIMÉ");
                            } else {
                              gotoxy(75,33);
                              color(10,15);
                              printf("RESERVATION CLIENT SUPPRIMÉ");
                            }
                        }
                        Affiche_List();
                        do{
                            color(0,7);
                            CreateCarre(60,5,7,36);
                            gotoxy(9,38);
                            printf("Voullez vous Faire une autre Suppression 1=Oui /0=Non:  ");
                            scanf("%d",&choix);
                        }while(choix < 0 || choix >= 2);

                    }while (choix == 1);
                    system("cls");
                    system("color 3f");

                break;

                case 5:
                    system("cls");
                    system("color 3f");

                    color(3,15);
                    CreateCarre(50,20,40,15);

                    gotoxy(50,17);
                    printf("/FERMETURE DU PROGRAMME GOODBYE/");
                    color(0,3);
                    CreateCarre(50,4,40,20);
                    do{
                        gotoxy(50,22);
                        printf("1=CONFIRMER    |    0=ANNULER:  ");
                        scanf("%d", &choix);
                    }while(choix < 0 || choix >= 2);

                    if(choix == 1){

                    gotoxy(45,30);
                    color(3,15);
                    system("pause");
                    color(15,3);
                    CreateCarre(50,20,40,15);
                    system("color 0f");
                    gotoxy(5,1);
                    } else {
                    system("cls");
                    system("color 3f");
                    goto Debut;

                    }
                break;

                default:
                    system("cls");
                    system("color 3f");

                    c1=0;
                    c2=12;
                    gotoxy(60,34);
                    color(0,12);
                    printf("\aCHOIX ERRONÉ ");
                    /*CreateCarre(40,5,60,25);
                    gotoxy(67,27);
                    printf("CHOIX ERRONÉ");*/

            }

                printf("\n\n\n\n");

            }while(choixMenu != 5);

    return 0;
}
