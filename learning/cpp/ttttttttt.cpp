#include <iostream>



// 定义回调函数指针类型

typedef void (*CallbackFunc)(int);



// 执行某个操作，当操作完成时调用回调函数

void performOperation(int value, CallbackFunc callback) {

  // 模拟执行操作

  std::cout << "Performing operation with value: " << value << std::endl;



  // 操作完成后调用回调函数

  callback(value * 2);

}



// 回调函数，用于处理操作完成后的结果

void handleResult(int result) {

  std::cout << "Received result: " << result << std::endl;

  // 其他处理逻辑...

}



int main() {

  int value = 5;



  // 调用 performOperation，并传递回调函数的地址

  performOperation(value, handleResult);



  return 0;

}