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
        int i = 0;

        QueryParam(&buffer,param1,strlen(param1),0);

        for(int k = 0 ; k < buffer.cmp  ; k++){

            char *param;
            param =(char*) malloc( ( (buffer.index[k]) -posInit) -1 * sizeof (char));

            i = 0;
            for(;posInit < (buffer.index[k]) ; posInit++){
                param[i] = param1[posInit];
                i++;
            }

            param[i] = '\0';
         
            switch(k%2) {
                case 0:
                    printf("<div>");
                    printf("<div>Param %d</div>",posInit);
                    printf("$ : %s <br/>",param);
                    break;
                case 1:
                    printf("= : %s <br/>",param);
                    printf("</div>");
                    break;
            }

            posInit++;

        }
     
     }

    free(buffer.index);
    printf("</body></html>");
    return 0;
}


