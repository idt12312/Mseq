# Mseq
M系列信号を生成するライブラリ

## 使い方
実装例はこのリポジトリのexample/example.cppを参照のこと

N bitシフトレジスタから生成されるM系列信号を1周期分(2^N-1)生成するサンプルコード

```cpp:example.cpp
Mseq mseq(N);

for (int i = 0; i < (1 << N) -1; i++)
{
    std::cout << (int)mseq.update() << " ";
}
std::cout << std::endl;
```

他の機能については実装(Mseq.cpp)を参照
