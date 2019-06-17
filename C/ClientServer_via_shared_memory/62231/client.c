#include "comm.h"

#include <string.h>

int main(int argc, char ** argv) {
	
	if (argc != 2) {
        printf("%s\n", "Exactly one argument required [Accpount Code]");
        return 1;
    }

    char *account = argv[1];
    if (strlen(account) != 1) {
    	printf("%s\n", "Invalid account format provided");
    	return 1;
    }
    
    
    sem_t *mutex, *server, *client;

    if ((mutex = sem_open(MUTEX_NAME, O_RDWR)) == SEM_FAILED) {
        printf("%s\n", "sem_open Failed for mutex semaphore");
        return 1;
    }

    if ((server = sem_open(SERVER_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        printf("%s\n", "sem_open Failed for server semaphore");
        return 1;
    }

    if ((client = sem_open(CLIENT_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        printf("%s\n", "sem_open Failed for client semaphore");
        return 1;
    }

    printf("%s\n", "Waiting to connect with the server..." );

    if ( sem_wait(mutex) == - 1 ) {
        printf("%s\n", "sem_wait failed for mutex semaphore" );
        sem_post(mutex);
        return 1;
    }
    //Start session
    printf("%s\n", "Session started" );


    struct Info *shared_point;
    
    int shared_point_fd;

    if ((shared_point_fd = shm_open(SHARED_MEM_NAME, O_RDWR | O_CREAT, 0660)) == -1) {
        printf("%s\n", "shm_open failed to execute");
        return 1;
    }


   // if (ftruncate(fd_shm, sizeof(Query)) < 0) 
     //   error("Could not set the shared memory");
    
    if ((shared_point = mmap(NULL, sizeof(struct Info), PROT_READ | PROT_WRITE, MAP_SHARED, shared_point_fd, 0)) == MAP_FAILED) {
        printf("%s\n", "Failed to mmap shared point");
        return 1;
    }

    printf("%s\n", "Connected to shared memory" );


    *shared_point = (struct Info){0,0,account[0]};

    //signal server that account info was added
    if ( sem_post(client) == - 1 ) {
        printf("%s\n", "sem_post failed for client semaphore" );
        sem_post(mutex);
        return 1;
    }

    //transaction time 
    if ( sem_wait(server) == - 1 ) {
        printf("%s\n", "sem_wait failed for server semaphore" );
        sem_post(mutex);
        return 1;
    }


    //check if account is ok 
    if ( shared_point -> transaction != 0 ) {
    	switch(shared_point -> transaction) {
    		case INCORRECT_ACCOUNT_ERROR:
    			printf("%s\n", "The provided account is not among the existing accounts!" );
    			sem_post(mutex);
    			return 1;
    		default:
    			printf("%s %d\n", "Unknown error encountered with code: ", shared_point -> transaction );
    			sem_post(mutex);
    			return 1;
    	}
    }

    printf("%s %d\n", "Current balance: ", shared_point -> balance);

    //proceed with transaction query
    int32_t transaction = 200;
    shared_point -> transaction = transaction;


    if ( sem_post(client) == - 1 ) {
        printf("%s\n", "sem_post failed for client semaphore" );
        sem_post(mutex);
        return 1;
    }

    //wait the server's responce
    if ( sem_wait(server) == - 1 ) {
        printf("%s\n", "sem_wait failed for server semaphore" );
        sem_post(mutex);
        return 1;
    }

    //chack if transaction query is ok

    //check if account is ok 
    if ( shared_point -> transaction != 0 ) {
    	switch(shared_point -> transaction) {
    		case INSUFFICIENT_ACCOUNT_BALANCE:
    			printf("%s\n", "The provided account does not have enough balance for this transaction!" );
    			sem_post(mutex);
    			return 1;
    		default:
    			printf("%s %d\n", "Unknown error encountered with code: ", shared_point -> transaction );
    			sem_post(mutex);
    			return 1;
    	}
    }

    printf("Current balance of %c is %d \n", argv[1][0], shared_point -> balance );

    //free mutex
    if ( sem_post(mutex) == - 1 ) {
        printf("%s\n", "sem_post failed for mutex semaphore" );
        return 1;
    }

	return 0;
}