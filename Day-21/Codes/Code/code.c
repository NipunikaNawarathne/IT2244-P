Code

//writer process1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of shared memory segment

int main(){
	
	key_t key = ftok("shmfile", 2141); //Generate unique key
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Create shared memory segment
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat (shmid, NULL, 0); //Attach to shared memory
	if(shmaddr == (char*)-1){
		perror("shmat");
		exit(1);
	}
	
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE, stdin); // Write data to shared memory
	
	printf("Data written in memory: %s\n", shmaddr);
	
	shmdt(shmaddr); //Detach from shared memory
	
	return 0;
}





// run both in the separate files

//reader process2

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of shared memory segment

int main(){
	
	key_t key = ftok("shmfile", 2141); //Generate unique key
	int shmid = shmget(key, SHM_SIZE, 0666); // Access shared memory segment
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid, NULL, 0); //Attach to shared memory
	if(shmaddr == (char*)-1){
		perror("shmat");
		exit(1);
	}
	
	printf("Data read from memory: %s\n", shmaddr); // Read from shared memory
	
	shmdt(shmaddr); //Detach from shared memory
	
	shmctl(shmid, IPC_RMID, NULL); // Remove shared memory segment
	
	return 0;
}


//Output
[nipunika@ChathuraDN ~]$ touch shmfile
[nipunika@ChathuraDN ~]$ chmod 644 shmfile
[nipunika@ChathuraDN ~]$ vi writer.c
[nipunika@ChathuraDN ~]$ gcc writer.c -o writer
[nipunika@ChathuraDN ~]$ ./writer
Write Data: Hi Nipu
Data written in memory: Hi Nipu

[nipunika@ChathuraDN ~]$ vi reader.c
[nipunika@ChathuraDN ~]$ gcc reader.c -o reader
[nipunika@ChathuraDN ~]$ ./reader
Data read from memory: Hi Nipu





//Question01

//Creating both write and read in same file
//so we use mmap to create shared memory


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(){
	
	size_t size = 4096;
	char *shared_mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if(shared_mem == MAP_FAILED){
		perror("mmap failed");
		exit(1);
	}
	
	pid_t pid = fork();
	if(pid == 0){
		//Child process
		sprintf(shared_mem, "Hello from child!");
		printf("Child wrote: %s\n", shared_mem);
		exit(0);
	}
	else if(pid >0){
		//Parent process
		wait(NULL); //Wait for child to finish
		printf("Parent read: %s\n", shared_mem);
		munmap(shared_mem, size);
	}
	else{
		perror("fork failed");
		exit(1);
	}
	
	return 0;
}



//Output
[nipunika@ChathuraDN ~]$ vi Exercise1.c
[nipunika@ChathuraDN ~]$ gcc Exercise1.c -o Exercise1
[nipunika@ChathuraDN ~]$ ./Exercise1
Child wrote: Hello from child!
Parent read: Hello from child!





//3 Shared Exercise - Madam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main() {
    size_t size = 4096;
    char *shared_mem = mmap(NULL, size, PROT_READ | PROT_WRITE,
	MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sprintf(shared_mem, "Hello from child!");
        printf("Child wrote: %s\n", shared_mem);
        exit(0);
    } else if (pid > 0) {
        // Parent process
        wait(NULL); // Wait for child to finish
        printf("Parent read: %s\n", shared_mem);
        munmap(shared_mem, size);
    } else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}



//Output
[nipunika@ChathuraDN ~]$ vi sharedEx.c
[nipunika@ChathuraDN ~]$ gcc sharedEx.c -o sharedEx
[nipunika@ChathuraDN ~]$ ./sharedEx
Child wrote: Hello from child!
Parent read: Hello from child!