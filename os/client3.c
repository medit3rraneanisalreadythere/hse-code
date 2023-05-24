#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    int    msqid;
    char   pathname[] = "server3.c"; 
    key_t  key;
    int    len, maxlen;

    if ((key = ftok(pathname, 0)) < 0) 
    {
        printf("Can\'t generate key\n");
        exit(-1);
    }

    if ((msqid = msgget(key, 0666 | IPC_CREAT)) < 0) 
    {
        printf("Can\'t get msqid\n");
        exit(-1);
    } 

    struct mymsgbuf
    {
        long mtype;
        struct
        {
            pid_t pid;
            float x;
        } info;
    } mybuf;

    scanf("%f", &mybuf.info.x);
    pid_t t = getpid();
    mybuf.info.pid = t;
    mybuf.mtype = 1;
    len = sizeof(mybuf.info);

    if (msgsnd(msqid, (struct msgbuf *) &mybuf, len, 0) < 0) 
    {
        printf("Can\'t send message to queue\n");
        msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
        exit(-1);
    }

    while (true)
    {
        maxlen = sizeof(mybuf.info);

        if ((len = msgrcv(msqid, (struct msgbuf *) &mybuf, maxlen, (long)t, 0)) < 0) 
        {
            printf("Can\'t receive message from queue\n");
            exit(-1);
        }

        printf("%f\n", mybuf.info.x);
        exit(0);
    }

    return 0;
}