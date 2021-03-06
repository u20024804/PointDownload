#ifndef NORMALNOTICE_H
#define NORMALNOTICE_H

#include <QObject>
#include <QQmlEngine>

enum NoticeTitleColor
{
    Notice_Color_Notice,
    Notice_Color_Warning,
    Notice_Color_Success,
    Notice_Color_Error,
    Notice_Color_Unknown
};

class NormalNotice : public QObject
{
    Q_OBJECT
public:
    static NormalNotice * getInstance();
    static QObject * normalNoticeObj(QQmlEngine *engine, QJSEngine *scriptEngine);

    void initData();

    void setNoticeTitle(QString title);
    void setNoticeTitleColor(NoticeTitleColor noticeTitleColor);
    void setMessage(QString message);
    void appendMessage(QString message);

    void showMessage(); //please use tr(QString message) for I18N
    void showMessage(QString message); //please use tr(QString message) for I18N
    void showMessage(QString title, QString message); //please use tr(QString message) for I18N
    void showMessage(QString title, NoticeTitleColor noticeTitleColor, QString message);
signals:
    void signalShowMessage(QString title, QString noticeTitleColor, QString message);

public slots:

private:
    explicit NormalNotice(QObject *parent = 0);

    QString colorToString(NoticeTitleColor noticeColor);

private:
    static NormalNotice * normalNotice;

    QString noticeTitle;
    QString gmessage;
    NoticeTitleColor gnoticeTitleColor;
};
#endif // NORMALNOTICE_H
