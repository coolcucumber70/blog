#include <iostream>

// 回调函数类型定义
typedef void (*CallbackFunction)(int);

// 发送消息的类
class MessageSender {
private:
    CallbackFunction callback;

public:
    void setCallback(CallbackFunction cb) {
        callback = cb;
    }

    void sendMessage(int data) {
        std::cout << "Sending message: " << data << std::endl;

        // 发送消息后调用回调函数
        if (callback != nullptr) {
            callback(data);
        }
    }
};

// 接收消息并处理的类
class MessageReceiver {
public:
    void processMessage(int data) {
        std::cout << "Received message: " << data << std::endl;
        // 处理消息
    }
};

// 回调函数实现
void callbackFunction(int data) {
    MessageReceiver receiver;
    receiver.processMessage(data);
}

int main() {
    MessageSender sender;
    MessageReceiver receiver;

    // 将回调函数注册到发送者对象
    sender.setCallback(callbackFunction);

    // 发送消息，触发回调
    sender.sendMessage(42);

    return 0;
}