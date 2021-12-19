#include "trap.h"

char *s[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
             "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
             "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
             ", World!\n",
             "Hello, World!\n",
             "#####"};

char str1[] = "Hello";
char str[20];
// char str2[20];

int main() {
  // check(strcmp(strcat(strcpy(str, str1), s[3]), s[4]) == 0);

  check(strcmp(s[0], s[2]) == 0);
  // check(strcmp(s[0], s[1]) < 0);
  // check(strcmp(s[0] + 1, s[1] + 1) < 0);
  // check(strcmp(s[0] + 2, s[1] + 2) < 0);
  // check(strcmp(s[0] + 3, s[1] + 3) < 0);

  printf("s: 0x%08x\tstr1: 0x%08x\tstr: 0x%08x\t", s, str1, str);

  check(strcmp(strcat(strcpy(str, str1), s[3]), s[4]) == 0);

  // check(strcmp(s[0] + 2, s[1] + 2) < 0);

  // check(memcmp(memset(str, '#', 5), s[5], 5) == 0);
  return 0;
}
