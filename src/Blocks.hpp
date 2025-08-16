#pragma once
#include "BaseBlock.hpp"

namespace com { namespace lab111 { namespace labwork3 {

class StartBlock : public BaseBlock {
public:
    StartBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}
    std::string identify() const override {
        return "StartBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }
    void printInfo() const override {
        std::cout << "printInfo -> StartBlock: id=" << id << ", label='" << label << "'\n";
    }
};

class ProcessBlock : public BaseBlock {
public:
    ProcessBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}
    std::string identify() const override {
        return "ProcessBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }
    void printInfo() const override {
        std::cout << "printInfo -> ProcessBlock: id=" << id << ", label='" << label << "'\n";
    }
};

class InputOutputBlock : public BaseBlock {
public:
    InputOutputBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}
    std::string identify() const override {
        return "InputOutputBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }
    void printInfo() const override {
        std::cout << "printInfo -> InputOutputBlock: id=" << id << ", label='" << label << "'\n";
    }
};

class EndBlock : public BaseBlock {
public:
    EndBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}
    std::string identify() const override {
        return "EndBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }
    void printInfo() const override {
        std::cout << "printInfo -> EndBlock: id=" << id << ", label='" << label << "'\n";
    }
};

class DecisionBlock : public BaseBlock {
    std::shared_ptr<FlowElement> trueBranch;
    std::shared_ptr<FlowElement> falseBranch;
public:
    DecisionBlock(int id_, std::string label_) : BaseBlock(id_, std::move(label_)) {}
    void setTrueBranch(std::shared_ptr<FlowElement> b) { trueBranch = std::move(b); }
    void setFalseBranch(std::shared_ptr<FlowElement> b) { falseBranch = std::move(b); }
    std::shared_ptr<FlowElement> getTrueBranch() const { return trueBranch; }
    std::shared_ptr<FlowElement> getFalseBranch() const { return falseBranch; }

    std::string identify() const override {
        return "DecisionBlock[id=" + std::to_string(id) + ", label='" + label + "']";
    }
    void printInfo() const override {
        std::cout << "printInfo -> DecisionBlock: id=" << id << ", label='" << label
                  << "', true->" << (trueBranch ? std::to_string(trueBranch->getId()) : "null")
                  << ", false->" << (falseBranch ? std::to_string(falseBranch->getId()) : "null")
                  << "\n";
    }
};


}}}

