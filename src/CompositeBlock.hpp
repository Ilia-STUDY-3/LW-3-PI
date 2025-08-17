#pragma once
#include "FlowElement.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

namespace com { namespace lab111 { namespace labwork3 {

/**
 * @class CompositeBlock
 * @brief Представляє композитний блок, який може містити інші елементи блок-схеми.
 *
 * Цей клас є реалізацією патерну **Composite**. Він дозволяє створювати
 * ієрархічні структури та обробляти як окремі блоки, так і групи блоків однаковим чином.
 */
class CompositeBlock : public FlowElement {
private:
    int id;
    std::string label;
    std::vector<std::shared_ptr<FlowElement>> children;
public:
    /**
     * @brief Конструктор для CompositeBlock.
     * @param id_ Унікальний ідентифікатор блоку.
     * @param label_ Мітка, що описує композитний блок.
     */
    CompositeBlock(int id_, std::string label_) : id(id_), label(std::move(label_)) {}

    /**
     * @brief Отримує унікальний ідентифікатор блоку.
     * @return Унікальний ідентифікатор.
     */
    int getId() const override { return id; }
    
    /**
     * @brief Отримує мітку блоку.
     * @return Рядок-мітка блоку.
     */
    std::string getLabel() const override { return label; }

    /**
     * @brief Додає дочірній елемент до композитного блоку.
     * @param child Вказівник на дочірній елемент, який потрібно додати.
     */
    void addChild(std::shared_ptr<FlowElement> child) override {
        children.push_back(std::move(child));
    }

    /**
     * @brief Видаляє дочірній елемент з композитного блоку.
     * @param child Вказівник на дочірній елемент, який потрібно видалити.
     */
    void removeChild(std::shared_ptr<FlowElement> child) override {
        children.erase(std::remove(children.begin(), children.end(), child), children.end());
    }

    /**
     * @brief Повертає список дочірніх елементів.
     * @return Вектор вказівників на дочірні елементи.
     */
    std::vector<std::shared_ptr<FlowElement>> getChildren() const override {
        return children;
    }

    /**
     * @brief Повертає ідентифікаційний рядок для композитного блоку.
     * @return Рядок, що містить ідентифікатор, мітку та кількість дочірніх елементів.
     */
    std::string identify() const override {
        return "CompositeBlock[id=" + std::to_string(id) + ", label='" + label +
               "', children=" + std::to_string(children.size()) + "]";
    }
    
    /**
     * @brief Виводить інформацію про композитний блок у консоль.
     */
    void printInfo() const override {
        std::cout << "printInfo -> CompositeBlock: id=" << id
                  << ", label='" << label
                  << "', children=" << children.size() << "\n";
    }
};

}}}
