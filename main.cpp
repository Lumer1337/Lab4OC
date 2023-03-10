#include <iostream>

class Stack {
private:
    int* array;
    int size;
    int topIndex;

public:
    Stack() {
        size = 10;
        array = new int[size];
        topIndex = -1;
    }

    ~Stack() {
        delete[] array;
    }

    void push(int element) {
        if (topIndex == size - 1) {
            int* newArray = new int[size * 2];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            size *= 2;
        }
        topIndex++;
        array[topIndex] = element;
    }

    int pop() {
        if (topIndex == -1) {
            std::cerr << "Стэк пустой." << std::endl;
            return -1;
        }
        int element = array[topIndex];
        topIndex--;
        return element;
    }

    int peek() {
        if (topIndex == -1) {
            std::cerr << "Стэк пустой." << std::endl;
            return -1;
        }
        return array[topIndex];
    }

    bool isEmpty() {
        return (topIndex == -1);
    }
};

int main() {
    Stack myStack;   //Создаём объект myStack
    std::cout << "Пустой ли стэк? " << myStack.isEmpty() << std::endl;  //Возвращает true, тк туда ещё ничего не записали
    std::cout << "Попнутый эллемент: " << myStack.pop() << std::endl; //Пытаемся извлечь элемент из стека, в результате чего выводится сообщение об ошибке
    myStack.push(5);  //помещаем элемент 5 в стек
    std::cout << "Верхний элемент стэка: " << myStack.peek() << std::endl;   //печатаем верхний элемент с помощью peek()
    myStack.push(10);  //помещаем элемент 10 в стек
    myStack.push(15);  //помещаем элемент 15 в стек
    myStack.push(20);  //помещаем элемент 20 в стек
    std::cout << "Попнутый эллемент: " << myStack.pop() << std::endl;
    std::cout << "Попнутый эллемент: " << myStack.pop() << std::endl;//извлекаем два верхних элемента с помощью pop()
    std::cout << "Пустой ли стэк? " << myStack.isEmpty() << std::endl;
    return 0;
}


/*стек инициализируется с размером по умолчанию 10, и каждый раз, когда стек заполнен и
 * мы хотим вставить элемент, мы удваиваем размер массива. Это гарантирует, что в массиве всегда будет достаточно
 * места для любого количества элементов. Функции pop()и peek()проверяют, пуст ли стек, прежде чем пытаться получить
 * доступ к верхнему элементу, и если стек пуст, они выводят сообщение об ошибке и возвращают -1*/