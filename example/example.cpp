#include <iostream>
#include <cstdio>
#include "Mseq.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "argument must be an integer (3~32)\n";
        return 1;
    }

    int N;
    sscanf(argv[1], "%d", &N);
    if (N < 3 || 32 < N)
    {
        std::cerr << "argument must be an integer (3~32)\n";
        return 1;
    }

    Mseq mseq(N);

    for (int i = 0; i < (1 << N) - 1; i++)
    {
        std::cout << (int)mseq.update() << " ";
    }
    std::cout << std::endl;

    return 0;
}