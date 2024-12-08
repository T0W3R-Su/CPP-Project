#pragma once  // 防止头文件被重复包含
#include <string>

namespace adas  // 防止命名冲突，将所有的代码放在 adas 命名空间下
{
enum class CarType : uint16_t {
    NormalCar = 0,
    SportsCar,
};

struct Pose {  // 车辆的位置和朝向
    int x;
    int y;
    char heading;
};  // 便于数据的传递

class Executor  // 抽象类，定义了 Executor 的接口，隐藏了具体的实现
{
public:
    static Executor* NewExecutor(const Pose& initialPose = {0, 0, 'N'}, const CarType = CarType::NormalCar) noexcept;
    // 工厂方法，根据初始位置创建一个 Executor 对象，无需实例化

public:
    Executor(void) = default;  // default 表示使用默认的构造函数
    virtual ~Executor(void) = default;
    Executor(const Executor&) = delete;  // 防止拷贝构造
    Executor& operator=(const Executor&) = delete;

public:
    virtual const Pose Query(void) const noexcept = 0;  // nonexpect 表示不抛出异常
    virtual void Execute(const std::string& instruction) noexcept = 0;
};
}  // namespace adas