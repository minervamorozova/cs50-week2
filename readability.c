#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void){
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    int index = round ((0.0588 * letters/words*100) - (0.296 * sentences/words*100)- 15.8);
    // Print the grade level
    if(index < 1){
        printf("Before Grade 1\n");
    }else if(index >= 16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %i\n", index);
    }
}

int count_letters(string text){
    int count = 0;
    for(int i = 0, n = strlen(text); i < n; i++){
        if(isalpha(text[i])){
            count++;
        }
    }
    return count;
}

int count_words(string text){
    int count = 0;
    for( int i = 0, n = strlen(text); i < n; i++){
        if(text[i] == ' '){
            count++;
        }else if((text[i] == '.' || text[i] == '?' || text[i] == '!') && isalpha(text[i-1]) && text[i+1] != ' '){
            count++;
        }

    }
    return count;
}

int count_sentences(string text){
    int count = 0;
    for( int i = 0, n = strlen(text); i < n; i++){
        if((text[i] == '.' || text[i] == '?' || text[i] == '!')){
            count++;
        }
    }

    return count;
}
