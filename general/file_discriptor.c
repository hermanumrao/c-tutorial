#include <unistd.h>
#include <string.h>
void main()
{
    char buff[20];
    char hello[20]="I Am ";
    read(0,buff,20);
    strcat(hello,buff);
    write(1,hello,strlen(hello));
}
/*Here we are reading characters from stdin by using File Descriptor 0 [ read() at line 7 ] 
and then after concatenating it with a message [ strcat() at line 8 ] and then writes the 
resultant string to the I/On stream pointed to by File Descriptor 1, 
i.e, stdout [ write() at line 9 ].*/