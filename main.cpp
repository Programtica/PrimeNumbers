#include "application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/icon/favicon-0.png"));
    Application w;
    w.show();

    return a.exec();
}
