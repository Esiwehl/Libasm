#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define STDIN   0
#define STDOUT  1
#define STDERR  2

#define SEPERATOR "------------------------------------------------\n"

size_t ft_strlen(char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *s);

char *ft_strcpy(char *dest, const char *src);

void strlen_test(){
    char* str = "Hello World! :D";
    size_t len = ft_strlen(str);
    size_t anotherLen = strlen(str);
    printf("\tlen\t= %zu\n\toglen\t= %zu\n", len, anotherLen);
}

void write_test(){
    char *str = "This is what we're writing ;)\n";
    int test = ft_write(STDOUT, str, ft_strlen(str)); 
    if (test < 0)
    {
        printf("Errno %d: %s\n", errno, strerror(errno));
        return;
    }
}

void read_test(){
    int buffsize = 256;
    char buff[buffsize];
    char a;
    int i = 0;
    int test = 0;

    while ((test = ft_read(44, &a, 1)) > 0 && i < 256)
    {
        buff[i] = a;
        i++;
    }
    if (test < 0)
    {
        printf("Errno %d: %s\n", errno, strerror(errno));
        return;
    }
    else
        printf("\nThis is what we read = \"%s\"", buff);
}

void strcpy_test(){
    char test[20] = "we are copying this";
    char copy[21] = "the copied string...";

    printf("Before: %s | %s \n", test, copy);
    ft_strcpy(copy,test);
    // strcpy(copy,test);
    printf("_After: %s | %s \n", test, copy);
    // printf("Copied bytes: %s\n", copied_bytes);
}

void strcmp_test(){
    char *s1 = "testing";
    char *s2 = "testi";

    int retval =  ft_strcmp(s1, s2);
    int ogretval =  strcmp(s1, s2);

    printf("retval = %d\n" ,retval);
    printf("ogretval = %d\n", ogretval);
}

void strdup_test(){
    char *dupped;
    char *og = "You got this :)";
    // char *og = NULL;

    dupped = ft_strdup(og);
    if (!dupped) printf("something went wrong\n");
    else {
        printf("I was dupped correctly\n");
        printf("str = %s\n", dupped);
    }
    free(dupped);
}

int main( void )
{
    printf("\t\tSTRLEN TEST :D\n");
    printf(SEPERATOR);
    // strlen_test();
    
    printf("\n\t\t WRITE TEST :D\n");
    printf(SEPERATOR);
    // write_test();

    printf("\n\t\t READ TEST :D\n");
    printf(SEPERATOR);
    // read_test();

    printf("\n\t\t STRCPY TEST :D\n");
    printf(SEPERATOR);
    // strcpy_test();

    printf("\n\t\t STRCMP TEST :D\n");
    printf(SEPERATOR);
    strcmp_test();

    printf("\n\t\t STRDUP TEST :D\n");
    printf(SEPERATOR);
    strdup_test();
    return (0);
}