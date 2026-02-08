#include "global.h"
#include "simple.h"
#include <QFileDialog>
#include <qnamespace.h>
#include <QApplication>

QWidget *main_page(QMainWindow *window) {
  QWidget *centralWidget = new QWidget(window);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);

  Simple::title("欢迎使用开发工具集", centralWidget, layout);

  layout->addStretch();

  Simple::button(
      "打开目录",
      []() {
        QString folderPath = QFileDialog::getExistingDirectory(
            nullptr, 
            "选择文件夹", 
            QDir::homePath(), 
            QFileDialog::ShowDirsOnly  
                | QFileDialog::DontResolveSymlinks 
        );
        global::GlobalPath = folderPath.toStdString();
        global::GlobalGit.set_path(global::GlobalPath);
      },
      centralWidget, layout);

  Simple::button(
      "版本管理", []() { global::GlobalRouter().Navigate("/git"); },
      centralWidget, layout);

  layout->addStretch();

  Simple::button(
      "退出", []() { QApplication::quit(); }, centralWidget, layout, 16,
      Qt::AlignRight);

  layout->addStretch();

  return centralWidget;
}