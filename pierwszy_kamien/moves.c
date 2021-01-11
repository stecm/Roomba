#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "moves.h"




int move(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/qwerty_17");
    return 0;
}

int rotate_left(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_17/left");
    return 0;
}

int rotate_right(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_17/right");
    return 0;
}

int explore(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_17");
    return 0;
}