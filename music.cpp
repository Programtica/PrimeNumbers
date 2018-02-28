#include "music.h"

Music::Music() {
    //constructor
    player = new QMediaPlayer();
    for(int i=0; i<4; i++) {
        playlists[i] = nullptr;
    }
}

void Music::addFirstMusic() {
    playlists[0] = new QMediaPlaylist();
    playlists[0]->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
    playlists[0]->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlists[0]);
}

void Music::addSecondMusic() {
    playlists[1] = new QMediaPlaylist();
    playlists[1]->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
    playlists[1]->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlists[1]);
}

void Music::addThirdMusic() {
    playlists[2] = new QMediaPlaylist();
    playlists[2]->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
    playlists[2]->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlists[2]);
}

void Music::addFourthMusic() {
    playlists[3] = new QMediaPlaylist();
    playlists[3]->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
    playlists[3]->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
    playlists[3]->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
    playlists[3]->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
    playlists[3]->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlists[3]);
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
