#include<iostream>
#define taille 20
 using namespace std;
 int lenght(int T[taille])
 {
     int i, len=0;
     for(i=0;i<taille;i++)
     if(T[i]!=0)
     len=len+1;
     return len;
 }
 void printlist*Age(int T[taille])
 {
     int lenght(int);
     int n=lenght(T);
     int i;
     for(i=0;i<n;i++) cout<<t[i] <<" ";

 }
 void insertAgeFirst(int age,int T[taille])
 {
     int n=lenght(T);
     int i;
     for(i=n-1;i==0;i--)
     {
         T[i+1]=T[i];
     }
     T[0]=age;
 }
 void deleteFirst(int T[taille])
 {
     int i, n=lenght(T);
     for(i=0;i<n-1;i++) T[i]=T[i+1];
 }
 void isEmpty(int T[taille])
 {
     int i,k=0,n=lenght(T);
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
     for(i=0;i<n;i++)if(T[i]==age) break;
     return T[i];
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
 void SortAsd(int T[taille])
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
     T1[i]=T[n-i];
     for(i=0;i<n;i++)
     T[i]=T1[i];
 }
 main()
 {


 }
