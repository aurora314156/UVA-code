
// UVa489 Hangman Judge
// Rujia Liu
#include<stdio.h>
#include<string.h>
#define maxn 100
int left, chance;
char s[maxn], s2[maxn];
int win, lose;


int main() {
  int rnd;
  while(scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1) {
    printf("%d\n",strlen(s));
    for(int i =0;i<strlen(s);i++)
    {
      for(int j =i;j<strlen(s);j++)
      {
        
      }
    }

    if(win) printf("You win.\n");
    else if(lose) printf("You lose.\n");
    else printf("You chickened out.\n");
  }
  return 0;
}