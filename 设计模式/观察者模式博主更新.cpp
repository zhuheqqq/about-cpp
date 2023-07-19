#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 前向声明
class Blogger;

// 观察者接口
class Observer {
public:
    virtual void update() = 0;
};

// 主题接口
class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// 博主类作为主题对象
class Blogger : public Subject {
private:
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // 在向量中查找并移除观察者
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }

    void publishUpdate() {
        std::cout << "博主发布了新的更新！" << std::endl;
        notifyObservers();
    }
};

// 粉丝类作为观察者对象
class Fan : public Observer {
private:
    std::string name;
public:
    Fan(const std::string& fanName) : name(fanName) {}

    void update() {
        std::cout << name << " 收到了博主的更新提醒。" << std::endl;
    }
};

int main() {
    // 创建博主和粉丝对象
    Blogger blogger;
    Fan fan1("粉丝1");
    Fan fan2("粉丝2");

    // 博主注册粉丝为观察者
    blogger.registerObserver(&fan1);
    blogger.registerObserver(&fan2);

    // 博主发布更新
    blogger.publishUpdate();

    // 移除一个观察者
    blogger.removeObserver(&fan1);

    // 博主再次发布更新
    blogger.publishUpdate();

    return 0;
}
