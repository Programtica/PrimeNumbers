#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtGlobal>

class Music {
private:
    int test;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
public:
    Music();
    ~Music();

    void startMusic();
    void addMusic();
    void stopMusic();
};

#endif // MUSIC_H
