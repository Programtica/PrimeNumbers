#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtGlobal>
#include <QTime>

class Music {
private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QTime time;

    int randomValue;
public:
    Music();
    ~Music();

    void startMusic();
    void addMusic();
    void stopMusic();
    int randInt(int low, int high);
};

#endif // MUSIC_H
