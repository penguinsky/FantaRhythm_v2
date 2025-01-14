#include "Game.h"

Game::Game(const String& music, const String& dif) {
	musicpath = music;
	difpath = dif;

	subject = new NotesSubject();
	hitpoint = new HitPoint();

	subject->addObserver(hitpoint);
	
	notes = new NotesManager(subject,difpath);
	
	
	
	TextureAsset::Register(U"back", U"resources/images/back/first.jpg");
	TextureAsset::Preload(U"back");

	FontAsset::Register(U"font", 30);
	FontAsset::Preload(U"font");

	MusicManager::playMusicGame(musicpath);

	
}
Game::~Game() {
	delete notes;
	TextureAsset::UnregisterAll();
	FontAsset::Unregister(U"font");
}

void Game::update() {
	notes->update();
	hitpoint->update();
}
void Game::draw() {
	//�w�i�摜�`��
	TextureAsset(U"back").draw();
	notes->draw();
	hitpoint->draw();
}