#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//à
int main()
{

    system("color 03"); //0 la valeur du couleur pour de background et 3 la valeur du couleur de texte
    srand(time(NULL)); // pour s'assurer qu'à chaque fois que vous ouvrez le programme, un nouveau caractère aléatoire apparaît

    printf("                               J E U   D E   M O T S\n");
    printf("\n\n\n1- Jouer à un\n");
    printf("2- Jouer à un sous un contrainte de temps\n");
    printf("3- Jouer à deux\n");
    printf("0- quitter\n");

    int choix;
    do{
    printf("                                    Votre choix = ");
    scanf("%i",&choix);}
    while(choix>3 || choix<0);

    if(choix==1){
    int taille;
    do{
    printf("\n\nTapez la taille (7/8/9) du mot le plus long à retrouver = ");
    scanf("%i",&taille);
    if (taille>9 || taille<7){
    printf("La taille que vous avez saisie est erronée!\n");};
    }
    while(taille>9 || taille<7);
    printf("\n");

    char lettres [70]="";
    char lettresobli [70]="";
    char choix2;
    int i;
    for(i=1;i<=taille;i++){
    do{
    printf("Caractére %i : Consonne (c/C) ou Voyelle (v/V)= ",i);
    scanf(" %c",&choix2);}
    while(choix2!='c' && choix2!='C' && choix2!='v' && choix2!='V');
    printf("\n");


    char caractere;
    if(choix2=='c'||choix2=='C'){
    char consonnes[] = "BCDFGHJKLMNPQRSTVWXYZ";
    int taillecons = sizeof(consonnes) - 1;
    caractere = consonnes[rand() % taillecons]; }
    else{
    char voyelles[] = "AEIOU";
    int taillevoy = sizeof(voyelles) - 1;
    caractere = voyelles[rand() % taillevoy];
    }


    char temp1[7] = {' ',' ',' ',' ',' ',caractere, '\0'};
    char temp2[7] = {caractere,'\0'};
    strcat(lettres, temp1);
    strcat(lettresobli, temp2);
    };
    printf("%s\n",lettres);





    int k;
    int max=0;
    char ch[28];
    int b;
    int h;
    char lettreoblitempo[28];
    FILE*f=fopen("dictionnaire.txt","r");
    if(f==NULL){
            printf ("Erreur lors de l'ouverture du fichier \n");
        }
    while (fgets(ch, sizeof(ch), f) != NULL){
        if (ch[strlen(ch) - 1] == '\n') {
            ch[strlen(ch) - 1] = '\0';
        }
        k=0;
        while (ch[k] != '\0') {
                ch[k] = toupper(ch[k]);
                k++;
            }

        b=1;
        strcpy(lettreoblitempo,lettresobli);
        for (h = 0; h < strlen(ch); h++) {

            if (strchr(lettreoblitempo, ch[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                break;
            }


            else {
                char *resultat = strchr(lettreoblitempo, ch[h]);
                size_t position = resultat - lettreoblitempo;
                for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';
            }






            }

        if (b==1 && strlen(ch)>max){
                max=strlen(ch);


            }

        }
        fclose(f);


        char t[30][28];
        char t3[999][28];
        int y=0;
        int m=0;
        FILE*d=fopen("dictionnaire.txt","r");
        if(d==NULL){
            printf ("Erreur lors de l'ouverture du fichier \n");
        }
        while (fgets(ch, sizeof(ch), d) != NULL){
            if (ch[strlen(ch) - 1] == '\n') {
            ch[strlen(ch) - 1] = '\0';
        }
        k=0;
        while (ch[k] != '\0') {
                ch[k] = toupper(ch[k]);
                k++;
            }

        int b=1;
        strcpy(lettreoblitempo,lettresobli);
        for (h = 0; h < strlen(ch); h++) {
            if (strchr(lettreoblitempo, ch[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                break;
            }

            else {
                char *resultat = strchr(lettreoblitempo, ch[h]);
                size_t position = resultat - lettreoblitempo;
                for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';

            }


            }
            if(b==1){
            strcpy(t3[m],ch);
            m++;}
        if (b==1 && strlen(ch)==max){
                printf("%s \n",ch);//juste pour tester et connaitre les mot les plus longs
                strcpy(t[y],ch);
                y++;


            }
        }
        fclose(d);





    char t2[9][28];
    char reponse[26];
    i=0;
    int n=0;
    int v=1;
    while(i<taille && v==1){
        i++;
        printf("%i-   ",i);
        scanf("%s",reponse);
        k=0;
        while (reponse[k] != '\0') {
        reponse[k] = toupper(reponse[k]);
        k++;
        }




        strcpy(lettreoblitempo,lettresobli);

        b=1;
        for (h = 0; h < strlen(reponse); h++) {


                if (strchr(lettreoblitempo, reponse[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                printf("Le mot que vous avez saisi est incorrect!\n");
                break;

                }

                else {
                    char *resultat = strchr(lettreoblitempo, reponse[h]);
                    size_t position = resultat - lettreoblitempo;
                    for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';

                }



            }

        if(b==1){
                int c=0;
                FILE*d=fopen("dictionnaire.txt","r");
                if(d==NULL){
                    printf ("Erreur lors de l'ouverture du fichier \n");
                }
                while (fgets(ch, sizeof(ch), d) != NULL){
                    if (ch[strlen(ch) - 1] == '\n') {
                        ch[strlen(ch) - 1] = '\0';
                    }

                k=0;
                while (ch[k] != '\0') {
                    ch[k] = toupper(ch[k]);
                    k++;
                }

                if(strcmp(ch,reponse)==0){
                    c=1;
                }

                }

                fclose(d);
                if (c==0){
                    printf("Votre phrase n'existe pas!\n");
                }
                else{

                    k=0;

                    while(v==1 && k<y){

                        if(strcmp(t[k],reponse)==0){

                            v=0;
                        }
                        k++;

                    }
                    if (v==1){
                    strcpy(t2[n],reponse);
                    n++;
                    printf("le mot que vous avez saisi est correct mais n'est pas le plus long!\n");

                    }
                    else{
                        strcpy(t2[n],reponse);
                        n++;
                        printf("Vous gagnez! Le mot que vous avez saisi est correct et est le plus long.\n");

                    }
                }




        }


     }
     int score=0;
     for (int l=0;l<n;l++){
        printf("%s (%i)\n",t2[l],strlen(t2[l]));
        if (score<strlen(t2[l])){
        score=strlen(t2[l]);}

     }
     printf("                               Votre score est %i.\n\n\n",score);
     int choixf;
     printf("1- Afficher le/les mot(s) le/les plus long(s)\n");
     printf("2- Afficher tous les mots possibles\n\n");
     do{

     printf("                               Votre choix:");
     scanf("%i",&choixf);}
     while(choixf>2 || choixf<1);
     printf("\n");
     if (choixf==1){
        for(int l=0;l<y;l++){
            printf("%s \n",t[l]);
        }
     }
     else{
        if(choixf==2){
            for(int l=0;l<m;l++){
            printf("%s \n",t3[l]);
        }


        }
     }



    }











    else{if(choix==2){
            int taille;
    do{
    printf("\n\nTapez la taille (7/8/9) du mot le plus long à retrouver = ");
    scanf("%i",&taille);
    if (taille>9 || taille<7){
    printf("La taille que vous avez saisie est erronée!\n");};
    }
    while(taille>9 || taille<7);
    printf("\n");

    char lettres [70]="";
    char lettresobli [70]="";
    char choix2;
    int i;
    for(i=1;i<=taille;i++){
    do{
    printf("Caractére %i : Consonne (c/C) ou Voyelle (v/V)= ",i);
    scanf(" %c",&choix2);}
    while(choix2!='c' && choix2!='C' && choix2!='v' && choix2!='V');
    printf("\n");


    char caractere;
    if(choix2=='c'||choix2=='C'){
    char consonnes[] = "BCDFGHJKLMNPQRSTVWXYZ";
    int taillecons = sizeof(consonnes) - 1;
    caractere = consonnes[rand() % taillecons]; }
    else{
    char voyelles[] = "AEIOU";
    int taillevoy = sizeof(voyelles) - 1;
    caractere = voyelles[rand() % taillevoy];
    }


    char temp1[7] = {' ',' ',' ',' ',' ',caractere, '\0'};
    char temp2[7] = {caractere,'\0'};
    strcat(lettres, temp1);
    strcat(lettresobli, temp2);
    };
    printf("%s\n",lettres);





    int k;
    int max=0;
    char ch[28];
    int b;
    int h;
    char lettreoblitempo[28];
    FILE*f=fopen("dictionnaire.txt","r");
    if(f==NULL){
            printf ("Erreur lors de l'ouverture du fichier \n");
        }
    while (fgets(ch, sizeof(ch), f) != NULL){
        if (ch[strlen(ch) - 1] == '\n') {
            ch[strlen(ch) - 1] = '\0';
        }
        k=0;
        while (ch[k] != '\0') {
                ch[k] = toupper(ch[k]);
                k++;
            }

        b=1;
        strcpy(lettreoblitempo,lettresobli);
        for (h = 0; h < strlen(ch); h++) {

            if (strchr(lettreoblitempo, ch[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                break;
            }


            else {
                char *resultat = strchr(lettreoblitempo, ch[h]);
                size_t position = resultat - lettreoblitempo;
                for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';
            }






            }

        if (b==1 && strlen(ch)>max){
                max=strlen(ch);


            }

        }
        fclose(f);


        char t[30][28];
        char t3[999][28];
        int y=0;
        int m=0;
        FILE*d=fopen("dictionnaire.txt","r");
        if(d==NULL){
            printf ("Erreur lors de l'ouverture du fichier \n");
        }
        while (fgets(ch, sizeof(ch), d) != NULL){
            if (ch[strlen(ch) - 1] == '\n') {
            ch[strlen(ch) - 1] = '\0';
        }
        k=0;
        while (ch[k] != '\0') {
                ch[k] = toupper(ch[k]);
                k++;
            }

        int b=1;
        strcpy(lettreoblitempo,lettresobli);
        for (h = 0; h < strlen(ch); h++) {
            if (strchr(lettreoblitempo, ch[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                break;
            }

            else {
                char *resultat = strchr(lettreoblitempo, ch[h]);
                size_t position = resultat - lettreoblitempo;
                for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';

            }


            }
            if(b==1){
            strcpy(t3[m],ch);
            m++;}
        if (b==1 && strlen(ch)==max){
                printf("%s \n",ch);
                strcpy(t[y],ch);
                y++;


            }
        }
        fclose(d);





    char t2[9][28];
    char reponse[26];
    int timeout = taille; // Timeout en secondes
    int elapsed;
    i=0;
    int n=0;
    int v=1;
    while(i<taille && v==1){
        i++;
        printf("%i-   ",i);
        elapsed = 0;
        int test=1;



        while (elapsed < timeout && test==1) {
        Sleep(1000); // Sleep pour 1 seconde (1000 millisecondes)

        if (_kbhit()) {
        scanf("%s",reponse);
        test=0;

        }
        elapsed++;
        }
        if (elapsed==timeout){
        printf("\nVous avez dépassé le temps permis pour une tentative qui est de %is!.\n",taille);}




        k=0;
        while (reponse[k] != '\0') {
        reponse[k] = toupper(reponse[k]);
        k++;
        }




        strcpy(lettreoblitempo,lettresobli);

        b=1;
        for (h = 0; h < strlen(reponse); h++) {


                if (strchr(lettreoblitempo, reponse[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                printf("Le mot que vous avez saisi est incorrect!\n");
                break;

                }

                else {
                    char *resultat = strchr(lettreoblitempo, reponse[h]);
                    size_t position = resultat - lettreoblitempo;
                    for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';

                }



            }

        if(b==1){
                int c=0;
                FILE*d=fopen("dictionnaire.txt","r");
                if(d==NULL){
                    printf ("Erreur lors de l'ouverture du fichier \n");
                }
                while (fgets(ch, sizeof(ch), d) != NULL){
                    if (ch[strlen(ch) - 1] == '\n') {
                        ch[strlen(ch) - 1] = '\0';
                    }

                k=0;
                while (ch[k] != '\0') {
                    ch[k] = toupper(ch[k]);
                    k++;
                }

                if(strcmp(ch,reponse)==0 || reponse==""){
                    c=1;
                }

                }

                fclose(d);
                if (c==0){
                    printf("Votre phrase n'existe pas!\n");
                }
                else{

                    k=0;

                    while(v==1 && k<y){

                        if(strcmp(t[k],reponse)==0){

                            v=0;
                        }
                        k++;

                    }
                    if (v==1){
                    strcpy(t2[n],reponse);
                    n++;
                    printf("le mot que vous avez saisi est correct mais n'est pas le plus long!\n");

                    }
                    else{
                        strcpy(t2[n],reponse);
                        n++;
                        printf("Vous gagnez! Le mot que vous avez saisi est correct et est le plus long.\n");

                    }
                }




        }


     }
     int score=0;
     for (int l=0;l<n;l++){
        printf("%s (%i)\n",t2[l],strlen(t2[l]));
        if (score<strlen(t2[l])){
        score=strlen(t2[l]);}

     }
     printf("                               Votre score est %i.\n\n\n",score);
     int choixf;
     printf("1- Afficher le/les mot(s) le/les plus long(s)\n");
     printf("2- Afficher tous les mots possibles\n\n");
     do{

     printf("                               Votre choix:");
     scanf("%i",&choixf);}
     while(choixf>2 || choixf<1);
     printf("\n");
     if (choixf==1){
        for(int l=0;l<y;l++){
            printf("%s \n",t[l]);
        }
     }
     else{
        if(choixf==2){
            for(int l=0;l<m;l++){
            printf("%s \n",t3[l]);
        }


        }
     }



    }




    else{if(choix==3){






    char choixx;
    int score1=0;
    int score2=0;
    do{
        int taille;
    do{
    printf("\n\nTapez la taille (nombre pair) du mot le plus long à retrouver = ");
    scanf("%i",&taille);
    if (taille%2!=0||taille>25 || taille<1){
    printf("La taille que vous avez saisie est erronée!\n");};
    }
    while(taille%2!=0||taille>25 || taille<1);
    printf("\n");

    char lettres [70]="";
    char lettresobli [70]="";
    char choix2;
    int i;
    for(i=1;i<=taille;i++){
    do{
    printf("Caractére %i : Consonne (c/C) ou Voyelle (v/V)= ",i);
    scanf(" %c",&choix2);}
    while(choix2!='c' && choix2!='C' && choix2!='v' && choix2!='V');
    printf("\n");


    char caractere;
    if(choix2=='c'||choix2=='C'){
    char consonnes[] = "BCDFGHJKLMNPQRSTVWXYZ";
    int taillecons = sizeof(consonnes) - 1;
    caractere = consonnes[rand() % taillecons]; }
    else{
    char voyelles[] = "AEIOU";
    int taillevoy = sizeof(voyelles) - 1;
    caractere = voyelles[rand() % taillevoy];
    }


    char temp1[7] = {' ',' ',' ',' ',' ',caractere, '\0'};
    char temp2[7] = {caractere,'\0'};
    strcat(lettres, temp1);
    strcat(lettresobli, temp2);
    };
    printf("%s\n",lettres);





    int k;
    int max=0;
    char ch[28];
    int b;
    int h;
    char lettreoblitempo[28];
    FILE*f=fopen("dictionnaire.txt","r");
    if(f==NULL){
            printf ("Erreur lors de l'ouverture du fichier \n");
        }
    while (fgets(ch, sizeof(ch), f) != NULL){
        if (ch[strlen(ch) - 1] == '\n') {
            ch[strlen(ch) - 1] = '\0';
        }
        k=0;
        while (ch[k] != '\0') {
                ch[k] = toupper(ch[k]);
                k++;
            }

        b=1;
        strcpy(lettreoblitempo,lettresobli);
        for (h = 0; h < strlen(ch); h++) {

            if (strchr(lettreoblitempo, ch[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                break;
            }


            else {
                char *resultat = strchr(lettreoblitempo, ch[h]);
                size_t position = resultat - lettreoblitempo;
                for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';
            }






            }

        if (b==1 && strlen(ch)>max){
                max=strlen(ch);


            }

        }
        fclose(f);


        char t[30][28];
        char t3[999][28];
        int y=0;
        int m=0;
        FILE*d=fopen("dictionnaire.txt","r");
        if(d==NULL){
            printf ("Erreur lors de l'ouverture du fichier \n");
        }
        while (fgets(ch, sizeof(ch), d) != NULL){
            if (ch[strlen(ch) - 1] == '\n') {
            ch[strlen(ch) - 1] = '\0';
        }
        k=0;
        while (ch[k] != '\0') {
                ch[k] = toupper(ch[k]);
                k++;
            }

        int b=1;
        strcpy(lettreoblitempo,lettresobli);
        for (h = 0; h < strlen(ch); h++) {
            if (strchr(lettreoblitempo, ch[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                break;
            }

            else {
                char *resultat = strchr(lettreoblitempo, ch[h]);
                size_t position = resultat - lettreoblitempo;
                for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';

            }


            }
            if(b==1){
            strcpy(t3[m],ch);
            m++;}
        if (b==1 && strlen(ch)==max){
                printf("%s \n",ch);
                strcpy(t[y],ch);
                y++;


            }
        }
        fclose(d);





    char t2[9][28];
    char t4[9][28];
    char reponse1[26];
    char reponse2[26];
    i=0;
    int n1=0;
    int n2=0;
    int v=1;
    int ne=2;
    while(i<taille/2 && v==1){
        if(ne==1){ne=2;}
        else{ne=1;}
        i++;
        printf("J%i-   ",ne);
        scanf("%s",reponse1);
        k=0;
        while (reponse1[k] != '\0') {
        reponse1[k] = toupper(reponse1[k]);
        k++;
        }




        strcpy(lettreoblitempo,lettresobli);

        b=1;
        for (h = 0; h < strlen(reponse1); h++) {


                if (strchr(lettreoblitempo, reponse1[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                printf("Le mot que vous avez saisi est incorrect!\n");
                break;

                }

                else {
                    char *resultat = strchr(lettreoblitempo, reponse1[h]);
                    size_t position = resultat - lettreoblitempo;
                    for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';

                }



            }

        if(b==1){
                int c=0;
                FILE*d=fopen("dictionnaire.txt","r");
                if(d==NULL){
                    printf ("Erreur lors de l'ouverture du fichier \n");
                }
                while (fgets(ch, sizeof(ch), d) != NULL){
                    if (ch[strlen(ch) - 1] == '\n') {
                        ch[strlen(ch) - 1] = '\0';
                    }

                k=0;
                while (ch[k] != '\0') {
                    ch[k] = toupper(ch[k]);
                    k++;
                }

                if(strcmp(ch,reponse1)==0){
                    c=1;
                }

                }

                fclose(d);
                if (c==0){
                    printf("Votre phrase n'existe pas!\n");
                }
                else{

                    k=0;

                    while(v==1 && k<y){

                        if(strcmp(t[k],reponse1)==0){

                            v=0;
                        }
                        k++;

                    }
                    if (v==1){
                    strcpy(t2[n1],reponse1);
                    n1++;
                    printf("le mot que vous avez saisi est correct mais n'est pas le plus long!\n");

                    }
                    else{
                        strcpy(t2[n1],reponse1);
                        n1++;
                        printf("Vous gagnez! Le mot que vous avez saisi est correct et est le plus long.\n");

                    }
                }




        }

        //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        if(ne==1){ne=2;}
        else{ne=1;}

        printf("J%i-   ",ne);
        scanf("%s",reponse2);
        k=0;
        while (reponse2[k] != '\0') {
        reponse2[k] = toupper(reponse2[k]);
        k++;
        }




        strcpy(lettreoblitempo,lettresobli);

        b=1;
        for (h = 0; h < strlen(reponse2); h++) {


                if (strchr(lettreoblitempo, reponse2[h]) == NULL) {
                b = 0;  // il ya un character qui n'existe pas dans lettresobli
                printf("Le mot que vous avez saisi est incorrect!\n");
                break;

                }

                else {
                    char *resultat = strchr(lettreoblitempo, reponse2[h]);
                    size_t position = resultat - lettreoblitempo;
                    for (int p = position; p < strlen(lettreoblitempo) - 1; ++p) {
                        lettreoblitempo[p] = lettreoblitempo[p + 1];
                }
                lettreoblitempo[strlen(lettreoblitempo) - 1] = '\0';

                }



            }

        if(b==1){
                int c=0;
                FILE*d=fopen("dictionnaire.txt","r");
                if(d==NULL){
                    printf ("Erreur lors de l'ouverture du fichier \n");
                }
                while (fgets(ch, sizeof(ch), d) != NULL){
                    if (ch[strlen(ch) - 1] == '\n') {
                        ch[strlen(ch) - 1] = '\0';
                    }

                k=0;
                while (ch[k] != '\0') {
                    ch[k] = toupper(ch[k]);
                    k++;
                }

                if(strcmp(ch,reponse2)==0){
                    c=1;
                }

                }

                fclose(d);
                if (c==0){
                    printf("Votre phrase n'existe pas!\n");
                }
                else{

                    k=0;

                    while(v==1 && k<y){

                        if(strcmp(t[k],reponse2)==0){

                            v=0;
                        }
                        k++;

                    }
                    if (v==1){
                    strcpy(t4[n2],reponse2);
                    n2++;
                    printf("le mot que vous avez saisi est correct mais n'est pas le plus long!\n");

                    }
                    else{
                        strcpy(t4[n2],reponse2);
                        n2++;
                        printf("Vous gagnez! Le mot que vous avez saisi est correct et est le plus long.\n");

                    }
                }




        }


      }
      //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

     int scrr=0;
     int scrr2=0;
     for (int l=0;l<n1;l++){
        printf("%s (%i)\n",t2[l],strlen(t2[l]));

        score1=score1+strlen(t2[l]);

     }
     printf("                               le score de J1 %i.\n\n\n",score1);
     for (int l=0;l<n2;l++){
        printf("%s (%i)\n",t4[l],strlen(t4[l]));

        score2=score2+strlen(t4[l]);

     }
     printf("                               le score de J2 %i.\n\n\n",score2);
     int choixf;
     printf("1- Afficher le/les mot(s) le/les plus long(s)\n");
     printf("2- Afficher tous les mots possibles\n\n");
     do{

     printf("                               Votre choix:");
     scanf("%i",&choixf);}
     while(choixf>2 || choixf<1);
     printf("\n");
     if (choixf==1){
        for(int l=0;l<y;l++){
            printf("%s \n",t[l]);
        }
     }
     else{
        if(choixf==2){
            for(int l=0;l<m;l++){
            printf("%s \n",t3[l]);
        }


        }
     }


     do{
     printf("\n\nVous voulez continuez? Réponder par 'o' si oui et 'n' sinon = ");
     scanf(" %c",&choixx);}
     while (choixx!='o' && choixx!='O' && choixx!='n' && choixx!='N');

    }

     while (choixx=='O' || choixx=='o');

     if (choixx=='n' || choixx=='N'){
        if (score1==score2){
            printf("\égalité!");
        }
        else{

        if (score1>score2){
            printf("\nj1 est le vainqueur!");
        }
        else{printf("\nj2 est le vainqueur!");}
     }
     }

     }

     else{
            exit(0);
     }


    }}


    return 0;
}
