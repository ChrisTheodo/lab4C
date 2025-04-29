#include <stdio.h> 
#include <string.h> 

struct charact { 
    char ch; //o xarakthras
    int occurs; //poses fores yparxei
}; 
typedef struct charact Char;

Char countfirstletter(char name[50]); 
void report(Char temp);  

int main(void) { 
    char name[50]; 
    Char first;
    
    printf("Please input a word (<50): ");
    scanf("%49s", name);
    first = countfirstletter(name); 
    report(first);  
    
    return 0; 
}

Char countfirstletter(char name[50]) { 
    Char temp ; 
        /* Your code here! No printf or equivalent!!! 
        (6 to 10 lines) */  

    temp.ch = name[0];
    temp.occurs = 0;

    for (int i=0; i<50; i++){
        if (name[i]==temp.ch){temp.occurs++;}
    }

    return temp;    
}  

void report(Char t) { 
        /* Your code here! (two lines) */ 
    
        printf("%c\n%d\n", t.ch, t.occurs);
    
    return; 
}