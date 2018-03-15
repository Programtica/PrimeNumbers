#include "application.h"
#include <QApplication>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QSystemSemaphore semaphore("<instance>", 1);
    semaphore.acquire();

#ifndef Q_OS_WIN32
    QSharedMemory nixFixSharedMemory("<instance 2>");
    if(nixFixSharedMemory.attach()){
        nixFixSharedMemory.detach();
    }
#endif
    QSharedMemory sharedMemory("<instance 2>");
    bool isRunning;
    if (sharedMemory.attach()){
        isRunning = true;
    } else {
        sharedMemory.create(1);
        isRunning = false;
    }
    semaphore.release();

    if(isRunning == true) {
        QMessageBox informationMessage;
        informationMessage.setWindowTitle("Liczby pierwsze");
        informationMessage.setIcon(QMessageBox::Warning);
        informationMessage.setText("Program już jest uruchomiony.\n\n"
                       "Tylko może być uruchomiona jedna instancja programu.");
        informationMessage.exec();
        return 1;
    }

    Application w;
    w.show();

    return a.exec();
}
