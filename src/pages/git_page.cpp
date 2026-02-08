#include "global.h"
#include "pages.h"
#include "simple.h"

QWidget *git_page(QMainWindow *window) {

  QWidget *centralWidget = new QWidget(window);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);

  Simple::title("版本管理", centralWidget, layout);

  layout -> addStretch();

  if (!global::GlobalGit.git_exists()) {
    Simple::info("警告: 未发现版本库");
    Simple::text("未发现版本库", centralWidget, layout);
  }

  layout -> addStretch();

  Simple::back("/", centralWidget, layout);

  layout -> addStretch();

  return centralWidget;
}