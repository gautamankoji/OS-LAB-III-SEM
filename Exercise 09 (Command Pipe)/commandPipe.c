#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pfds[2];
    char buf[80];
    if (pipe(pfds) == -1) {
        perror("pipe failed");
        exit(1);
    }
    if (!fork()) {
        close(1);
        dup(pfds[1]);
        close(pfds[0]);
        system("ls -l");
    } else {
        close(0);
        dup(pfds[0]);
        close(pfds[1]);
        printf("parent reading from pipe \n");
        while (read(0, buf, 80))
            printf("%s \n", buf);
    }
    return 0;
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

[student@gcet ~]$ vi pipes2.c
[student@gcet ~]$ cc pipes2.c
[student@gcet ~]$ ./a.out
Parent reading from pipe
Total 24
-rwxrwxr-x l student student 5563Aug 3 10:39 a.out
-rw-rw-r—l
Student student 340 jul 27 10:45 pipe2.c
-rw-rw-r—l student student
Pipes2.c
-rw-rw-r—l student student 401 34127 10:27 pipe2.c
student

--------------[END-OF-OUTPUT]--------------

*/
