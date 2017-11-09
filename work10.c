#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static void sighandler(int signo)
{
  if (signo == SIGINT) {
    int fd;
    fd = open("program_exited.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
      printf("%s\n", strerror(errno));
      exit(1);
    }
    char msg[] = "the program exited due to SIGINT";
    write(fd, msg, sizeof(msg));
    close(fd);
    exit(1);
  }

  
}
