#include "music.h"

Music::Music() {
    //constructor
    player = new QMediaPlayer();
    playlist = new QMediaPlaylist();
    playlist2 = new QMediaPlaylist();
}

void Music::addFirstMusic() {
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/snd/chicken.ogg"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist);
    player->setVolume(40);
    player->play();
}

void Music::addSecondMusic() {
    playlist2->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.ogg"));
    playlist2->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist2);
    player->setVolume(40);
    player->play();
}

void Music::stopMusic() {
    player->stop();
}

Music::~Music() {
    //destructor
}
