#ifndef DISKCLEANWIDGET_H
#define DISKCLEANWIDGET_H

#include "../../src/repairtoolsproxy.h"
#include "diskcleanthread.h"

#include <QWidget>
#include <QPushButton>
#include <QPointer>
#include <QLabel>
#include <QComboBox>

class DiskCleanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DiskCleanWidget(QWidget *parent = nullptr);

    void setToolsProxy(RepairToolsProxy *proxy);

protected:
    void showEvent(QShowEvent *e);

private slots:
    void reset();
    void cleanStart();
    void cleanCancel();
    void refreshDiskSize();
    void cleanEnd(const quint64 clearedSize);

private:
    QPointer<DiskCleanThread> m_worker;
    RepairToolsProxy *m_toolsProxy;
    QLabel *m_icon;
    QLabel *m_tips;
    QLabel *m_statusTips;
    QComboBox *m_diskSelectBox;
    QPushButton *m_cleanButton;
    QPushButton *m_cancelButton;
    QPushButton *m_okButton;
};

#endif // DISKCLEANWIDGET_H
