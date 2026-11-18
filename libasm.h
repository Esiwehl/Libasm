#ifndef LIBASM_H
# define LIBASM_H

# include <stddef.h>
# include <sys/types.h>

#define STDIN   0
#define STDOUT  1
#define STDERR  2

#define SEPERATOR "------------------------------------------------\n"

ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *s);

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);

#endif