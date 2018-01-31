#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/query.c"

int main(void)
{

    printf("Content-type:text/html\n\n");

    printf("<html><body>");
    struct Buffer buffer;

    char *param1;
    param1 = getenv("QUERY_STRING");
    
    if(param1 != NULL){
        
        int posInit = 0;
        char *param;
        int diff;

        QueryParam(&buffer,param1,strlen(param1),0);

        for(int k = 0 ; k < buffer.cmp  ; k++){

            diff = (buffer.index[k]) - posInit  ;

            param =(char*) malloc( diff  * sizeof (char));
            memcpy(param , param1 + (posInit * sizeof(char)), diff );

            param[diff] = '\0';
            
            switch(k%2) {
                case 0:
                    printf("<div>");
                    printf("<div>Param %d</div>",k/2);
                    printf("$ : %s <br/>",param);
                    break;
                case 1:
                    printf("= : %s <br/>",param);
                    printf("</div>");
                    break;
            }

            posInit+=diff+1;
        }

        free(param);
     
    }

    printf("</body></html>");

    free(buffer.index);

    return 0;
}


