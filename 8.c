#include <stdio.h>
#include <string.h>

int textTable[256];

void table(char pattern[]) {
    int patternLength = strlen(pattern);

    for(int i = 0; i<256; i++) {
        textTable[i] = patternLength;
    }

    for(int i = 0; i < patternLength-1; i++) {
        textTable[pattern[i]] = patternLength-i-1;
    }
} 

int horspools(char text[], char pattern[]) {

    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int i = patternLength - 1;

    while(i < textLength) {
        int k = 0;

        while(k < patternLength && text[i-k] == pattern[patternLength-k-1]) {
            k++;
        }

        if(k == patternLength) {
            return i - patternLength + 1;
        } else {
            i = i + textTable[text[i]];
        }
    }
    return -1;
}

void main() {

    char text[50];
    char pattern[10];
    printf("Enter the text: \n");
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")] = '\0';

    printf("Enter the pattern: \n");
    fgets(pattern,sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    table(pattern);

    int res = horspools(text, pattern);
    if(res < 0) {
        printf("No such pattern found");
    } else {
        printf("The pattern found at: %d", res);
    }
}