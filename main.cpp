#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    system("clear");
    QDir dir;
    dir.cdUp();
    dir.cd("QtFile");
    QString filePath = dir.absoluteFilePath("input.txt");

    QFile file (filePath);
    if(file.open(QIODevice::Text | QIODevice::ReadWrite)){
        qDebug() << "ok";
    }else{
        qDebug() << "Cannot open file!";
    }

    QTextStream qStream(&file);
    QString s;
    int T = 0;
    while(qStream.atEnd() == false)
    {
        qStream >> s;
        T+=s.toInt();
    }

    QFile f2(dir.absoluteFilePath("output.txt"));
    f2.open(QIODevice::Text | QIODevice::WriteOnly);
    QTextStream s2(&f2);
    s2<<T;

    f2.close();
    file.close();

    return a.exec();
}
