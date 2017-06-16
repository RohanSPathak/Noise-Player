#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

//    connect(volumeSlider, SIGNAL(valueChanged(int)), this, SIGNAL(volumeChanged(int)));
//    connect(volumeSlider, SIGNAL(volumeChanged(int)), player, SLOT(setVolume(int)));

    //    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStart_clicked()
{
    bool white,pink,brown;
    white = ui->radioButtonWhite->isChecked();
    pink = ui->radioButtonPink->isChecked();
    brown = ui->radioButtonBrown->isChecked();
    if(white)
    {
        player->setMedia(QUrl::fromLocalFile("/home/rohan/Downloads/white-noise.mp3"));
    }
    if(pink)
    {
        player->setMedia(QUrl::fromLocalFile("/home/rohan/Downloads/pink-noise.mp3"));
    }
    if(brown)
    {
        player->setMedia(QUrl::fromLocalFile("/home/rohan/Downloads/brown-noise.mp3"));
    }

    player->play();
    qDebug()<< player->errorString();
}

void MainWindow::on_pushButtonStop_clicked()
{
    player->stop();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{

    player->setVolume(position);
}
