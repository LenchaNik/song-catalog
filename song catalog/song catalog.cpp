

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Song {
	std::string title;
	std::string artist;
	std::string lyrics;
};
//Функция для добавления текста песни с клавиатуры 
void addLyricsManually(std::vector<Song>& songs) {
	Song newSong;
	std::cout << "Enter song title:";
	std::cin >> newSong.title;
	std::cout << "Enter artist name:";
	std::cin >> newSong.artist;
	std::cout << "Enter lyrics:";
	std::cin >> newSong.lyrics;
	songs.push_back(newSong);

}
//Функция для добавления текста песни из файла 
void addLyricsFromFile(std::vector<Song>& songs) {
	std::string filePath;
	std::cout << "Enter path to lyrics file:";
	std::cin >> filePath;
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Faild to open file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(file, line)) {
		songs.push_back({});//добавление новую песню без названия исполнителя
		songs.back().lyrics += line + "\n";//добавляем строку текста к последней песне
	}
	file.close();
}


int main()
{
	std::vector<Song>songs;//вектор для хранения песен
	//Меню для выбора способа добавления песни
	int choice;
	do {
		std::cout << "1. Add lyrics manually" << std::endl;
		std::cout << "2. Add lyrics from file" << std::endl;
		std::cout << "Choice:";
		std::cin >> choice;
		switch (choice) {
		case 1:
			addLyricsManually(songs);
			break;
		case 2:
			addLyricsFromFile(songs);
			break;
		default:
			std::cout << "Invalid choice." << std::endl;
		}
	} while (choice != 0);//Повторяем цикл до тех пор, пока пользователь не выберет 0 для выхода
	//Вывод всех добавленных песен
	for (const auto& song : songs) {
		std::cout << "Title:" << song.title << std::endl;
		std::cout << "Artist:" << song.artist << std::endl;
		std::cout << "Lyrics:" << song.lyrics << std::endl;

	}
	return 0;
}


