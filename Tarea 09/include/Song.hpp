#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include <sstream>

class Song
{
    private:
        std::string name;
        std::string mp3Name;
        std::string author;
        std::string interpreter;
        int ranking;

        std::string formatData(std::string Data);
        std::string formatData(int value);

    public:
        Song();
        Song(int, std::string, std::string, std::string, std::string);

        void setName(std::string);
        void setMP3Name(std::string);
        void setAuthor(std::string);
        void setInterpreter(std::string);
        void setRanking(int);

        std::string getName();
        std::string getMP3Name();
        std::string getAuthor();
        std::string getInterpreter();
        int getRanking() const;

        std::string toString();

        static int compareBySongName(const Song&, const Song&);
        static int compareByInterpreter(const Song&, const Song&);
};

#endif // SONG_HPP
