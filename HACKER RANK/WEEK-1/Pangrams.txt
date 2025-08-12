#include <stdio.h>
#include <ctype.h>
#include <string.h>
int check_all_letters(const char*text) {
    int letters[26]={0};
    const char *p=text; 
    while (*p){
        if (isalpha(*p)){
            letters[tolower(*p)-'a']=1;
        }
        p++;  }
    for (int idx=0;idx<26;idx++) {
        if (!letters[idx])
            return 0;
    }
    return 1;
}
int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input,"\n")] ='\0'; 

    if (check_all_letters(input))
        printf("pangram\n");
    else
        printf("not pangram\n");
    return 0;
}
