#include <stdio.h> 
#include <string.h> 

struct charact { 
    char ch; 
    int occurs;
};
typedef struct charact Char;

void letters(char name[50], Char chars[50]); 
void report(Char chars[50]);

int main(void) { 
    char name[50]; 
    Char chars[50];
    
    printf("Please input a word (<50): ");
    scanf("%49s", name);
    letters(name, chars); 
    report(chars);  
    
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
            printf("%c: %d\n", t[i].ch, t[i].occurs);
            i++;
        }
    
    return;
}