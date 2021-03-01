#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QFileDialog>
#include <QInputDialog>
#include <vector>
#include <string>
#include <QKeyEvent>
#include <QTextCodec>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
using namespace std;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int calc_dist(const QString &s1, const QString &s2);
    void search_min_dist();

    virtual void keyPressEvent(QKeyEvent *);

private slots:

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QString ans;
    vector<QString> dictionary;
};
#endif // MAINWINDOW_H
