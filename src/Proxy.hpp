#pragma once
#include "Blocks.hpp"

namespace com { namespace lab111 { namespace labwork3 {

class LazyProcessProxy : public FlowElement {
    int id;
    std::string label;
    mutable std::shared_ptr<ProcessBlock> realObj;

    void ensure() const {
        if (!realObj) {
            realObj = std::make_shared<ProcessBlock>(id, label);
            std::cout << "[Proxy] Lazy created ProcessBlock id=" << id << "\n";
        }
    }
public:
    LazyProcessProxy(int id_, std::string label_) : id(id_), label(std::move(label_)) {}

    int getId() const override { return id; }
    std::string getLabel() const override { return label; }

    std::string identify() const override {
        ensure();
        return realObj->identify();
    }
    void printInfo() const override {
        ensure();
        realObj->printInfo();
    }
};

}}}
