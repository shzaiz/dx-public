#include <stdio.h>
void hanoi(int n, char from, char to, char via) {
  printf("hanoi(n=%d, from=%c, to=%c, via=%c)\n", n, from, to, via);
  if (n == 1) {
    printf("%c -> %c\n", from, to);
  } else {
    hanoi(n - 1, from, via, to);
    hanoi(1,     from, to,  via);
    hanoi(n - 1, via,  to,  from);
  }
}

int main(){
  hanoi(3, 'A', 'C', 'B');
  return 0;
}
