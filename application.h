#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QCloseEvent>
#include <QAbstractButton>
#include <QDesktopWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QValidator>
#include <QIntValidator>
#include <QPixmap>

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

    QVBoxLayout *vertical;
    QVBoxLayout *vertical2;
    //QVBoxLayout *vertical3;

    QHBoxLayout *labelHorizontal;
    QHBoxLayout *lineEditHorizontal;

    QHBoxLayout *label2Horizontal;
    QHBoxLayout *meHorizontal;

    QHBoxLayout *pictureHorizontal;
    QHBoxLayout *returnToMenuHorizontal;

    QHBoxLayout *buttonToConfirmHorizontal;
    QHBoxLayout *horizontal2;

    QLabel *label;
    QLabel *label2;
    //QLabel *label3;
    QLabel *me;
    QLabel *yesOrNo;

    QLineEdit *lineEdit;

    QPushButton *testPrime;
    QPushButton *sieve;
    QPushButton *documentation;
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
    void setMenu();
    void setAMenuOfPrime();

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
