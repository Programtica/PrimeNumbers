#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

class Music {
private:
    QMediaPlayer *player;
    QMediaPlaylist *playlists[4];
public:
    Music();
    ~Music();

    void addFirstMusic();
    void addSecondMusic();
    void addThirdMusic();
    void addFourthMusic();
    void startMusic();
    void stopMusic();
};

#endif // MUSIC_H
