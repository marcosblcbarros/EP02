#define _GNU_SOURCE
#include <stdio.h>
#include <sys/utsname.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    struct utsname uts;

    if (uname(&uts) == -1) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    printf("Sistema: %s\n", uts.sysname);
    printf("Nome do host: %s\n", uts.nodename);
    printf("Versão: %s\n", uts.release);
    printf("Versão do SO: %s\n", uts.version);
    printf("Arquitetura: %s\n", uts.machine);

    return 0;
}
