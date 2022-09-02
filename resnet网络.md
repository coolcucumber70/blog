# 学习任务



## 1 PyTorch环境搭建

### anaconda安装--虚拟环境搭建

```python
conda create --name python37 python=3.7  //创建
conda info --env                        //看看环境
conda activate python37                 //激活
conda remove -n python37 --all          //删除
conda activate pytorch_learn

```

参考资料：[1. Pytorch零失败安装使用|Anaconda安装|最新版本torch安装|PyCharm配置torch| 保姆级教程【PyTorch修炼】【AI蜗牛车】_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1o3411V7Zz?spm_id_from=333.337.search-card.all.click)

  什么是conda？

      常讲conda和pip比较，conda可以在conda环境下安装任何语言的包，pip可以在任何环境下安装python包。所以用conda管理安装python包是绰绰有余的。那为何要用conda而不用pip呢? 原因是conda可以很好解决如Numpy和Scipy的包之间的依赖关系。
    原文链接：https://blog.csdn.net/z_xiaoxin/article/details/82051982
### pytorch安装

```
#镜像
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/pytorch/
conda config --add channels http://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge/
conda config --set show_channel_urls yes
conda install pytorch torchvision torchaudio cudatoolkit=11.3 -c pytorch//安装
conda install pytorch torchvision torchaudio cpuonly -c pytorch
import torch //
torch.__version__ //查看版本
```

..........先安装的cuda GPU 告诉我no moudle torch 后来查了查，说amd架构不能用？我的电脑是amd的架构，但是显卡是N卡。先安cpu版本吧。

## 2卷积神经网络（CNN）--吴恩达视频课（选择直接学习第4堂课）

​       使用传统神经网络处理机器视觉的一个主要问题是输入层维度很大。例如一张64x64x3的图片，神经网络输入层的维度为12288。如果图片尺寸较大，例如一张1000x1000x3的图片，神经网络输入层的维度将达到3百万，使得网络权重W非常庞大。这样会造成两个后果，一是神经网络结构复杂，数据量相对不够，容易出现过拟合；二是所需内存、计算量较大。解决这一问题的方法就是使用卷积神经网络（CNN）。

### 2.1卷积神经网络基础

#### 如何检测图片边缘？

**神经网络由浅层到深层，分别可以检测出图片的边缘特征 、局部特征（例如眼睛、鼻子等）、整体面部轮廓---需要回头看前面的课程**

最常检测的图片边缘有两类：一是垂直边缘（vertical edges），二是水平边缘（horizontal edges）。

图片的边缘检测可以通过与相应滤波器进行卷积来实现。以垂直边缘检测为例，原始图片尺寸为6x6，滤波器filter尺寸为3x3，卷积后的图片尺寸为4x4。

##### 何为图像卷积？ 

数字图像是一个二维的[离散](https://so.csdn.net/so/search?q=离散&spm=1001.2101.3001.7020)信号，对数字图像做卷积操作其实就是利用卷积核（卷积模板）在图像上滑动，将图像点上的像素灰度值与对应的卷积核上的数值相乘，然后将所有相乘后的值相加作为卷积核中间像素对应的图像上像素的灰度值，并最终滑动完所有图像的过程。

Vertical edge detection能够检测图片的垂直方向边缘。下图对应一个垂直边缘检测的例子：这样就能把中间的竖杠给检测出来了。

![这里写图片描述](C:\Users\wfp\Desktop\format,png)

垂直边缘检测和水平边缘检测的**滤波器算子**如下所示：

![这里写图片描述](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcxMTI4MTQ1MzA0MDM2?x-oss-process=image/format,png)

Sobel filter和Scharr filter，这两种滤波器的特点是增加图片中心区域的权重：

![这里写图片描述](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcxMTI4MTUxMzQ0MjI2?x-oss-process=image/format,png)

在深度学习中，如果我们想检测图片的各种边缘特征，而不仅限于垂直边缘和水平边缘，那么filter的数值一般需要通过模型训练得到，类似于标准神经网络中的权重W一样由梯度下降算法反复迭代求得。**CNN的主要目的就是计算出这些filter的数值**。确定得到了这些filter后，CNN浅层网络也就实现了对图片所有边缘特征的检测。

#### **Padding**

**think：**经过卷积后的矩阵的阶数显然是变小的，这就会导致图像外框的信息丢失了，如何解决？

**solve：**如果我事先将图片往外扩一部分，filter之后就是原始大小了---padding扩展：外圈补。经过padding之后，原始图片尺寸为(n+2p) x (n+2p)，filter尺寸为f x f，则卷积后的图片尺寸为(n+2p-f+1) x (n+2p-f+1)。若要保证卷积前后图片尺寸不变，则p应满足：p=(f-1)/2

#### **Strided Convolutions**

Stride表示filter在原图片中水平方向和垂直方向每次的步进长度。之前我们默认stride=1。若stride=2，则表示filter每次步进长度为2，即隔一点移动一次。

#### 相关系数

值得一提的是，相关系数（cross-correlations）与卷积（convolutions）之间是有区别的。实际上，真正的卷积运算会先将filter绕其中心旋转180度，然后再将旋转后的filter在原始图片上进行滑动计算。相关系数的计算过程则不会对filter进行旋转，而是直接在原始图片上进行滑动计算。目前为止我们介绍的CNN卷积实际上计算的是相关系数，而不是数学意义上的卷积。但是，为了简化计算，我们一般把CNN中的这种“相关系数”就称作卷积运算。之所以可以这么等效，是因为滤波器算子一般是水平或垂直对称的，180度旋转影响不大；而且最终滤波器算子需要通过**CNN网络梯度下降算法**计算得到，旋转部分可以看作是包含在CNN模型算法中。总的来说，忽略旋转运算可以大大提高CNN网络运算速度，而且不影响模型性能。

#### **Convolutions Over Volume**

对于3通道的RGB图片，其对应的滤波器算子同样也是3通道的。例如一个图片是6 x 6 x 3，分别表示图片的高度（height）、宽度（weight）和通道（#channel）。

**理解**：图像三通道，对应的filter便亦是3通道，filter有多个，则最终的图片尺寸为：（n-f+1) x (n-f+1) x n' --n'为filter的个数,n为通道数

#### **One Layer of a Convolutional Network**

卷积神经网络的单层结构如下所示：

相比之前的卷积过程，CNN的单层结构多了激活函数ReLU和偏移量b。整个过程与标准的神经网络单层结构非常类似

![这里写图片描述](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcxMTI4MjMzMjQyNDk0?x-oss-process=image/format,png)



我们来计算一下上图中参数的数目：每个滤波器组有3x3x3=27个参数，还有1个偏移量b，则每个滤波器组有27+1=28个参数，两个滤波器组总共包含28x2=56个参数。我们发现，选定滤波器组后，参数数目与输入图片尺寸无关。所以，就不存在由于图片尺寸过大，造成参数过多的情况。例如一张1000x1000x3的图片，标准神经网络输入层的维度将达到3百万，而在CNN中，参数数目只由滤波器组决定，数目相对来说要少得多，这是CNN的优势之一。

**理解：**CNN的模型参数只有我的filter的规格，以及偏移量有关，相比于标准神经网络（不晓得标准神经网络咋设计的），参数的数目少，是其优势所在。

下面介绍一个简单的CNN网络模型：

​    ![这里写图片描述](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcxMTMwMTA1NTQ2MzIx?x-oss-process=image/format,png)       



这个模型经历了三次的filter卷积，第一次filter为10组，第二次为20组，第三次为40组，最后生成的图像大小为7×7×40，随着CNN的层数增加，图像的长宽在减少，层数在增加。

CNN有三种类型的layer：

**Convolution层（CONV） **  **Pooling层（POOL）**  **Fully connected层（FC）**



#### **Pooling Layers**

pooling layers是CNN中用来减小尺寸，提高运算速度的，同样能减小noise影响，让各特征更具有健壮性。对输入的特征图进行压缩，一方面使特征图变小，简化网络计算复杂度；一方面进行特征压缩，提取主要特征。

Pooling layers的做法比convolution layers简单许多，没有卷积运算，仅仅是在滤波器算子滑动区域内取最大值，即max pooling，这是最常用的做法。注意，超参数p很少在pooling layers中使用。

**Max pooling**的好处是只保留区域内的最大值（特征），忽略其它值，降低noise影响，提高模型健壮性。而且，max pooling需要的超参数仅为滤波器尺寸f和滤波器步进长度s，没有其他参数需要模型训练得到，计算量很小。

![这里写图片描述](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcxMTI5MjAyMzIyMzA2?x-oss-process=image/format,png)



**average pooling**：在滤波器算子滑动区域计算平均值。

![这里写图片描述](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcxMTI5MjAzODQxMzM2?x-oss-process=image/format,png)

#### Fully connected Layers

连接所有的特征，将输出值送给分类器（如softmax分类器）。

### 2.2深度卷积模型

#### **Classic Networks**

##### LeNet -5

LeNet-5模型是Yann LeCun教授于1998年提出来的，它是第一个成功应用于数字识别问题的卷积神经网络。在MNIST数据中，它的准确率达到大约99.2%。典型的LeNet-5结构包含CONV layer，POOL layer和FC layer，顺序一般是CONV layer->POOL layer->CONV layer->POOL layer->FC layer->FC layer->OUTPUT layer，即y^y^。下图所示的是一个数字识别的LeNet-5的模型结构：

![img](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcxMTMwMTAyNTMwNTQ0?x-oss-process=image/format,png)

**example ：PyTorch 手写字体识别 MNIST**

​       MNIST数据集：数据集包含的是手写的数字图片，二进制字节码存储，28*28的灰度图片，6w训练图片，1w测试图片。模型通过train这6w张图片，而后test这1w张测试图片。

###### 模型构建代码：

卷积层：由卷积核构建，卷积核简称为卷积，也称为滤波器。卷积的大小可以在实际需要时自定义其长和宽（1*1, 3*3, 5*5）。

池化层：对图片进行压缩（降采样）的一种方法，如max pooling, average pooling等。

激活层：激活函数的作用就是，在所有的隐藏层之间添加一个激活函数，这样的输出就是一个非线性函数了，因而神经网络的表达能力更加强大了。

![image-20220402115712294](C:\Users\wfp\AppData\Roaming\Typora\typora-user-images\image-20220402115712294.png)



###### 训练方法代码：

损失函数：在深度学习中，损失反映模型最后预测结果与实际真值之间的差距，可以用来分析训练过程的好坏、模型是否收敛等，例如均方损失、交叉熵损失等。

反向传播：

![image-20220402120836151](C:\Users\wfp\AppData\Roaming\Typora\typora-user-images\image-20220402120836151.png)



![image-20220402115634839](C:\Users\wfp\AppData\Roaming\Typora\typora-user-images\image-20220402115634839.png)

![image-20220402150407493](C:\Users\wfp\AppData\Roaming\Typora\typora-user-images\image-20220402150407493.png)

##### AlexNet

##### VGG-16

#### **ResNets**

我们知道，如果神经网络层数越多，网络越深，源于梯度消失和梯度爆炸的影响，整个模型难以训练成功。解决的方法之一是人为地让神经网络某些层跳过下一层神经元的连接，隔层相连，弱化每层之间的强联系。这种神经网络被称为Residual Networks(ResNets)。

thinking：为啥隔层相连效果就好呢？？

Residual Networks由许多隔层相连的神经元子模块组成，我们称之为Residual block。单个Residual block的结构如下图所示：

![这里写图片描述](https://img-blog.csdn.net/20171211204756960?)

##### 网络比较：

​        **正常流程**：

​      这是一个两层神经网络，在𝐿层进行激活，得到 𝑎[𝑙+1]，再次进行激活，两层之后得到 𝑎[𝑙+2]。计算过程是从 𝑎[𝑙]开始，首先进行线性激活，根据这个公式： **𝑧[𝑙+1]=𝑊[𝑙+1]𝑎[𝑙]+𝑏[𝑙+1]**，通过 𝑎[𝑙]算出 𝑧[𝑙+1]，即 𝑎[𝑙]乘以权重矩阵，再加上偏差因子。然后通过 ReLU非线性激活函数得到  𝑎[𝑙+1]=𝑔(𝑧[𝑙+1])计算得出。接着再次进行线性激活，依据等式 **𝑧[𝑙+2]=𝑊[𝑙+2]𝑎[𝑙+1]+𝑏[𝑙+2]**，最后根据这个等式再次进行 ReLu非线性激活，即 𝑎[𝑙+2]=𝑔(𝑧[𝑙+2])这里的 𝑔是指 ReLU非线性函数，得到的结果就是 𝑎[𝑙+2]。换句话说，信息流从 𝑎[𝑙]到 𝑎[𝑙+2]需要经过以上所有步骤，即这组网络层的主路径。

​        **残差网络流程：**

​       在残差网络中有一点变化，我们将𝑎[𝑙]直接向后，拷贝到神经网络的深层，在 ReLU非线性激活函数前加上 𝑎[𝑙]，这是一条捷径。 𝑎[𝑙]的信息直接到达神经网络的深层，不再沿着主路径传递，这就意味着最后这个等式 (𝑎[𝑙+2]=𝑔(𝑧[𝑙+2]))去掉了，取而代之的是另一个 ReLU非
线性函数，仍然对 𝑧[𝑙+2]进行 𝑔函数处理，但这次要加上 𝑎[𝑙]，即 **𝑎[𝑙+2]=𝑔(𝑧[𝑙+2]+𝑎[𝑙])**  也就 是加上的这个 **𝑎[𝑙]**产生了一个残差块。

​     **resnet网络优势：**

```mathematica
a^{[l+2]}=g(z^{[l+2]}+a^{[l]})=g(W^{[l+2]}a^{[l+1]}+b^{[l+2]}+a^{[l]})
输入x经过Big NN后，若W[l+2]≈0，b[l+2]≈0，则有：
a^{[l+2]}=g(a^{[l]})=ReLU(a^{[l]})=a^{[l]}    when a^{[l]}>=0
#ReLU激活函数，并且所有激活值都是非负的， 𝑔(𝑎[𝑙])是应用于非负数的 ReLU函数，所以 𝑎[𝑙+2]=𝑎[𝑙]。

```

​       可以看出，即使发生了梯度消失，W[l+2]≈0，b[l+2]≈0，也能直接建立a[l+2]a[l+2]与a[l]a[l]的线性关系，且a[l+2]=a[l]，这其实就是identity function。a[l]直接连到a[l+2]，从效果来说，相当于直接忽略了a[l]之后的这两层神经层。这样，看似很深的神经网络，其实由于许多Residual blocks的存在，弱化削减了某些神经层之间的联系，实现隔层线性传递，而不是一味追求非线性关系，模型本身也就能“容忍”更深层的神经网络了。而且从性能上来说，这两层额外的Residual blocks也不会降低Big NN的性能。

有一点需要注意的是，如果Residual blocks中a[l]和a[l+2]的维度不同，通常可以引入矩阵WsWs，与a[l]a[l]相乘，使得Ws∗a[l]Ws∗a[l]的维度与a[l+2]a[l+2]一致。参数矩阵WsWs有来两种方法得到：一种是将WsWs作为学习参数，通过模型训练得到；另一种是固定WsWs值（类似单位矩阵），不需要训练，WsWs与a[l]a[l]的乘积仅仅使得a[l]a[l]截断或者补零。这两种方法都可行。

![这里写图片描述](https://img-blog.csdn.net/20171212142205247?)

ResNets同类型层之间，例如CONV layers，大多使用same类型，保持维度相同。如果是不同类型层之间的连接，例如CONV layer与POOL layer之间，如果维度不同，则引入矩阵WsWs。

## 3 Pytorch--ResNet识别MNIST数据集

[(69条消息) Pytorch--ResNet识别MNIST数据集_不不加辣椒的博客-CSDN博客_resnet识别mnist](https://blog.csdn.net/qq_38308028/article/details/106982599)

流程：

- 加载必要的库

- 定义超参数
- 构建pipeline，对图像处理or构建transforms，对图像做变换
- 下载加载数字集mnitst
- 构建网络模型（最重要环节）
- 定义优化器
- 定义训练方法
- 定义测试方法
- 开始训练模型，输出预测结果

```python
#加载必要的库
import torch
import torchvision
import torch.nn as nn
import torch.nn.functional as F
import torch.utils.data as Data
import matplotlib.pyplot as plt

# define hyper parameters 定义超参数
Batch_size = 50  #每一批处理的数据数目
Lr = 0.1
Epoch = 1
# define train set and test set 定义训练数据和测试数据
train_dataset = torchvision.datasets.MNIST(
    root='./MNIST',
    train=True,
    download=True,
    transform=torchvision.transforms.ToTensor()
)
test_dataset = torchvision.datasets.MNIST(
    root='./MNISt',
    train=False,
    download=True,
    transform=torchvision.transforms.ToTensor()
)
# define train loader  加载训练数据
train_loader = Data.DataLoader(
    dataset=train_dataset,
    shuffle=True,      #打乱训练数据的顺序
    batch_size=Batch_size
)
test_x = torch.unsqueeze(test_dataset.data, dim=1).type(torch.Tensor)
test_y = test_dataset.targets
# print(test_y.shape, test_x.shape)

# construct network
class Basicblock(nn.Module):
    def __init__(self, in_planes, planes, stride=1):
        super(Basicblock, self).__init__()
        self.conv1 = nn.Sequential(
            nn.Conv2d(in_channels=in_planes, out_channels=planes, kernel_size=3, stride=stride, padding=1, bias=False),
            nn.BatchNorm2d(planes),
            nn.ReLU()
        )
        self.conv2 = nn.Sequential(
            nn.Conv2d(in_channels=planes, out_channels=planes, kernel_size=3, stride=1, padding=1, bias=False),
            nn.BatchNorm2d(planes),
        )

        if stride != 1 or in_planes != planes:
            self.shortcut = nn.Sequential(
                nn.Conv2d(in_channels=in_planes, out_channels=planes, kernel_size=3, stride=stride, padding=1),
                nn.BatchNorm2d(planes)
            )
        else:
            self.shortcut = nn.Sequential()

    def forward(self, x):
        out = self.conv1(x)
        out = self.conv2(out)
        out += self.shortcut(x)
        out = F.relu(out)
        return out

class ResNet(nn.Module):
    def __init__(self, block, num_block, num_classes):
        super(ResNet, self).__init__()
        self.in_planes = 16
        self.conv1 = nn.Sequential(
            nn.Conv2d(in_channels=1, out_channels=16, kernel_size=3, stride=1, padding=1),
            nn.BatchNorm2d(16),
            nn.ReLU()
        )
        self.maxpool = nn.MaxPool2d(kernel_size=3, stride=1, padding=1)

        self.block1 = self._make_layer(block, 16, num_block[0], stride=1)
        self.block2 = self._make_layer(block, 32, num_block[1], stride=2)
        self.block3 = self._make_layer(block, 64, num_block[2], stride=2)
        # self.block4 = self._make_layer(block, 512, num_block[3], stride=2)

        self.outlayer = nn.Linear(64, num_classes)

    def _make_layer(self, block, planes, num_block, stride):
        layers = []
        for i in range(num_block):
            if i == 0:
                layers.append(block(self.in_planes, planes, stride))
            else:
                layers.append(block(planes, planes, 1))
        self.in_planes = planes
        return nn.Sequential(*layers)

    def forward(self, x):
        x = self.maxpool(self.conv1(x))
        x = self.block1(x)                       # [200, 64, 28, 28]
        x = self.block2(x)                       # [200, 128, 14, 14]
        x = self.block3(x)                       # [200, 256, 7, 7]
        # out = self.block4(out)
        x = F.avg_pool2d(x, 7)                   # [200, 256, 1, 1]
        x = x.view(x.size(0), -1)                # [200,256]
        out = self.outlayer(x)
        return out

ResNet18 = ResNet(Basicblock, [1, 1, 1, 1], 10)
# print(ResNet18)

opt = torch.optim.SGD(ResNet18.parameters(), lr=Lr)
loss_fun = nn.CrossEntropyLoss()
a = []
ac_list = []
for epoch in range(Epoch):
    for i, (x, y) in enumerate(train_loader):
        output = ResNet18(x)
        loss = loss_fun(output, y)
        opt.zero_grad()
        loss.backward()
        opt.step()

        if i % 100 == 0:
            a.append(i)
            test_output = torch.max(ResNet18(test_x), dim=1)[1]
            loss = loss_fun(ResNet18(test_x), test_y).item()
            accuracy = torch.sum(torch.eq(test_y, test_output)).item() / test_y.numpy().size
            ac_list.append(accuracy)
            print('Epoch:', Epoch, '|loss%.4f' % loss, '|accuracy%.4f' % accuracy)

print('real value', test_y[: 10].numpy())
print('train value', torch.max(ResNet18(test_x)[: 10], dim=1)[1].numpy())

plt.plot(a, ac_list, color='r')
plt.show()
```
