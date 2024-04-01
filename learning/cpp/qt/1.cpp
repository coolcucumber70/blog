#include <QMetaObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
public:
    QString getName() const { return m_name; }
    void setName(const QString& name) { m_name = name; emit nameChanged(); }

signals:
    void nameChanged();

private:
    QString m_name;
};

int main()
{
    const QMetaObject* metaObject = MyClass::staticMetaObject();  // 获取 MyClass 的元对象

    qDebug() << "Class name:" << metaObject->className();

    // 遍历属性
    qDebug() << "Properties:";
    for (int i = 0; i < metaObject->propertyCount(); ++i)
    {
        const QMetaProperty property = metaObject->property(i);
        qDebug() << "Name:" << property.name() << "Type:" << property.typeName();
    }

    // 遍历方法（包括信号和槽）
    qDebug() << "Methods:";
    for (int i = 0; i < metaObject->methodCount(); ++i)
    {
        const QMetaMethod method = metaObject->method(i);
        qDebug() << "Name:" << method.name() << "Signature:" << method.methodSignature();
    }

    return 0;
}