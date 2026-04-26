#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qmediaplayer.h>
#include <qaudiooutput.h>
#include <qurl.h>
#include <qslider.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    //Label
    ui->setupUi(this);
    QLabel *Label = new QLabel("input open File:",this);
    Label -> move(10,10);

    //input
    QLineEdit *Edit = new QLineEdit(this);
    Edit -> move(115,10);

    //Button show
    QPushButton *Button = new QPushButton("Play",this);
    Button -> move(340,500);

    QPushButton *Button_STOP = new QPushButton("Stop",this);
    Button_STOP -> move(450,500);



    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audio = new QAudioOutput(this);

    player->setAudioOutput(audio);
    //player->setAudioOutput(new QAudioOutput);

    QSlider *Volume = new QSlider(Qt::Horizontal,this);
    Volume->setGeometry(50,100,200,30);
    Volume ->setRange(0,100);
    Volume ->setValue(50);


    connect(Button,&QPushButton::clicked,this,[=](){
        player->setSource(QUrl::fromLocalFile(Edit->text()));
        player->play();





    });

    connect(Volume,&QSlider::valueChanged,this,[=](int value){
        audio->setVolume(value/100.0);
    });

    connect(Button_STOP,&QPushButton::clicked,this,[=](){
        player->stop();

});
}

MainWindow::~MainWindow()
{
    delete ui;
}
