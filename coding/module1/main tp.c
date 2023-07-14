#include<stdio.h>
#include"module1.h"
#include"module_2.h"
#include"module3.h"
#include"module4.h"

int main()
{ int c=-1;
while(c!=0){
printf("\n\n |******************************************************\n"
       " |             Que voulez vous faire?                 |\n"
       " |             ----------------------                 |\n"
       " |1.Ecrire le texte a crypter                         |\n"
       " |2.Crypter le texte avec ROT                         |\n"
       " |3.Crypter le texte avec XOR                         |\n"
       " |4.Decrypter le texte avec ROT                       |\n"
       " |5.Decrypter le texte avec XOR                       |\n"
       " |6.Afficher le nombre de caracteres cryptes avec ROT |\n"
       " |7.Afficher le nombre mots                           |\n"
       " |8.Afficher la longueur maximale d'un mot            |\n"
       " |9.Afficher la longueur moyenne des mots             |\n"
       " |10.Afficher le nombre de caracteres                 |\n"
       " |11.Afficher le nombre de phrases                    |\n"
       " |0. Quitter                                          |\n"
       "******************************************************|\n\n");
       scanf("%d",&c);
       switch(c)
       {
           case 1:{saisir_txt();
                    int t;
                    printf("afficher le texte entre?\n1.OUI\n2.NON\n");
                    scanf("%d",&t);
                    if(t==1) {printf("\n\n");
                    afficher_txt();}}
           break;
           case 2:{
               int chart; Crypt_ROT(&chart);
               printf("Cryptage en ROT-13 termine \n\n");
               int t;
                    printf("afficher le texte crypte en ROT?\n1.OUI\n2.NON\n");
                    scanf("%d",&t);
                    if(t==1) {printf("\n\n");
                    affichage_ROT_crypt();}}
           break;
           case 3:{
               char cle[20];
               printf("Entrer la cle\n");
               scanf("%s", cle);
               Crypt_XOR(cle);
               printf("Cryptage en XOR termine \n\n");
                int t;
                    printf("afficher le texte crypte en XOR?\n1.OUI\n2.NON\n");
                    scanf("%d",&t);
                    if(t==1) {printf("\n\n");
                    affichage_XOR_crypt();}}
           break;
           case 4:{Decrypt_ROT();
           printf("Decryptage en ROT-13 termine\n\n\n");
            int t;
                    printf("afficher le texte decrypte en ROT?\n1.OUI\n2.NON\n");
                    scanf("%d",&t);
                    if(t==1) {printf("\n\n");
                    affichage_ROT_decrypt();}}
           break;
           case 5:{
               char cle[20];
               printf("Entrer la cle\n");
               scanf("%s", cle);
               Decrypt_XOR(cle);
               printf("Decryptage en XOR termine\n\n\n");
                int t;
                    printf("afficher le texte decrypte en XOR?\n1.OUI\n2.NON\n");
                    scanf("%d",&t);
                    if(t==1) {printf("\n\n");
                    affichage_XOR_decrypt();}
                }
           break;
           case 6:{int j;
           j=nbchar_ROT();
           printf("Le nombre de caracteres est de %d\n", j);
            }
           break;
           case 7:{int j;
           j=nbmots();
           printf("\nLe nombre de mots est de %d\n\n", j);}
           break;
           case 8:{
           int j;
           j=lengthmax();
           printf("\nLa longueur maximale d'un mot est de %d\n\n", j);}
           break;
           case 9:{int j;
           j=lenghtmoy();
           printf("\nLa longueur moyenne des mots est de %d\n\n", j);}
           break;
           case 10:{int j;
           j=alphanum();
           printf("\nLe nombre de caracteres est de %d\n\n", j);}
           break;
           case 11:{int j;
           j=phrases();
           if(j!=0)
           printf("\nLe nombre de phrases est de %d\n\n", j);
           else printf("Aucun point ('.') n'a ete detecte\n");}
           break;
           case 0:{
           printf("FIN DU PROGRAMME\n\n");}
           break;
           default:{ printf("\nValeur entree incorrecte\n");}
       }

}
return 0;
}
