// Copyright (c) 2017-2019 The PIVX developers
// Copyright (c) 2020 The Learnium developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZLRACONTROLDIALOG_H
#define ZLRACONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zlra/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZLraControlDialog;
}

class CZLraControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZLraControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZLraControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZLraControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZLraControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZLraControlDialog(QWidget *parent);
    ~ZLraControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZLraControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZLraControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZLRACONTROLDIALOG_H
