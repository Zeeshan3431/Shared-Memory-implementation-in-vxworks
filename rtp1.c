#include <vxWorks.h>
#include <sdLib.h>
#include <taskLib.h>
#include <stdio.h>
#include <string.h>

#define SHARED_MEMORY_NAME "/SharedMemory"
#define SHARED_MEMORY_SIZE 1024

void rtp1(void)
{
    SD_ID sharedMemoryId; 
    char *buffer = NULL;
    const char *message = "Hello from RTP1!";

    // Create shared memory
    sharedMemoryId = sdOpen(SHARED_MEMORY_NAME, 0, OM_CREATE, SHARED_MEMORY_SIZE, 0, SD_ATTR_RW | SD_CACHE_OFF, (void **)&buffer);
    if (!sharedMemoryId)
    {
        printf("RTP1: Error creating shared memory\n");
        return;
    }

    // Write to shared memory
    strncpy(buffer, message, SHARED_MEMORY_SIZE - 1);
    buffer[SHARED_MEMORY_SIZE - 1] = '\0'; // Null-terminate
    printf("RTP1: Wrote to shared memory: %s\n", buffer);

    // Keep running
    while (1) taskDelay(100);
}

int main(void)
{
    printf("RTP1: Starting...\n");
    rtp1();
    return 0;
}
