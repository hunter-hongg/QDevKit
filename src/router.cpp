#include <qwidget.h>
#include <router.h>

util::Router::Router(std::unordered_map<std::string, QWidget *> route,
                     QMainWindow *MainWindow)
    : window(MainWindow) {
  // 将现有的页面转换为工厂函数
  for (auto& pair : route) {
    routeFactories[pair.first] = [widget = pair.second](QMainWindow*) -> QWidget* {
      return widget;
    };
  }
}

util::Router::Router(
    std::unordered_map<std::string, std::function<QWidget *(QMainWindow *)>>
        route,
    QMainWindow *MainWindow)
    : routeFactories(std::move(route)), window(MainWindow) {
  // 构造函数现在直接存储工厂函数
}

std::unordered_map<std::string, QWidget *> util::Router::GetRoutes() noexcept {
  // 这个方法需要重新考虑，因为我们现在存储的是工厂函数
  // 返回空映射作为临时解决方案
  return {};
}

void util::Router::Navigate(std::string route) noexcept(false) {
  auto it = routeFactories.find(route);
  if (it == routeFactories.end()) {
    throw std::runtime_error("Route not found");
  }
  
  // 使用工厂函数创建新页面实例
  QWidget* newWidget = it->second(window);
  
  // Qt会自动删除旧的中心部件
  window->setCentralWidget(newWidget);
}