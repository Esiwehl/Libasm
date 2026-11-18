#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "libasm.h"

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

    printf("Enter something: ");
    fflush(stdout);
    
    while ((i < buffsize - 1) && (test = ft_read(44, &a, 1)) > 0)
    {
        if (a == '\n') break;
        buff[i] = a;
        i++;
    }
    buff[i] = '\0';
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
    char *retval = ft_strcpy(copy,test);
    // strcpy(copy,test);
    printf("_After: %s | %s \n", test, copy);
    printf("Returned original destination: %s\n",
    retval == copy ? "YES" : "NO");
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

    printf("Original address: %p\n", (void *)og);
    printf("Copied address:   %p\n", (void *)dupped);

    free(dupped);
}

void list_test(){
    t_list *head = NULL;
    t_list *current;

    ft_list_push_front(&head, "first");
    ft_list_push_front(&head, "second");
    ft_list_push_front(&head, "third");

    printf("List size: %d\n", ft_list_size(head));

    current = head;
    while (current)
    {
        printf("Node: %s\n", (char *)current->data);
        current = current->next;
    }

    while (head)
    {
        current = head;
        head = head->next;
        free(current);
    }
}

int main( void )
{
    printf("\t\tSTRLEN TEST :D\n");
    printf(SEPERATOR);
    strlen_test();
    
    printf("\n\t\t WRITE TEST :D\n");
    printf(SEPERATOR);
    write_test();

    printf("\n\t\t READ TEST :D\n");
    printf(SEPERATOR);
    read_test();

    printf("\n\t\t STRCPY TEST :D\n");
    printf(SEPERATOR);
    strcpy_test();

    printf("\n\t\t STRCMP TEST :D\n");
    printf(SEPERATOR);
    strcmp_test();

    printf("\n\t\t STRDUP TEST :D\n");
    printf(SEPERATOR);
    strdup_test();

    printf("\n\t\t LIST TEST :D\n");
    printf(SEPERATOR);
    list_test();
    return (0);
}