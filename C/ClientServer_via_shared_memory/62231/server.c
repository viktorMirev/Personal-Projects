#include "comm.h"

#define BANK_SIZE 32


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("%s\n", "Exactly one argument required [Bank File]");
        return 1;
    }

    uint32_t accounts[8] = {0, 0, 0, 0, 0, 0, 0, 0};


    //validate file and create if missing
    int bank_fd = open(argv[1], O_RDWR | O_CREAT, 0666 );

    if ( bank_fd < 0 ) {
        printf("%s\n", "Failed to open/create bank file");
        return 1;
    }

    struct stat data;
    fstat(bank_fd, &data);
    int bankFileSize = data.st_size;

    //initialize if it was not 
    if( bankFileSize == 0 ) {
        printf("%s\n", "Creating 0 bank file");
        if (write(bank_fd, &accounts, BANK_SIZE) != BANK_SIZE) {
            printf("%s\n", "Unable to initialise new bank file");
        }

    }

    int shared_point_fd;

    if ((shared_point_fd = shm_open(SHARED_MEM_NAME, O_RDWR | O_CREAT, 0660)) == -1) {
        printf("%s\n", "shm_open failed to execute");
        return 1;
    }
    printf("%s\n", "Create shared_point_fd");

    struct Info *shared_point;
    if ((shared_point = mmap(NULL, sizeof(struct Info), PROT_READ | PROT_WRITE, MAP_SHARED, shared_point_fd, 0)) == MAP_FAILED) {
        printf("%s\n", "Failed to mmap shared point");
    } 

    sem_t *mutex, *server, *client;

    if ((mutex = sem_open(MUTEX_NAME, O_CREAT, 0660, 1)) == SEM_FAILED) {
        printf("%s\n", "sem_open Failed for mutex semaphore");
        return 1;
    }

    printf("%s\n", "Mutex semaphore initialised" );

    if ((server = sem_open(SERVER_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        printf("%s\n", "sem_open Failed for server semaphore");
        return 1;
    }

    if ((client = sem_open(CLIENT_NAME, O_CREAT, 0660, 0)) == SEM_FAILED) {
        printf("%s\n", "sem_open Failed for client semaphore");
        return 1;
    }


    while(1) {

        printf("%s\n", "Waiting for client..." );
        int account_idx;
        //wait for session start
        //get account and verify
        if ( sem_wait(client) == - 1 ) {
            printf("%s\n", "sem_wait failed for client semaphore" );
            return 1;
        }
        printf("%s\n", "Session Started" );

        char account = shared_point -> account;
        if ( account >= 'A' && account <= 'H') {
            account_idx = account - 'A';
            shared_point -> balance = accounts[account_idx];
            shared_point -> transaction = 0;
        } else {
            shared_point -> transaction = INCORRECT_ACCOUNT_ERROR;
            if ( sem_post(server) == - 1 ) {
                printf("%s\n", "sem_post failed for server semaphore" );
                return 1;
            }
            continue;
        }

        if ( sem_post(server) == - 1 ) {
            printf("%s\n", "sem_post failed for server semaphore" );
            return 1;
        }


        //get transaction query
        if ( sem_wait(client) == - 1 ) {
            printf("%s\n", "sem_wait failed for client semaphore" );
            return 1;
        }

        int16_t transaction = shared_point -> transaction;
        if( transaction < 0 ) {
            if ( (uint32_t)(transaction * (-1)) > accounts[account_idx] ) {
                shared_point -> transaction = INSUFFICIENT_ACCOUNT_BALANCE;
                if ( sem_post(server) == - 1 ) {
                    printf("%s\n", "sem_post failed for server semaphore" );
                    return 1;
                }
                continue;
            }
        }

        accounts[account_idx] += transaction;

        if (write(bank_fd, &accounts, BANK_SIZE) != BANK_SIZE) {
            printf("%s\n", "Unable to update bank file");
            sem_post(server);
            return 1;
        }

        shared_point -> transaction = 0;
        shared_point -> balance += transaction;

        if ( sem_post(server) == - 1 ) {
            printf("%s\n", "sem_post failed for server semaphore" );
            return 1;
        }

    }

}