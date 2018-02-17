#include "application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent) {
    width = 800;
    height = 600;

    music = new Music();
    prime = new Prime();
    setMenu();
}

void Application::setMenu() {
    music->addFirstMusic();
    label = new QLabel(this);
    label->setText("Liczby pierwsze");
    label->setStyleSheet("font-size: 40px;");
    label->setAlignment(Qt::AlignCenter);
    label->setFixedSize(400, 50);

    testPrime = new QPushButton(this);
    testPrime->setCursor(Qt::PointingHandCursor);
    testPrime->setText("Test pierwszości");
    testPrime->setStyleSheet("font-size: 20px;");
    testPrime->setFixedSize(400, 65);

    sieve = new QPushButton(this);
    sieve->setCursor(Qt::PointingHandCursor);
    sieve->setText("Sito Eratostenesa");
    sieve->setStyleSheet("font-size: 20px;");
    sieve->setFixedSize(400, 65);

    documentation = new QPushButton(this);
    documentation->setCursor(Qt::PointingHandCursor);
    documentation->setText("Pomoc i dokumentacja");
    documentation->setStyleSheet("font-size: 20px;");
    documentation->setFixedSize(400, 65);

    widget = new QWidget(this);

    horizontal = new QHBoxLayout();
    horizontal->addStretch();

    vertical = new QVBoxLayout();
    vertical->addStretch();
    vertical->addWidget(label);
    vertical->addSpacing(40);

    vertical->addWidget(testPrime);
    vertical->addSpacing(20);

    vertical->addWidget(sieve);
    vertical->addSpacing(20);

    vertical->addWidget(documentation);
    vertical->addSpacing(20);

    vertical->addStretch();
    horizontal->addLayout(vertical);
    horizontal->addStretch();

    widget->setLayout(horizontal);

    setPropertiesOfApplication();
    setCentralWidget(widget);

    connect(testPrime, SIGNAL(released()), this, SLOT(detectAClickOfTestOfPrime()));
    connect(sieve, SIGNAL(released()), this, SLOT(detectAClickOfSieve()));
    connect(documentation, SIGNAL(released()), this, SLOT(detectAClickOfDocumentation()));
}

void Application::setPropertiesOfApplication() {
    setWindowTitle("Liczby pierwsze");

    setFixedSize(width, height);
    desktop = QApplication::desktop();

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    move((screenWidth - width) / 2, (screenHeight - height) / 2);
    setStyleSheet("QMainWindow{ background-image: url(:/img/paper.jpg)}");

}

void Application::detectAClickOfTestOfPrime() {
    music->stopMusic();
    music->addSecondMusic();
    label->setText("Podaj liczbę: ");
    label->setStyleSheet("font-size: 40px;");
    label->setAlignment(Qt::AlignCenter);
    label->setFixedSize(400, 50);

    lineEdit = new QLineEdit(this);
    lineEdit->setContextMenuPolicy(Qt::NoContextMenu);
    lineEdit->setStyleSheet("border: 2px solid #0000ff; font-size: 40px;");
    lineEdit->setAlignment(Qt::AlignCenter);

    validator = new QIntValidator(this);
    lineEdit->setValidator(validator);
    lineEdit->setFixedSize(400, 50);

    label2 = new QLabel(this);
    label2->setStyleSheet("font-size: 40px;");
    label2->setAlignment(Qt::AlignCenter);
    label2->setFixedSize(400, 50);

    mePicture = new QLabel(this);

    returnToMenu = new QPushButton(this);

    widgetTestOfPrime = new QWidget(this);

    horizontal2 = new QHBoxLayout();
    horizontal2->addStretch();

    vertical2 = new QVBoxLayout();
    vertical2->addStretch();
    vertical2->addWidget(label);
    vertical2->addSpacing(20);

    vertical2->addWidget(lineEdit);
    vertical2->addSpacing(20);
    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(setAText()));

    vertical2->addWidget(label2);
    vertical2->addSpacing(10);
    vertical2->addStretch();

    pictureHorizontal = new QHBoxLayout();
    pictureHorizontal->addStretch();
    pictureHorizontal->addWidget(mePicture);
    pictureHorizontal->addStretch();

    returnToMenuHorizontal = new QHBoxLayout();
    returnToMenuHorizontal->addStretch();
    returnToMenuHorizontal->addWidget(returnToMenu);
    returnToMenuHorizontal->addStretch();

    vertical2->addLayout(pictureHorizontal);
    vertical2->addStretch();
    vertical2->addSpacing(30);

    vertical2->addLayout(returnToMenuHorizontal);
    vertical2->addStretch();

    horizontal2->addLayout(vertical2);
    horizontal2->addStretch();

    widgetTestOfPrime->setLayout(horizontal2);
    setCentralWidget(widgetTestOfPrime);

    testPrime->hide();
    sieve->hide();
    documentation->hide();
    returnToMenu->hide();
}

void Application::detectAClickOfSieve() {
    //to be continued
    music->stopMusic();

    label3 = new QLabel(this);
    label3->setText("W przygotowaniu!");
    label3->setStyleSheet("font-size: 40px;");
    label3->setAlignment(Qt::AlignCenter);
    label3->setFixedSize(400, 50);

    //lineEdit2 = new QLineEdit(this);
    //lineEdit2->setContextMenuPolicy(Qt::NoContextMenu);
    //lineEdit2->setStyleSheet("border: 2px solid #0000ff; font-size: 40px;");
    //lineEdit2->setAlignment(Qt::AlignCenter);

    //validator = new QIntValidator(this);
    //lineEdit2->setValidator(validator);
    //lineEdit2->setFixedSize(400, 50);

    vertical3 = new QVBoxLayout();
    vertical3->addStretch();
    vertical3->addWidget(label3);
    vertical3->addSpacing(420);

    widgetSieve = new QWidget(this);

    //vertical3->addWidget(lineEdit2);
    vertical3->addSpacing(20);
    //connect(lineEdit2, SIGNAL(returnPressed()), this, SLOT(setAText()));

    horizontal3 = new QHBoxLayout();
    horizontal3->addStretch();

    horizontal3->addLayout(vertical3);
    horizontal3->addStretch();

    widgetSieve->setLayout(horizontal3);
    setCentralWidget(widgetSieve);
}

void Application::detectAClickOfDocumentation() {
    //to be continued
    documentation->setText("Jeszcze nie zrobione!");
}

void Application::setAText() {
    QString numberFromInput = lineEdit->text();

    bool ok;
    int number = numberFromInput.toInt(&ok, 10);

    if(prime->isPrime(number) == true) {
        label2->setText("Czy jest pierwsza: TAK");
        QPixmap pixmap(":/img/me_yes.png");
        mePicture->setPixmap(pixmap);
    }

    else {
        label2->setText("Czy jest pierwsza: NIE");
        QPixmap pixmap(":/img/me_no.png");
        mePicture->setPixmap(pixmap);
    }


    mePicture->setStyleSheet("background-image: url(:/img/white.jpg); "
                             "border: 2px solid #000; border-radius: 5px;");

    addButtonReturnToMenu();
}

void Application::addButtonReturnToMenu() {
    returnToMenu->show();
    returnToMenu->setCursor(Qt::PointingHandCursor);
    returnToMenu->setText("Powrót do menu");
    returnToMenu->setStyleSheet("font-size: 25px");
    returnToMenu->setFixedSize(300, 75);
    connect(returnToMenu, SIGNAL(released()), this, SLOT(setMenu()));
}

Application::~Application() {
    //destructor
}
