# qt系统学习笔记

## 1、网络通信相关

### 1.1关于QThread线程类的使用

- 不使用事件循环：
  while写死循环a. 子类化 QThreadb. 重载 run 函数，run函数内有一个 while 或 for 的死循环c. 设置一个标记为来控制死循环的退出。
- 使用事件循环。（博客 you are-doing-it-wrong 批驳的就是这种情况下的 一种用法。）
  - a. 子类化 QThread，
  - b. 重载 run 使其调用 QThread::exec() 
  - c. 并为该类定义信号和槽，这样一来，由于槽函数并不会在新开的 thread 运行，很多人为了解决这个问题在构造函数中调用 moveToThread(this)而争论和不解正是这样的一条语句造成的。
  - Bradley T. Hughes 给出说明是： QThread 应该被看做是操作系统线程的接口或控制点，而不应该包含需要在新线程中运行的代码。需要运行的代码应该放到一个QObject的子类中，然后将该子类的对象moveToThread到新线程中。

### 1.2关于connect信号槽

- 自动连接(Auto Connection)
这是默认设置
如果信号在接收者所依附的线程内发射，则等同于直接连接
如果发射信号的线程和接受者所依附的线程不同，则等同于队列连接
也就是这说，只存在下面两种情况
- 直接连接(Direct Connection)
当信号发射时，槽函数将直接被调用。
无论槽函数所属对象在哪个线程，槽函数都在发射信号的线程内执行。
- 队列连接(Queued Connection)
当控制权回到接受者所依附线程的事件循环时，槽函数被调用。
槽函数在接收者所依附线程执行。

个人理解：其实直接连接的本质就是connect的一个同线程直接调用回调函数，只涉及一个进程，不涉及中断。队列连接涉及到了异步编程了。

movetothread的方式，本质上就是改变了接收者的线程依附。所以是队列连接。但是直接调用其函数，仍然是谁调用就在谁的线程里面。

### 1.3关于 QByteArray的使用

访问与赋值访问QByteArray主要有4中方式，分别为[]、at()、data[]和constData[]。其中[]和data[]为可读可写，at()和constData[]仅为可读。如果仅是读，则通过at()和constData[]访问速度最快，因可避免复制处理。示例如下：

```cpp
QByteArray ba;
ba.resize(6);
ba[0] = 0x3c;
ba[1] = 0xb8;
ba[2] = 0x64;
ba[3] = 0x18;
ba[4] = 0xca;
ba.data()[5] = 0x31;
qDebug()<<"[]"<<ba[2]; //[] d
qDebug()<<"at()"<<ba.at(2); //at() d
qDebug()<<"data()"<<ba.data()[2]; //data() d
qDebug()<<"constData()"<<ba.constData()[2]; //constData() d
qDebug()<<"constData()"<<ba.constData()[5]; //constData() 1
```

#### 数据转换与处理

从串口读取到的QByteArray数据，一般需要进行提取和解析，此时就需要QByteArray转换为各类型数据。常用转换包括：

- 转为HEX，用于显示十六进制，这点在调试时特别有用，因为大多HEX码是没有字符显示的，如0x00、0x20等等；
- 转为不同进制数值并显示，如二进制、八进制、十进制和十六进制等；
- 转为整型、浮点型等数值类型；
- 大小写转换；
- 转为字符串类型；

#### Hex转换

```cpp
把Hex编码转换为char存储到QByteArray：
QByteArray text = QByteArray::fromHex("517420697320677265617421");
text.data();            // returns "Qt is great!"
把QByteArray转为Hex编码：
QByteArray ba;
ba.resize(3);
ba[0] = 0x30;
ba[1] = 0x31;
ba[2] = 0x32;
qDebug() << ba.toHex(); //return "303132"
```

#### 数值转换与输出

尽管QByteArray是一个集合，但也可以作为一个特殊形式的数值用，其灵活的转换格式，可大大方便各种格式数据转换与显示的需求。如显示二进制和十六进制、显示科学计数和指定小数位的数值。示例如下：

```cpp
把单个字符转为2-36进制数据格式：
int n = 63;
qDebug()<<QByteArray::number(n);              // returns "63"
qDebug()<<QByteArray::number(n, 16);          // returns "3f"
qDebug()<<QByteArray::number(n, 16).toUpper();  // returns "3F"
qDebug()<<QByteArray::number(n, 2);          // returns "111111"
qDebug()<<QByteArray::number(n, 8);          // returns "77"
按照指定进制格式直接复制，其中n可以是各类常见数值类型：
QByteArray ba;
int n = 63;
ba.setNum(n);          // ba == "63"
ba.setNum(n, 16);      // ba == "3f"
把数值按指定格式和小数位转换输出，小数位四舍五入：
QByteArray ba1 = QByteArray::number(12.3456, 'E', 3);
QByteArray ba2 = QByteArray::number(12.3456, 'f', 3);
qDebug()<<ba1;  // returns "1.235E+01"
qDebug()<<ba2;  // returns "12.346"
```

#### 字符串数值转为各类数值

```cpp
QByteArray若为数值，可通过to**方法转为各种类型数据，示例如下：
QByteArray strInt("1234");
bool ok0;
qDebug() << strInt.toInt();  // return 1234
qDebug() << strInt.toInt(&ok0,16);  // return 4660, 默认把strInt作为16进制的1234，对应十进制数值为4660

QByteArray string("1234.56");
bool ok1;
qDebug() << string.toInt();  // return 0, 小数均视为0
qDebug() << string.toInt(&ok1,16);  // return 0, 小数均视为0
qDebug() << string.toFloat();  // return 1234.56
qDebug() << string.toDouble();  // return 1234.56

QByteArray str("FF");
bool ok2;
qDebug() << str.toInt(&ok2, 16);    // return 255, ok2 == true
qDebug() << str.toInt(&ok2, 10);    // return 0, ok == false, 转为十进制失败
```

#### 大小写转换

```cpp
QByteArray若为带大小写的字符串，可通过toUpper()和toLower()方法实现大小写转换，示例如下：
QByteArray x("Qt by THE QT COMPANY");
QByteArray y = x.toLower();
// y == "qt by the qt company"

QByteArray z = x.toUpper();
// z == "QT BY THE QT COMPANY"
```

#### 与字符串互转

QByteArray与QString互转极为简单，二者从本质上类似，都是连续存储，区别是前者可以存无法显示的字符，后者只存可显示的字符。如QByteArray可以存0x00-0x19，而QString则存储如0x30等可显示字符（0x20-0x7E）。可显示字符可参见ASCII表，链接如下：ASCII可显示字符

```cpp
    QByteArray转为QString示例：
QByteArray ba("abc123");
QString str = ba;
//或str.prepend(ba);
qDebug()<<str ;
//输出："abc123"
    QString转为QByteArray示例：
QString str("abc123");
QByteArray ba = str.toLatin1();
qDebug()<<ba;
//输出："abc123"
```
