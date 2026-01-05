#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Setup UI Layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    accIdInput = new QLineEdit();
    accIdInput->setPlaceholderText("Enter Account ID");
    
    amountInput = new QLineEdit();
    amountInput->setPlaceholderText("Enter Amount ($)");

    QPushButton *depBtn = new QPushButton("Deposit");
    QPushButton *withBtn = new QPushButton("Withdraw");
    displayArea = new QListWidget();

    layout->addWidget(new QLabel("Bank Management System"));
    layout->addWidget(accIdInput);
    layout->addWidget(amountInput);
    layout->addWidget(depBtn);
    layout->addWidget(withBtn);
    layout->addWidget(displayArea);

    setCentralWidget(centralWidget);

    // CONNECTING: The magic of Qt
    connect(depBtn, &QPushButton::clicked, this, &MainWindow::handleDeposit);
    connect(withBtn, &QPushButton::clicked, this, &MainWindow::handleWithdraw);

    // Initial Data Load
    myBank.loadFromFile();
    refreshAccountList();
}

void MainWindow::handleDeposit() {
    int id = accIdInput->text().toInt();
    double amt = amountInput->text().toDouble();
    
    Account* acc = myBank.findAccount(id);
    if (acc) {
        acc->deposit(amt);
        QMessageBox::information(this, "Success", "Deposit Complete!");
        refreshAccountList();
    } else {
        QMessageBox::warning(this, "Error", "Account Not Found");
    }
}

void MainWindow::refreshAccountList() {
    displayArea->clear();
    // Logic to loop through bank accounts and add strings to displayArea
}