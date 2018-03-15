/* ISC license. */

#include <skalibs/types.h>
#include <skalibs/strerr2.h>
#include <skalibs/djbunix.h>

#define USAGE "<> fd1 fd2 prog..."

int main (int argc, char const *const *argv, char const *const *envp)
{
  unsigned int fd1, fd2 ;
  PROG = "<>" ;
  if ((argc < 4) || !uint0_scan(argv[1], &fd1) || !uint0_scan(argv[2], &fd2))
    strerr_dieusage(100, USAGE) ;
  if (fd_move2(fd1, fd2, fd2, fd1) < 0) strerr_diefu1sys(111, "swap fds") ;
  xpathexec_run(argv[3], argv+3, envp) ;
}
