#pragma once
#include "FlowElement.hpp"
#include <vector>
#include <iostream>

namespace com { namespace lab111 { namespace labwork3 {

/**
 * @class Decorator
 * @brief Абстрактний базовий клас для декораторів у патерні Decorator.
 *
 * Цей клас реалізує інтерфейс Component (FlowElement) і містить посилання
 * на об'єкт, який потрібно "обгорнути" (декорувати).
 * Методи цього класу перенаправляють виклики до вкладеного компонента.
 */
class Decorator : public FlowElement {
protected:
    std::shared_ptr<FlowElement> component;
public:
    /**
     * @brief Конструктор для Decorator.
     * @param comp Вказівник на об'єкт FlowElement, який буде декорований.
     */
    explicit Decorator(std::shared_ptr<FlowElement> comp) : component(std::move(comp)) {}

    /**
     * @brief Отримує ідентифікатор вкладеного компонента.
     * @return Унікальний ідентифікатор.
     */
    int getId() const override { return component->getId(); }

    /**
     * @brief Отримує мітку вкладеного компонента.
     * @return Рядок-мітка.
     */
    std::string getLabel() const override { return component->getLabel(); }

    /**
     * @brief Перенаправляє виклик до методу додавання дочірнього елемента.
     * @param child Вказівник на дочірній елемент.
     */
    void addChild(std::shared_ptr<FlowElement> child) override { component->addChild(std::move(child)); }
    
    /**
     * @brief Перенаправляє виклик до методу видалення дочірнього елемента.
     * @param child Вказівник на дочірній елемент.
     */
    void removeChild(std::shared_ptr<FlowElement> child) override { component->removeChild(std::move(child)); }
    
    /**
     * @brief Перенаправляє виклик до методу отримання дочірніх елементів.
     * @return Вектор вказівників на дочірні елементи.
     */
    std::vector<std::shared_ptr<FlowElement>> getChildren() const override { return component->getChildren(); }
};

/**
 * @class LoggingDecorator
 * @brief Конкретний декоратор, що додає функцію логування до операцій.
 *
 * Цей клас розширює функціонал об'єкта, додаючи вивід у консоль перед
 * виконанням основної операції.
 */
class LoggingDecorator : public Decorator {
public:
    /**
     * @brief Конструктор для LoggingDecorator.
     * @param comp Вказівник на об'єкт, який буде обгорнутий цим декоратором.
     */
    explicit LoggingDecorator(std::shared_ptr<FlowElement> comp) : Decorator(std::move(comp)) {}

    /**
     * @brief Виводить лог-повідомлення, а потім викликає метод identify() вкладеного компонента.
     * @return Ідентифікаційний рядок компонента.
     */
    std::string identify() const override {
        std::cout << "[LOG] identify() on id=" << component->getId() << "\n";
        return component->identify();
    }

    /**
     * @brief Виводить лог-повідомлення, а потім викликає метод printInfo() вкладеного компонента.
     */
    void printInfo() const override {
        std::cout << "[LOG] printInfo() on id=" << component->getId() << "\n";
        component->printInfo();
    }
};

}}}
