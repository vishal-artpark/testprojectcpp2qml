#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
#include<QDebug>

class DataProvider : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString header READ header NOTIFY headerChanged)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)

public:
    explicit DataProvider(QObject *parent = nullptr);
    Q_INVOKABLE void callMe(){
        _header="Reclaiming Your Focus";
        _description=R"(
<h1> Reclaiming Your Focus: The Art of the Digital Sabbatical</h1>

In an era where our pockets buzz every three minutes and the "infinite scroll" has become a literal pastime, we’ve lost something precious: **the ability to be bored.** We tend to treat boredom as a bug in our internal software that needs to be patched with a quick hit of dopamine from a social media feed. But what if that boredom is actually where our best ideas live?

<h1> Why We’re Always "On"</h1>

The modern attention economy is designed to keep us engaged. From the red notification bubbles to the autoplaying videos, every interface is engineered to trigger a response. While these tools keep us connected, they also keep us in a state of **continuous partial attention.** We are rarely 100% present in any one moment because a part of our brain is always waiting for the next ping.

<h2> The Benefits of Powering Down</h2>

Taking a "Digital Sabbatical"—whether it’s for an hour a day or a full weekend—isn't about hating technology. It’s about **resetting your baseline.** When you step away from the screen, you might notice:

* **Increased Depth of Thought:** Without interruptions, you can finally finish that book or solve that complex problem at work.
* **Reduced Comparison Anxiety:** You stop measuring your "behind-the-scenes" against everyone else’s "highlight reel."
* **Physical Relief:** Your eyes rest, your posture improves, and that low-level "tech neck" tension begins to fade.

<h1> How to Start Small</h1>

You don’t have to throw your smartphone into a lake to see results. Try these three micro-habits this week:

1. <b>The Golden Hour:</b> No screens for the first 60 minutes after you wake up.
2. <b>Analog Meals:</b> Leave your phone in another room during dinner.
3. <b>Grey-Scale Mode:</b> Turn your phone screen to black and white; it makes those colorful icons much less addictive.

True productivity isn't about how many tabs you have open; it’s about how much of yourself you can bring to a single task. Maybe it's time to close the laptop and see what happens when the only thing "processing" is your own mind.)";
        emit headerChanged();
        emit descriptionChanged();
    };
    QString description()const{
        return _description;
    }
    QString header()const{
        return _header;
    }
signals:
    void descriptionChanged();
    void headerChanged();

private:
    QString _header{"NA"};
    QString _description{"NA"};
    QTimer*_timer{};
private:
    void update();
};

#endif // DATAPROVIDER_H
