//Code

//Inter Process Communication


// 01. send

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10 // Maximum size for the message queue

//structure for message queue
struct mesg_buffer{ //mesg_buffer is temporary storage box
	long mesg_type;
	char mesg_text[100];
}
message; //variable for the message box

int main(){
	
	key_t key;
	int msgid;
	
	//ftok to generate unique key
	//key = ftok("progfile41", 41);// 41 is key
	
	//OR
	key = ftok("send41", 41);
	
	//message creates a message queue
	//and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT); //0666 for read and write
	message.mesg_type = 1;
	printf("Write Data: ");
	fgets(message.mesg_text, MAX, stdin);
	
	//msgsnd to send message
	msgsnd(msgid, &message, sizeof(message), 0);
	
	//display the message
	printf("Data send is: %s \n", message.mesg_text);
	
	
	return 0;
}


//You have to run both files in different file


// 02. receive

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//structure for message queue
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}
message;

int main(){
	
	key_t key;
	int msgid;
	
	//ftok to generate unique key
	
	//key = ftok("progfile41", 41);
	//key = ftok("pathname", key); //pathname file has the access to raed and write
	
	//OR
	key = ftok("send41", 41);
	
	
	//msgget creates a message queue
	//and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT); //0666 for read and write
	
	//msgrcv to receive message
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	
	//display the message
	message.mesg_type = 1;
	printf("Data Received is: %s \n", message.mesg_text);
	
	//to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	
	return 0;
}



//Output

[nipunika@ChathuraDN ~]$ touch send41
[nipunika@ChathuraDN ~]$ chmod 644 send41
[nipunika@ChathuraDN ~]$ vi send41.c
[nipunika@ChathuraDN ~]$ vi receive41.c
[nipunika@ChathuraDN ~]$ gcc send41.c -o send41
[nipunika@ChathuraDN ~]$ ./send41
Write Data: Nipuu
Data send is: Nipuu

[nipunika@ChathuraDN ~]$ gcc receive41.c -o receive41
[nipunika@ChathuraDN ~]$ ./receive41
Data Received is: Nipuu