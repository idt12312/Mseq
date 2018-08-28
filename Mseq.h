#ifndef MSEQ_H_
#define MSEQ_H_

#include <cstdint>
#include <vector>

/**
 * @brief M-sequence (maximum length sequence) generator
 */
class Mseq
{
  private:
    //! シフトレジスタのビット数
    uint8_t n;

    //! シフトレジスタ本体
    //! reg[0](LSB)が出力
    //! reg[n](MSB)がフィードバック先
    //! 更新時にはregが右に1bitづつシフトされていく
    uint32_t reg;

    //! reg更新時にfeedbackするbitの位置
    std::vector<uint8_t> a;

  public:
    Mseq(uint8_t _n);
    void reset();
    void reset(uint8_t _n);
    uint8_t update();
    uint8_t getOutput() const;
    uint32_t getRegsister() const;
};

#endif /* MSEQ_H_ */
