// DISCLAIMER.
// This code was taken from the ACMReader plugin of the GemRB project (http://gemrb.org)
// and then adapted for libfalltergeist. All credit goes to the original authors.

#ifndef LIBFALLTERGEIST_ACM_VALUE_UNPACKER_H
#define LIBFALLTERGEIST_ACM_VALUE_UNPACKER_H

#include <cstdlib>
#include "../../src/DatFileItem.h"

#define UNPACKER_BUFFER_SIZE 16384

namespace libfalltergeist
{

class CValueUnpacker
{
private:
    // Parameters of ACM stream
    int _levels, _subblocks;
    DatFileItem *stream;
    // Bits
    unsigned int _nextBits; // new bits
    int _availBits; // count of new bits
    unsigned char _bitsBuffer[UNPACKER_BUFFER_SIZE];
    unsigned int _bufferBitOffset;

    int _sbSize;
    short *_ampBuffer, *_buffMiddle;
    int *_blockPtr;

    // Reading routines
    void _prepareBits(int bits); // request bits
    int _getBits(int bits); // request and return next bits
public:
    // These functions are used to fill the buffer with the amplitude values
    int return0(int pass, int ind);

    int zeroFill(int pass, int ind);

    int linearFill(int pass, int ind);

    int k1_3bits(int pass, int ind);

    int k1_2bits(int pass, int ind);

    int t1_5bits(int pass, int ind);

    int k2_4bits(int pass, int ind);

    int k2_3bits(int pass, int ind);

    int t2_7bits(int pass, int ind);

    int k3_5bits(int pass, int ind);

    int k3_4bits(int pass, int ind);

    int k4_5bits(int pass, int ind);

    int k4_4bits(int pass, int ind);

    int t3_7bits(int pass, int ind);


    CValueUnpacker(int levCnt, int sbCount, libfalltergeist::DatFileItem *stream);

    virtual ~CValueUnpacker();

    int init();

    int getOneBlock(int *block);
};

typedef int (CValueUnpacker::*FillerProc)(int pass, int ind);

}

#endif // LIBFALLTERGEIST_ACM_VALUE_UNPACKER_H