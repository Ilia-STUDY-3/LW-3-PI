#pragma once
#include "FlowElement.hpp"

namespace com { namespace lab111 { namespace labwork3 {

class Decorator : public FlowElement {
protected:
    std::shared_ptr<FlowElement> component;
public:
    explicit Decorator(std::shared_ptr<FlowElement> comp) : component(std::move(comp)) {}
    int getId() const override { return component->getId(); }
    std::string getLabel() const override { return component->getLabel(); }
    void addChild(std::shared_ptr<FlowElement> child) override { component->addChild(std::move(child)); }
    void removeChild(std::shared_ptr<FlowElement> child) override { component->removeChild(std::move(child)); }
    std::vector<std::shared_ptr<FlowElement>> getChildren() const override { return component->getChildren(); }
};

class LoggingDecorator : public Decorator {
public:
    explicit LoggingDecorator(std::shared_ptr<FlowElement> comp) : Decorator(std::move(comp)) {}
    std::string identify() const override {
        std::cout << "[LOG] identify() on id=" << component->getId() << "\n";
        return component->identify();
    }
    void printInfo() const override {
        std::cout << "[LOG] printInfo() on id=" << component->getId() << "\n";
        component->printInfo();
    }
};

}}}
