/*
Name: Niranjan Vinod Patil.
Batch: B-3.
Roll No: SCETTY305.
Subject: Operating System.
Assignment : IPC with Pipe -

Design a program using ordinary pipes in which one process
sends a string message to a second process, 
and the second process reverses the charactesr 
in the message and sends it back to the first process

*/
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void processA(int);
void processB(int);

void processA(int writefd, int readfd)
/* Process A reads the data and writes to pipe */
{
    int len=0;
    char buff[80];
    printf("Enter the string :");
    fgets(buff,80,stdin);
    len=strlen(buff);

    if(buff[len-1]='\n')
    {
        len--;

    }
    write(writefd,buff,len);

   
}


void processB(int readfd, int writefd)
{
    int n,i,j;
    int len=0;
    char str[80],temp;
    n=read(readfd,str,80);
    str[n]='\0';
    i=0;
    j=strlen(str)-1;
    while(i<=j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    //return str
    len=strlen(str);

    write(writefd,str,len);
    //printf(len);
    printf("Reversed string is %s\n",str);
    /*From Buffer read the charecters in reverse order */
}




int main()
{
   
    int pipe1[2];
    pid_t childpid;
    pipe(pipe1);
    childpid=fork();
    
    if( childpid == 0 )
    {
        wait(NULL);
        close(pipe1[1]);         /*Close write end of file descr */
        processB(pipe1[0], pipe1[1]);
    }
    else
    {
        close(pipe1[0]);    /* get data means writing to pipe */
        processA(pipe1[1], pipe1[0]);  /*  writing data to pipe */
    }
    return 0;
}



/*
:::::: OUTPUT ::::::

[student@MGL4 PrashantWalunj]$ g++ -o t twoway.cpp
[student@MGL4 PrashantWalunj]$ ./t
Enter the string :Niru
Reversed string is uriN
[student@MGL4 PrashantWalunj]$ ./t
Enter the string :I Am Man
Reversed string is naM mA I
[student@MGL4 PrashantWalunj]$ 
*/

