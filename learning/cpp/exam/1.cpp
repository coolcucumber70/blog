#include <iostream>
using namespace std;

int arr[5] = {1, 2, 3, 4, 5};

int& getElement(int index) {
    return arr[index];
}
int* getElementptr(int index){
    return &arr[index];


}

int main() {
    int& element = getElement(2);  // 获取 arr 数组的第三个元素的引用
    cout << "Element before modification: " << element << endl;

    element = 10;  // 修改 arr 数组的第三个元素
    int* elementptr=getElementptr(3);
    *elementptr=14;

    cout << "Element after modification: " << element << endl;
    cout << "Modified array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}