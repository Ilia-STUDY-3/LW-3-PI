#pragma once
#include "FlowElement.hpp"
#include <unordered_map>

namespace com { namespace lab111 { namespace labwork3 {

class FlowChart {
    std::unordered_map<int, std::shared_ptr<FlowElement>> nodes;
public:
    void add(const std::shared_ptr<FlowElement>& node) { nodes[node->getId()] = node; }

    std::shared_ptr<FlowElement> get(int id) const {
        auto it = nodes.find(id);
        if (it != nodes.end()) return it->second;
        return nullptr;
    }

    void printAll() const {
        for (auto &kv : nodes) {
            if (kv.second) kv.second->printInfo();
        }
    }

    void printStructure(int rootId) const {
        auto root = get(rootId);
        if (root) root->traversePrint();
    }
};

}}}
