#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_durationChanged(qint64 position);

//    volumeSlider = new QSlider(Qt::Horizontal, this);
//    volumeSlider->setRange(0, 100);
//    volumeSlider->setFixedWidth(100);
//    volumeSlider->setValue(100);
//    player = new QMediaPlayer;

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
};

#endif // MAINWINDOW_H
