## 问题一：

![avatar](images/error1.gif)

由于通用计算段没有判断上方已计算的内容边界条件。

![avatar](images/q1.png)

解决： 删除判断最后一个节点的内容即可， 通用计算段最终的位置即为end， 不用单独考虑。


## 正确结果--欧拉方法：

![avatar](images/euler_hide_rusult.gif)


## 正确结果--非物理verlet方法：

![avatar](images/verlet_rusult.gif)
