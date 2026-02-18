#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QRegularExpression>
#include <QMessageBox>
#include <vector>
#include <map>
#include <utility>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Queens");
    ui->solusiChoice->setVisible(false);
    ui->btnSimpan->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isValid(vector<pair<int,int>> queens){
    if(queens.empty()) return 0;
    for(int i = 0; i < queens.size(); i++){
        for(int j = i + 1; j < queens.size(); j++){
            if(queens[i].first == queens[j].first || queens[i].second == queens[j].second)return 0;
            if(queens[i].first == queens[j].first-1 &&
                queens[i].second == queens[j].second -1) return 0;
            if(queens[i].first == queens[j].first-1 &&
                queens[i].second == queens[j].second +1) return 0;
            if(queens[i].first == queens[j].first+1 &&
                queens[i].second == queens[j].second -1) return 0;
            if(queens[i].first == queens[j].first+1 &&
                queens[i].second == queens[j].second +1) return 0;
        }
    }
    return 1;
}

void MainWindow::printUpdate(vector<pair<int,int>> queens, long long iter){
    QStringList copy = lines;
    for(int i = 0; i < queens.size(); i++){
        copy[queens[i].first][queens[i].second] = '#';
    }
    QString it = QString::number(iter);
    ui->LiveUpdate->append("Iterasi ke - " +it + " :\n");
    for(int i = 0; i< lines.size(); i++){
        ui->LiveUpdate->append(copy[i] + "\n");
    }
    ui->LiveUpdate->append("\n\n");
}
void MainWindow::printHasil(bool sukses, vector<pair<int,int>> queens, long long iter,
                            chrono::high_resolution_clock::time_point start, chrono::high_resolution_clock::time_point end){
    if(sukses){
        ui->LiveUpdate->append( "Ditemukan solusi :\n");
        for(int i = 0; i < queens.size(); i++){
            lines[queens[i].first][queens[i].second] = '#';
        }
        for(int i = 0; i< lines.size(); i++){
            ui->LiveUpdate->append(lines[i] + "\n");
        }
        ui->LiveUpdate->append("Banyak kasus yang ditinjau: " + QString::number(iter));
        int elapsed = (end-start).count();
        ui->LiveUpdate->append("Waktu pencarian : " + QString::number(elapsed) +"ms\n");
    }
    else{
       ui->LiveUpdate->append( "Tidak ditemukan solusi\n");
    }
}
void MainWindow::solve(){
    map<QChar, vector<pair<int,int>>> colours;
    vector<QChar> huruf;

    for(int i = 0; i < lines.size(); i++){
        for(int j = 0; j < lines[i].length(); j++){
            colours[lines[i][j]].push_back({i,j});
        }
    }
    for(const auto &c : colours)
        huruf.push_back(c.first);
    int n = colours.size();
    vector<pair<int,int>> queens(n);
    vector<int> idx(n, 0);
    bool flag = false;
    long long iter = 0;

    auto start = chrono::high_resolution_clock::now();
    while (true) {
        for (int i = 0; i < n; i++) {
            queens[i] = colours[huruf[i]][idx[i]];
        }
        if (isValid(queens)) {
            flag = true;
            break;
        }
        if (iter > 0 && iter % 100000 == 0){
            printUpdate(queens, iter);
        }
        int pos = n - 1;
        while (pos >= 0 && ++idx[pos] == colours[huruf[pos]].size()) {
            idx[pos] = 0;
            pos--;
        }

        if (pos < 0) break;
        iter++;
    }
    auto end = chrono::high_resolution_clock::now();

    printHasil(flag, queens, iter, start, end);
}

void MainWindow::on_btnPilihFile_clicked()
{
    lines.clear();
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Pilih File Teks",
        "..",
        "Text Files (*.txt)"
        );

    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "File tidak bisa dibuka!");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        line.remove(QRegularExpression("\\s"));
        if(!line.isEmpty())lines.append(line);
    }
    file.close();
    ui->LiveUpdate->clear();
    solve();
    ui->solusiChoice->setVisible(true);
    ui->btnSimpan->setVisible(true);
}
void MainWindow::on_btnSimpan_clicked(){
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Simpan Solusi",
        "",
        "Text File (*.txt)"
        );

    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "File tidak bisa dibuka!");
        return;
    }
    QTextStream out(&file);

    for(const QString &line : lines){
        out << line << "\n";
    }

    file.close();

}

