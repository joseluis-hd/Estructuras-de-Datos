#ifndef SONG_HPP
#define SONG_HPP

#include <string>

class Song
{
    private:
        std::string name;
        std::string author;
        std::string interpreter;
        int position;

    public:
        Song();
        Song(const Song&);

        std::string getAuthor();
        std::string getInterpreter();
        std::string getName();
        int getPosition();

        void setAuthor(const std::string&);
        void setInterpreter(const std::string&);
        void setName(const std::string&);
        void setPosition(const int&);

        std::string toString();
};

#endif // SONG_HPP
