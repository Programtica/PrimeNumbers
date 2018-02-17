#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
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
    QWidget *widgetSieve;

    QHBoxLayout *horizontal;
    QHBoxLayout *horizontal2;
    QHBoxLayout *horizontal3;
    QHBoxLayout *pictureHorizontal;
    QHBoxLayout *returnToMenuHorizontal;

    QVBoxLayout *vertical;
    QVBoxLayout *vertical2;
    QVBoxLayout *vertical3;

    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *mePicture;

    QLineEdit *lineEdit;
    //QLineEdit *lineEdit2;

    QPushButton *testPrime;
    QPushButton *sieve;
    QPushButton *documentation;

    QPushButton *returnToMenu;

    Music *music;
    Prime *prime;

    QValidator *validator;

private slots:
    void detectAClickOfTestOfPrime();
    void detectAClickOfSieve();
    void detectAClickOfDocumentation();

    void setAText();
    void setMenu();
public:
    Application(QWidget *parent = 0);
    ~Application();

    bool isPrime(int number);
    void addButtonReturnToMenu();
    void setPropertiesOfApplication();
};

#endif // APPLICATION_H
