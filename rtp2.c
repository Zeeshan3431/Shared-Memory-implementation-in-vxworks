#include <vxWorks.h>
#include <sdLib.h>
#include <taskLib.h>
#include <stdio.h>

#define SHARED_MEMORY_NAME "/SharedMemory"

void rtp2(void)
{
    SD_ID sharedMemoryId;
    char *buffer = NULL;

    // Open shared memory
    sharedMemoryId = sdOpen(SHARED_MEMORY_NAME, 0, 0, 0, 0, 0, (void **)&buffer);
    if (!sharedMemoryId)
    {
        printf("RTP2: Error opening shared memory\n");
        return;
    }

    // Read from shared memory
    while (1)
    {
        printf("RTP2: Message: %s\n", buffer ? buffer : "No data");
        taskDelay(100);
    }
}

int main(void)
{
    printf("RTP2: Starting...\n");
    rtp2();
    return 0;
}
