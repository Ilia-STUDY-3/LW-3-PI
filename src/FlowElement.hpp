#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iostream>

namespace com { namespace lab111 { namespace labwork3 {

class FlowElement {
public:
    virtual ~FlowElement() = default;
    virtual int getId() const = 0;
    virtual std::string getLabel() const = 0;
    virtual std::string identify() const = 0;
    virtual void printInfo() const = 0;

    virtual void addChild(std::shared_ptr<FlowElement>) {}
    virtual void removeChild(std::shared_ptr<FlowElement>) {}
    virtual std::vector<std::shared_ptr<FlowElement>> getChildren() const { return {}; }

    virtual void traversePrint(int depth = 0) const {
        for (int i = 0; i < depth; ++i) std::cout << "  ";
        std::cout << "- " << identify() << "\n";
        for (auto &c : getChildren()) if (c) c->traversePrint(depth + 1);
    }
};

}}}
