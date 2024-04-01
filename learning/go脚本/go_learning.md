

go语言中的列表，有迭代器那味道了，可以说是一摸一样


goto的语法，用来退出两层循环：指到哪里就打到哪里

go语言中的可变参数：参数使用interface{}可以表示任何的参数

使用延迟执行语句在函数退出时释放资源：

```go
func readValue(key string) int {

    valueByKeyGuard.Lock()
   
    // defer后面的语句不会马上调用, 而是延迟到函数结束时调用
    defer valueByKeyGuard.Unlock()

    return valueByKey[key]
}
```
### Go语言宕机（panic）

在Go语言中，"宕机"（panic）是一种表示程序运行时发生了无法恢复的错误的机制。当程序发生无法处理的错误或异常情况时，可以使用`panic`函数来触发宕机。

宕机的过程如下：

1. 当程序执行到一个`panic`函数调用时，当前函数的执行被中断，立即执行`defer`语句（如果有）。
2. 程序开始沿着调用栈向上回溯，寻找包含`recover`函数调用的`defer`语句。
3. 如果找到了包含`recover`的`defer`语句，程序会从宕机状态中恢复，并进入这个`defer`语句执行后续逻辑。
4. 如果没有找到包含`recover`的`defer`语句，程序会退出，并打印宕机错误信息（包括宕机原因和堆栈跟踪信息）。

以下是一个示例，演示了宕机的使用和恢复：

```go
func main() {
    defer func() {
        if r := recover(); r != nil {
            fmt.Println("Recovering from panic:", r)
        }
    }()

    fmt.Println("Start")

    // 触发宕机
    panic("Something went wrong!")

    fmt.Println("End") // 不会被执行
}
```

在上述示例中，我们使用`defer`语句定义了一个匿名函数。这个匿名函数包含了一个`recover`函数调用，用于捕获宕机状态并进行恢复。

在`main`函数中，我们首先打印"Start"，然后通过调用`panic`函数触发了宕机。由于存在`defer`语句，程序会进入`defer`语句定义的匿名函数，并执行其中的逻辑。

在匿名函数中，我们使用`recover`函数检查是否有宕机状态，如果有，则打印恢复消息。在这个例子中，我们将打印"Recovering from panic: Something went wrong!"。

请注意，宕机是一种用于处理严重错误的机制，应该小心使用。它通常用于处理不可恢复的错误或异常情况，并在程序无法继续运行时进行适当的清理和报告。在大多数情况下，我们应该优先使用错误处理机制（例如返回错误值），而不是过度依赖宕机。

面向接口的这种编程，确实挺有意思的哈

类型断言

