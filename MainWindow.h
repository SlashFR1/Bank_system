#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include "Bank.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // These are "Slots" triggered by button clicks
    void handleDeposit();
    void handleWithdraw();
    void refreshAccountList();

private:
    Bank myBank;                // Your existing backend class
    QLineEdit *amountInput;     // Text box for money
    QLineEdit *accIdInput;      // Text box for ID
    QListWidget *displayArea;   // List to show accounts
};

#endif