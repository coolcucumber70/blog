# PYBIND11学习

1、从C++访问 Python 库

以下是一个完整的使用 PyBind11 导入 Python 中的 scipy 库，并获取其版本号的例子：

```
c++Copy code#include <pybind11/embed.h>

namespace py = pybind11;

int main() {
    // Start the Python interpreter
    py::scoped_interpreter guard{};

    // Try to import scipy
    py::object scipy = py::module_::import("scipy");
    py::object version = scipy.attr("__version__");

    // Print the version number of scipy
    std::string version_str = py::str(version);
    std::cout << "scipy version: " << version_str << std::endl;

    return 0;
}
```

这个例子做了以下几件事情：

1. 在程序开始时，使用 `py::scoped_interpreter` 类型的对象创建了一个 Python 解释器。这样，程序就可以在 C++ 中使用 Python 语言了。
2. 使用 `py::module_::import("scipy")` 语句导入 Python 中的 scipy 库，并将其绑定到一个 `py::object` 类型的变量 `scipy` 上。
3. 使用 `scipy.attr("__version__")` 语句从 `scipy` 变量中获取版本号属性，并将其绑定到一个 `py::object` 类型的变量 `version` 上。
4. 使用 `py::str` 函数将 `version` 变量转换为字符串类型，并将其打印到标准输出中。

运行这个程序，将输出类似以下内容：

```
yamlCopy code
scipy version: 1.7.3
```

2、从C++中访问python自定义的模块

g++ -o example example.cpp -I/home/wfp/anaconda3/include/python3.9 -L/home/wfp/anaconda3/lib -lpython3.9

