#include <iostream>
#include <string>

// 基础奶茶接口
class MilkTea {
public:
    virtual std::string getDescription() const = 0; // 获取奶茶描述的纯虚函数
    virtual double cost() const = 0; // 获取奶茶价格的纯虚函数
};

// 基础奶茶实现
class BasicMilkTea : public MilkTea {
public:
    std::string getDescription() const override {
        return "Basic Milk Tea";
    }

    double cost() const override {
        return 3.0; // 基础奶茶价格为3.0
    }
};

// 奶茶加料装饰器基类提供装饰器的基本功能
class MilkTeaDecorator : public MilkTea {
protected:
    MilkTea* milkTea; // 指向被装饰的奶茶对象的指针

public:
    explicit MilkTeaDecorator(MilkTea* tea) : milkTea(tea) {}

    std::string getDescription() const override {
        return milkTea->getDescription(); // 调用被装饰奶茶对象的getDescription()函数
    }

    double cost() const override {
        return milkTea->cost(); // 调用被装饰奶茶对象的cost()函数
    }
};

// 具体的加料装饰器：珍珠
class PearlDecorator : public MilkTeaDecorator {
public:
    explicit PearlDecorator(MilkTea* tea) : MilkTeaDecorator(tea) {}

    std::string getDescription() const override {
        return milkTea->getDescription() + " + Pearl"; // 在被装饰奶茶的描述后面添加 "+ Pearl"
    }

    double cost() const override {
        return milkTea->cost() + 0.5; // 加珍珠的奶茶价格增加0.5
    }
};

// 具体的加料装饰器：椰果
class CoconutDecorator : public MilkTeaDecorator {
public:
    explicit CoconutDecorator(MilkTea* tea) : MilkTeaDecorator(tea) {}

    std::string getDescription() const override {
        return milkTea->getDescription() + " + Coconut"; // 在被装饰奶茶的描述后面添加 "+ Coconut"
    }

    double cost() const override {
        return milkTea->cost() + 0.8; // 加椰果的奶茶价格增加0.8
    }
};

int main() {
    // 创建基础奶茶对象
    MilkTea* basicMilkTea = new BasicMilkTea();
    std::cout << "Description: " << basicMilkTea->getDescription() << std::endl;
    std::cout << "Cost: $" << basicMilkTea->cost() << std::endl;

    // 使用装饰器给奶茶加上珍珠
    MilkTea* pearlMilkTea = new PearlDecorator(basicMilkTea);
    std::cout << "Description: " << pearlMilkTea->getDescription() << std::endl;
    std::cout << "Cost: $" << pearlMilkTea->cost() << std::endl;

    // 使用装饰器给奶茶加上椰果
    MilkTea* coconutMilkTea = new CoconutDecorator(basicMilkTea);
    std::cout << "Description: " << coconutMilkTea->getDescription() << std::endl;
    std::cout << "Cost: $" << coconutMilkTea->cost() << std::endl;

    // 使用多个装饰器组合加料
    MilkTea* combinedMilkTea = new CoconutDecorator(new PearlDecorator(basicMilkTea));
    std::cout << "Description: " << combinedMilkTea->getDescription() << std::endl;
    std::cout << "Cost: $" << combinedMilkTea->cost() << std::endl;

    // 释放内存
    delete basicMilkTea;
    delete pearlMilkTea;
    delete coconutMilkTea;
    delete combinedMilkTea;

    return 0;
}
