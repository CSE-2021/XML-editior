#ifndef SYNSETINFO_H
#define SYNSETINFO_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>

class SynsetInfo : public QWidget{
    Q_OBJECT
public:
    explicit SynsetInfo(QString fileName, QWidget *parent = nullptr);
    QLineEdit *wordTXT;
    QListWidget *availableWordsLST;
    QVBoxLayout *mainLay;

};

#endif // SYNSETINFO_H
