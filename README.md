# Introduction

## permutation basic

程序包中提供了4种包含生成全排列的函数的类：`per_dict`，`per_cantor`，`per_vcantor`，`per_swanp`，分别继承递增进位制数`mid_num_in`和递减进位制数`mid_num_de`，有类方法：

`get_order()`：获取当前排列

`set_mid(long r)`：将排列重置为第r顺序的排列

`alter(long amount)`：将排列变动amount（可为负）

通过调用`alter( 1 )`和`get_order()`能够生成相应的全排列


## permutation speedup

algorithm.c实现了4种速度比较快的全排列生成算法——字典序法`dict_perm`，邻位对换法`adj_perm`，改进的字典序法`dict_perm_new`和Heap算法`heap_perm`。

permutation.c分别在n=10，11，12时调用这4种算法各10次，并将计时结果输出到benchmark.out文件中。

vc环境下可以使用IDE直接编译，如果使用gcc，输入命令

`gcc algorithm.c permutation.c -o permutation`

可能需要加入C99标准参数

`gcc algorithm.c permutation.c -o permutation -std=c99`