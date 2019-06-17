#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <stdint.h>
#include <error.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SHARED_MEM_NAME "birnika"
#define MUTEX_NAME "Mutex"
#define SERVER_NAME "Server"
#define CLIENT_NAME "Client"

#define INCORRECT_ACCOUNT_ERROR -1
#define INSUFFICIENT_ACCOUNT_BALANCE -2


struct Info {
	uint32_t balance;
	int32_t transaction;
	char account;
};