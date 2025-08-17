#pragma once
#include "BaseBlock.hpp"

namespace com { namespace lab111 { namespace labwork3 {

/**
 * @class StartBlock
 * @brief Представляє початковий блок у блок-схемі.
 *
 * Це конкретний "листовий" клас (Leaf), який позначає точку входу в алгоритм.
 */
class StartBlock : public BaseBlock {
public:
    /**
     * @brief Конструктор для початкового блоку.
     * @param id_ Унікальний ідентифікатор блоку.
     * @param label_ Мітка, що описує блок.
     */
    StartBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}

    /**
     * @brief Повертає ідентифікаційний рядок для початкового блоку.
     * @return Рядок у форматі "StartBlock[id=..., label='...']".
     */
    std::string identify() const override {
        return "StartBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }

    /**
     * @brief Виводить інформацію про початковий блок у консоль.
     */
    void printInfo() const override {
        std::cout << "printInfo -> StartBlock: id=" << id << ", label='" << label << "'\n";
    }
};

/**
 * @class ProcessBlock
 * @brief Представляє блок обробки (дії).
 *
 * Це "листовий" клас (Leaf), який містить одну операцію.
 */
class ProcessBlock : public BaseBlock {
public:
    /**
     * @brief Конструктор для блоку обробки.
     * @param id_ Унікальний ідентифікатор.
     * @param label_ Мітка, що описує операцію.
     */
    ProcessBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}

    /**
     * @brief Повертає ідентифікаційний рядок для блоку обробки.
     * @return Рядок у форматі "ProcessBlock[id=..., label='...']".
     */
    std::string identify() const override {
        return "ProcessBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }

    /**
     * @brief Виводить інформацію про блок обробки у консоль.
     */
    void printInfo() const override {
        std::cout << "printInfo -> ProcessBlock: id=" << id << ", label='" << label << "'\n";
    }
};

/**
 * @class InputOutputBlock
 * @brief Представляє блок введення/виведення.
 *
 * Це "листовий" клас (Leaf) для операцій введення та виведення даних.
 */
class InputOutputBlock : public BaseBlock {
public:
    /**
     * @brief Конструктор для блоку введення/виведення.
     * @param id_ Унікальний ідентифікатор.
     * @param label_ Мітка, що описує операцію введення/виведення.
     */
    InputOutputBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}

    /**
     * @brief Повертає ідентифікаційний рядок для блоку введення/виведення.
     * @return Рядок у форматі "InputOutputBlock[id=..., label='...']".
     */
    std::string identify() const override {
        return "InputOutputBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }

    /**
     * @brief Виводить інформацію про блок введення/виведення у консоль.
     */
    void printInfo() const override {
        std::cout << "printInfo -> InputOutputBlock: id=" << id << ", label='" << label << "'\n";
    }
};

/**
 * @class EndBlock
 * @brief Представляє кінцевий блок у блок-схемі.
 *
 * Це "листовий" клас (Leaf), що позначає точку виходу з алгоритму.
 */
class EndBlock : public BaseBlock {
public:
    /**
     * @brief Конструктор для кінцевого блоку.
     * @param id_ Унікальний ідентифікатор.
     * @param label_ Мітка, що описує блок.
     */
    EndBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}

    /**
     * @brief Повертає ідентифікаційний рядок для кінцевого блоку.
     * @return Рядок у форматі "EndBlock[id=..., label='...']".
     */
    std::string identify() const override {
        return "EndBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }

    /**
     * @brief Виводить інформацію про кінцевий блок у консоль.
     */
    void printInfo() const override {
        std::cout << "printInfo -> EndBlock: id=" << id << ", label='" << label << "'\n";
    }
};

/**
 * @class DecisionBlock
 * @brief Представляє блок прийняття рішення (умова).
 *
 * Це "листовий" клас (Leaf), який містить дві гілки виконання: true (істинна) та false (хибна).
 */
class DecisionBlock : public BaseBlock {
    std::shared_ptr<FlowElement> trueBranch;
    std::shared_ptr<FlowElement> falseBranch;
public:
    /**
     * @brief Конструктор для блоку рішення.
     * @param id_ Унікальний ідентифікатор.
     * @param label_ Мітка, що описує умову.
     */
    DecisionBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}

    /**
     * @brief Встановлює гілку для істинної умови.
     * @param b Вказівник на наступний елемент.
     */
    void setTrueBranch(std::shared_ptr<FlowElement> b) { trueBranch = std::move(b); }

    /**
     * @brief Встановлює гілку для хибної умови.
     * @param b Вказівник на наступний елемент.
     */
    void setFalseBranch(std::shared_ptr<FlowElement> b) { falseBranch = std::move(b); }

    /**
     * @brief Повертає гілку для істинної умови.
     * @return Вказівник на наступний елемент.
     */
    std::shared_ptr<FlowElement> getTrueBranch() const { return trueBranch; }

    /**
     * @brief Повертає гілку для хибної умови.
     * @return Вказівник на наступний елемент.
     */
    std::shared_ptr<FlowElement> getFalseBranch() const { return falseBranch; }

    /**
     * @brief Повертає ідентифікаційний рядок для блоку рішення.
     * @return Рядок у форматі "DecisionBlock[id=..., label='...']".
     */
    std::string identify() const override {
        return "DecisionBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }

    /**
     * @brief Виводить інформацію про блок рішення, включаючи його гілки.
     */
    void printInfo() const override {
        std::cout << "printInfo -> DecisionBlock: id=" << id << ", label='" << label
                  << "', true->" << (trueBranch ? std::to_string(trueBranch->getId()) : "null")
                  << ", false->" << (falseBranch ? std::to_string(falseBranch->getId()) : "null")
                  << "\n";
    }
};


}}}

