# Contiguous Allocation

## Sequenced Description: File Contiguous Allocation

In a system utilizing contiguous allocation for file storage on a disk, each file occupies a contiguous set of blocks. This implies that if a file requires 'n' blocks and is assigned a starting block 'b,' the blocks assigned to the file will follow a contiguous sequence: b, b+1, b+2, …, b+n-1. This straightforward allocation strategy facilitates easy determination of the blocks occupied by a file based on its starting block address and the length of the file in terms of required blocks.

The directory entry for a file utilizing contiguous allocation includes the following information:

1. **Address of Starting Block:**
   - This signifies the starting block address assigned to the file. Let's denote it as 'b.'
  
2. **Length of the Allocated Portion:**
   - It represents the length of the allocated portion of the file in terms of the number of blocks required. Let's denote it as 'n.'

## Indexed Allocation

In indexed allocation, a special block known as the Index block contains pointers to all blocks occupied by a file. Each file has its own index block, and the ith entry in the index block contains the disk address of the ith file block. The directory entry for a file with indexed allocation includes the address of the index block. This approach streamlines access to various file blocks and enhances file organization.

## Linked Allocation

In linked allocation, each file is represented as a linked list of disk blocks that need not be contiguous. Disk blocks can be scattered anywhere on the disk. The directory entry for a linked allocation file includes pointers to the starting and ending file blocks. Each block contains a pointer to the next block occupied by the file, forming a linked list structure. This method provides flexibility in allocating non-contiguous blocks but may result in increased access time due to scattered block locations.

The three allocation methods - contiguous, indexed, and linked - offer different approaches to organizing and accessing file blocks on a disk, each with its own advantages and considerations.
