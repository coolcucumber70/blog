//5.7

//Tcp内容:
关于三次握手与四次挥手等问题:
为什么进行三次握手？
保证双方的序列号与确认号对应
 解决tcpack问题，以及重传问题：重传？突然产生两个第一次握手之类问题

 如果第一次握手丢了，第二次丢了，第三次丢了？
 同样的问题-挥手

 后面主要讲解的是重传机制---超时与快速--->sack-->告诉服务器后面的我哪些是接收了的--->dsack---->我能看到哪一个是被我重传了

 流量控制-->端到端的流量控制-->通过滑动窗口--->窗口变成0怎么解决的问题？？
 流量拥塞-->慢启动，快启动，一个直接回到解放前，快启动本质就是我不想让他一下掉的太凶了，命名网络里还是有资源，没必要直接从初始开始。

//IP
关于ip的划分--->
cidr打破之前，用子网掩码来进行判断
路由的调度问题---

arp:主要是找mac，通过广播的方法;
icmp:主要就是给你回错误消息的协议
igmp：管理网管-->化组，用于组播
dhcp：用来分配ip，这个是tcp协议

//5.8
关于io的多路复用问题如何解决？？

