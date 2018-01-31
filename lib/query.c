struct Buffer {
    int *index;
    int cmp;
};

const char CH_AND = '&';
const char CH_MARK = '?';
const char CH_EGAL = '=';

int QueryParam(struct Buffer* buffer,char* param1,int size,int pos) {
    int posInit = pos;
 
    buffer->index =(int*) malloc( (size-pos)/2 * sizeof (int));
    buffer->cmp = 0;

step1:
    for (;pos<size;pos++){
        if(param1[pos]==CH_EGAL){
            buffer->index[buffer->cmp++] = pos;
            goto step2;
        }
    }
    goto end;
step2:
    for (;pos<size;pos++){
        if(param1[pos]==CH_AND){
                buffer->index[buffer->cmp++] = pos;
            goto step1;
        }
    }
end:
    buffer->index[buffer->cmp++] = pos;
    return pos;

}
