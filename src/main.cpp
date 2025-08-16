#include "FlowChart.hpp"
#include "Blocks.hpp"
#include "CompositeBlock.hpp"
#include "Decorator.hpp"
#include "Proxy.hpp"
#include <memory>

using namespace com::lab111::labwork3;

int main() {
    FlowChart chart;

    auto start = std::make_shared<StartBlock>(1, "Початок");
    auto initX = std::make_shared<ProcessBlock>(2, "x = 0");
    auto decision = std::make_shared<DecisionBlock>(3, "x < 10 ?");
    auto ioTrue = std::make_shared<InputOutputBlock>(4, "Вивести x");
    auto inc = std::make_shared<LazyProcessProxy>(5, "x = x + 1");
    auto end = std::make_shared<EndBlock>(6, "Кінець");

    auto ioTrueLogged = std::make_shared<LoggingDecorator>(ioTrue);

    auto loopBody = std::make_shared<CompositeBlock>(7, "Тіло циклу");
    loopBody->addChild(ioTrueLogged);
    loopBody->addChild(inc);

    decision->setTrueBranch(loopBody);
    decision->setFalseBranch(end);

    auto program = std::make_shared<CompositeBlock>(8, "Програма");
    program->addChild(start);
    program->addChild(initX);
    program->addChild(decision);

    chart.add(program);
    chart.add(start);
    chart.add(initX);
    chart.add(decision);
    chart.add(ioTrue);
    chart.add(inc);
    chart.add(end);
    chart.add(loopBody);

    chart.printAll();
    chart.printStructure(8);

    start->printInfo();
    initX->printInfo();
    decision->printInfo();
    ioTrueLogged->printInfo();
    inc->printInfo();
    end->printInfo();

    return 0;
}
