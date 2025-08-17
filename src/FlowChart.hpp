#pragma once
#include "FlowElement.hpp"
#include <unordered_map>
#include <memory>
#include <iostream>

namespace com { namespace lab111 { namespace labwork3 {

/**
 * @class FlowChart
 * @brief Клас, що виступає "клієнтом" патерну Composite, керуючи колекцією елементів блок-схеми.
 *
 * Цей клас відповідає за додавання, отримання та обробку всіх елементів
 * блок-схеми, незалежно від того, чи є вони простими блоками, чи композитними.
 */
class FlowChart {
private:
    std::unordered_map<int, std::shared_ptr<FlowElement>> nodes;
public:
    /**
     * @brief Додає елемент блок-схеми до колекції.
     *
     * Використовує ідентифікатор елемента як ключ для зберігання у map.
     * @param node Вказівник на об'єкт FlowElement, який потрібно додати.
     */
    void add(const std::shared_ptr<FlowElement>& node) {
        nodes[node->getId()] = node;
    }

    /**
     * @brief Отримує елемент блок-схеми за його унікальним ідентифікатором.
     * @param id Унікальний ідентифікатор елемента.
     * @return Вказівник на знайдений елемент, або nullptr, якщо елемент не знайдено.
     */
    std::shared_ptr<FlowElement> get(int id) const {
        auto it = nodes.find(id);
        if (it != nodes.end()) {
            return it->second;
        }
        return nullptr;
    }

    /**
     * @brief Виводить інформацію про всі елементи в колекції.
     *
     * Обходить всі вузли в map та викликає їхній метод printInfo().
     */
    void printAll() const {
        for (auto &kv : nodes) {
            if (kv.second) {
                kv.second->printInfo();
            }
        }
    }

    /**
     * @brief Рекурсивно виводить структуру блок-схеми, починаючи з кореневого елемента.
     * @param rootId Ідентифікатор кореневого елемента, з якого починається виведення.
     */
    void printStructure(int rootId) const {
        auto root = get(rootId);
        if (root) {
            root->traversePrint();
        }
    }
};

}}}
