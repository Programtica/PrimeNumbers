#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

class Music {
private:
    QMediaPlayer *player;

    QMediaPlaylist *playlist;
    QMediaPlaylist *playlist2;
public:
    Music();
    ~Music();

    void addFirstMusic();
    void addSecondMusic();
    void startMusic();
    void stopMusic();
};

#endif // MUSIC_H
