



### anaconda安装--虚拟环境搭建

```python
conda create --name python37 python=3.7  //创建
conda info --env                        //看看环境
conda activate python37                 //激活
conda remove -n python37 --all          //删除
conda activate pytorch_learn
conda config --show channels//查看源通道
//修改下载源
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/r
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/pro
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/msys2

conda config --set show_channel_urls yes

//移除下载源
conda config --remove-key channels

python -m pip install --upgrade pip

```

参考资料：[1. Pytorch零失败安装使用|Anaconda安装|最新版本torch安装|PyCharm配置torch| 保姆级教程【PyTorch修炼】【AI蜗牛车】_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1o3411V7Zz?spm_id_from=333.337.search-card.all.click)

  什么是conda？

      常讲conda和pip比较，conda可以在conda环境下安装任何语言的包，pip可以在任何环境下安装python包。所以用conda管理安装python包是绰绰有余的。那为何要用conda而不用pip呢? 原因是conda可以很好解决如Numpy和Scipy的包之间的依赖关系。
    原文链接：https://blog.csdn.net/z_xiaoxin/article/details/82051982

### 