//
// launch_game.cpp for freewar in /u/ept2/ribas_j/freewar
// 
// Made by jonathan ribas
// Login   <ribas_j@epita.fr>
// 
// Started on  Mon May  3 14:55:42 2004 jonathan ribas
// Last update Tue Jun 29 19:01:04 2004 jonathan huot
//

#include "freewar.h"

int	launch_game(t_cfg *info)
{
#ifdef WIN32
  TCHAR procname[MAX_PATH + 100];
  STARTUPINFO defInfo;

  GetStartupInfo (&defInfo);
  defInfo.dwFlags = STARTF_USESTDHANDLES;
  defInfo.hStdOutput = GetStdHandle (STD_OUTPUT_HANDLE);
  defInfo.hStdError = GetStdHandle (STD_ERROR_HANDLE);
  defInfo.hStdInput = GetStdHandle (STD_INPUT_HANDLE);
  sprintf(procname, "%s%s", info->GamePath, info->Game);
  if (!CreateProcess (NULL, procname, NULL, NULL, TRUE, 0,
            NULL, NULL, &defInfo, &(info->GamePid)))
  MessageBox (NULL, TEXT ("Error"), "Error swe poya!", MB_OK);
#else
  pid_t	pid;
  fprintf(fd_log, "Launching game...\n");
  if ((pid = fork()) < 0)
    {
      fprintf(fd_log, "No more process\n");
      return (1);
    }
  if (pid)
    {
      info->GamePid = pid;
    }
  else
    {
      char buf[512];
      char **toc;

      toc = (char**)xmalloc(sizeof(*toc) * 2);
      sprintf(buf, "%s%s", info->GamePath, info->Game);
      toc[0] = strdup(buf);
      toc[1] = 0;
      execve(buf, toc, environ);
      fprintf(fd_log, "Execution du jeu echouee (%s): %s\n",
	      buf, strerror(errno)); 
      put_error("execve du jeu");
      return (1);
    }
#endif
  return (0);
}
