#include "ledanzeige/TM1637.h"

#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

void LED_Demo(){
    int i;
    TM1637_setup();
    while(1) {
        TM1637_display_number((float)i);
        printf("Showing: %d\n", i);
        i ++;
        if(i > 999) {
            i = 0;
        }
    }
}

int main(){
    LED_Demo();
    return 0;
}