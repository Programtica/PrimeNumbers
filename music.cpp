#include "music.h"

Music::Music() {
    //constructor
    player = new QMediaPlayer();
    playlist = new QMediaPlaylist();
    playlist2 = new QMediaPlaylist();
}

void Music::addFirstMusic() {
    playlist->addMedia(QUrl("qrc:/snd/chicken.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
}

void Music::addSecondMusic() {
    playlist2->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
    playlist2->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist2);
}

void Music::startMusic() {
    player->setVolume(40);
    player->play();
}

void Music::stopMusic() {
    player->stop();
}

Music::~Music() {
    //destructor
}
