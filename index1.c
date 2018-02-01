#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/query.c"

int main(void)
{

    char *param1;

    printf("Content-type:text/html\n\n");

    printf("<html><body>__1__");

    param1 = getenv("QUERY_STRING");

    if (param1 != NULL) {

        char * param;
        int len;
        int pos0;
        int pos1;
        int diff;

        len = strlen(param1);
        pos0 = NextQuery(param1,len,0);
    
        param = (char*) malloc( pos0  * sizeof (char));
        memcpy(param , param1 , pos0 );
        param[pos0] = '\0';

        printf("<div>Repertory %s</div>",param);

        pos1 = NextQuery(param1,len,++pos0);

        if (pos1 == 0) {
            
            diff = len - pos0;

            param = (char*) malloc( diff * sizeof (char));
            memcpy(param , param1 + (pos0* sizeof (char)), diff );
            
            param[diff] = '\0';

            printf("<div>File %s</div>",param);

        } else {

            struct Buffer buffer;

            diff = pos1 - pos0;

            param =(char*) malloc( diff  * sizeof (char));
            memcpy(param , param1 + (pos0* sizeof (char)), diff );
        
            param[diff] = '\0';

            printf("<div>File %s</div>",param);
    
            QueryParam(&buffer,param1,len,++pos1);
     
            for(int k = 0 ; k < buffer.cmp  ; k++){

                diff = (buffer.index[k]) - pos1  ;

                param = (char*) malloc( diff  * sizeof (char));
                memcpy(param , param1 + (pos1 * sizeof(char)), diff );

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

                pos1+=diff+1;

            }
        }

        free(param);
    }

    printf("</body></html>");
    
    return 0;
}


