#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
//#include "../../cJSON/cJSON.h"

typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;

static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    Memory *mem = (Memory *) userp;
    char *ptr = NULL;

    if (mem->response != NULL)
        ptr = realloc(mem->response, mem->size + realsize + 1);
    else
        ptr = malloc(mem->size + realsize + 1);
    if (ptr == NULL)
        return 0; 

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0; 

    return realsize;
}
char * make_request(char *url)
{
    CURL *curl;
    CURLcode res;
    Memory chunk;
    chunk.size = 0;
    chunk.response = NULL;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "Błąd! curl_easy_perform() niepowodzenie: %s\n", curl_easy_strerror(res));
        else
        {
            //printf("%s\n", chunk.response);
        }

        free(chunk.response);
        curl_easy_cleanup(curl);
    }
}

int move(char *token) {
make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/qwerty_17");
return 0;
}
int left(char *token) {
make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_17/left");
return 0;
}
int right(char *token) {
make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_17/right");
return 0;
}
int explore(char *token) {
make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_17");
printf("\n");
return 0;
}
int info(char *token) {
make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/info/qwerty_17");
return 0;
}
int main(int argc, char **argv)
{
    char *token="qwerty_17";

    for(int i=1; i<argc;i++)
    {
    if(strcmp(argv[i], "i") == 0){
    info(token);
    }
    if(strcmp(argv[i], "e") == 0){
    explore(token);
    }
    if(strcmp(argv[i], "r") == 0){
    right(token);
    }
    if(strcmp(argv[i], "m") == 0){
    move(token);
    }
    if(strcmp(argv[i], "l") == 0){
    left(token);
    }


//stworzenie mapy
int mapa[100][100];
for(int i = 0; i < 100; i++)
{
    for(int j = 0; j < 100; j++)
    {
        mapa[i][j] = 0;
    }
}



//wypisanie mapy
for(int i = 0; i < 100; i++)
{
    for(int j = 0; j < 100; j++)
    {
        printf("%4d\n",mapa[i][j]);
    }
}

//przechwanie danych (chunk.response) w tablicy
dane[1000] = chunk.response;

//podzial dane na poszczegolne info
dane2[1000] = strtok(dane[1000]; ":");




}
return 0;
}

