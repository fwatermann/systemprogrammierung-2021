#include "ledanzeige/TM1637.h"

#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>

void LED_Demo(){
    int i;
    TM1637_setup();
    /*for(i=0; i<20; i++){
        TM1637_display_number(420.1f);
        printf("Showing: %d\n", i);
        delayMicroseconds(1000*1000);
    }*/
    TM1637_clear_display();
}

int main(){
    LED_Demo();
    return 0;
}