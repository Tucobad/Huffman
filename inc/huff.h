#ifndef __HUFFMANCODE_H__
#define __HUFFMANCODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

            /* CONSTANTS AND MACROS */

#define CHAR_MAX 256

            /* STRUCTURES */ 

typedef enum bool{
    false, true
}bool;
typedef struct Data{
    size_t occur;
    unsigned char value;
}Data;

typedef struct Encoding{
    int binaryC, lengthBc; 
    unsigned char value;
}Encoding;

typedef struct Tree{
    size_t occur;
    unsigned char value;
    struct Tree *left, *right;
}Tree, *HTree;

typedef struct Queue{
    HTree pTree;
    struct Queue *next;
}Queue, *PtrQ;


            /* PROTOTYPES */

// huff.c
char* concat(char*, char*);
void compression(char*);
void decompression(char*);
PtrQ findCharFile(char*);
HTree buildHuffmanTree(PtrQ);
Encoding* getCharEncoding(HTree, Encoding*);

// misc.c
void help();
Data* insertionSort(Data*);
PtrQ enqueue(PtrQ, HTree);
PtrQ dequeue(PtrQ);

// tree.c
int leavesTree(HTree);
HTree createTree(size_t, char);
HTree createSubHTree(HTree, HTree);
void vDisplay(HTree, int);

#endif
