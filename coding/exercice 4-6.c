int main()
{
  float montant_i, montant_f;
  printf("entrer le montant");
  scanf("%f",&montant_i);
    if((montant_i<=5000)&&(montant_i>=2000))
    {
    montant_f=montant_i-(montant_i/100);
    printf("le montant net obtenu apres la remise est : %f", montant_f);
    }
    else {
    montant_f=montant_i-((montant_i*2)/100);
    printf("le montant net obtenu apres la remise est : %f", montant_f);}
}
