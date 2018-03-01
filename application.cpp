#include "application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent) {
    width = 800;
    height = 600;

    music = new Music();
    prime = new Prime();
    setLayoutsOfMainMenu();
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

void Application::setLayoutsOfMainMenu() {
    music->addFirstMusic();
    music->startMusic();

    label = new QLabel(this);
    label->setText("Liczby pierwsze");
    label->setStyleSheet("font-size: 40px;");
    label->setAlignment(Qt::AlignCenter);
    label->setFixedSize(400, 50);

    for(int i=0; i<3; i++) {
        buttonsInMainMenu[i] = new QPushButton(this);
        buttonsInMainMenu[i]->setCursor(Qt::PointingHandCursor);
        buttonsInMainMenu[i]->setStyleSheet("font-size: 20px;");
        buttonsInMainMenu[i]->setFixedSize(400, 65);
    }

    buttonsInMainMenu[0]->setText("Test pierwszości");
    buttonsInMainMenu[1]->setText("Sito Eratostenesa");
    buttonsInMainMenu[2]->setText("Pomoc i dokumentacja");

    addLayoutsOfMainMenu();

    connect(buttonsInMainMenu[0], SIGNAL(released()), this, SLOT(detectAClickOfTestOfPrime()));
    connect(buttonsInMainMenu[1], SIGNAL(released()), this, SLOT(detectAClickOfSieve()));
    connect(buttonsInMainMenu[2], SIGNAL(released()), this, SLOT(detectAClickOfDocumentation()));
}

void Application::addLayoutsOfMainMenu() {
    widget = new QWidget(this);

    horizontal = new QHBoxLayout();
    horizontal->addStretch();

    vertical = new QVBoxLayout();
    vertical->addStretch();
    vertical->addWidget(label);
    vertical->addSpacing(40);

    for(int i=0; i<3; i++) {
        vertical->addWidget(buttonsInMainMenu[i]);
        vertical->addSpacing(20);
    }

    vertical->addStretch();

    info = new QLabel(this);

    horizontal->addLayout(vertical);
    horizontal->addStretch();

    widget->setLayout(horizontal);

    setPropertiesOfApplication();
    setCentralWidget(widget);
}

void Application::addLayoutsInTestOfPrime() {
    for(int i=0; i<7; i++) {
        vertical2->addLayout(horizontalsObjects[i]);
        vertical2->addStretch();

        if(i==0) {
            vertical2->addSpacing(10);
        } else if(i==2) {
            vertical2->addSpacing(-20);
        }
    }

    horizontal2->addLayout(vertical2);
    horizontal2->addStretch();
    widgetTestOfPrime->setLayout(horizontal2);

    setCentralWidget(widgetTestOfPrime);
}

void Application::setLayoutsInTestOfPrime() {
    horizontal2 = new QHBoxLayout();
    horizontal2->addStretch();

    vertical2 = new QVBoxLayout();
    vertical2->addStretch();

    for(int i=0; i<7; i++) {
        horizontalsObjects[i] = new QHBoxLayout();
        horizontalsObjects[i]->addStretch();
    }

    horizontalsObjects[0]->addWidget(label);
    horizontalsObjects[1]->addWidget(lineEdit);
    horizontalsObjects[2]->addWidget(label2);
    horizontalsObjects[3]->addWidget(me);
    horizontalsObjects[4]->addWidget(yesOrNo);
    horizontalsObjects[5]->addWidget(returnToMenu);
    horizontalsObjects[6]->addWidget(buttonToConfirm);

    for(int i=0; i<7; i++) {
        horizontalsObjects[i]->addStretch();
    }

    addLayoutsInTestOfPrime();
}

void Application::setAMenuOfPrime() {
    music->stopMusic();
    music->addSecondMusic();
    music->startMusic();

    label->setText("Podaj liczbę: ");
    label->setStyleSheet("font-size: 40px;");
    label->setAlignment(Qt::AlignCenter);
    label->adjustSize();

    lineEdit = new QLineEdit(this);
    lineEdit->setContextMenuPolicy(Qt::NoContextMenu);
    lineEdit->setStyleSheet("border: 2px solid #0000ff; font-size: 40px;");
    lineEdit->setAlignment(Qt::AlignCenter);

    validator = new QIntValidator(this);
    lineEdit->setValidator(validator);
    lineEdit->adjustSize();

    me = new QLabel(this);
    QPixmap pixmap(":/img/calculator.jpg");
    me->setPixmap(pixmap);
    me->show();

    buttonToConfirm = new QPushButton("Sprawdź", this);
    buttonToConfirm->show();
    buttonToConfirm->setCursor(Qt::PointingHandCursor);
    buttonToConfirm->setStyleSheet("font-size: 25px;");
    buttonToConfirm->setFixedSize(400, 65);

    connect(buttonToConfirm, SIGNAL(pressed()), this, SLOT(setATextOfPrime()));
}

void Application::setAMenuOfSieve() {
    music->stopMusic();
    music->addThirdMusic();
    music->startMusic();
}

bool Application::pdfFileExists(QString path) {
    QFileInfo check_file(path);
    if (check_file.exists() && check_file.isFile() && QDir("pdf").exists()) {
        return true;
    } else {
        return false;
    }
}

void Application::setAMenuOfDocumentation() {
    music->stopMusic();
    music->addFourthMusic();
    music->startMusic();

    if(pdfFileExists(":/pdf/Liczby pierwsze.pdf")) {
        info->hide();
        QFile HelpFile("qrc:/pdf/Liczby pierwsze.pdf");
        HelpFile.copy(qApp->applicationDirPath().append("/pdf/Liczby pierwsze.pdf"));
        QDesktopServices::openUrl(QUrl::fromLocalFile
                                  (qApp->applicationDirPath().append("/pdf/Liczby pierwsze.pdf")));
    } else {
        info->show();
        info->setText("Brak pliku z dokumentacją!");
        info->move(QPoint(270, 500));
        info->setFixedSize(450, 30);
        info->setStyleSheet("color: #ff0000; font-size: 20px; font-weight: bold;");
    }
}

void Application::detectAClickOfTestOfPrime() {
    setAMenuOfPrime();

    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(setATextOfPrime()));

    label2 = new QLabel(this);
    label2->setStyleSheet("font-size: 40px;");
    label2->setAlignment(Qt::AlignCenter);
    label2->setFixedSize(600, 50);

    yesOrNo = new QLabel(this);
    returnToMenu = new QPushButton(this);
    widgetTestOfPrime = new QWidget(this);

    setLayoutsInTestOfPrime();

    for(int i=0; i<3; i++) {
        buttonsInMainMenu[i]->hide();
    }

    returnToMenu->hide();
}

void Application::detectAClickOfSieve() {
    //to be continued - in preparation
    setAMenuOfSieve();
}

void Application::detectAClickOfDocumentation() {
    //to be continued - in preparation
    buttonsInMainMenu[1]->setText("Sito Eratostenesa");
    setAMenuOfDocumentation();
}

void Application::setATextOfPrime() {
    buttonToConfirm->hide();
    me->hide();

    bool ok = true;
    QString numberFromInput = lineEdit->text();
    int number = numberFromInput.toInt(&ok, 10);
    QString textOfNumber = QString::number(number);

    if(prime->isPrime(number) == true) {
        label2->setText("Czy " + textOfNumber + " jest pierwsza: TAK");
        QPixmap pixmap(":/img/me_yes.png");
        yesOrNo->setPixmap(pixmap);
    } else {
        label2->setText("Czy " + textOfNumber + " jest pierwsza: NIE");
        QPixmap pixmap(":/img/me_no.png");
        yesOrNo->setPixmap(pixmap);
    }

    yesOrNo->setStyleSheet("background-image: url(:/img/white.jpg); "
                           "border: 2px solid #000; border-radius: 5px;");
    addButtonReturnToMenu();
}

void Application::addButtonReturnToMenu() {
    returnToMenu->show();
    returnToMenu->setCursor(Qt::PointingHandCursor);
    returnToMenu->setText("Powrót do menu");
    returnToMenu->setStyleSheet("font-size: 25px");
    returnToMenu->setFixedSize(300, 75);
    connect(returnToMenu, SIGNAL(released()), this, SLOT(setLayoutsOfMainMenu()));
}

void Application::closeEvent(QCloseEvent *event)
{
    QMessageBox exitMessage;
    exitMessage.setWindowTitle("Liczby pierwsze");
    exitMessage.setIcon(QMessageBox::Question);
    exitMessage.setText(tr("Koniec pracy na dziś. \nCzy chcesz zakończyć program?"));
    QAbstractButton *yesButton = exitMessage.addButton(tr("Tak"), QMessageBox::YesRole);
    exitMessage.addButton(tr("Nie"), QMessageBox::NoRole);
    exitMessage.exec();

    if (exitMessage.clickedButton()==yesButton) {
        music->stopMusic();
        event->accept();
    } else {
        event->ignore();
    }
}

Application::~Application() {
    //destructor
}
