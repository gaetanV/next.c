
#include <stdio.h>

void CompileJs(char* param){

    printf("<r id=\"c1\">");

    FILE *fp;

    char *path;
    path = (char*) malloc( (20 + strlen(param)) * sizeof (char));

    strcpy(path, "node ./lib/node.js ");
    strcat(path, param);

    fp = popen(path, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    pclose(fp);


    printf("</r>");
    
}