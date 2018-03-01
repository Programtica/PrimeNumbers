#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopServices>
#include <QMessageBox>
#include <QCloseEvent>

#include <QDesktopWidget>
#include <QWidget>

#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QAbstractButton>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLineEdit>
#include <QValidator>
#include <QIntValidator>

#include <QUrl>
#include <QFileInfo>
#include <QDir>

#include "music.h"
#include "prime.h"

class Application : public QMainWindow {
    Q_OBJECT
private:
    int width;
    int height;

    QDesktopWidget *desktop;
    QWidget *widget;
    QWidget *widgetTestOfPrime;
    //QWidget *widgetSieve;
    //QWidget *widgetDocumentation;

    QVBoxLayout *vertical;
    QVBoxLayout *vertical2;

    QHBoxLayout *horizontal;
    QHBoxLayout *horizontal2;

    QHBoxLayout *horizontalsObjects[7];

    QLabel *label;
    QLabel *label2;
    QLabel *me;
    QLabel *yesOrNo;
    QLabel *info;
    QLineEdit *lineEdit;

    QPushButton *buttonsInMainMenu[3];
    QPushButton *buttonToConfirm;
    QPushButton *returnToMenu;

    Music *music;
    Prime *prime;

    QValidator *validator;

private slots:
    void detectAClickOfTestOfPrime();
    void setATextOfPrime();
    void detectAClickOfSieve();
    void detectAClickOfDocumentation();
    void setLayoutsOfMainMenu();
    void addLayoutsOfMainMenu();
    void setAMenuOfPrime();
    void setAMenuOfSieve();
    void setAMenuOfDocumentation();
    bool pdfFileExists(QString path);

public:
    Application(QWidget *parent = 0);
    ~Application();

    bool isPrime(int number);
    void addButtonReturnToMenu();
    void setPropertiesOfApplication();
    void setLayoutsInTestOfPrime();
    void addLayoutsInTestOfPrime();
    void closeEvent(QCloseEvent *event);
};

#endif // APPLICATION_H
