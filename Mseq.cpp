#include "Mseq.h"

Mseq::Mseq(uint8_t _n)
{
    reset(_n);
}

void Mseq::reset(uint8_t _n)
{
    n = _n;
    a.clear();

    // https://www.xilinx.com/support/documentation/application_notes/xapp052.pdf
    switch (_n)
    {
    case 3:
        a.assign({3, 2});
        break;
    case 4:
        a.assign({4, 3});
        break;
    case 5:
        a.assign({5, 3});
        break;
    case 6:
        a.assign({6, 5});
        break;
    case 7:
        a.assign({7, 6});
        break;
    case 8:
        a.assign({8, 6, 5, 4});
        break;
    case 9:
        a.assign({9, 5});
        break;
    case 10:
        a.assign({10, 7});
        break;
    case 11:
        a.assign({11, 9});
        break;
    case 12:
        a.assign({12, 6, 4, 1});
        break;
    case 13:
        a.assign({13, 4, 3, 1});
        break;
    case 14:
        a.assign({14, 5, 3, 1});
        break;
    case 15:
        a.assign({15, 14});
        break;
    case 16:
        a.assign({16, 15, 13, 4});
        break;
    }
    reset();
}

void Mseq::reset()
{
    reg = 1;
}

uint8_t Mseq::update()
{
    uint32_t feedback = 0;
    for (auto p : a)
    {
        feedback ^= reg >> (p % n);
    }
    feedback &= 1;

    reg = reg >> 1;

    reg = ((~(0xffffffff << (n - 1))) & reg) | (feedback << (n - 1));

    return getOutput();
}

uint8_t Mseq::getOutput() const
{
    return reg & 1;
}

uint32_t Mseq::getRegsister() const
{
    return reg;
}
