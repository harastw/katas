#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parentheses_score(const char *s)
{
  int res = 0, n;
  char *st = NULL;
  st = strdup(s);
 
  for (int i = 0, j = 0; s[i] != '\0'; i++) {
    if (s[i] == '(' && s[i+1] == ')') {
      st[j] = '1';
      j++;
      st[j] = '+';
      j++;
      i++;
    } else {
      st[j] = s[i];
      j++;
    }
  }

  int leftp = 0, rightp = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (st[i] == '1') {
      for (int j = i; j >= 0; j--) {
	if (st[j] == '(') {
	  leftp++;
	} else if (st[j] == ')') {
	  rightp++;
	}
      }
      n = 1;
      for (int power = 0; power < leftp - rightp; power++) {
	n *= 2;
      }
      rightp = 0;
      leftp = 0;
      res += n;
    }
  }
  
  free(st); // free memory
  st = NULL;
  
  return res;
}

int main() {
  int answer;
  
  answer = parentheses_score("()");
  printf("%d\n\n", answer);

  answer = parentheses_score("(((())))");
  printf("%d\n\n", answer);

  answer = parentheses_score("(()(()))");
  printf("%d\n\n", answer);

  answer = parentheses_score("(()())()");
  printf("%d\n\n", answer);

  answer = parentheses_score("()()(())");
  printf("%d\n\n", answer);

  answer = parentheses_score("()(())");
  printf("%d\n\n", answer);

  answer = parentheses_score("(()()(()(()()()()))(()()()())())");
  printf("%d\n\n", answer);

  answer = parentheses_score("(()()(()(()())()))");
  printf("%d\n\n", answer);

  return 0;
}
