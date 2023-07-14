#include<iostream>
#define taille 20
 using namespace std;
 int lenght(int T[taille])
 {
     int i=0, len=1;
     while(T[i]!=0)
     {
         len=len+1;
         i=i+1;
     }
     len=len-1;
     return len;
 }
 void printlistAge(int T[taille])
 {
     int n=lenght(T);
     int i;
     for(i=0;i<n;i++) {cout<<T[i] <<" ";}

 }
 void insertAgeFirst(int age,int T[taille])
 {
     int n=lenght(T);
     int i;
     for(i=n+1;i>0;i--)
     {
         T[i]=T[i-1];
     }
     T[0]=age;
 }
 void deleteFirst(int T[taille])
 {
     int i, n=lenght(T);
     for(i=0;i<n-1;i++) {T[i]=T[i+1];}
     T[n-1]=0;
 }
 void isEmpty(int T[taille])
 {
     int i,k=0;
     for(i=0;i<taille;i++)
     if(T[i]==0)
     k=k+1;
     if(k==taille-1) cout<<"TABLEAU VIDE\n";
     else
     cout<<"TABLEAU NON VIDE\n";
 }
 int find(int T[taille],int age)
 {
     int n=lenght(T);
     int i;
     for(i=0;i<=n;i++){if(T[i]==age) break;}

     return i;
 }
 void SortAsd(int T[taille])
 {
     int n=lenght(T);
     int i,j,permut;
     for(i=0;i<n-1;i++)
     for(j=i;j<n;j++)
     if(T[j]<T[i])
     {
         permut=T[j];
         T[j]=T[i];
         T[i]=permut;
     }
 }
 void SortDsd(int T[taille])
 {
     int n=lenght(T);
     int i,j,permut;
     for(i=0;i<n-1;i++)
     for(j=i;j<n;j++)
     if(T[j]>T[i])
     {
         permut=T[j];
         T[j]=T[i];
         T[i]=permut;
     }
 }
 void reverseArray(int T[taille])
 {
     int n=lenght(T);
     int T1[taille];
     int i;
     for(i=0;i<n;i++)
     T1[i]=T[n-1-i];
     for(i=0;i<n;i++)
     T[i]=T1[i];
 }
 main()
 {
     int i,choix=23;
     int T[taille];
     T[0]=15;
     T[1]=19;
     T[2]=14;
     T[3]=17;
     T[4]=15;
     T[5]=16;
     T[6]=0;
     while(choix!=0)
     {
    cout<<"\n\n\nQuelle action voulez-vous effectuer?\n";
    cout<<"1. Afficher les ages\n";
    cout<<"2. Afficher le nombre d'ages\n";
    cout<<"3. Inserer un age au debut du tableau\n";
    cout<<"4. Supprimer un age au debut du tableau\n";
    cout<<"5. Verifier si le tableau des ages est vide\n";
    cout<<"6. Trouver un age\n";
    cout<<"7. Trier les ages par ordre croissant\n";
    cout<<"8. Trier les ages par ordre decroissant\n";
    cout<<"9. Reverser le tableau d'ages\n";
    cout<<"0. Quitter\n\n\n";
    cin >> choix ;
    if(choix==0) break;
    else if(choix==1) printlistAge(T);
    else if(choix==2){int j=lenght(T); cout<<"Le nombre d'ages est de:" <<j<<"\n";}
    else if(choix==3){int ins; cout<<"Entrer l'age a inserer\n"; cin >> ins; insertAgeFirst(ins,T);}
    else if(choix==4){deleteFirst(T);}
    else if(choix==5){isEmpty(T);}
    else if(choix==6){int i; int age; cout<<"Entrer l'age a chercher\n"; cin >> age;i=find(T,age); cout<<"l'age recherche occupe l'indice " <<i<< " du tableau\n";}
    else if(choix==7){SortAsd(T); cout<<"Le tableau a bien ete trie par ordre croissant\n"; printlistAge(T);}
    else if(choix==8){SortDsd(T); cout<<"Le tableau a bien ete trie par ordre decroissant\n";printlistAge(T);}
    else if(choix==9){reverseArray(T); cout<<"Le tableau a bien renverse\n";printlistAge(T);}
    else cout<<"Choix errone";

     }


 }
