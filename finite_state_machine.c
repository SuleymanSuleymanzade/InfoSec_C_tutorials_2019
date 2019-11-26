#include <stdio.h>

enum state{ON, OFF, BLINK};

void lamp_on();
void lamp_off();
void lamp_blink();

void (*lamp_state)() = lamp_off;
enum state global_state = OFF;
int change_state = 0;

int main()
{   
    while(scanf("%d",&change_state)!=0){

        //scanf("%d",&change_state);
        
        if(global_state == OFF)
            lamp_state = lamp_off;
        if(global_state == ON)
            lamp_state = lamp_on;
        if(global_state == BLINK)
            lamp_state = lamp_blink;
        
        
        lamp_state();
        
        
        
    }

    return 0;
}

void lamp_on(){
    printf("lamp on\n");
    global_state = ON;
    if(change_state)
        global_state = BLINK;
}
void lamp_off(){
    printf("lamp off\n");
    global_state = OFF;
    if(change_state)
        global_state = ON;

}
void lamp_blink(){
    printf("lamp blink\n");
    global_state = BLINK;
        if(change_state)
            global_state = OFF;
}
