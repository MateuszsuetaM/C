#include <stdio.h>
#include  <string.h>
#include  <ctype.h>
#include  <stdlib.h>
#include <stdbool.h>
int potega(int x, int y);
long long int i;
long int j;

int main(){
  // int czy=0;
  int max=100;
  float czy, wczytana;//, mantysa;
  FILE *fp;
  fp = fopen("liczby2.txt", "r");
  char linia[max];
  fgets(linia, max, fp);
  czy=wczytana=strtof(linia, NULL);
  int dwa=2, poteg=0, tak;
  char mantysa[23];
  // wczytana=strtof(linia, NULL);
  while(!(2>czy&&czy>=1)){
    tak=potega(dwa, poteg);
    czy=wczytana/tak;
    poteg++;
  }
  printf("f = %f\n",czy);

int licznik=0;
float zero = 0;
while(!(czy==zero)){
  if (czy>1.0f){
    mantysa[licznik]=1;
    czy=czy-1;
  }
  else{
    mantysa[licznik]=0;
  }
  // float probna=czy;
  printf("czy = %f",czy);
czy=czy*2.0f;
printf("czy + czy = %f",czy);
  // czy=probna*2;
  licznik++;
}
printf("wyszedlem, hej :)\n");
// licznik++;
while(licznik<23){
  mantysa[licznik]=0;
  licznik++;
}
licznik=0;
while(licznik<23){
  printf("%d",mantysa[licznik]);
  licznik++;
}
// printf("mantysa: %d\n",mantysa[0]);
// int licznik2=0;
// while(licznik2<23){
//   printf("")
// }
fclose(fp);
return 0;
}
int potega(int x, int y){
  int ex=x;
  if(y==0)
    x=1;
  else
    y--;
    while(y>0){
      x=x*ex;
      y--;
    }
  return x;
}
