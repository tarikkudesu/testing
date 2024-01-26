

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int ac, char **av, char **env)
{
    (void)ac;

    int fd[2];
    int file = open("f.txt", O_CREAT | O_RDWR);

    if (pipe(fd) == -1) {
        return 1;
    }
    
    int child1 = fork();

    if (0 == child1) {
        close(fd[0]);
        close(file);
        dup2(fd[1], 1);
        execve("/usr/bin/ls", av + 1, env);
    }

    int child2 = fork();

    if (0 == child2) {
        char buff[100];
        close(fd[1]);
        read(fd[0], buff, 99);
        buff[99] = '\0';
        write(file, buff, 99);
    }

    close(file);
    close(fd[0]);
    close(fd[1]);

}

// int child(void)
// {
//     return (8);
// }

// int main()
// {
//     pid_t pid = fork();

//     if (-1 == pid) {
//         return (0);
//     }

//     if (0 == pid) {
//         printf("Child 1\n");
//         usleep(100000);
//     } else {
//         pid_t pid1 = fork();
//         if (pid1 == 0) {
//             printf("Child 2\n");
//             usleep(110000);
//         } else {
//             int status1, status2;
//             printf("Parent\n");
//             waitpid(-1, &status1, 0);
//             printf("%d\n00", WEXITSTATUS(status1));
//             waitpid(pid1, &status2, 0);
//             printf("%d\n", WEXITSTATUS(status2));
//         }
        
//     }
//     return (12);
// }

// int main()
// {
//     int pid1 = fork();
//     int pid2 = fork();
//     int pid3 = fork();

//     if (pid1 == 0) {
//         if (pid2 == 0) {
//             if (pid3 == 0) {
//                 printf("grand grand child 1\n");
//             } else {
//                 printf("grand child 1\n");
//             }
//             wait(NULL);
//         } else if (pid3 == 0) {
//             printf("grand grand child 2\n");
//         } else {
//             printf("Child 1\n");
//         }
//     } else {
//         if (pid2 == 0) {
//             if (pid3 == 0) {
//             printf("grand grand child 3\n");
//             } else {
//             printf("grand child 2\n");
//             }
//         } else if (pid3 == 0) {
//             printf("grand grand child 4\n");
//         } else {
//             printf("Parent\n");
//         }
//     }
//     return (1);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!n)
// 		return (0);
// 	while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i) && i < n)
// 		i++;
// 	if (i == n)
// 		return (0);
// 	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
// }

// int main()
// {
//     printf("%d\n", ft_strncmp("PATH=", "USER=codes", 5));
// }

// int main(int ac, char **av, char **ap)
// {
//     printf("Number of arguments : %d\n", ac);
//     for (int i = 0; i >= 0; i++)
//     {
//         printf("Argument : %s\n", ap[i]);
//         usleep(50000);
//         if (!*(ap + i)) { break ;}
//     }
// }
// int main()
// {
//     int pid1 = fork();
//     int pid2 = fork();

//     if (pid1 == 0) {
//         if (pid2 == 0) {
//             printf("grand child 1\n");
//         } else {
//             printf("child 1\n");
//         }
//     } else {
//         printf("pid1 : %d\tpid2 : %d\n", pid1, pid2);
//     }
//     return (1);
// }
