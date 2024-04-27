#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substitution(string s, string key);
bool only_letters(string s);
char roller(char c, string k);
bool duplicates(string s);
int main(int argc, string argv[]){

    if(argv[1] != NULL && argv[2] == NULL){
        if(strlen(argv[1]) != 26 ){
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        if(only_letters(argv[1]) == 0){
            if(duplicates(argv[1]) != 0){
                return 1;
            }else{
                string plaintext = get_string("plaintext: ");
                char* cipher = substitution(plaintext, argv[1]);
                printf("ciphertext: %s\n", cipher);
                free(cipher);
            }

        }else{
            return 1;
        }
        return 0;
    }else{
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool only_letters(string s){
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        if(!isalpha(s[i])){
            return 1;
        }
    }
    return 0;
}

bool duplicates(string s){
    int n = strlen(s);
    int buffer = 0;

    for(int i = 0; i < n; i++){
        buffer += (int) toupper(s[i]) % 26;
    }
    if(buffer != 325){
        return 1;
    }

    return 0;
}

char roller(char c, string k){
    int n = strlen(k);
    if(isalpha(c)){
        char base = islower(c) ? 'a' : 'A';
        char new = k[(int)(c - base) % 26];
        if(islower(base)){
            return tolower(new);
        }else{
            return toupper(new);
        }
    }
    return c;
}

char* substitution(string s, string key){
    int n = strlen(s);
    char* cipher = malloc((n + 1) * sizeof(char));
    if (cipher == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for(int i = 0 ; i < n; i++){
        cipher[i] = roller(s[i], key);
    }
    cipher[n] = '\0';
    return cipher;
}

