#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON/cJSON.h"
#include "map.h"
#define N 30

Canvas *stworz(){
    Canvas *new;
    new = (Canvas*) malloc(sizeof(Canvas));
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++)
            new->index[i][j] = '0'; 
    }
    
    return new;
}

Canvas * dodaj(Canvas *C, Map *M){
    Canvas *new = C;
    return new;
}


Map * wczytaj_json(Map *M, const char *const dane){
    Map *new;
    const cJSON *jj = NULL;
    const cJSON *status;
    const cJSON *payload;
    const cJSON *name;
    const cJSON *current_x;
    const cJSON *current_y;
    const cJSON *current_session;
    const cJSON *direction;
    const cJSON *step;
    const cJSON *field_type;
    const cJSON *field_bonus;

    cJSON *dane_cjson = cJSON_Parse(dane);

    status = cJSON_GetObjectItemCaseSensitive(dane_cjson, "status");
    new->status = status->valuestring;

    payload = cJSON_GetObjectItemCaseSensitive(dane_cjson, "payload");
        cJSON_ArrayForEach(jj, payload)
        {
            cJSON *name = cJSON_GetObjectItemCaseSensitive(payload, "name");
            new->name = name->valuestring;

            cJSON *current_x = cJSON_GetObjectItemCaseSensitive(payload, "current_x");
            new->current_x = current_x->valueint;

            cJSON *current_y = cJSON_GetObjectItemCaseSensitive(payload, "current_y");
            new->current_y = current_y->valueint;
            
            cJSON *current_session = cJSON_GetObjectItemCaseSensitive(payload, "current_session");
            new->current_session = current_session->valuestring;

            cJSON *direction = cJSON_GetObjectItemCaseSensitive(payload, "direction");
            new ->direction = direction->valuestring;

            cJSON *step = cJSON_GetObjectItemCaseSensitive(payload, "step");
            new->step = step->valueint;

            cJSON *field_type = cJSON_GetObjectItemCaseSensitive(payload, "field_type");
            new->field_type = field_type->valuestring;

            cJSON *field_bonus = cJSON_GetObjectItemCaseSensitive(payload, "field_bonus");
            new->field_bonus = field_bonus->valuestring;
        }
    
    return new;
}

Map_explore *wczytaj_json_explore(Map_explore *M, const char *const dane){
    Map_explore *new = NULL;
    new = (Map_explore*) malloc(sizeof(Map_explore));
    int i =0;
    const cJSON *jj = NULL;
    const cJSON *status =NULL;
    const cJSON *payload =NULL;
    const cJSON *list =NULL;
    
    cJSON *dane_cjson = cJSON_Parse(dane);

    status = cJSON_GetObjectItemCaseSensitive(dane_cjson, "status");
    new->status = status->valuestring;

    payload = cJSON_GetObjectItemCaseSensitive(dane_cjson, "payload");

    list = cJSON_GetObjectItemCaseSensitive(payload, "list");

    cJSON_ArrayForEach(jj, list){
        
        cJSON *x = cJSON_GetObjectItemCaseSensitive(jj, "x");
        cJSON *y = cJSON_GetObjectItemCaseSensitive(jj, "y");
        cJSON *type = cJSON_GetObjectItemCaseSensitive(jj, "type");

        new->x[i]=x->valueint;
        
        new->y[i]=y->valueint;
        new->type[i] = (char*) malloc(sizeof(char) * strlen((type->valuestring) + 1));
        strcpy(new->type[i], type->valuestring);
        i++;
    }
    return new;
}



void print_map(int map[N][N])
    {
        int i,j;
        for(j=0;j<N;j++)
        {
            for(i=0;i<N;i++)
            {
                if(j==N-1)
                printf("%d\n", map[j][i]);
                else
                printf("%d",map[j][i]);
            }
        }
    }

void save_map(int map[N][N])
{
    int i, j;
    
    FILE * fin = fopen("Logo_Worlds_map.txt", "w");
    for(j=0;j<N;j++)
        {
            for(i=0;i<N;i++)
            {
                if(j==N-1)
                fprintf("%d\n", map[j][i]);
                else
                fprintf("%d",map[j][i]);
            }
        }
        fclose(fin);
}


