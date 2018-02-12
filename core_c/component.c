#include <stdlib.h>
#include <string.h>
#include "./io.c"

char * component(char *param,char *(*IO_HTTP)()) {
    char *a = IO_HTTP();
    int l = strlen(a) + strlen(param) + 1;
    char *response =  (char*) malloc(l * sizeof (char));

    if (strlen(param) > 0) {
        strcpy(response, param );
        strcat(response," ");
        strcat(response, a );
        response[l] = '\0';
    } else {
        strcpy(response, a);
        response[l] = '\0';
    }

    return response;
}