# Introduction

在程序包中提供了4种包含生成全排列的函数的类：`per_dict`，`per_cantor`，`per_vcantor`，`per_swanp`，分别继承递增进位制数`mid_num_in`和递减进位制数`mid_num_de`，有类方法：

`char* get_order()`：获取当前排列
`set_mid(long r)`：将排列重置为第r顺序的排列
`alter(long amount)`：将排列变动amount（可为负）

通过调用`alter(1)`和`char* get_order()`能够生成相应的全排列
