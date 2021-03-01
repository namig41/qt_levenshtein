#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Редакторское расстояние");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::calc_dist(const QString &s1, const QString &s2)
{
    const int n = (int)s1.size();
    const int m = (int)s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
    }
    return dp[n][m];
}

void MainWindow::search_min_dist()
{
    if (dictionary.empty())
        QMessageBox::information(this, tr("Словарь"), tr("Cловарь пустой"));

    int min_dist = INT_MAX;
    QString user_input = ui->lineEdit->text();

    for (auto &s : dictionary)
    {
        int dist  = calc_dist(s, user_input);
        if (min_dist > dist)
        {
            ans = s;
            min_dist = dist;
        }
    }

    ui->lineEdit_2->setText(ans);
}

void MainWindow::on_action_2_triggered()
{
    QString str = QInputDialog::getText(0, "Диалоговое окно", "Введите слова в словарь");
    QStringList list = str.split(' ');

    dictionary.clear();
    for (auto &word : list)
        dictionary.push_back(word);
}

void MainWindow::on_action_3_triggered()
{
    QString str = QInputDialog::getText(0, "Диалоговое окно", "Добавьте слова в словарь");
    QStringList list = str.split(' ');

    for (auto &word : list)
        dictionary.push_back(word);
}

void MainWindow::on_action_4_triggered()
{
    QFile inputFile(QFileDialog::getOpenFileName(0, "Выберите словарь", "../lab4/"));

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       in.setCodec(QTextCodec::codecForName("UTF-8"));

       while (!in.atEnd())
       {
           QString word = in.readLine();
           dictionary.push_back(word);
       }

       QMessageBox::information(this, tr("Словарь"), tr("Файл успешно прочитан"));
       inputFile.close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Escape:
        close();
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QRegExp re("[a-zA-Z0-9");
    if (re.exactMatch(ui->lineEdit->text()))
        QMessageBox::information(this, tr("Ошибка"), tr("Неправильный ввод"));
    else
        search_min_dist();
}
