#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define CHARS 10 

typedef struct text_t { char ** t; int words;} Text_t;
Text_t readText(void);


int main(void) {
    Text_t myText;
    int i;
    
    myText = readText();
    for (i=0; i<myText.words; i++) 
        printf("%s\n", myText.t[i]);  

    return 0; 
}

Text_t readText(void) { 
    Text_t myText;
    myText.t = NULL; 
    char *word; 
    int i;
    myText.words = 0; 

    while (scanf("%s", word = malloc(CHARS * sizeof(char))), strcmp(word,"TELOS")) {  // to malloc(CHARS * sizeof(char)) einai pollaplasiasmos CHARS x sizeof(char) opou to sizeof(char) einai panta 1 byte
        myText.words ++;
        myText.t = realloc(myText.t, (myText.words) * sizeof(char *)); //to realloc pairnei to mytext kai to kanei resize kanontas return thn nea dieuthynsh, sizeof(char *) einai 4 byte se 32bit systhma kai 8byte se 64bit
        myText.t[myText.words-1] = word; 
    }
    
    free(word);  
    
    return myText; 
}