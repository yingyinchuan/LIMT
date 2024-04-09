#include "FileCompressHuffman.hpp"

int main()
{
    FileCompressHM* FCHM = new FileCompressHM();
    FCHM->CompressHM("test.txt");

    return 0;
}