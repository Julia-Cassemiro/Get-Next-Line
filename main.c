#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int    main(void)
{
    int fd1 = open("file1", O_RDONLY);
    int fd2 = open("file2", O_RDONLY);
    int fd3 = open("file3", O_RDONLY);

    char *line;
    get_next_line(fd1, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd1, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd2, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd2, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd1, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd2, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd3, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd1, &line);
    printf("%s\n", line);



    close(fd1);
    close(fd2);
    close(fd3);
    free(line);
    return (0);
}