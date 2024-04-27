#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);
char* ciphertext(string s, int key);
int main(int argc, string argv[]){

    if(argv[1] != NULL && argv[2] == NULL){

        if(only_digits(argv[1]) == 0){
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            char* cipher = ciphertext(plaintext, key);
            printf("ciphertext: %s\n", cipher);
            free(cipher);
        }else{
            printf("Usage: ./caesar key\n");
            return 1;
        }
        return 0;
    }else{
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string s){
    for(int i = 0, n = strlen(s); i < n; i++){
        if(isdigit(s[i])){
        }else{
            return 1;
        }
    }
    return 0;
}

char rotate(char c, int n){
    if(isalpha(c)){
        char base = islower(c) ? 'a' : 'A';
        return (c - base + n) % 26 + base;
    }
    return c;
}

char* ciphertext(string s, int key){
    int n = strlen(s);
    char* cipher = malloc((n + 1) * sizeof(char));
    if (cipher == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for(int i = 0 ; i < n; i++){
        cipher[i] = rotate(s[i], key);
    }
    cipher[n] = '\0';
    return cipher;
}