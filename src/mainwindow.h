#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
Solve the Queens problem
**/


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnPilihFile_clicked();
    void on_btnSimpan_clicked();

private:
    QStringList lines;
    void solve();
    void printUpdate(std::vector<std::pair<int,int>> queens, long long iter);
    void printHasil(bool sukses,std::vector<std::pair<int,int>> queens , long long iter,
                    std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point end);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
