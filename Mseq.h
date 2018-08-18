#ifndef MSEQ_H_
#define MSEQ_H_

#include <cstdint>
#include <vector>

class Mseq
{
  private:
    uint8_t n;
    uint32_t reg;
    std::vector<uint8_t> a;

  public:
    Mseq(uint8_t _n = 2);
    void reset();
    void reset(uint8_t _n);
    uint8_t update();
    uint8_t getOutput() const;
    uint32_t getRegsister() const;
};

#endif /* MSEQ_H_ */
