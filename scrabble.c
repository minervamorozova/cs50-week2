#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score(string word);

int main(){
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = score(player1);
    int score2 = score(player2);
    
    if(score1 > score2){
        printf("Player 1 wins!\n");
    }else if(score1 < score2){
        printf("Player 2 wins!\n");
    }else{
        printf("Tie!\n");
    }
}

int score(string word){

    int buffer = 0;
    int value = 0;
    for(int i = 0, n = strlen(word); i < n; i++){
        value = toupper(word[i])-65;
        if(value >= 0 && value <= 24){
            buffer += POINTS[value];
        }
    }

    return buffer;
}
