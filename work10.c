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
    }
    char msg[] = "the program exited due to SIGINT\n";
    write(fd, msg, sizeof(msg));
    close(fd);
    exit(1);
  }

  if (signo == SIGUSR1) {
    printf("%d\n", getppid());
  }
}

int main()
{
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    printf("%d\n", getpid());
    sleep(1);
  }
  
  return 0;
}
