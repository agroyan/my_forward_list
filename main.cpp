#include <iostream>
#include "node.h"


int main()
{
    std::cout << "" << std::endl;
    std::cout << "У нас есть вектор V = {5, 6, 2, 3, 20, 50, -11, 88}" << std::endl;
    std::vector<int> V = {5, 6, 2, 3, 20, 50, -11, 88};
    std::cout << "" << std::endl;
    std::cout << "С помощью функции MakeList сделаем из вектора V однонаправленный список node" << std::endl;
    std::cout << "node хранит указатель на первый элемент списка" << std::endl;
    Node* node = MakeList(V);
    std::cout << "" << std::endl;
    std::cout << "Теперь с помощью функции print выведем узлы списка node" << std::endl;
    print(node);
    std::cout << "" << std::endl;
    std::cout << "С помощью функции Insert вставим в node число 33 в начало и с помощью print выведем результат" << std::endl;
    Insert(node, 33, 0);
    print(node);
    std::cout << "" << std::endl;
    std::cout << "Теперь с помощью функции Insert вставим в node число 220 на 5-ую позицию и с помощью print выведем результат" << std::endl;
    Insert(node, 220, 5);
    print(node);
    std::cout << "" << std::endl;
    std::cout << "Перевернем наш список и запишем результат в node_rev, потом выведем оба результата для наглядности" << std::endl;
    Node* node_rev = reverse(node);
    print(node);
    print(node_rev);
    std::cout << "" << std::endl;
    std::cout << "Теперь покажем как работает функция deep_copy в сравнении с обычной копирующей инициализацией" << std::endl;
    std::cout << "node_copy - поверхностная копия node" << std::endl;
    std::cout << "node_deep_copy - глубокая копия node" << std::endl;
    std::cout << "" << std::endl;
    Node* node_copy = node;
    Node* node_deep_copy = deep_copy(node);
    std::cout << "node_copy: ";
    print(node_copy);
    std::cout << "node_deep_copy: ";
    print(node_deep_copy);
    std::cout << std::endl;
    std::cout << "Вставим в node элемент 17 на вторую позицию" << std::endl;
    std::cout << std::endl;
    Insert(node, 17, 2);
    std::cout << "Вставим в node элемент 59 на четвертую позицию" << std::endl;
    std::cout << std::endl;
    Insert(node, 59, 4);
    std::cout << "node_copy: ";
    print(node_copy);
    std::cout << "node_deep_copy: ";
    print(node_deep_copy);
    std::cout << std::endl;
    std::cout << "Удалим в node элемент на пятой позиции" << std::endl;
    std::cout << std::endl;
    Delete(node, 5);
    std::cout << "node_copy: ";
    print(node_copy);
    std::cout << "node_deep_copy: ";
    print(node_deep_copy);
    std::cout << std::endl;
}
