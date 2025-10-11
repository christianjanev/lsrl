#include "gui.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Window window(0);

    window.show();

    return app.exec();
}