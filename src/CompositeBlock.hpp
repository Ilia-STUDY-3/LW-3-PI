#pragma once
#include "FlowElement.hpp"
#include <algorithm>

namespace com { namespace lab111 { namespace labwork3 {

class CompositeBlock : public FlowElement {
    int id;
    std::string label;
    std::vector<std::shared_ptr<FlowElement>> children;
public:
    CompositeBlock(int id_, std::string label_) : id(id_), label(std::move(label_)) {}

    int getId() const override { return id; }
    std::string getLabel() const override { return label; }

    void addChild(std::shared_ptr<FlowElement> child) override {
        children.push_back(std::move(child));
    }
    void removeChild(std::shared_ptr<FlowElement> child) override {
        children.erase(std::remove(children.begin(), children.end(), child), children.end());
    }
    std::vector<std::shared_ptr<FlowElement>> getChildren() const override {
        return children;
    }

    std::string identify() const override {
        return "CompositeBlock[id=" + std::to_string(id) + ", label='" + label +
               "', children=" + std::to_string(children.size()) + "]";
    }
    void printInfo() const override {
        std::cout << "printInfo -> CompositeBlock: id=" << id
                  << ", label='" << label
                  << "', children=" << children.size() << "\n";
    }
};

}}}
