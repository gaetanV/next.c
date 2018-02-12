#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./query.c"

int main(void)
{
    char *param1;

    printf("Content-type:text/html\n\n");

    printf("<html><body>__API__");

    param1 = getenv("QUERY_STRING");
  
    if (param1 != NULL){
        
        int len;
        char *param;
        int pos;

        len = strlen(param1);
        pos = NextQuery(param1,len,0);

        if (pos==0) {

            printf("<div>File %s</div>",param1);

        } else {

            int diff;
            struct Buffer buffer;

            param =(char*) malloc( pos  * sizeof (char));
            memcpy(param , param1 , pos );
            param[pos] = '\0';
    
            printf("<div>File %s</div>",param);

            QueryParam(&buffer,param1,len,++pos);

            for(int k = 0 ; k < buffer.cmp  ; k++){

                diff = (buffer.index[k]) - pos  ;

                param =(char*) malloc( diff  * sizeof (char));
                memcpy(param , param1 + (pos * sizeof(char)), diff );

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

                pos+=diff+1;

            }

            free(param);

        }
    }
   
    printf("</body></html>");
    
    return 0;
}