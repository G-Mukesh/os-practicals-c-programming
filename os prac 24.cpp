#include <stdio.h>

#define BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4 // Size of a disk block pointer in bytes
#define DIRECT_BLOCKS 12
#define INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (INDIRECT_BLOCKS * INDIRECT_BLOCKS)
#define TRIPLE_INDIRECT_BLOCKS (INDIRECT_BLOCKS * DOUBLE_INDIRECT_BLOCKS)

int main() {
    int maxFileSize = 0;
    int availableBlocks = DIRECT_BLOCKS;
    maxFileSize += availableBlocks * BLOCK_SIZE;
    availableBlocks -= DIRECT_BLOCKS;
    if (availableBlocks > 0) {
        maxFileSize += INDIRECT_BLOCKS * BLOCK_SIZE;
        availableBlocks -= 1;
    }
    if (availableBlocks > 0) {
        maxFileSize += DOUBLE_INDIRECT_BLOCKS * BLOCK_SIZE;
        availableBlocks -= INDIRECT_BLOCKS;
    }
    if (availableBlocks > 0) {
        maxFileSize += TRIPLE_INDIRECT_BLOCKS * BLOCK_SIZE;
        availableBlocks -= DOUBLE_INDIRECT_BLOCKS;
    }
    if (availableBlocks > 0) {
        int lastIndirectBlocks = availableBlocks > INDIRECT_BLOCKS ? INDIRECT_BLOCKS : availableBlocks;
        maxFileSize += lastIndirectBlocks * BLOCK_SIZE;
    }

    printf("Maximum file size: %d bytes\n", maxFileSize);

    return 0;
}

