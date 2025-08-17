#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iostream>

namespace com { namespace lab111 { namespace labwork3 {

/**
 * @class FlowElement
 * @brief Представляє абстрактний базовий інтерфейс (Component) для всіх елементів блок-схеми.
 *
 * Цей клас оголошує операції, спільні для простих (Leaf) і композитних (Composite) об'єктів.
 * Він є ключовим елементом патерну Composite, дозволяючи клієнтському коду працювати
 * з усіма об'єктами уніфікованим способом.
 */
class FlowElement {
public:
    /**
     * @brief Віртуальний деструктор.
     * Необхідний для коректного видалення об'єктів похідних класів через вказівник на базовий клас.
     */
    virtual ~FlowElement() = default;

    /**
     * @brief Повертає унікальний ідентифікатор елемента.
     * @return Унікальний цілочисельний ідентифікатор.
     */
    virtual int getId() const = 0;

    /**
     * @brief Повертає текстову мітку елемента.
     * @return Рядок-мітка, що описує вміст блоку.
     */
    virtual std::string getLabel() const = 0;

    /**
     * @brief Повертає ідентифікаційний рядок для елемента.
     * @return Рядок, що містить тип та ідентифікаційні дані елемента.
     */
    virtual std::string identify() const = 0;

    /**
     * @brief Виводить інформацію про елемент у консоль.
     */
    virtual void printInfo() const = 0;

    /**
     * @brief Додає дочірній елемент.
     *
     * Цей метод є необов'язковим для Leaf-вузлів, тому має порожню реалізацію за замовчуванням.
     * @param child Вказівник на дочірній елемент.
     */
    virtual void addChild(std::shared_ptr<FlowElement>) {}
    
    /**
     * @brief Видаляє дочірній елемент.
     *
     * Має порожню реалізацію за замовчуванням для Leaf-вузлів.
     * @param child Вказівник на дочірній елемент.
     */
    virtual void removeChild(std::shared_ptr<FlowElement>) {}

    /**
     * @brief Повертає список дочірніх елементів.
     *
     * Порожня реалізація за замовчуванням для Leaf-вузлів.
     * @return Вектор вказівників на дочірні елементи.
     */
    virtual std::vector<std::shared_ptr<FlowElement>> getChildren() const { return {}; }

    /**
     * @brief Рекурсивно обходить і виводить структуру блок-схеми.
     *
     * Це головний "бізнес-метод" вашого завдання. Він використовує рекурсію для обходу
     * ієрархічної структури, друкуючи ідентифікатор кожного елемента.
     * @param depth Глибина занурення в ієрархію для виводу з відступом.
     */
    virtual void traversePrint(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << "- " << identify() << "\n";
        for (auto &c : getChildren()) {
            if (c) {
                c->traversePrint(depth + 1);
            }
        }
    }
};

}}}
