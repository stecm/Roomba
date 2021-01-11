#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moves.h"
#include "map.h"
#include "communication.h"



int main(int argc, char **argv)
{   
    char *token = "qwerty_17";

    for(int i = 2; i < argc; i++){

        if(strcmp(argv[i], "info") == 0)
            info(token);
          
        else if(strcmp(argv[i], "explore") == 0)
        {
            explore(token);
        }
        else if(strcmp(argv[i], "move") == 0)
        {
            move(token);
        }
        else if(strcmp(argv[i], "rotate") == 0)
        {
            rotate(token, argv[i+1]);
            i++;
        }
        else if(strcmp(argv[i], "reset") == 0)
        {
            reset(token);
        }
        else
        {
            printf("Error, nieznana komenda, użyj 'info','move','rotate', 'reset' lub 'explore'\n");
        }    
    }

    return 0;
}