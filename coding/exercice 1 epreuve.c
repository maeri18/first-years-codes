#include<stdio.h>
void unites(int u)
{
    switch(u)
    {
        case 1 : printf(" un "); break;
        case 2 : printf(" deux "); break;
        case 3 : printf(" trois "); break;
        case 4 : printf(" quatre "); break;
        case 5 : printf(" cinq "); break;
        case 6 : printf(" six "); break;
        case 7 : printf(" sept "); break;
        case 8 : printf(" huit "); break;
        case 9 : printf(" neuf "); break;
    }
}
void dizaines(int d)
{
    switch(d)
    {
//il ny a pas le cas "1" par expres, c'est considere plus tard dans le code
        case 2 : printf(" vingt "); break;
        case 3 : printf(" trente "); break;
        case 4 : printf(" quarante "); break;
        case 5 : printf(" cinquante "); break;
        case 6 : printf(" soixante "); break;
        case 7 : printf(" soixante "); break;
        case 8 : printf(" quatre-vingt "); break;
        case 9 : printf(" quatre-vingt "); break;
    }
}
void centaines (int c)
{
    switch(c)
    {
        case 1 : printf(" cent "); break;
        case 2 : printf(" deux cent "); break;
        case 3 : printf(" trois cent "); break;
        case 4 : printf(" quatre cent "); break;
        case 5 : printf(" cinq cent "); break;
        case 6 : printf(" six cent "); break;
        case 7 : printf(" sept cent "); break;
        case 8 : printf(" huit cent "); break;
        case 9 : printf(" neuf cent "); break;
    }
}

main()
{
    int n, n1, u, d, c, m, dm, cm;
    printf("Entrer le nombre\n");
    scanf("%d", &n);
    if(n>=1000000 || n<0)
    {
        while(n>=1000000 || n<0)
        {
            printf("nombre incorrect, veuillez en choisir un entre 0 et 999 999\n");
            scanf("%d", &n);
        }
    }
    else if (n==0)
    {
        printf("l'ecriture en lettre de %d est : zero", n);
    }

    n1 = n;
    cm = dm = m = u = d = c = 0;
    while(n >= 100000)
    {
        cm+= 1;
        n-= 100000;
    }
    while(n>=10000)
    {
        dm+=1;
        n-=10000;
    }
    while(n>=1000)
    {
        m+=1;
        n-=1000;
    }
    while(n>=100)
    {
        c+=1;
        n-=100;
    }
    while(n>=10)
    {
        d+=1;
        n-=10;
    }
    while(n>0)
    {
        u+=1;
        n-=1;
    }
    printf("L'ecriture en lettres de %d est:\n",n1);

    if(cm!=0)
    {
        centaines(cm);
    }
    if(dm!=0)
    {   dizaines(dm);
        if(((dm==1 )||( dm==7)||(dm==9))&&(1<=m<=5))
        {
                switch(m)
                {
                            case 1 : printf("-onze"); break;
                            case 2 : printf("-douze"); break;
                            case 3 : printf("-treize"); break;
                            case 4 : printf("-quatorze"); break;
                            case 5 : printf("-quinze"); break;
                            case 6 : printf("-seize"); break;
                }

        }
        if(((dm==7) || (dm==9) || (dm==1))&&(m>6))
        {
           printf("dix-");
        }

    }
    if(((m!=0)&&( m>6))||((m!=0)&&(dm==0))||((m!=0)&&(dm!=1)&&(dm!=7)&&(dm!=9)))
    {
        unites(m);
    }
    if(dm!=0 || cm!=0 || m!=0)
    {
        printf(" mille ");
    }
    if(c!=0)
    {
        centaines(c);
    }
    if(d!=0)
    {   dizaines(d);
        if(((d==1 )||( d==7)||(d==9))&&(1<=u<=5))
        {
                switch(u)
                {
                            case 1 : printf("-onze"); break;
                            case 2 : printf("-douze"); break;
                            case 3 : printf("-treize"); break;
                            case 4 : printf("-quatorze"); break;
                            case 5 : printf("-quinze"); break;
                            case 6 : printf("-seize"); break;
                }

        }
        if(((d==7) || (d==9) || (d==1))&&(u>6))
        {
           printf("dix-");

        }

    }
    if(((u!=0)&&( u>6))||((u!=0)&&(d==0))||((u!=0)&&(d!=1)&&(d!=7)&&(d!=9)))
    {
        unites(u);
    }

    return 0;
}

