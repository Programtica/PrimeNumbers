#include "music.h"

Music::Music() {
    //constructor
    player = new QMediaPlayer();
    time = QTime::currentTime();
    qsrand((uint)time.msec());
}

int Music::randInt(int low, int high) {
    return qrand() % ((high + 1) - low) + low;
}

void Music::addMusic() {
    playlist = new QMediaPlaylist();
    randomValue = randInt(1,4);

    if(randomValue == 1) {
        playlist->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
    } else if(randomValue == 2) {
        playlist->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
    } else if(randomValue == 3) {
        playlist->addMedia(QUrl("qrc:/snd/battyMcFaddinSilentFilmLight.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/brightlyFancyOddities.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/ifIHadAChicken.mp3"));
        playlist->addMedia(QUrl("qrc:/snd/amazingPlanSilentFilmDark.mp3"));
    } else if(randomValue == 4) {
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
