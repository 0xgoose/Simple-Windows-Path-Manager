#include <process.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

char s1[] = "C:\\Python27\\python.exe";
char s2[] = "C:\\Python37\\python.exe";

char argv2[] = "";

char cwd[PATH_MAX];

void strcat_func(char *arg) {
    strcat(argv2, s1);
    strcat(argv2, " ");               
    strcat(argv2, cwd);
    strcat(argv2, "\\");
    strcat(argv2, arg);
    system(argv2); 
}

void find_func(char *arg) {
    strcat(argv2, "dir");
    strcat(argv2, " *");               
    strcat(argv2, arg);
    strcat(argv2, "*");
    system(argv2); 
}

int main(int argc, char *argv[])
{
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        //printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    if (argc > 1) {
        if (strcmp(argv[1], "help") == 0) {
            puts("(1) - [py2] - python2");
            puts("(2) - [py3] - python3");
            puts("(3) - [find] - find as dir *name*");
        } else if (strcmp(argv[1], "py2") == 0) {
            if (argc > 2) {
                strcat_func(argv[2]);              
            } else {
                system(s1);
            }
        } else if (strcmp(argv[1], "py3") == 0) {
            if (argc > 2) {
                strcat_func(argv[2]);
            } else {
                system(s2);
            }
        }  else if (strcmp(argv[1], "find") == 0) {
            if (argc > 2) {
                find_func(argv[2]);
            }
        }
    }
    
    return 0;
}