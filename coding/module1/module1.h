#ifndef MODULE1_H
#define MODULE1_H
struct mot
{
    char t[21];
};
typedef struct mot mot;
extern void saisir_txt();
extern void saisir_tab(mot []);
extern void saisir_ROT(mot []);
extern void saisir_XOR(mot []);
extern void lecture_txt(mot [],int *);
extern void lecture_ROT_crypt(mot [],int *);
extern void lecture_ROT_decrypt(mot [],int *);
extern void lecture_XOR_crypt(mot [],int *);
extern void lecture_XOR_decrypt(mot [],int *);
extern int taille_tab(mot []);
extern void init_txt();
extern void init_ROT();
extern void init_XOR();
extern void afficher_txt();
extern void affichage_ROT_crypt();
extern void affichage_ROT_decrypt();
extern void affichage_XOR_crypt();
extern void affichage_XOR_decrypt();

#endif // MODULE1_H
