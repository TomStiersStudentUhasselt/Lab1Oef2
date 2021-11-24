//
// Created by tomst on 24/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "orcs.h"

int main(){
    srand(time (NULL));

    printf("Hoeveel orcs?\n");
    int aantal;
    scanf("%d", &aantal);

    Orc* leger = generateOrcs(aantal);

    for(int i=0; i<aantal; i++){
        Orc beest = leger[i];
        printf("Orc %d: aanval %d, levens %d\n", i+1, beest.aanval, beest.levens);
    }

    printf("De orcs beginnen onderling te vechten...\n");

    Orc winnaar = leger[0];

    for(in i=1; i<aantal; i++){
        Orc verdediger = leger[i];
        printf("\n%d,%d VS %d,%d\n", winnaar.aanval, winnaar.levens, verdediger.aanval, verdediger.levens);
        winnaar = vecht(winnaar, verdediger);
        printf("Orc %d,%d wint en heeft nog %d levens(s)\n", winnaar.aanval, winnaar.levens, winnaar.levens);
    }

    printf("\nOrc met %d aanval is de laatst overlevende!\n", winnaar.aanval);

    return 0;
}
