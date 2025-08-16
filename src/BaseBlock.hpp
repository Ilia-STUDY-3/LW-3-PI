#pragma once
#include "FlowElement.hpp"

namespace com { namespace lab111 { namespace labwork3 {

class BaseBlock : public FlowElement {
protected:
    int id;
    std::string label;
public:
    BaseBlock(int id_, std::string label_) : id(id_), label(std::move(label_)) {}
    int getId() const override { return id; }
    std::string getLabel() const override { return label; }
};

}}}
