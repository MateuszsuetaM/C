#include <stdio.h>
#include  <string.h>
#include  <ctype.h>
#include  <stdlib.h>
#include <stdbool.h>
bool check(int dlugosc, char linia[]);
bool check32(int dlugosc, char linia[]);
void ujemna(long long int i, int x, int tab[], int k);
void dodatnia(long long int i, int x, int tab[], int k);
void wypisz(int tab[], int x);
long long int i;
long int j;

int main(){
  // int wybor;
  int x=64, y=32, max=100;
  int tab[x], stab[y], dlugosc;
  x--;
  y--;

  FILE *fp;
  fp = fopen("liczby1.txt", "r");

  while(!feof(fp)){
    char linia[max];
    fgets(linia, max, fp);
    dlugosc = strlen(linia);
//sprawdzamy czy input jest ok
    if(!check(dlugosc, linia))
      continue;
//zamieniamy ciąg znaków (char) na liczbe
    i=atoll(linia);
//jesli liczba jest dodatnia/ujemna
  // printf("\nwykonuje na liczbie: %lli\n",i);
  //   printf("\n linia: %s\n",linia);
    if(i<0)
      ujemna(i, x, tab, 64);
    else if(i>=0)
      dodatnia(i, x, tab, 64);

  if(!check32(dlugosc,linia))
    continue;
j=atol(linia);
  if(j<0)
    ujemna(i, y, stab, 32);
  else if(j>=0)
    dodatnia(i, y, stab, 32);



}
    fclose(fp);
    return 0;
}

bool check(int dlugosc, char linia[]){
  // long long int linijka = atoi(linia);
  char znak=linia[0];
  int sign, wielkosc;
  printf("\n________________________________________________________________\n%s\nNa 64 bitach:\n",linia);
  if(znak=='-')
    sign=1,wielkosc=21;
  else if(isdigit(linia[0]))
    sign=0, wielkosc=20;
  if(dlugosc>wielkosc){
    printf("Wyraz poza zakresem!\n");
    return false;
  }

    for(int a=sign;a<dlugosc;a++){
      if(a==(dlugosc-1)){
        // printf("dlugosc: %i",dlugosc);
        if(dlugosc==20+sign){
            char test[18];
            strncpy(test,linia+sign,18);
            long long int testInt=atoll(test);
            int ostatnia = atoi(&linia[18+sign]);
            printf(" ostatnia: %i, liczba: %s", ostatnia, linia);
            printf("\nint: %lli ostatnia: %i\n",testInt, ostatnia);

            if(testInt<=922337203685477580&&ostatnia<=7){
              // printf("\nto jest LICZBA!!!  %s\n", linia);
              i=atoll(linia);
              return true;}
            else
              printf("liczba nie mieści się w zakresie!\n");
          }
        else{
          i=atoll(linia);
          // printf("\nudało się: %s\n", linia);
          return true;
        }
      }

      else if(!isdigit(linia[a])){
        printf("Wszystko, tylko nie to! Bez literek poproszę :)\n");
        return false;
      }
    }
    return false;
}
void ujemna(long long int i, int x, int tab[], int k){
  i=i*(-1);
  while(x>0){
    if(i%2==1){
      tab[x]=0;
    }
    else if(i%2==0){
      tab[x]=1;
    }
    i=i/2;
    x--;
  }
  tab[0]=1;
  wypisz(tab, k);
  }
void dodatnia(long long int i, int x, int tab[], int k){
  while(x>0){
    tab[x]=i%2;
    i=i/2;
    x--;
    }
  tab[0]=0;
  x=0;
  wypisz(tab, k);
}
void wypisz(int tab[], int q){
  int x=0;
  // printf("\nq=%i\n",q);
  while(x<q){
    printf("%i", tab[x]);
    x++;
  }
  printf("\n");
}
bool check32(int dlugosc, char linia[]){
  // long long int linijka = atoi(linia);
  char znak=linia[0];
  int sign, wielkosc;
  printf("\n***\nna 32 bitach:\n");
  // printf("%c\n",znak);
  if(znak=='-')
    sign=1,wielkosc=12;
  else if(isdigit(linia[0]))
    sign=0, wielkosc=11;
  if(dlugosc>wielkosc){
    printf("Wyraz poza zakresem!\n");
    return false;
  }

    for(int a=sign;a<dlugosc;a++){
      if(a==(dlugosc-1)){
        // printf("dlugosc: %i",dlugosc);
        if(dlugosc==11+sign){
            char test[9];
            strncpy(test,linia+sign,9);
            long int testInt=atol(test);
            int ostatnia = atoi(&linia[9+sign]);
            // printf(" ostatnia: %i, liczba: %s", ostatnia, linia);
            // printf("\nint: %li ostatnia: %i\n",testInt, ostatnia);
            if(testInt<=214748364&&ostatnia<=7){
              // printf("\nto jest LICZBA!!!  %s\n", linia);
              j=atol(linia);
              return true;}
            else
              printf("liczba nie mieści się w zakresie!\n");
          }
        else{
          j=atol(linia);
          // printf("\nudało się: %s\n", linia);
          return true;
        }
      }

      else if(!isdigit(linia[a])){
        printf("Wszystko, tylko nie to! Same cyfry poproszę :)\n");
        return false;
      }
    }
    return false;
}
