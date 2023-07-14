float somme (int n, float T[n])
{
 int i;
 float S=0;
 for (i=0;i<n;i++)
 {
 S=S+T[i];
 }
 return S;
}
float produit (int n, float T[n])
{
 int i;
 float S=1;
 for (i=0;i<n;i++)
 {
 S=S*T[i];
 }
 return S;
}
float moyenne(int n, float T[n])
{
 int i;
 float moyenne,s;
 s=somme(n,T);
 moyenne=s/n;
 return moyenne;
}
float maximum(int n, float T[n])
{
 float max=T[0];
 int i;
 for(i=1;i<n;i++)
 {
  if(max<T[i]) max=T[i];
 }
 return max;
}
float minimum(int n, float T[n])
{
 float min=T[0];
 int i;
 for(i=1;i<n;i++)
 {
  if(T[i]<min) min=T[i];
 }
 return min;
}
