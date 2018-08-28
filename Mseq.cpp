#include "Mseq.h"

/**
 * @brief コンストラクタ
 * @param uint8_t n M系列信号を発生させるレジスタの個数
 */
Mseq::Mseq(uint8_t _n)
{
    reset(_n);
}

/**
 * @brief レジスタの個数を変更しつつ初期化する
 * @param uint8_t n M系列信号を発生させるレジスタの個数
 * @details n bitシフトレジスタから生成されるM系列信号の1周期の長さは2^n-1
 *          レジスタ(reg)の初期化と、nに応じたフィードバック係数を設定する
 */
void Mseq::reset(uint8_t _n)
{
    n = _n;
    a.clear();

    // フィードバック係数を更新
    // フィードバック係数は以下の資料から引用
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

/**
 * @brief レジスタのみを初期化する
 * @param なし
 * @details 常にレジスタの出力に近い側を1に初期化する
 */
void Mseq::reset()
{
    reg = 1;
}

/**
 * @brief M系列信号を1step更新し、出力を得る
 * @param なし
 * @return 出力 (0 or 1)
 * @details
 *  p1, p2, ... pk \in aの時、regは以下の2ステップで更新される
 *  step1 : reg[j] = reg[j+1] \forall j \in {0,2,...n-1}
 *  step2 : reg[n] = reg[p1] xor reg[p2] xor .... reg[pk]
 */
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

/**
 * @brief 出力を得る
 * @param なし
 * @return 出力 (0 or 1)
 */
uint8_t Mseq::getOutput() const
{
    return reg & 1;
}

/**
 * @brief シフトレジスタ全体の状態を得る
 * @param なし
 * @return シフトレジスタの生データ
 */
uint32_t Mseq::getRegsister() const
{
    return reg;
}
