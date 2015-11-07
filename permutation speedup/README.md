# 简介

algorithm.c实现了4种速度比较快的全排列生成算法——字典序法，邻位对换法，改进的字典序法和Heap算法。permutation.c分别在n=10，11，12时调用这4种算法各10次，并将结果输出到benchmark.out文件中。

# 编译

vc环境下可以使用IDE直接编译，如果使用gcc，输入命令

`gcc algorithm.c permutation.c -o permutation`

可能需要加入C99标准参数

`gcc algorithm.c permutation.c -o permutation -std=c99`