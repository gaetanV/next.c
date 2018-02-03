#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/query.c"
#include "./lib/compileJs.c"



int main(void)
{
    printf("Content-type:text/html\n\n");
    printf("<html><body>__JavaScript__");

    char *param1;
    param1 = getenv("QUERY_STRING");
    
    if(param1 != NULL){


        printf("<div>File %s</div>",param1);
    
        printf("<ul>");
            printf("<li><a onclick=\"Route('page1')\">1</a></li>");
            printf("<li><a onclick=\"Route('page2')\">2</a></li>");
        printf("</ul>");

        CompileJs(param1);
        
    }
    printf("<script src='./js/route.js'></script>");
    printf("<script src='./js/component.js'></script>");
    printf("</body></html>");
    return 0;
}


