#pragma once
#include "FlowElement.hpp"
#include <string>

namespace com { namespace lab111 { namespace labwork3 {

/**
 * @class BaseBlock
 * @brief Представляє абстрактний базовий клас для всіх "листових" вузлів у блок-схемі.
 *
 * Цей клас служить конкретною реалізацією інтерфейсу FlowElement для
 * всіх простих, некомутованих блоків (наприклад, Start, Process, End). Він надає
 * загальні члени даних, такі як унікальний ідентифікатор та мітка.
 */
class BaseBlock : public FlowElement {
protected:
    int id;
    std::string label;
public:
    /**
     * @brief Конструює новий об'єкт BaseBlock.
     * @param id_ Унікальний цілочисельний ідентифікатор для блоку.
     * @param label_ Рядок, що описує призначення або вміст блоку.
     */
    BaseBlock(int id_, std::string label_) : id(id_), label(std::move(label_)) {}

    /**
     * @brief Отримує унікальний ідентифікатор блоку.
     * @return Унікальний цілочисельний ідентифікатор.
     */
    int getId() const override { return id; }

    /**
     * @brief Отримує мітку блоку.
     * @return Рядок-мітка блоку.
     */
    std::string getLabel() const override { return label; }
};

}}}
