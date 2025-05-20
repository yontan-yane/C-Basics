#include<stdio.h>
#define MAX_LIMIT 20

int main() {
  char str[MAX_LIMIT];
  fgets(str, MAX_LIMIT, stdin);

  int w_len[MAX_LIMIT];
  int w_len_idx = 0, temp_len = 0, idx = 0, max_len = 0;
  while(str[idx] != '\n') {
    if(str[idx] == ' ') {
      w_len[w_len_idx++] = temp_len;
      temp_len = 0;
    } else temp_len++;
    max_len = temp_len > max_len ? temp_len : max_len;
    idx++;
  }
  
  max_len = temp_len > max_len ? temp_len : max_len;
  w_len[w_len_idx++] = temp_len; 
  
  for(int i=0;i<max_len;++i) {
    for(int j=0;j<w_len_idx;++j) {
      printf("%s", max_len - w_len[j] - i <= 0 ? "|" : " ");
    }
    printf("\n");
  }
}
