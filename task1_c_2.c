#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define CHARS 10 

struct charact { 
    char ch; 
    int occurs;
};
typedef struct charact Char;

typedef struct text_t { char ** t; int words;} Text_t;
Text_t readText(void);

void letters(char name[50], Char chars[50]); 
void report(Char chars[50]);

int main(void) {  
    Char chars[50];
    Text_t myText;
    
    myText = readText();
    
    for (int i=0; i<myText.words; i++){
        printf("\nWord: %s", myText.t[i]);
        letters(myText.t[i], chars); 
        report(chars);

    }

    return 0;
} 

void initialize(Char chars[50]) { 
    int i; 
    
    for (i=0;i<50;i++) { 
        chars[i].ch = '\0'; 
        chars[i].occurs = 0;
    } 
    
    return;
} 

void letters(char name[50], Char chars[50]) { 
    size_t i=0, j;
    initialize(chars); 

        /* Your code here! No printfs or equivalent 
        (No more than 15 lines, are required. Can be done with less) */ 
    while(name[i] != '\0'){
        for (j=0; j<50;j++){
            
            if (chars[j].ch == '\0'){
                chars[j].ch = name[i];   //an den yparxei auto to gramma sta chars to prostheto 
                chars[j].occurs = 1;
                break; 
            }
            
            else if (chars[j].ch == name[i]){
                chars[j].occurs++;
                break;
            }
        }
        
        i++; //epomeno gramma
    }

    return;
} 

void report(Char t[50]) { 
        /* your code here (5-6 lines) */ 
        int i=0;

        while (t[i].ch != '\0'){
            printf("\n%c: %d", t[i].ch, t[i].occurs);
            i++;
        }
    
    return;
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