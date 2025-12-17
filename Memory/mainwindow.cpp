#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <random>
#include <algorithm>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui{new Ui::MainWindow}
{
    ui->setupUi(this);

    // Inserimento del layout
    auto griglia{new QGridLayout{ui->centralwidget}};
    ui->centralwidget->setLayout(griglia);

    // Inseriamo i bottoni
    QFont font;
    font.setPointSize(32);
    for (int i{0}; i<m_dimensione; ++i) {
        for(int j{0}; j<m_dimensione; ++j) {
            auto btn{new QPushButton{ui->centralwidget}};
            btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            btn->setText("?");
            btn->setFont(font);
            griglia->addWidget(btn,i,j);
            connect(btn, SIGNAL(pressed()), this, SLOT(onScopriTessera()));
        }
    }

    connect(ui->actionInizia_nuova_partita,SIGNAL(triggered()),this,SLOT(onNuovaPartita()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNuovaPartita()
{
    m_stato = Stato::ATTESA;
    m_mosse = 0;
    m_tessere_rimanenti = (m_dimensione * m_dimensione) / 2;

    creaGriglia();

    ui->statusbar->showMessage("Stai attento!");
    QTimer::singleShot(7000,[this]() {
        auto bottoni{ui->centralwidget->findChildren<QPushButton*>()};
        for(auto& btn : bottoni) {
            btn->setText("?");
        }
        ui->statusbar->showMessage("Partita iniziata!");
        m_stato = Stato::IN_PARTITA;
    });
}

void MainWindow::onScopriTessera()
{
    if (m_stato != Stato::IN_PARTITA) return;
    m_stato = Stato::ATTESA;
    auto btn = dynamic_cast<QPushButton*>(sender());
    if (btn) {
        if (btn->objectName() != btn->text()) {
            ++m_mosse;
            // Rivelando una tessera nascosta
            btn->setText(btn->objectName());
            if (m_tessera_precedente) {
                if (btn->objectName() == m_tessera_precedente->objectName()) {
                    // Ho trovato una coppia
                    m_tessera_precedente = nullptr;
                    --m_tessere_rimanenti;
                    if (m_tessere_rimanenti == 0) {
                        ui->statusbar->showMessage(QString{"Hai vinto! Mosse: %1"}.arg(m_mosse));
                        m_stato = Stato::FERMO;
                    }
                    else {
                        ui->statusbar->showMessage(QString{"Grande! Mosse: %1"}.arg(m_mosse));
                    }
                }
                else {
                    ui->statusbar->showMessage(QString{"Peccato! Mosse: %1"}.arg(m_mosse));
                    QTimer::singleShot(3000,[this,btn]() {
                        m_tessera_precedente->setText("?");
                        btn->setText("?");
                        m_tessera_precedente = nullptr;
                        m_stato = Stato::IN_PARTITA;
                        ui->statusbar->showMessage(QString{"Fai la tua scelta! Mosse: %1"}.arg(m_mosse));
                    });
                    return;
                }
            }
            else {
                ui->statusbar->showMessage(QString{"Fai la tua scelta! Mosse: %1"}.arg(m_mosse));
                m_tessera_precedente = btn;
            }
        }
    }
    m_stato = Stato::IN_PARTITA;
}

void MainWindow::creaGriglia()
{
    QStringList tessere;
    for (int k{0}; k<(m_dimensione*m_dimensione)/2; ++ k) {
        auto base = 0x1F600 + k;
        QString smiley;
        smiley += QChar::highSurrogate(base);
        smiley += QChar::lowSurrogate(base);
        tessere.push_back(smiley);
        tessere.push_back(smiley);
    }

    std::random_device random;
    std::mt19937 generatore{random()};
    std::shuffle(tessere.begin(),tessere.end(),generatore);

    auto bottoni{ui->centralwidget->findChildren<QPushButton*>()};
    auto indice{0};
    for(auto& btn : bottoni) {
        btn->setObjectName(tessere.at(indice));
        btn->setText(tessere.at(indice++));
    }
}
