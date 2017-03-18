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
  czy=atof(linia);
  printf("%f", czy);
  int dwa=2, poteg=0, tak;
  char mantys[23];
  // czy=atof(linia);
  wczytana=atof(linia);
  printf("\nmantysa zaraz po konwersji: %f\n", wczytana);
  while(!(2>czy&&czy>=1)){
    // float
    tak=potega(dwa, poteg);
    czy=wczytana/tak;
    poteg++;
    printf("heh");
  }

  printf("\nczy:%f",czy);
  float mantysa=czy;
  printf("\n%fmantysa",mantysa);
  // printf("\n mantysa: %f", mantysa);
mantysa=mantysa-1;

printf("mantysa: %f", mantysa);

int licznik=0;
float zero = 0;
while(!(mantysa==zero)){
  if (mantysa>1){
    mantys[licznik]=1;
    mantysa--;
  }
  else{
    mantys[licznik]=0;
  }
  mantysa=mantysa*2;
  licznik++;

}
printf("%s",mantys);
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
