#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    enum class Stato { FERMO, IN_PARTITA, ATTESA };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNuovaPartita();
    void onScopriTessera();

private:
    void creaGriglia();
    Ui::MainWindow *ui;
    unsigned int m_dimensione{8};
    Stato m_stato{Stato::FERMO};
    QPushButton *m_tessera_precedente{nullptr};
    unsigned int m_mosse{0};
    unsigned int m_tessere_rimanenti{0};
};
#endif // MAINWINDOW_H
