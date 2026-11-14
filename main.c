#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define STDIN   0
#define STDOUT  1
#define STDERR  2

#define SEPERATOR "------------------------------------------------\n"

size_t ft_strlen(char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);

char *str = "This is what we're writing ;)\n";
void strlen_test(){
    // char* str = "Hello World! :D";
    size_t len = ft_strlen(str);
    size_t anotherLen = strlen(str);
    printf("\tlen\t= %zu\n\toglen\t= %zu\n", len, anotherLen);
}

void write_test(){
    int test = ft_write(STDIN, str, 12); 
    if (test < 0)
    {
        // strerror(errno);
        printf("Errno %d: %s\n", errno, strerror(errno));
        return;
    }
    // write(STDIN, str, strlen(str));
}

int main( void )
{
    printf("\t\tSTRLEN TEST :D\n");
    printf(SEPERATOR);
    strlen_test();
    printf("\t\t WRITE TEST :D\n");
    printf(SEPERATOR);
    write_test();
    return (0);
}