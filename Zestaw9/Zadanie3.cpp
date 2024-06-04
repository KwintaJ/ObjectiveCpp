//######################################//
//                                      //
//    Jan Kwinta          14.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 9, zadanie 3               //
//                                      //
//######################################//

#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Definicja klasy Song
class Song {
public:
    Song(const std::wstring& a, const std::wstring& t) : artist_(a), title_(t)
    {
    }
    
    ~Song() 
    {
    }
    
    void play() const 
    {
        std::wcout << L"Playing: " << artist_ << L" - " << title_ << std::endl;
    }

private:
    std::wstring artist_;
    std::wstring title_;
};

template<typename... Args>
std::unique_ptr<Song> SongFactory(Args&&... args)
{
    return std::make_unique<Song>(std::forward<Args>(args)...);
}


int main()
{
    auto song = SongFactory(L"Michael Jackson", L"Beat It");
    song->play();

    std::vector<std::unique_ptr<Song>> songs;

    songs.push_back(SongFactory(L"Queen", L"Bohemian Rhapsody"));
    songs.push_back(SongFactory(L"Deep Purple", L"Stormbringer"));
    songs.push_back(SongFactory(L"Led Zeppelin", L"Stairway to Heaven"));

    for (const auto& s : songs) 
    {
        s->play();
    }
}
