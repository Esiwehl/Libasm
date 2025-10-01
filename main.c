#include "stdio.h"
#include "types.h"
#include "string.h"

#define STDIN   0
#define STDOUT  1
#define STDERR  2

#define SEPERATOR "------------------------------------------------\n"

size_t ft_strlen(char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);

void strlen_test(){
    char* str = "Hello World! :D";
    size_t len = ft_strlen(str);
    size_t anotherLen = strlen(str);
    printf("\tlen\t= %zu\n\togl\t= %zu\n", len, anotherLen);
}

void write_test(){
    char *str = "This is what we're writing ;)";
    ft_write(STDIN, str, strlen(str));
    write(STDIN, str, strlen(str));
}

int main( void )
{
    printf("\t\tSTRLEN TEST :D\n");
    printf(SEPERATOR);
    strlen_test();
    printf(SEPERATOR);
    write_test();
    return (0);
}