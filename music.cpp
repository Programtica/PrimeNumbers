#include "music.h"

Music::Music() {
    //constructor
    player = new QMediaPlayer();
}

void Music::addMusic() {
    playlist = new QMediaPlaylist();
    test = qrand() % 4 + 1;

    if(test == 1) {
        playlist->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
    } else if(test == 2) {
        playlist->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
    } else if(test == 3) {
        playlist->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
    } else if(test == 4) {
        playlist->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
    }
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
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
