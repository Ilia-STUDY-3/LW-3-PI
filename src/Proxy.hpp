#pragma once
#include "Blocks.hpp"
#include "FlowElement.hpp"
#include <iostream>

namespace com { namespace lab111 { namespace labwork3 {

/**
 * @class LazyProcessProxy
 * @brief Клас, що виступає в ролі віртуального проксі для ProcessBlock.
 *
 * Цей клас реалізує патерн **Proxy**, забезпечуючи "ліниву" (відкладену)
 * ініціалізацію об'єкта `ProcessBlock`. Реальний об'єкт створюється лише
 * тоді, коли клієнт вперше звертається до нього.
 */
class LazyProcessProxy : public FlowElement {
private:
    int id;
    std::string label;
    mutable std::shared_ptr<ProcessBlock> realObj;

    /**
     * @brief Забезпечує, що реальний об'єкт ProcessBlock створений.
     *
     * Цей метод є "заглушкою" для лінивої ініціалізації. Він створює об'єкт
     * `realObj` лише один раз, при першому зверненні.
     */
    void ensure() const {
        if (!realObj) {
            realObj = std::make_shared<ProcessBlock>(id, label);
            std::cout << "[Proxy] Lazy created ProcessBlock id=" << id << "\n";
        }
    }

public:
    /**
     * @brief Конструктор для LazyProcessProxy.
     * @param id_ Унікальний ідентифікатор проксі-блоку.
     * @param label_ Мітка, що описує блок обробки.
     */
    LazyProcessProxy(int id_, std::string label_) : id(id_), label(std::move(label_)) {}

    /**
     * @brief Отримує ідентифікатор проксі-блоку.
     * @return Унікальний ідентифікатор.
     */
    int getId() const override { return id; }

    /**
     * @brief Отримує мітку проксі-блоку.
     * @return Рядок-мітка.
     */
    std::string getLabel() const override { return label; }

    /**
     * @brief Перенаправляє виклик до методу identify() реального об'єкта після ініціалізації.
     * @return Ідентифікаційний рядок реального об'єкта.
     */
    std::string identify() const override {
        ensure();
        return realObj->identify();
    }

    /**
     * @brief Перенаправляє виклик до методу printInfo() реального об'єкта після ініціалізації.
     */
    void printInfo() const override {
        ensure();
        realObj->printInfo();
    }
};

}}}
