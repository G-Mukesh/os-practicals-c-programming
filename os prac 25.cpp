#include <stdio.h>

#define BLOCK_SIZE 1 

int main() {
    int fileBlocks = 100;
    int blockToAdd;
    int contigIO, linkedIO, indexedIO;
    blockToAdd = 0;
    contigIO = 1; // Only need to write the block at the beginning
    linkedIO = blockToAdd + 2; // Need to update the previous block and write the new block
    indexedIO = 2; // Need to update the index block and write the new block

    printf("Adding block at the beginning:\n");
    printf("Contiguous: %d I/O operations\n", contigIO);
    printf("Linked: %d I/O operations\n", linkedIO);
    printf("Indexed: %d I/O operations\n\n", indexedIO);
    blockToAdd = fileBlocks / 2;
    contigIO = 1; // Only need to write the new block
    linkedIO = blockToAdd + 2; // Need to update the previous block and write the new block
    indexedIO = 2; // Need to update the index block and write the new block

    printf("Adding block in the middle:\n");
    printf("Contiguous: %d I/O operations\n", contigIO);
    printf("Linked: %d I/O operations\n", linkedIO);
    printf("Indexed: %d I/O operations\n\n", indexedIO);
    blockToAdd = fileBlocks;
    contigIO = 1; // Only need to write the new block
    linkedIO = fileBlocks + 2; // Need to update the previous block and write the new block
    indexedIO = 2; // Need to update the index block and write the new block

    printf("Adding block at the end:\n");
    printf("Contiguous: %d I/O operations\n", contigIO);
    printf("Linked: %d I/O operations\n", linkedIO);
    printf("Indexed: %d I/O operations\n", indexedIO);

    return 0;
}

